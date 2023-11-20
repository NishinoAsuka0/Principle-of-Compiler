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
	IR_LABEL,
	IR_FUNCTION.
	IR_ASSIGN,
	IR_ADD,
	IR_SUB,
	IR_MUL,
	IR_DIV,
	IR_GET_ADDR,
	IR_GET_ADDRVAL,
	IR_GET_VAL,
	IR_GOTO,
	IR_IF_GOTO,
	IR_RETURN,
	IR_PARAM,
	IR_READ,
	IR_WRITE,
	IR_CALL,
	IR_DEC,
	IR_ARG	
}IRCodeKind

typedef enum{
	OP_VAR,	// 变量
	OP_CONSTANT,	// 常量
	OP_ADDR,	// 地址（&var）
	OP_LABEL,	// 标签
	OP_ARRAY,	// 数组
	OP_STRUCTURE,	// 结构体
	OP_TEMP	// 临时变量（t1）
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
        	struct { Operand ifopleft; char*relop; Operand ifopright; Operand gotoLabelID; } if_goto;  // IF_GOTO
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
IRCode CreateIRCode(IRCodeKind IRkind);
Operand GetSizeOfstruct(Type structType, char*name);
Operand FindVar(char*name);
Operand CreateConstant(int val);
Operand CreateTemp();
Operand CreateLabel();
CodeList CreateOpCodeList(Operand op, IRCodeKind IRkind);
CodeList CreateNewCodeList(IRCode code);
CodeList IRcode_start(struct Node* root);
CodeList Translate_ExtDefList(struct Node* node);
CodeList Translate_ExtDef(struct Node* node);
CodeList Translate_FunDec(struct Node* node);
CodeList Translate_CompSt(struct Node* node);
CodeList Translate_DefList(struct Node* node);
CodeList Translate_Def(struct Node* node);
CodeList Translate_DecList(struct Node*node);
CodeList Translate_Dec(struct Node*node);
Operand Translate_VarDec(struct Node*node);
CodeList Translate_StmtList(struct Node* node);
CodeList Translate_Stmt(struct Node* node);
CodeList Translate_Exp(struct Node* node, Operand value);
CodeList Translate_Args(struct Node* node, ArgList arglist);
CodeList Translate_Cond(struct Node* node, Operand TrueLabel, Operand FalseLabel);
#endif
