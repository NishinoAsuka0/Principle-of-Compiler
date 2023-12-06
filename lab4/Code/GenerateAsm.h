#ifndef	GENERATE_ASM
#define GENERATE_ASM
#include <stdio.h>
#include "IRcode.h"

#define LAB4_DEBUG 0

typedef _VarStructure* VarStructure;
typedef _Register* Register;

struct _VarStructure{
	char * VarName;	//变量名
	Register Reg;	//变量存放的寄存器
	int VarOffset;	//变量在内存中的存储位置
	VarStructure next;	//变量链表
}


struct _Register{
	char * RegName;
	VarStructure var;
}


#endif
