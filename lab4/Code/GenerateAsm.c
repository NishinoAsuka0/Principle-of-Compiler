#include<stdio.h>
#include<stdlib.h>
#include "GenerateAsm.h"
#include<string.h>

Register Regs[32];
VarStructure AsmVarList = NULL;
StackPointer nowFunctionStack = NULL;
int Arg_Num = 0;
int Param_Num = 0;
int Last_clearReg = 8;

void Generate_Asm(CodeList curNode,FILE* file){
	// 打印目标代码数据段
	fprintf(file,".data\n_prompt: .asciiz \"Enter an integer:\"\n_ret: .asciiz \"\\n\"\n.globl main\n.text\n");
	// 打印read函数定义
	fprintf(file,"\nread:\n");
	fprintf(file,"\tli $v0, 4\n");
	fprintf(file,"\tla $a0, _prompt\n");
	fprintf(file,"\tsyscall\n");
	fprintf(file,"\tli $v0, 5\n");
	fprintf(file,"\tsyscall\n");
	fprintf(file,"\tjr $ra\n");

	// 打印write函数定义
	fprintf(file,"\nwrite:\n");
	fprintf(file,"\tli $v0, 1\n");
	fprintf(file,"\tsyscall\n");
	fprintf(file,"\tli $v0, 4\n");
	fprintf(file,"\tla $a0, _ret\n");
	fprintf(file,"\tsyscall\n");
	fprintf(file,"\tmove $v0, $0\n");
	fprintf(file,"\tjr $ra\n\n");

	//设置寄存器
	for(int i = 0; i<32; i++){
		Register newreg = (Register)malloc(sizeof(struct Register_));
		if(i == 0){
			newreg->RegName = "$zero";	//常数0
		}
		else if(i == 1){
			newreg->RegName = "$at";	// 汇编器保留
		}
		else if(i >= 2 && i <= 3){
			sprintf(newreg->RegName, "v%d", i-2);	//表达式求值或函数结果 
		}
		else if(i >= 4 && i <= 7){
			sprintf(newreg->RegName, "a%d", i-4);	//函数的首四个参数
		}
		else if(i >= 8 && i <= 15){
			//函数调用者负责保存
			sprintf(newreg->RegName, "t%d", i-8);
		}
		else if(i >= 16 && i<=23){
			//函数负责保存和恢复
			sprintf(newreg->RegName, "s%d", i-16);
		}
		else if(i >= 24 && i<=25){
			sprintf(newreg->RegName, "t%d", i-24+8);	//函数调用者负责保存
		}
		else if(i >= 26 && i<=27){
			sprintf(newreg->RegName, "k%d", i-26);	//中断处理保留
		}
		else if(i == 28){
			newreg->RegName = "$gp";	//指向静态数据段64K内存空间的中部
		}
		else if(i == 29){
			newreg->RegName = "$sp";	//栈顶指针
		}
		else if(i == 30){
			newreg->RegName = "$s8";	//MIPS32作为$s8，GCC作为帧指针
		}
		else if(i == 31){
			newreg->RegName = "$ra";	// 返回地址
		}
		if(LAB4_DEBUG)	printf("the RegName is %s\n", newreg->RegName);
		newreg->var = NULL;
		Regs[i] = newreg; 
	}
	CodeList nowNode = curNode;
	while (nowNode != NULL)
	{
		Generate_IR_Asm(nowNode, file);
		nowNode = nowNode->next;
	}
	
}

char*GetVarName(Operand op){
	char*name;
	switch (op->kind)
		{
		case OP_TEMP:
			sprintf(name, "t%d", op->inform.Temp_Num);
			break;
		case OP_ARRAY:
		case OP_ADDR:
		case OP_VAR:
			sprintf(name, "v%d", op->inform.Var_Num);
		default:
			break;
		}
	return name;
}

