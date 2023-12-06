#include<stdio.h>
#include<stdlib.h>
#include "GenerateAsm.h"
#include<string.h>

Register Regs[32];
VarStructure AsmVarList = NULL;


void generate_asm(CodeList curcode,FILE* file){
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
		Register newreg = (Register)malloc(sizeof(struct _Register));
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
		else if()
		newreg->var = NULL;
		Regs[i] = newreg; 
	}
}
