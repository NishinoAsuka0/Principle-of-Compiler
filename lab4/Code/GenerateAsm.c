#include<stdio.h>
#include<stdlib.h>
#include "GenerateAsm.h"
#include<string.h>

Register Regs[32];
VarStructure AsmVarList = NULL;
FILE*file = NULL;
int Arg_Num = 0;
//int Param_Num = 0;
//int Last_clearReg = 8;
int CurOffset;

void Lab4_Debug_Print(CodeList listhead){
	CodeList nowList = listhead;
	while(nowList != NULL){
		//printf("start\n");
		IRCode nowNode = nowList->IRcoding;
		//printf("start 2 \n");
		switch(nowNode->kind){
			case IR_LABEL:
			{
				if(LAB4_DEBUG)	printf("LABEL label%d :\n", nowNode->inform.labelID->inform.Label_Num);
				//fprintf(file, "LABEL label%d :\n", nowNode->inform.labelID->inform.Label_Num);
				break;
			}
			case IR_FUNCTION:
			{
				if(LAB4_DEBUG)	printf("FUNCTION %s :\n", nowNode->inform.funcName);
				//fprintf(file, "FUNCTION %s :\n", nowNode->inform.funcName);
				break;
			}
			case IR_ASSIGN:
			{
				Operand left = nowNode->inform.assign.left;
				Operand right = nowNode->inform.assign.right;
				if(LAB4_DEBUG)	printf("%s := %s \n", GetVarString(left), GetVarString(right));
				//fprintf(file, "%s := %s \n", GetVarString(left), GetVarString(right));
				break;
			}
			case IR_ADD:
			{
				Operand res = nowNode->inform.binOp.result;
				Operand left = nowNode->inform.binOp.op1;
                Operand right = nowNode->inform.binOp.op2;
				if(LAB4_DEBUG)	printf("%s := %s + %s \n", GetVarString(res), GetVarString(left), GetVarString(right));
				//fprintf(file, "%s := %s + %s \n", GetVarString(res), GetVarString(left), GetVarString(right));
				break;
			}
			case IR_SUB:
			{
                Operand res = nowNode->inform.binOp.result;
                Operand left = nowNode->inform.binOp.op1;
                Operand right = nowNode->inform.binOp.op2;
				if(LAB4_DEBUG)	printf("%s := %s - %s \n", GetVarString(res), GetVarString(left), GetVarString(right));
                //fprintf(file, "%s := %s - %s \n", GetVarString(res), GetVarString(left), GetVarString(right));
                break;
			}
			case IR_MUL:
			{
                Operand res = nowNode->inform.binOp.result;
                Operand left = nowNode->inform.binOp.op1;
                Operand right = nowNode->inform.binOp.op2;
				if(LAB4_DEBUG)	printf("%s := %s * %s \n", GetVarString(res), GetVarString(left), GetVarString(right));
                //fprintf(file, "%s := %s * %s \n", GetVarString(res), GetVarString(left), GetVarString(right));
                break;
			}
			case IR_DIV:
			{
            	Operand res = nowNode->inform.binOp.result;
                Operand left = nowNode->inform.binOp.op1;
                Operand right = nowNode->inform.binOp.op2;
                if(LAB4_DEBUG)	printf("%s := %s / %s \n", GetVarString(res), GetVarString(left), GetVarString(right));
				//fprintf(file, "%s := %s / %s \n", GetVarString(res), GetVarString(left), GetVarString(right));
                break;
			}
			case IR_GET_ADDR:
			{
				Operand left = nowNode->inform.assign.left;
                Operand right = nowNode->inform.assign.right;
				if(LAB4_DEBUG)	printf("%s := &%s \n", GetVarString(left), GetVarString(right));
                //fprintf(file, "%s := &%s \n", GetVarString(left), GetVarString(right));
                break;
			}
			case IR_GET_ADDRVAL:
			{
				Operand left = nowNode->inform.assign.left;
                Operand right = nowNode->inform.assign.right;
				if(LAB4_DEBUG)	printf("%s := *%s \n", GetVarString(left), GetVarString(right));
                //fprintf(file, "%s := *%s \n", GetVarString(left), GetVarString(right));
                break;
			}
			case IR_GET_VAL:
			{
				Operand left = nowNode->inform.assign.left;
                Operand right = nowNode->inform.assign.right;
				if(LAB4_DEBUG)	printf("*%s := %s \n", GetVarString(left), GetVarString(right));
                //fprintf(file, "*%s := %s \n", GetVarString(left), GetVarString(right));
                break;
			}
			/*case IR_VAL_ASSIGN:
                        {
                                Operand left = nowNode->inform.assign.left;
                                Operand right = nowNode->inform.assign.right;
                                fprintf(file, "*%s := *%s \n", GetVarString(left), GetVarString(right));
                                break;
                        }*/
			case IR_GOTO:
			{
				if(LAB4_DEBUG)	printf("GOTO label%d\n", nowNode->inform.gotoLabelID->inform.Label_Num);
				//fprintf(file, "GOTO label%d\n", nowNode->inform.gotoLabelID->inform.Label_Num);
				break;
			}
			case IR_IF_GOTO:
			{
				Operand left = nowNode->inform.if_goto.ifopleft;
				Operand right = nowNode->inform.if_goto.ifopright;
				if(LAB4_DEBUG)	printf("IF %s %s %s GOTO label%d\n", GetVarString(left), nowNode->inform.if_goto.relop, GetVarString(right), nowNode->inform.if_goto.gotoLabelID->inform.Label_Num);
				//fprintf(file, "IF %s %s %s GOTO label%d\n", GetVarString(left), nowNode->inform.if_goto.relop, GetVarString(right), nowNode->inform.if_goto.gotoLabelID->inform.Label_Num);
				break;
			}
			case IR_RETURN:
			{
				if(LAB4_DEBUG)	printf("RETURN %s\n", GetVarString(nowNode->inform.retVal));
				//fprintf(file, "RETURN %s\n", GetVarString(nowNode->inform.retVal));
				break;
			}
			case IR_PARAM:
			{
				if(LAB4_DEBUG)	printf("PARAM %s\n", GetVarString(nowNode->inform.param));
				//fprintf(file, "PARAM %s\n", GetVarString(nowNode->inform.param));
				break;
			}
			case IR_READ:
			{
				if(LAB4_DEBUG)	printf("READ %s\n", GetVarString(nowNode->inform.read));
				//fprintf(file, "READ %s\n", GetVarString(nowNode->inform.read));
                break;
			}
			case IR_WRITE:
			{
				if(LAB4_DEBUG)	printf("WRITE %s\n", GetVarString(nowNode->inform.write));
				//fprintf(file, "WRITE %s\n", GetVarString(nowNode->inform.write));
                break;
			}
			case IR_ARG:
			{
				if(LAB4_DEBUG)	printf("ARG %s\n", GetVarString(nowNode->inform.arg));
				//fprintf(file, "ARG %s\n", GetVarString(nowNode->inform.arg));
                break;
			}
			case IR_CALL:
			{
				if(LAB4_DEBUG)	printf("%s := CALL %s \n", GetVarString(nowNode->inform.call.ret), nowNode->inform.call.funcName);
				//fprintf(file, "%s := CALL %s \n", GetVarString(nowNode->inform.call.ret), nowNode->inform.call.funcName);
				break;
			}
			case IR_DEC:
			{
				if(LAB4_DEBUG)	printf("DEC %s %d\n", GetVarString(nowNode->inform.dec.VarType), nowNode->inform.dec.size);
				//fprintf(file, "DEC %s %d\n", GetVarString(nowNode->inform.dec.VarType), nowNode->inform.dec.size);
				break;
			}
			default:
			{
				printf("ErrorLine!\n");
				break;
			}
		}
		//printf("a1\n");
		nowList = nowList->next;
		//printf("a2\n");
	}	
}
void Generate_Asm(CodeList curNode,FILE* Asmfile){
	if(LAB4_DEBUG)	Lab4_Debug_Print(curNode);
	//printf("kk\n");
	file = Asmfile;
	if(!file){
		printf("Error file!\n");
	}
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
			newreg->RegName = malloc(10);
			sprintf(newreg->RegName, "$v%d", i-2);	//表达式求值或函数结果 
		}
		else if(i >= 4 && i <= 7){
			newreg->RegName = malloc(10);
			sprintf(newreg->RegName, "$a%d", i-4);	//函数的首四个参数
		}
		else if(i >= 8 && i <= 15){
			//函数调用者负责保存
			newreg->RegName = malloc(10);
			sprintf(newreg->RegName, "$t%d", i-8);
		}
		else if(i >= 16 && i<=23){
			//函数负责保存和恢复
			newreg->RegName = malloc(10);
			sprintf(newreg->RegName, "$s%d", i-16);
		}
		else if(i >= 24 && i<=25){
			newreg->RegName = malloc(10);
			sprintf(newreg->RegName, "$t%d", i-24+8);	//函数调用者负责保存
		}
		else if(i >= 26 && i<=27){
			newreg->RegName = malloc(10);
			sprintf(newreg->RegName, "$k%d", i-26);	//中断处理保留
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
		Generate_IR_Asm(nowNode);
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
	//printf("k1\n");
	while(curNode != NULL){
		if(curNode->op->kind != op->kind){
			curNode = curNode->next; 
			continue;
		}
		switch (op->kind)
		{
		case OP_TEMP:
			if(curNode->op->inform.Temp_Num == op->inform.Temp_Num)
				return curNode;
			break;
		case OP_ARRAY:
		case OP_ADDR:
		case OP_VAR:
			//printf("k3\n");
			if(curNode->op->inform.Var_Num == op->inform.Var_Num)
				return curNode;
			break;
		default:
			break;
		}
		//printf("k2\n");
		curNode = curNode->next;
	}
	return NULL;
}