VarStructure findVar(Operand op){
	VarStructure curNode = AsmVarList;
	while(curNode != NULL){
		if(curNode->op->kind != op->kind)	continue;
		switch (op->kind)
		{
		case OP_TEMP:
			if(curNode->op->inform.Temp_Num == op->inform.Temp_Num)
				return curNode;
		case OP_ARRAY:
		case OP_ADDR:
		case OP_VAR:
			if(curNode->op->inform.Var_Num == op->inform.Var_Num)
				return curNode;
		default:
			break;
		}
	}
	return NULL;
}
int GetRegNum(Operand op){
	int i;
	if(op->kind == OP_CONSTANT){
		for(i = 8; i<= 15 ; i++){
			if(Regs[i]->var == NULL){
				if(LAB4_DEBUG)	printf("Use the reg %s\n", Regs[i]->RegName);
				return i;
			}
		}
		for(i = 24; i<= 25 ; i++){
			if(Regs[i]->var == NULL){
				if(LAB4_DEBUG)	printf("Use the reg %s\n", Regs[i]->RegName);
				return i;
			}
		}
	}
	else{
		VarStructure opVar = findVar(op);
		if(opVar != NULL){
			return opVar->Reg;
		}
		else{
			opVar = (VarStructure)malloc(sizeof(struct VarStructure_));
			for(i = 8; i<= 15 ; i++){
				if(Regs[i]->var == NULL){
					if(LAB4_DEBUG)	printf("Use the reg %s\n", Regs[i]->RegName);
					opVar->op = op;
					opVar->Reg = i;
					opVar->next = AsmVarList;
					AsmVarList = opVar;
					Regs[i]->var = opVar;
					return i;
				}
			}
			for(i = 24; i<= 25 ; i++){
				if(Regs[i]->var == NULL){
					if(LAB4_DEBUG)	printf("Use the reg %s\n", Regs[i]->RegName);
					opVar->op = op;
					opVar->Reg = i;
					opVar->next = AsmVarList;
					AsmVarList = opVar;
					Regs[i]->var = opVar;
					return i;
				}
			}
		}
	}
}

void Clear_Reg(int index){
	if(LAB4_DEBUG)	printf("The reg %s is clear\n", Regs[index]->RegName);
	Regs[index]->var = NULL;
	return;
}

