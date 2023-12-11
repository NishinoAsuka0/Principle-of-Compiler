#ifndef	GENERATE_ASM
#define GENERATE_ASM
#include <stdio.h>
#include "IRcode.h"

#define LAB4_DEBUG 0



typedef struct VarStructure_* VarStructure;
typedef struct Register_* Register;

struct VarStructure_{
	Operand op;	//变量名
	Register Reg;	//变量存放的寄存器
	int VarOffset;	//变量在内存中的存储位置
	VarStructure next;	//变量链表
};


struct Register_{
	char * RegName;
	VarStructure var;
};
void Generate_Asm(CodeList curNode, FILE* file);
void Generate_IR_Asm(IRCode ircode, FILE* file);

#endif
