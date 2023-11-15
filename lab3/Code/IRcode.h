#ifndef IRCODE
#define IRCODE
#define LAB3_DEBUG 0
#include "semantic.h"


typedef struct Operand_* Operand;
typedef struct IRCode_* IRCode;
typedef struct CodeList_* CodeList;
typedef struct VarList_* VarList;
typedef struct ArgList_* ArgList;

CodeList CodeHead;
CodeList CodeTail;
VarList VarHead;
VarList VarTail;
int VarNum,LabelNum,TempNum;


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
		Operand labelID;  // LABEL
        	char* funcName;  // FUNCTION
        	struct { Operand left; Operand right; } assign;  // ASSIGN
        	struct { Operand result; Operand op1; Operand op2; } binOp;  // ADD, SUB, MUL, DIV
        	Operand gotoLabelID;  // GOTO
        	struct { Operand ifopleft; Operand ifopright; Operand gotoLabelID; } if_goto;  // IF_GOTO
        	Operand retVal;  // RETURN
        	struct { Operand VarType; Operand size; } dec;  // DEC
        	Operand arg;  // ARG
        	struct { Operand ret; char* funcName; } call;  // CALL
        	Operand param;  // PARAM
        	Operand read;  // READ
		Operand write; //WRITE
	}inform;
}

struct CodeList_{
	IRCode IRcoding;
	CodeList pre;
	CodeList next;//中间代码列表
}

struct ArgList_{
	Operand arg;
	ArgList next;
}

struct VarList_{
	char* VarName;
	Operand Var;
	VarList next;
}

void printCode(IRCode curNode);
CodeList Merge_CodeList(CodeList Code1, CodeList Code2);
void Add_Code(CodeList IrCode);
CodeList IRcode_start(struct Node* root);
CodeList Translate_ExtDefList(struct Node* node);
CodeList Translate_ExtDef(struct Node* node);
COdeList Translate_FunDec(struct Node* node);

#endif