void Generate_IR_Asm(CodeList curNode, FILE* file){
	if(LAB4_DEBUG)	printf("Go in IR_Asm\n");
	if(curNode == NULL)	return;
	IRCode ircode = curNode->IRcoding;
	if(ircode == NULL)	return;
	switch(ircode->kind){
		case IR_LABEL:
			if(LAB4_DEBUG)	printf("lable%d\n", ircode->inform.labelID->inform.Label_Num);
			fprintf(file, "lable%d\n", ircode->inform.labelID->inform.Label_Num);
			break;
		case IR_FUNCTION:
			if(LAB4_DEBUG){
				printf("%s:\n", ircode->inform.funcName);
				
			}
			fprintf(file, "%s:\n", ircode->inform.funcName);
			fprintf(file, "\tsubu $sp, $sp, 4\n");	
			fprintf(file, "\tsw $fp, 0($sp)\n");
			fprintf(file, "\tmove $fp, $sp\n");
			//申请一段较大的栈空间（可通过$fp加上一段偏移寻址），保存局部变量等;
			StackPointer newFuncStack = (StackPointer)malloc(sizeof(struct StackPointer_));
			newFuncStack->CurOffset = -4;
			newFuncStack->next = nowFunctionStack;
			nowFunctionStack = newFuncStack;
			fprintf(file, "\taddi $sp, $fp, 1024\n");
			//初始化堆栈偏移量，函数形参个数等;
			break;
		case IR_ASSIGN:
		{
			Operand left = ircode->inform.assign.left;
			Operand right = ircode->inform.assign.right;
			if(right->kind == OP_CONSTANT){
				int index = GetRegNum(left);
				if(LAB4_DEBUG)	printf("\tli %s, %d\n", Regs[index]->RegName, right->inform.Value);
				fprintf(file, "\tli %s, %d\n", Regs[index]->RegName, right->inform.Value);
				nowFunctionStack->CurOffset -= 4;
				Regs[index]->var->VarOffset = nowFunctionStack->CurOffset;
				fprintf(file, "\tsw %s, %d($fp)\n", Regs[index]->RegName, nowFunctionStack->CurOffset);
				return;		
			}
			else{
				int leftindex = GetRegNum(left);
				int rightindex = GetRegNum(right);
				fprintf(file, "\tmove %s, %s\n", Regs[leftindex]->RegName, Regs[rightindex]->RegName);

				//将x关联到的变量值溢出到栈上并标记偏移量
				nowFunctionStack->CurOffset -= 4;
				Regs[leftindex]->var->VarOffset = nowFunctionStack->CurOffset;
				fprintf(file, "\tsw %s, %d($fp)\n", Regs[leftindex]->RegName, nowFunctionStack->CurOffset);
				return;
			}
			break;
		}
		case IR_ADD:
		{
			Operand result = ircode->inform.binOp.result;
			Operand op1 = ircode->inform.binOp.op1;
			Operand op2 = ircode->inform.binOp.op2;
			int Resindex = GetRegNum(result);
			int op1index = GetRegNum(op1);
			int op2index = GetRegNum(op2);
			fprintf(file, "\tadd %s, %s, %s\n", Regs[Resindex]->RegName, Regs[op1index]->RegName, Regs[op2index]->RegName);
			//将x关联到的变量值溢出到栈上并标记偏移量
			nowFunctionStack->CurOffset -= 4;
			Regs[Resindex]->var->VarOffset = nowFunctionStack->CurOffset;
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[Resindex]->RegName, nowFunctionStack->CurOffset);
			break;
		}
		case IR_SUB:
		{
			Operand result = ircode->inform.binOp.result;
            Operand op1 = ircode->inform.binOp.op1;
            Operand op2 = ircode->inform.binOp.op2;
            int Resindex = GetRegNum(result);
            int op1index = GetRegNum(op1);
            int op2index = GetRegNum(op2);
            fprintf(file, "\tsub %s, %s, %s\n", Regs[Resindex]->RegName, Regs[op1index]->RegName, Regs[op2index]->RegName);
            //将x关联到的变量值溢出到栈上并标记偏移量
			nowFunctionStack->CurOffset -= 4;
			Regs[Resindex]->var->VarOffset = nowFunctionStack->CurOffset;
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[Resindex]->RegName, nowFunctionStack->CurOffset);
			break;
		}
		case IR_MUL:
		{
			Operand result = ircode->inform.binOp.result;
            Operand op1 = ircode->inform.binOp.op1;
            Operand op2 = ircode->inform.binOp.op2;
            int Resindex = GetRegNum(result);
            int op1index = GetRegNum(op1);
            int op2index = GetRegNum(op2);
            fprintf(file, "\tmul %s, %s, %s\n", Regs[Resindex]->RegName, Regs[op1index]->RegName, Regs[op2index]->RegName);
			//将x关联到的变量值溢出到栈上并标记偏移量
			nowFunctionStack->CurOffset -= 4;
			Regs[Resindex]->var->VarOffset = nowFunctionStack->CurOffset;
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[Resindex]->RegName, nowFunctionStack->CurOffset);
            break;
		}
		case IR_DIV:
		{
			Operand result = ircode->inform.binOp.result;
            Operand op1 = ircode->inform.binOp.op1;
            Operand op2 = ircode->inform.binOp.op2;
            int Resindex = GetRegNum(result);
            int op1index = GetRegNum(op1);
            int op2index = GetRegNum(op2);
            fprintf(file, "\tdiv %s, %s\n", Regs[op1index]->RegName, Regs[op2index]->RegName);
			fprintf(file, "\tmflo %s\n", Regs[Resindex]->RegName);
			//将x关联到的变量值溢出到栈上并标记偏移量
			nowFunctionStack->CurOffset -= 4;
			Regs[Resindex]->var->VarOffset = nowFunctionStack->CurOffset;
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[Resindex]->RegName, nowFunctionStack->CurOffset);
            break;

		}
		case IR_GET_ADDRVAL:
		{
			Operand op1 = ircode->inform.binOp.op1;
            Operand op2 = ircode->inform.binOp.op2;
			int op1index = GetRegNum(op1);
            int op2index = GetRegNum(op2);
			fprintf(file, "\tlw %s, 0(%s) \n", Regs[op1index]->RegName, Regs[op2index]->RegName);
			//将x关联到的变量值溢出到栈上并标记偏移量
			nowFunctionStack->CurOffset -= 4;
			Regs[op1index]->var->VarOffset = nowFunctionStack->CurOffset;
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[op1index]->RegName, nowFunctionStack->CurOffset);
			break;
		}
		case IR_GET_VAL:
		{
			Operand op1 = ircode->inform.binOp.op1;
            Operand op2 = ircode->inform.binOp.op2;
			int op1index = GetRegNum(op1);
            int op2index = GetRegNum(op2);
			fprintf(file, "\tsw %s, 0(%s) \n", Regs[op2index]->RegName, Regs[op1index]->RegName);
			//将x关联到的变量值溢出到栈上并标记偏移量
			nowFunctionStack->CurOffset -= 4;
			Regs[op1index]->var->VarOffset = nowFunctionStack->CurOffset;
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[op1index]->RegName, nowFunctionStack->CurOffset);
			break;
		}
		case IR_GOTO:
		{
			Operand Labelid = ircode->inform.labelID;
			fprintf(file, "\tj label%d\n", Labelid->inform.Label_Num);
			break;
		}
		case IR_CALL:
		{
			fprintf(file, "\tli $v1,%d\n",Arg_Num*4); // 实参占用的栈空间
			fprintf(file, "\tsubu $sp, $sp, 4\n"); 
			fprintf(file, "\tsw $v1, 0($sp)\n"); // 将实参占用栈空间保存在栈上
			Arg_Num = 0; // 调用前处理ARG空间
			fprintf(file,"\tsubu $sp, $sp, 4\n");
			fprintf(file,"\tsw $ra, 0($sp)\n"); // 保存$ra寄存器
			Operand ret = ircode->inform.call.ret;
			int retindex = GetRegNum(ret);
			fprintf(file, "\tjal %s\n", ircode->inform.call.funcName);
			fprintf(file, "\tmove %s, $v0\n", Regs[retindex]->RegName);
			//将x溢出到栈上;
			nowFunctionStack->CurOffset -= 4;
			Regs[retindex]->var->VarOffset = nowFunctionStack->CurOffset;
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[retindex]->RegName, nowFunctionStack->CurOffset);
			fprintf(file,"\tlw $ra, 0($sp)\n"); // 恢复$ra的值
			fprintf(file,"\taddi $sp, $sp, 4\n");

			fprintf(file, "\tlw $v1, 0($sp)\n");
			fprintf(file,"\taddi $sp, $sp, 4\n");
			break;
		}
		case IR_RETURN:
		{
			Operand retVal = ircode->inform.retVal;
			int retValIndex = GetRegNum(retVal);
			fprintf(file, "\tmove $v0, %s\n", Regs[retValIndex]->RegName);
			fprintf(file, "\tjr $ra\n");
			break;
		}
		case IR_IF_GOTO:
		{
			char*relop;
			if(equal_string(ircode->inform.if_goto.relop, "=="))
			{
				relop = "beq";
			}
			else if(equal_string(ircode->inform.if_goto.relop, "!="))
			{
				relop = "bne";
			}
			else if(equal_string(ircode->inform.if_goto.relop, ">"))
			{
				relop = "bgt";
			}
			else if(equal_string(ircode->inform.if_goto.relop, "<"))
			{
				relop = "blt";
			}
			else if(equal_string(ircode->inform.if_goto.relop, ">="))
			{
				relop = "bge";
			}
			else if(equal_string(ircode->inform.if_goto.relop, "<="))
			{
				relop = "ble";
			}
			Operand op1 = ircode->inform.if_goto.ifopleft;
			Operand op2 = ircode->inform.if_goto.ifopright;
			Operand labelID = ircode->inform.if_goto.gotoLabelID;
			int op1index = GetRegNum(op1);
			int op2index = GetRegNum(op2);
			fprintf(file, "\t%s %s, %s, label%d\n", relop, Regs[op1index]->RegName, Regs[op2index]->RegName, labelID->inform.Label_Num);
			break;
		}
		case IR_ARG:
		{
			VarStructure var = findVar(ircode->inform.arg);
			fprintf(file, "\tlw $s0, %d($fp)\n", var->VarOffset);
			fprintf(file, "\tsubu $sp, $sp, 4\n");
			fprintf(file, "\tsw $s0, 0($sp)\n");
			Arg_Num++;
			break;
		}
		case IR_DEC:{

		}
		case IR_READ:
		{
			fprintf(file, "\taddi $sp, $sp, -4\n");
			fprintf(file, "\tsw $ra, 0($sp)\n"); // 保存$ra寄存器内容
			fprintf(file, "\tjal read\n");
			int xIndex = GetRegNum(ircode->inform.read);
			fprintf(file, "\tmove %s, $v0\n",Regs[xIndex]->RegName);
			//将x关联到的变量值溢出到栈上并标记偏移量;
			fprintf(file, "\tlw $ra, 0($sp)\n");
			fprintf(file, "\taddi $sp, $sp, 4\n"); // 恢复$ra寄存器
			break;
		}
		case IR_WRITE:
		{
			fprintf(file,"\taddi $sp, $sp, -4\n");
			fprintf(file,"\tsw $ra, 0($sp)\n"); // 保存$ra寄存器内容
			Operand write = ircode->inform.write;
			int writeIndex = GetRegNum(write);
			if(write->kind == OP_VAR || write->kind ==OP_TEMP){
				fprintf(file,"\tmove $a0, %s\n", Regs[writeIndex]->RegName);
			}else if(write->kind == OP_ADDR || write->kind == OP_ARRAY){
				fprintf(file, "\tlw $a0, 0(%s)\n", GetVarName(write));
			}
			fprintf(file,"\tjal write\n"); // 跳转到write函数
			//将寄存器x关联的变量值溢出到栈中记录偏移量;
			nowFunctionStack->CurOffset -= 4;
			Regs[writeIndex]->var->VarOffset = nowFunctionStack->CurOffset;
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[writeIndex]->RegName, nowFunctionStack->CurOffset);
			fprintf(file,"\tlw $ra, 0($sp)\n");
			fprintf(file,"\taddi $sp, $sp, 4\n"); // 恢复$ra内容
			break;
		}
	}
}
