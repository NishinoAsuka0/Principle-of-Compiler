#ifndef IRCODE
#define IRCODE
#include "semantic.h"

typedef enum{
	LABEL,
	FUNCTION.
	ASSIGN,
	ADD,
	SUB,
	MUL,
	DIV,
	GOTO,
	IF_GOTO,
	RETURN,
	PARAM,
	READ,
	WRITE,
	CALL,
	DEC,
	ARG	
}IRCodeKind

typedef enum{
	VAR,	// 变量
	CONSTANT,	// 常量
	ADDR,	// 地址（&var）
	LABEL,	// 标签
	ARRAY,	// 数组
	STRUCTURE,	// 结构体
	TEMP	// 临时变量（t1）
}OperandTypeKind;

struct Operand_{
	OperandTypeKind kind;
	union{
		int Var_Num;	// 变量定义的序号
		int Label_Num;	// 标签序号
		int Value;	// 操作数的值
		int Temp_Num;	// 临时变量序号（唯一性）
	}inform;
	Type type;	// 计算数组、结构体占用size
	int param;	// 标识函数参数
}

struct IRCode_{
	IRCodeKind kind;
	union{
		int labelID;  // LABEL
        	char* funcName;  // FUNCTION
        	struct { Operand left; Operand right; } assign;  // ASSIGN
        	struct { Operand result; Operand op1; Operand op2; } binOp;  // ADD, SUB, MUL, DIV
        	int gotoLabelID;  // GOTO
        	struct { CondExp* cond; int gotoLabelID; } if_goto;  // IF_GOTO
        	Operand retVal;  // RETURN
        	struct { Variable var; int size; } dec;  // DEC
        	Operand arg;  // ARG
        	struct { Variable ret; char* funcName; } call;  // CALL
        	Variable param;  // PARAM
        	Operand rwOperand;  // READ/WRITE
	}inform;
}


#endif