int GetRegNum(Operand op){
	int i;
	if(op->kind == OP_CONSTANT){
		VarStructure opVar = (VarStructure)malloc(sizeof(struct VarStructure_));
		for(i = 8; i<= 15 ; i++){
			if(Regs[i]->var == NULL){
				if(LAB4_DEBUG)	printf("Use the reg %s\n", Regs[i]->RegName);
				opVar->op = op;
				Regs[i]->var = opVar;
				fprintf(file, "\tli %s, %d\n", Regs[i]->RegName, op->inform.Value);
				return i;
			}
		}
		for(i = 24; i<= 25 ; i++){
			if(Regs[i]->var == NULL){
				if(LAB4_DEBUG)	printf("Use the reg %s\n", Regs[i]->RegName);
				opVar->op = op;
				Regs[i]->var = opVar;
				fprintf(file, "\tli %s, %d\n", Regs[i]->RegName, op->inform.Value);
				return i;
			}
		}
		/*Clear_Reg(Last_clearReg);
		i = Last_clearReg;
		if(Last_clearReg == 25)
			Last_clearReg = 8;
		else
			Last_clearReg++;
		return i;*/
		
	}
	else{
		//printf("a1\n");
		VarStructure opVar = findVar(op);
		//printf("a2\n");
		if(opVar != NULL){
			if(opVar->Reg != -1)
			{
				return opVar->Reg;
			}
			else{
				for(i = 8; i<= 15 ; i++){
					if(Regs[i]->var == NULL){
						if(LAB4_DEBUG)	printf("Use the reg %s\n", Regs[i]->RegName);
						opVar->Reg = i;
						//opVar->VarOffset = 1;
						Regs[i]->var = opVar;
						if(opVar->VarOffset < 0){
							fprintf(file, "\tlw %s, %d($fp)\n", Regs[opVar->Reg]->RegName, opVar->VarOffset);
						}
						return i;
					}
				}
				for(i = 24; i<= 25 ; i++){
					if(Regs[i]->var == NULL){
						if(LAB4_DEBUG)	printf("Use the reg %s\n", Regs[i]->RegName);
						opVar->Reg = i;
						//opVar->VarOffset = 1;
						Regs[i]->var = opVar;
						if(opVar->VarOffset < 0){
							fprintf(file, "\tlw %s, %d($fp)\n", Regs[opVar->Reg]->RegName, opVar->VarOffset);
						}
						return i;
					}
				}
				/*Clear_Reg(Last_clearReg);
				i = Last_clearReg;
				if(Last_clearReg == 25)
					Last_clearReg = 8;
				else
					Last_clearReg++;
				
				return i;*/
			}
		}
		else{
			opVar = (VarStructure)malloc(sizeof(struct VarStructure_));
			for(i = 8; i<= 15 ; i++){
				if(Regs[i]->var == NULL){
					if(LAB4_DEBUG)	printf("Use the reg %s\n", Regs[i]->RegName);
					opVar->op = op;
					opVar->Reg = i;
					opVar->VarOffset = 1;
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
					opVar->VarOffset = 1;
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
	if(Regs[index]->var != NULL){
		if(Regs[index]->var->op->kind != OP_CONSTANT && Regs[index]->var->VarOffset == 1){
			CurOffset -= 4;
			Regs[index]->var->VarOffset = CurOffset;
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[index]->RegName, Regs[index]->var->VarOffset);
		}
		Regs[index]->var->Reg = -1;
		Regs[index]->var = NULL;
	}
	return;
}

void Generate_IR_Asm(CodeList curNode){
	if(LAB4_DEBUG)	printf("Go in IR_Asm\n");
	if(curNode == NULL)	return;
	IRCode ircode = curNode->IRcoding;
	if(ircode == NULL)	return;
	switch(ircode->kind){
		case IR_LABEL:
			if(LAB4_DEBUG)	printf("LABEL label%d\n", ircode->inform.labelID->inform.Label_Num);
			fprintf(file, "label%d:\n", ircode->inform.labelID->inform.Label_Num);
			break;
		case IR_FUNCTION:
		{
			if(LAB4_DEBUG){
				printf("FUNCTION %s :\n", ircode->inform.funcName);				
			}
			fprintf(file, "%s:\n", ircode->inform.funcName);
			fprintf(file, "\tsubu $sp, $sp, 4\n");	
			fprintf(file, "\tsw $fp, 0($sp)\n");
			fprintf(file, "\tmove $fp, $sp\n");
			//申请一段较大的栈空间（可通过$fp加上一段偏移寻址），保存局部变量等;
			//StackPointer newFuncStack = (StackPointer)malloc(sizeof(struct StackPointer_));
			CurOffset = 0;
			fprintf(file, "\taddi $sp, $fp, -2048\n");
			//初始化堆栈偏移量，函数形参个数等;
			CodeList p = curNode->next;
			int nowoff = 12;
			while (p->IRcoding->kind == IR_PARAM)
			{
				Operand op = p->IRcoding->inform.param;
				int opIndex = GetRegNum(op);
				fprintf(file, "\tlw %s, %d($fp)\n", Regs[opIndex]->RegName, nowoff);
				CurOffset -= 4;
				Regs[opIndex]->var->VarOffset = CurOffset;
				fprintf(file, "\tsw %s, %d($fp)\n", Regs[opIndex]->RegName, CurOffset);
				Clear_Reg(opIndex);
				nowoff += 4;
				p = p->next;
			}
			break;
		}	
		case IR_ASSIGN:
		{
			Operand left = ircode->inform.assign.left;
			Operand right = ircode->inform.assign.right;
			if(LAB4_DEBUG)	printf("%s := %s \n", GetVarString(left), GetVarString(right));
			if(right->kind == OP_CONSTANT){
				int index = GetRegNum(left);
				if(LAB4_DEBUG)	printf("\tli %s, %d\n", Regs[index]->RegName, right->inform.Value);
				fprintf(file, "\tli %s, %d\n", Regs[index]->RegName, right->inform.Value);
				if(Regs[index]->var->VarOffset == 1){
					CurOffset -= 4;
					Regs[index]->var->VarOffset = CurOffset;
				}
				fprintf(file, "\tsw %s, %d($fp)\n", Regs[index]->RegName, Regs[index]->var->VarOffset);
				Clear_Reg(index);
				break;		
			}
			else{
				int leftindex = GetRegNum(left);
				int rightindex = GetRegNum(right);
				fprintf(file, "\tmove %s, %s\n", Regs[leftindex]->RegName, Regs[rightindex]->RegName);
				printf("a1\n");
				//将x关联到的变量值溢出到栈上并标记偏移量
				if(Regs[leftindex]->var->VarOffset == 1){
					printf("b1\n");
					CurOffset -= 4;
					printf("b2\n");
					Regs[leftindex]->var->VarOffset = CurOffset;
				}
				printf("a2\n");
				fprintf(file, "\tsw %s, %d($fp)\n", Regs[leftindex]->RegName, Regs[leftindex]->var->VarOffset);
				Clear_Reg(leftindex);
				printf("a3\n");
				Clear_Reg(rightindex);
				break;
			}
			break;
		}
		case IR_ADD:
		{
			Operand result = ircode->inform.binOp.result;
			Operand op1 = ircode->inform.binOp.op1;
			Operand op2 = ircode->inform.binOp.op2;
			if(LAB4_DEBUG)	printf("%s := %s + %s \n", GetVarString(result), GetVarString(op1), GetVarString(op2));
			int Resindex = GetRegNum(result);
			int op1index = GetRegNum(op1);
			int op2index = GetRegNum(op2);
			fprintf(file, "\tadd %s, %s, %s\n", Regs[Resindex]->RegName, Regs[op1index]->RegName, Regs[op2index]->RegName);
			//将x关联到的变量值溢出到栈上并标记偏移量
			if(Regs[Resindex]->var->VarOffset == 1){
				CurOffset -= 4;
				Regs[Resindex]->var->VarOffset = CurOffset;
			}
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[Resindex]->RegName, Regs[Resindex]->var->VarOffset);
			Clear_Reg(Resindex);
			Clear_Reg(op1index);
			Clear_Reg(op2index);
			break;
		}
		case IR_SUB:
		{
			Operand result = ircode->inform.binOp.result;
            Operand op1 = ircode->inform.binOp.op1;
            Operand op2 = ircode->inform.binOp.op2;
			if(LAB4_DEBUG)	printf("%s := %s - %s \n", GetVarString(result), GetVarString(op1), GetVarString(op2));
            int Resindex = GetRegNum(result);
            int op1index = GetRegNum(op1);
            int op2index = GetRegNum(op2);
            fprintf(file, "\tsub %s, %s, %s\n", Regs[Resindex]->RegName, Regs[op1index]->RegName, Regs[op2index]->RegName);
            //将x关联到的变量值溢出到栈上并标记偏移量
			if(Regs[Resindex]->var->VarOffset == 1){
				CurOffset -= 4;
				Regs[Resindex]->var->VarOffset = CurOffset;
			}
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[Resindex]->RegName, Regs[Resindex]->var->VarOffset);
			Clear_Reg(Resindex);
			Clear_Reg(op1index);
			Clear_Reg(op2index);
			break;
		}
		case IR_MUL:
		{
			Operand result = ircode->inform.binOp.result;
            Operand op1 = ircode->inform.binOp.op1;
            Operand op2 = ircode->inform.binOp.op2;
			if(LAB4_DEBUG)	printf("%s := %s * %s \n", GetVarString(result), GetVarString(op1), GetVarString(op2));
            int Resindex = GetRegNum(result);
            int op1index = GetRegNum(op1);
            int op2index = GetRegNum(op2);
            fprintf(file, "\tmul %s, %s, %s\n", Regs[Resindex]->RegName, Regs[op1index]->RegName, Regs[op2index]->RegName);
			//将x关联到的变量值溢出到栈上并标记偏移量
			if(Regs[Resindex]->var->VarOffset == 1){
				CurOffset -= 4;
				Regs[Resindex]->var->VarOffset = CurOffset;
			}
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[Resindex]->RegName, Regs[Resindex]->var->VarOffset);
			Clear_Reg(Resindex);
			Clear_Reg(op1index);
			Clear_Reg(op2index);
            break;
		}
		case IR_DIV:
		{
			Operand result = ircode->inform.binOp.result;
            Operand op1 = ircode->inform.binOp.op1;
            Operand op2 = ircode->inform.binOp.op2;
			if(LAB4_DEBUG)	printf("%s := %s / %s \n", GetVarString(result), GetVarString(op1), GetVarString(op2));
            int Resindex = GetRegNum(result);
            int op1index = GetRegNum(op1);
            int op2index = GetRegNum(op2);
            fprintf(file, "\tdiv %s, %s\n", Regs[op1index]->RegName, Regs[op2index]->RegName);
			fprintf(file, "\tmflo %s\n", Regs[Resindex]->RegName);
			//将x关联到的变量值溢出到栈上并标记偏移量
			if(Regs[Resindex]->var->VarOffset == 1){
				CurOffset -= 4;
				Regs[Resindex]->var->VarOffset = CurOffset;
			}
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[Resindex]->RegName, Regs[Resindex]->var->VarOffset);
			Clear_Reg(Resindex);
			Clear_Reg(op1index);
			Clear_Reg(op2index);
            break;

		}
		case IR_GET_ADDRVAL:
		{
			Operand op1 = ircode->inform.assign.left;
			Operand op2 = ircode->inform.assign.right;
			if(LAB4_DEBUG)	printf("%s := *%s \n", GetVarString(op1), GetVarString(op2));
			int op1index = GetRegNum(op1);
            int op2index = GetRegNum(op2);
			fprintf(file, "\tlw %s, 0(%s) \n", Regs[op1index]->RegName, Regs[op2index]->RegName);
			//将x关联到的变量值溢出到栈上并标记偏移量
			if(Regs[op1index]->var->VarOffset == 1){
				CurOffset -= 4;
				Regs[op1index]->var->VarOffset = CurOffset;
			}
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[op1index]->RegName, Regs[op1index]->var->VarOffset);
			Clear_Reg(op1index);
			Clear_Reg(op2index);
			break;
		}
		case IR_GET_VAL:
		{
			Operand op1 = ircode->inform.assign.left;
			Operand op2 = ircode->inform.assign.right;
			if(LAB4_DEBUG)	printf("*%s := %s \n", GetVarString(op1), GetVarString(op2));
			int op1index = GetRegNum(op1);
            int op2index = GetRegNum(op2);
			fprintf(file, "\tsw %s, 0(%s) \n", Regs[op2index]->RegName, Regs[op1index]->RegName);
			//将x关联到的变量值溢出到栈上并标记偏移量
			if(Regs[op1index]->var->VarOffset == 1){
				CurOffset -= 4;
				Regs[op1index]->var->VarOffset = CurOffset;
			}
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[op1index]->RegName, Regs[op1index]->var->VarOffset);
			Clear_Reg(op1index);
			Clear_Reg(op2index);
			break;
		}
		case IR_GET_ADDR:
		{
			Operand op1 = ircode->inform.assign.left;
			Operand op2 = ircode->inform.assign.right;
			if(LAB4_DEBUG)	printf("%s := &%s \n", GetVarString(op1), GetVarString(op2));
			int op1index = GetRegNum(op1);
            int op2index = GetRegNum(op2);
			if(Regs[op2index]->var->VarOffset == 1){//还没有存储在栈中
				CurOffset -= 4;
				Regs[op2index]->var->VarOffset = CurOffset;
				fprintf(file, "\tsw %s, %d($fp)\n", Regs[op2index]->RegName, CurOffset);
			}
			fprintf(file, "\taddi %s, $fp, %d \n", Regs[op1index]->RegName, Regs[op2index]->var->VarOffset);
			//将x关联到的变量值溢出到栈上并标记偏移量
			if(Regs[op1index]->var->VarOffset == 1){
				CurOffset -= 4;
				Regs[op1index]->var->VarOffset = CurOffset;
			}
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[op1index]->RegName, Regs[op1index]->var->VarOffset);
			Clear_Reg(op1index);
			Clear_Reg(op2index);
			break;
		}
		case IR_GOTO:
		{
			Operand Labelid = ircode->inform.gotoLabelID;
			if(LAB4_DEBUG)	printf("GOTO label%d\n", Labelid->inform.Label_Num);
			fprintf(file, "\tj label%d\n", Labelid->inform.Label_Num);
			break;
		}
		case IR_CALL:
		{
			if(LAB4_DEBUG)	printf("%s := CALL %s \n", GetVarString(ircode->inform.call.ret), ircode->inform.call.funcName);
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
			if(Regs[retindex]->var->VarOffset == 1){
				CurOffset -= 4;
				Regs[retindex]->var->VarOffset = CurOffset;
			}
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[retindex]->RegName, Regs[retindex]->var->VarOffset);
			Clear_Reg(retindex);
			fprintf(file,"\tlw $ra, 0($sp)\n"); // 恢复$ra的值
			fprintf(file,"\taddi $sp, $sp, 4\n");

			fprintf(file, "\tlw $v1, 0($sp)\n");
			fprintf(file, "\taddi $sp, $sp, 4\n");
			fprintf(file, "\tadd $sp, $sp, $v1\n");
			break;
		}
		case IR_RETURN:
		{
			Operand retVal = ircode->inform.retVal;
			if(LAB4_DEBUG)	printf("RETURN %s\n", GetVarString(retVal));
			int retValIndex = GetRegNum(retVal);
			fprintf(file, "\tmove $v0, %s\n", Regs[retValIndex]->RegName);
			fprintf(file, "\taddi $sp, $sp, 2048\n");
			fprintf(file, "\tlw $fp, 0($sp)\n");
			fprintf(file, "\taddi $sp, $sp, 4\n");
			fprintf(file, "\tjr $ra\n");
			Clear_Reg(retValIndex);
			//StackPointer p = nowFunctionStack;
			//nowFunctionStack = nowFunctionStack->next;
			//free(p);
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
			if(LAB4_DEBUG)	printf("IF %s %s %s GOTO label%d\n", GetVarString(op1), ircode->inform.if_goto.relop, GetVarString(op2), labelID->inform.Label_Num);
			int op1index = GetRegNum(op1);
			int op2index = GetRegNum(op2);
			fprintf(file, "\t%s %s, %s, label%d\n", relop, Regs[op1index]->RegName, Regs[op2index]->RegName, labelID->inform.Label_Num);
			Clear_Reg(op1index);
			Clear_Reg(op2index);
			break;
		}
		case IR_ARG:
		{
			if(LAB4_DEBUG)	printf("ARG %s\n", GetVarString(ircode->inform.arg));
			VarStructure var = findVar(ircode->inform.arg);
			fprintf(file, "\tlw $s0, %d($fp)\n", var->VarOffset);
			fprintf(file, "\tsubu $sp, $sp, 4\n");
			fprintf(file, "\tsw $s0, 0($sp)\n");
			Arg_Num++;
			break;
		}
		case IR_DEC:
		{
			Operand op = ircode->inform.dec.VarType;
			int size = ircode->inform.dec.size;
			if(LAB4_DEBUG)	printf("DEC %s %d\n", GetVarString(op), size);
			int opindex = GetRegNum(op);
			CurOffset -= size;
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[opindex]->RegName, CurOffset);
			Clear_Reg(opindex);
			break;
		}
		case IR_PARAM:
			if(LAB4_DEBUG)	printf("PARAM %s\n", GetVarString(ircode->inform.param));
			break;
		case IR_READ:
		{
			if(LAB4_DEBUG)	printf("READ %s\n", GetVarString(ircode->inform.read));
			fprintf(file, "\taddi $sp, $sp, -4\n");
			fprintf(file, "\tsw $ra, 0($sp)\n"); // 保存$ra寄存器内容
			fprintf(file, "\tjal read\n");
			int xIndex = GetRegNum(ircode->inform.read);
			fprintf(file, "\tmove %s, $v0\n",Regs[xIndex]->RegName);
			//将x关联到的变量值溢出到栈上并标记偏移量;
			if(Regs[xIndex]->var->VarOffset == 1){
				CurOffset -= 4;
				Regs[xIndex]->var->VarOffset = CurOffset;
			}
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[xIndex]->RegName, Regs[xIndex]->var->VarOffset);
			Clear_Reg(xIndex);
			fprintf(file, "\tlw $ra, 0($sp)\n");
			fprintf(file, "\taddi $sp, $sp, 4\n"); // 恢复$ra寄存器
			break;
		}
		case IR_WRITE:
		{
			fprintf(file,"\taddi $sp, $sp, -4\n");
			fprintf(file,"\tsw $ra, 0($sp)\n"); // 保存$ra寄存器内容
			Operand write = ircode->inform.write;
			if(LAB4_DEBUG)	printf("WRITE %s\n", GetVarString(write));
			int writeIndex = GetRegNum(write);
			if(write->kind == OP_VAR || write->kind ==OP_TEMP){
				fprintf(file,"\tmove $a0, %s\n", Regs[writeIndex]->RegName);
			}else if(write->kind == OP_ADDR || write->kind == OP_ARRAY){
				fprintf(file, "\tlw $a0, 0(%s)\n", GetVarName(write));
			}
			fprintf(file,"\tjal write\n"); // 跳转到write函数
			//将寄存器x关联的变量值溢出到栈中记录偏移量;
			if(Regs[writeIndex]->var->VarOffset == 1){
				CurOffset -= 4;
				Regs[writeIndex]->var->VarOffset = CurOffset;
			}
			fprintf(file, "\tsw %s, %d($fp)\n", Regs[writeIndex]->RegName, Regs[writeIndex]->var->VarOffset);
			Clear_Reg(writeIndex);
			fprintf(file,"\tlw $ra, 0($sp)\n");
			fprintf(file,"\taddi $sp, $sp, 4\n"); // 恢复$ra内容
			break;
		}
	}
}
