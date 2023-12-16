#ifndef _HASH_
#define _HASH_

#include <string.h>
#include <stdio.h>


#define DEBUG_FLAG 0
typedef struct Type_* Type;
typedef struct FieldList_* FieldList;
typedef struct Structure_* Structure;
typedef struct Function_* Function;
typedef struct HashNode_* HashNode;

HashNode gTable[1024];
HashNode sTable[1024];


typedef enum{
		BASIC,	//数
		ARRAY,	//数组
		STRUCTURE,	//结构体
		FUNCTION	//函数
	}TypeKind;
typedef enum{
		LEFT,
		RIGHT,
		BOTH
	}TypePos;
struct Type_
{
	//类型种类
	TypeKind kind;
	
	//类型信息
	union{
		int basic; // int = 1 , float = 0
		struct{
			Type type;
			int size;
		}array;// 数组类型信息包括元素类型与数组大小构成
		Structure structure;
		Function function;
	}inform;

	//符号出现位置
	TypePos possition;
};

struct FieldList_{
	char * name;	//域的名字
	Type type;	//域的类型
	FieldList next;// 下一个域
};

struct Structure_{
	char *name;	//域的名字
	FieldList next;	// 下一个域
};

struct Function_{
	char*name;	//名称
	int linenum;	//行号
	Type type;	//返回值类型
	int state;	//是否定义，0为声明，1为定义
	FieldList next;	// 下一个域
};

struct HashNode_{
	char * name;
	Type type;
	FieldList param;
	HashNode next;
};

void initHashTable();
unsigned int time33_hash(char*name);
int insert(char *name,Type type);
int find(char *name);
HashNode CreateNewNode(char *name, Type type);

#endif
