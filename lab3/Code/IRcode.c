#include "IRcode.h"
#include <stdio.h>
#include <stdlib.h>


void printCode(IRCode curNode){

}

IRCode CreateIRCode(IRCodeKind IRkind){
	IRCode newcode = (IRCode)malloc(sizeof IRCode_);
	newcode->kind = IRkind;
	return newcode;
}

CodeList CreateNewCodeList(IRCode code){
	CodeList newcodelist = (CodeList)malloc(sizeof(CodeList_));
    	newcodelist->ircoding = code;
	newcodelist->pre = NULL;
	newcodelist->next = NULL;
	return newcodelist;
}

Operand FindVar(char*name){
	//Operand newop = (Operand)malloc(sizeof Operand_);
	//newop->kind = OP_
	VarList p = VarHead;
	while(p != NULL){
		if(equal_string(name, p->VarName)){
			return p->Var;
		}
	}
	Operand newop = (Operand)malloc(sizeof(Operand_));
	newop->kind = OP_VAR;
	newop->inform.Var_Num = VarNum;
	VarNum++;
	VarList newlist = (VarList)malloc(sizeof(VarList_));
	strcpy(newlist->VarName, name);
	newlist->Var = newop;
	if(VarHead == NULL){
		VarHead = VarTail = newlist;
	}
	else{
		VarTail->next = newlist;
		VarTail = newlist;
	}
	return newop;
}

Operand CreateTemp(){
	Operand newop = (Operand)malloc(sizeof Operand_);
	newop->kind = OP_TEMP;
	newop->Temp_Num = TempNum;
	TempNum++;
	return newop;
}

Operand CreateLabel(){
	Operand newop = (Operand)malloc(sizeof Operand_);
	newop->kind = OP_LABEL;
	newop->Label_Num = LabelNum;
	LabelNum++;
	return newop;
}

CodeList CreateOpCodeList(Operand op, IRCodeKind IRkind){
	CodeList newcodelist = (CodeList)malloc(sizeof(CodeList_));
	IRCode code = CreateIRCode(IRkind);
	switch(IRkind){
		case IR_LABEL:
			code->labelID = op;
			break;
		case IR_GOTO:
			code->gotolabelID = op;
			break;
		case IR_RETURN:
			code->retVal = op;
			break;
		case IR_ARG:
			code->arg = op;
			break;
		case IR_READ:
			code->read = op;
			break;
		case IR_WRITE:
			code->write = op;
			break;
		case IR_PARAM:
			code->param = op;
			break;
		default:
			printf("Error in CreateOpCodeList!\n");
			return NULL;
	}
        newcodelist->ircoding = code;
        newcodelist->pre = NULL;
        newcodelist->next = NULL;
        return newcodelist;
}

Operand CreateConstant(int val){
	Operand newop = (Operand)malloc(sizeof Operand_);
	newop->kind = OP_CONSTANT;
	newop->inform.Value = val;
	return newop;
}

CodeList Merge_CodeList(CodeList Code1, CodeList Code2){
	if(Code1 == NULL){
		if(LAB3_DEBUG)	printf("Code1 is NULL\n");
		return Code2;
	}
	if(Code2 == NULL){
		if(LAB3_DEBUG)  printf("Code2 is NULL\n");
		return Code1;
	}
	if(LAB3_DEBUG){
		printCode(Code1->IRcoding);
		printCode(Code2->IRcoding);
	}
	CodeList curList = Code1;
	while(curList->next != NULL)	curList = curList->next;
	curList->next = Code2;
	Code2->pre = curList;
	return Code1;
}
void Add_Code(CodeList IrCode){
	if(LAB3_DEBUG){
		printCode(IrCode->IRcoding);
	}
	if(CodeHead == NULL){
		CodeHead = CodeTail = IrCode;
	}
	else{
		if(IrCode != NULL){
			CodeTail->next = IrCode;
			IrCode->pre = CodeTail;
			CodeTail = IrCode;
		}
	}
}

CodeList IRCode_start(struct Node*root){
	if(root == NULL)	return NULL;//判断AST是否为空
	if(LBA3_DEBUG)	printf("Program : ExtDefList\n")
	if(Use_This_Rule(root, 1, "Program")){
		CodeHead = CodeTail = NULL;
		VarHead = VarTail = NULL;
		VarNum = 1;
		LabelNum = 1;
		TempNum = 1;
		Add_Code(Translate_ExtDefList(root->firstChild));
		return CodeHead;
	}
	else
		return NULL;
}

CodeList Translate_ExtDefList(struct Node* node){
	if(LAB3_DEBUG){
                printf("Go in ExtDefList translate\n");
        }
	if(node == NULL)	return NULL;
	if(Use_This_Rule(node, 2, "ExtDef", "ExtDefList")){
		if(LAB3_DEBUG)	printf("ExtDefList : ExtDef ExtDefList \n")
		CodeList ExtDef = Translate_ExtDef(node->firstChild);
		return Merge_CodeList(ExtDef, Translate_ExtDefList(node->firstChild->bro));	
	}
	else{
		printf("Error!No this rule!\n");
		return NULL;
	}
}

CodeList Translate_ExtDef(struct Node* node);{
	if(LAB3_DEBUG){
                printf("Go in ExtDef translate\n");
        }
	if(node == NULL)	return NULL;
	if(Use_This_Rule(node, 3, "Specifier", "ExtDecList", "SEMI")){
		if(LAB3_DEBUG)	printf("ExtDef : Specifier ExtDecList SEMI\n");
		return NULL;	//不包含全局变量，结构体定义也已经处理
	}
	else if(Use_This_Rule(node, 2, "Specifier", "SEMI")){
		if(LAB3_DEBUG)  printf("ExtDef : Specifier SEMI\n");
		return NULL;	//检查是否为“；”
	}
	else if(Use_This_Rule(node, 3, "Specifier", "FunDec", "CompSt")){
		if(LAB3_DEBUG)  printf("ExtDef : Specifier FunDec CompSt\n");
		CodeList FunList = Translate_FunDec(node->firstChild->bro);
		CodeList CompSt = Translate_CompSt(node->firstChild->bro->bro);
		return Merge_CodeList(FunList, CompSt);
	}
	else{
                printf("Error!No this rule!\n");
		return NULL;
        }
}

CodeList Translate_FunDec(struct Node* node){
	if(LAB3_DEBUG){
                printf("Go in FunDec translate\n");
        }
	if(node == NULL)	return NULL;
	if(Use_This_Rule(node, 4, "ID", "LP", "VarList", "RP")){
		if(LAB3_DEBUG)	printf("FunDec : ID LP VarList RP\n");
		IRCode ircode = CreateIRCode(IR_FUNC);
		ircode->inform.funcName = node->firstChild->Valstr;
		CodeList FunDec = CreateNewCodeList(ircode);
		// 获取参数列表
		Type newFuncType = Type_get(node->firstChild);
		FieldList params = newFuncType->inform.function->next;
		while(params != NULL){
			// 构造函数参数列表判断参数类型
			if(params->type->kind == BASIC){
				
			}
			else if(params->type->kind == STRUCTURE){
				//处理结构体
				
			}
			else{
				printf("Error!No this rule!\n")
			}
		}
	}
	else if(Use_This_Rule(node, 3, "ID", "LP", "RP")){
		if(LAB3_DEBUG)  printf("FunDec : ID LP RP\n");
                IRCode ircode = CreateIRCode(IR_FUNC);
                ircode->inform.funcName = node->firstChild->Valstr;
                CodeList FunDec = CreateNewCodeList(ircode);
		return FunDec;
	}
	else{
                printf("Error!No this rule!\n");
                return NULL;
        }
}

CodeList Translate_CompSt(struct Node* node){
	if(LAB3_DEBUG){
                printf("Go in CompSt translate\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return NULL;
	CodeList DefList = NULL;
	CodeList StmtList = NULL;
	if(Use_This_Rule(node, 4, "LC", "DefList", "StmtList", "RC")){
                if(LAB3_DEBUG)  printf("CompSt := LC DefList StmtList RC\n");
                DefList = Translate_DefList(node->firstChild->bro);
		StmtList = Translate_StmtList(node->firstChild->bro->bro);
        }
	else if(Use_This_Rule(node, 3, "LC", "DefList", "RC")){
                if(LAB3_DEBUG)  printf("CompSt := LC DefList StmtList(=NULL) RC\n");
                DefList = Translate_DefList(node->firstChild->bro);
        }
	else if(Use_This_Rule(node, 3, "LC", "StmtList", "RC")){
                if(LAB3_DEBUG)  printf("CompSt := LC DefList(=NULL) StmtList RC\n");
                StmtList = Translate_StmtList(node->firstChild->bro);
        }
	else if(Use_This_Rule(node, 2, "LC", "RC")){
                if(LAB3_DEBUG)  printf("CompSt := LC DefList(=NULL) StmtList(=NULL) RC\n");
        }
	else{
		printf("Error!No This analyse!\n");
	}
	return Merge_CodeList(DefList, StmtList);
}

CodeList Translate_StmtList(struct Node* node){
	if(LAB3_DEBUG){
                printf("Go in StmtList translate\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return NULL;
	return Merge_CodeList(Translate_Stmt(node->firstChild), Translate_StmtList(node->firstChild->bro));
}

CodeList Translate_Stmt(struct Node* node){
	if(LAB3_DEBUG){
                printf("Go in Stmt translate\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return NULL;
	if(Use_This_Rule(node, 2, "Exp", "SEMI")){
		if(LAB3_DEBUG)	printf("Stmt := Exp SEMI\n");
		return Translate_Exp(node->firstChild, NULL);		
	}
	else if(Use_This_Rule(node, 1, "CompSt")){
		if(LAB3_DEBUG)  printf("Stmt := CompSt\n");
	 	return Translate_CompSt(node->firstChild);	
	}
	else if(Use_This_Rule(node, 3, "RETURN", "Exp", "SEMI")){
		if(LAB3_DEBUG)  printf("Stmt := RETURN Exp SEMI\n");
		Operand temp = CreateTemp();
		CodeList Exp = Translate_Exp(node->firstChild->bro, temp);
		CodeList RETURN = CreateOpCodeList(temp, IR_RETURN);
		return Merge_CodeList(Exp, RETURN);
	}
	else if(Use_This_Rule(node, 5, "IF", "LP", "Exp", "RP", "Stmt")){// true分支
		if(LAB3_DEBUG)	printf("Stmt := IF LP Exp RP Stmt\n");
		Operand newlabel1 = CreateLabel();
		Operand newlabel2 = CreateLabel();
		CodeList Cond = Translate_Cond(node->firsChild->bro->bro, newlabel1, newlabel2);
		CodeList Stmt = Translate_Stmt(node->firstChild->bro->bro->bro->bro);
		CodeList CondList = Merge_CodeList(Cond, CreateOpCodeList(newlabel1, IR_LABEL));
		CodeList StmtList = Merge_CodeList(Stmt, CreateOpCodeList(newlabel2, IR_LABEL));
		return Merge_CodeList(CondList, StmtList);
	}
	else if(Use_This_Rule(node, 7, "IF", "LP", "Exp", "RP", "Stmt", "ELSE", "Stmt")){
		if(LAB3_DEBUG)	printf("Stmt := IF LP Exp RP Stmt ELSE Stmt\n");
		Operand newlabel1 = CreateLabel();
                Operand newlabel2 = CreateLabel();
		Operand newlabel3 = CreateLabel();
                CodeList Cond = Translate_Cond(node->firsChild->bro->bro, newlabel1, newlabel2);
                CodeList Stmt1 = Translate_Stmt(node->firstChild->bro->bro->bro->bro);
		CodeList Stmt2 = Translate_Stmt(node->firstChild->bro->bro->bro->bro->bro->brp);
                CodeList GOTOLabel = CreateOpCodeList(newlabel3, IR_GOTO);
		CodeList CondList = Merge_CodeList(Cond, CreateOpCodeList(newlabel1, IR_LABEL));
                CodeList StmtList1 = Merge_CodeList(Stmt1, GOTOLabel);
		CodeList StmtList2 = Merge_CodeList(CreateOpCodeList(newlabel2, IR_LABEL), Stmt2);
		CodeList TrueList = Merge_CodeList(CondList, StmtList1);
		CodeList FalseList = Merge_CodeList(StmtList2, CreateOpCodeList(newlabel3, IR_GOTO));
		return Merge_CodeList(TrueList, FalseList);
	}
	else if(Use_This_Rule(node, 5, "WHILE", "LP", "Exp", "RP", "Stmt")){
		if(LAB3_DEBUG)	printf("Stmt := WHILE LP Exp RP Stmt\n");
		Operand newlabel1 = CreateLabel();
                Operand newlabel2 = CreateLabel();
                Operand newlabel3 = CreateLabel();
                CodeList Cond = Translate_Cond(node->firsChild->bro->bro, newlabel2, newlabel3);
		CodeList Stmt = Translate_Stmt(node->firstChild->bro->bro->bro->bro);
		CodeList CondList = Merge_CodeList(CreateOpCodeList(newlabel1, IR_LABEL), Cond);
		CodeList StmtList = Merge_CodeList(CreateOpCodeList(newlabel2, IR_LABEL), Stmt);
		CodeList WhileList = Merge_CodeList(CondList, StmtList);
		return Merge_CodeList(Merge_CodeList(WhileList, CreateOpCodeList(newlabel1, IR_GOTO)), CreateOpCodeList(newlabel3, IR_LABEL));
	}
	else{
                printf("Error!No This analyse!\n");
        	return NULL;
	}
}
CodeList Translate_Exp(struct Node* node, Operand value){
	if(LAB3_DEBUG){
                printf("Go in Exp translate\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return NULL;
	struct Node*Children = node->firstChild;
	if(equal_string(Children->nodeName, "ID")){
		if(Children->bro == NULL){
			// 处理标识符
			if(LAB3_DEBUG)	printf("Exp := ID\n");
			Operand operand = FindVar(Children->Valstr);	//查找标识符
			if(operand->kind == OP_ARR || operand->kind == OP_STRUCT){
				IRCode ircode = CreateIRCode(IR_GET_ADDR);
				ircode->inform.assign.left = value;
				ircode->inform.assign.right = operand;
				return CreateNewCodeList(ircode);
			}
			else{
				IRCode ircode = CreateIRCode(IR_ASSIGN);
				ircode->inform.assign.left = value;
				ircode->inform.assign.right = operand;
				return CreateNewCodeList(ircode);								
			}
		}
		else if(Use_This_Rule(node, 4, "ID", "LP", "Args", "RP")){
			if(LAB3_DEBUG)  printf("Exp := ID LP Args RP\n");
			Function nowfunc = Type_get(Children)->inform.function;
			FieldList params = nowfunc->next;
			// 获取函数参数列表并处理实参
			ArgList arglist = NULL;
			CodeList Args = Translate_Args(Children->bro->bro, arglist, params);
			// 是否是write函数
			if(equal_string(nowfunc->name, "write")){
				CodeList Writeargs = CreateOpCodeList(Args->arg, IR_WRITE);
				return Merge_CodeList(Args, Writeargs);
			}
			else{
				// 用户自定义函数
				CodeList params = NULL;
				while(arglist != NULL){
					params = Merge_CodeList(params, CreateOpCodeList(arglist->arg, IR_ARG));
					arglist = arglist->next;
				}
				IRCode CallCode = CreateIRCode(IR_CALL);
				CallCode->ret = value;
				CallCode->funcName = nowfunc->name;
				CodeList CallFunc = CreateNewCodeList(CallCode);
				return Merge_CodeList(Merge_CodeList(Args, params), CallFunc);
			}
		}
		else if(Use_This_Rule(node, 3, "ID", "LP", "RP")){
			if(LAB3_DEBUG)  printf("Exp := ID LP RP\n");
			Function nowfunc = Type_get(Children)->inform.function;
			if(equal_string(nowfunc->name, "read")){
				IRCode ircode = CreateIRCode(IR_READ);
				return CreateNewCodeList(ircode);
			}
			else{
				IRCode ircode = CreateIRCode(IR_CALL);
				ircode->inform.call.ret = value;
				ircode->inform.call.funcName = nowfunc->name;
				return CreateNewCodeList(ircode);
			}
		}
	}
	else if(Use_This_Rule(node, 3, "Exp", "ASSIGNOP", "Exp")){
		if(LAB3_DEBUG)	printf("Exp := Exp ASSIGNOP Exp\n");
		Operand Temp1 = CreateTemp();
                Operand Temp2 = CreateTemp();
                CodeList Exp1 = Translate_Exp(node->firstChild, Temp1);
                CodeList Exp2 = Translate_Exp(node->firstCHild->bro->bro, Temp2);
                CodeList Exp = Merge_CodeList(Exp1, Exp2);
		IRCode ir1 = CreateIRCode(IR_ASSIGN);
		ir1.inform.assign.left = Temp1;
		ir1.inform.assign.right = Temp2;
		IRCode ir2 = CreateIRCode(IR_ASSIGN);
                ir2.inform.assign.left = value;
                ir2.inform.assign.right = Temp1;
		CodeList code = Merge_CodeList(CreateNewCodeList(ir1),CreateNewCodeList(ir2));
		return Merge_CodeList(Exp, code);
	}
	else if(equal_string(Children->nodeName, "MINUS")){
		if(LAB3_DEBUG)	printf("Exp := MINUS Exp\n");
		Operand Temp = CreateTemp();
		CodeList Exp = Translate_Exp(Children->bro, Temp);
		IRCode minuscode = CreateIRCode(IR_SUB);
		minuscode->inform.binOp.result = value;
		minuscode->inform.binOp.op1 = CreateConstant(0);
		minuscode->inform.binOp.op2 = Temp;
		return Merge_CodeList(Exp, CreateNewCodeList(minuscode));
	}
	else if(Use_This_Rule(node, 3, "Exp", "AND", "Exp")||Use_This_Rule(node, 3, "Exp", "OR", "Exp")||Use_This_Rule(node, 3, "Exp", "RELOP", "Exp")||Use_This_Rule(node, 2, "NOT", "Exp")){
		if(LAB3_DEBUG)	printf("Exp := Exp AND/OR/RELOP Exp(OR NOT Exp)\n");
		Operand Label1 = CreateLabel();
		Operand Label2 = CreateLabel();
		IRCode truecode = CreateIRCode(IR_ASSIGN);
                truecode->inform.assign.left = value;     // 构建左值
                truecode->inform.assign.right = CreateConstant(1);       // 构建常量1
		IRCode falsecode = CreateIRCode(IR_ASSIGN);
                falsecode->inform.assign.left = value;     // 构建左值
                falsecode->inform.assign.right = CreateConstant(0);       // 构建常量0
		CodeList truelist = CreateNewCodeList(truecode);
		CodeList falselist = CreateNewCodeList(falsecode);
		CodeList Cond = Translate_Cond(node, Label1, Label2);
		CodeList labellist1 = CreateOpCodeList(Label1, IR_LABEL);
		CodeList labellist2 = CreateOpCodeList(Label2, IR_LABEL);
		CodeList list1 = Merge_CodeList(falselist, Cond);
		CodeList list2 = Merge_CodeList(labellist1, truelist);
		return Merge_CodeList(Merge_CodeList(list1, list2), labellist2);
	}
	else if(Use_This_Rule(node, 3, "Exp", "PLUS", "Exp")||Use_This_Rule(node, 3, "Exp", "MINUS", "Exp")||Use_This_Rule(node, 3, "Exp", "STAR", "Exp")||Use_This_Rule(node, 3, "Exp", "DIV", "Exp")){
                if(LAB3_DEBUG)  printf("Exp := Exp PLUS/MINUS/STAR/DIV Exp\n");
		Operand Temp1 = CreateTemp();
		Operand Temp2 = CreateTemp();
		CodeList Exp1 = Translate_Exp(node->firstChild, Temp1);
		CodeList Exp2 = Translate_Exp(node->firstCHild->bro->bro, Temp2);
		CodeList Exp = Merge_CodeList(Exp1, Exp2);
		switch(node->firstChild->bro->nodeName){
			case "PLUS":
				if(LAB3_DEBUG)  printf("Exp := Exp PLUS Exp\n");
				IRCode pluscode = CreateIRCode(IR_ADD);
				pluscode->inform.binOp.result = value;
				pluscode->inform.binOp.op1 = Temp1;
				pluscode->inform.binOp.op2 = Temp2;
				CodeList plusList = CreateNewCodeList(pluscode);
				return Merge_CodeList(Exp, plusList);
			case "MINUS":
				if(LAB3_DEBUG)  printf("Exp := Exp MINUS Exp\n");
                                IRCode minuscode = CreateIRCode(IR_SUB);
                                minuscode->inform.binOp.result = value;
                                minuscode->inform.binOp.op1 = Temp1;
                                minuscode->inform.binOp.op2 = Temp2;
                                CodeList minusList = CreateNewCodeList(minuscode);
                                return Merge_CodeList(Exp, minusList);
			case "STAR":
				if(LAB3_DEBUG)  printf("Exp := Exp STAR Exp\n");
                                IRCode starcode = CreateIRCode(IR_MUL);
                                starcode->inform.binOp.result = value;
                                starcode->inform.binOp.op1 = Temp1;
                                starcode->inform.binOp.op2 = Temp2;
                                CodeList starList = CreateNewCodeList(starcode);
                                return Merge_CodeList(Exp, starList);
			case "DIV":
				if(LAB3_DEBUG)  printf("Exp := Exp DIV Exp\n");
                                IRCode divcode = CreateIRCode(IR_DIV);
                                divcode->inform.binOp.result = value;
                                divcode->inform.binOp.op1 = Temp1;
                                divcode->inform.binOp.op2 = Temp2;
                                CodeList divList = CreateNewCodeList(divcode);
                                return Merge_CodeList(Exp, divList);
			default:
				printf("Error!\n");
				return NULL;
		}
	}
	else if(Use_This_Rule(node, 4, "Exp", "LB", "Exp", "RB")){
		if(LAB3_DEBUG)  printf("Exp := Exp LB Exp RB\n");
		
	}
	else if(Use_This_Rule(node, 3, "Exp", "DOT", "ID")){
		if(LAB3_DEBUG)	printf("Exp := Exp DOT ID");
		Operand headaddr = CreateTemp();
		headaddr->kind = OP_ADDR;
		CodeList Exp = Translate_Exp(Children, headaddr);	// 获取结构体的地址
		IRCode ircode = CreateIRCode(IR_ADD);
		Operand temp = CreateTemp();
		temp->kind = OP_ADDR;
		ircode->inform.binOp.result = temp;
		ircode->inform.binOp.op1 = headaddr;
		// 获取结构体域的偏移量
		ircode->inform.binOp.op2 = GetSizeOfstruct(Exp(Children), Children->bro->bro->Valstr);
		CodeList newExp = Merge_CodeList(Exp, CreateNewCodeList(ircode));
		IRCode addrcode = CreateIRCode(IR_ASSIGN);
		addrcode->inform.assign.left = value;
		addrcode->inform.assign.right = temp;
		return Merge_CodeList(newExp, CreateNewCodeList(addrcode));
	}
	/*else if(Use_This_Rule(node, 2, "NOT", "Exp")){
                if(LAB3_DEBUG)  printf("Exp := NOT Exp\n");
       
	}*/
	else if(Use_This_Rule(node, 3, "LP", "Exp", "RP")){
                if(LAB3_DEBUG)  printf("Exp := LP Exp RP\n");
                return Translate_Exp(Children->bro);
        }
	else if(Use_This_Rule(node, 1, "INT")){
		if(LAB3_DEBUG)  printf("Exp := INT\n");
		int val = node->firsChild->Valint;
		IRCode ircode = CreateIRCode(IR_ASSIGN);
		ircode->inform.assign.left = value;	// 构建左值
		ircode->inform.assign.right = CreateConstant(val);	 // 构建常量
		return CreateNewCodeList(ircode);
	}
	else if(Use_This_Rule(node, 1, "FLOAT")){
                if(LAB3_DEBUG)  printf("Exp := FLOAT\n");
                return NULL;
        }
	else{
                printf("Error!No This analyse!\n");
                return NULL;
        }
}

CodeList Translate_Args(struct Node* node, ArgList arglist, FieldList params){
	if(LAB3_DEBUG){
                printf("Go in Args translate\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return NULL;
	Operand op1 = CreateTemp();
	CodeList Exp = Translate_Exp(node->firstChild, op1);
	if(params != NULL){
		if(params->type->kind == ARRAY || params->type->kind == STRUCTURE)
			op1->kind = OP_ADDR;
	}
	ArgList newargs = (ArgList)malloc(sizeof(struct ArgList_));
	newargs->arg = op1;
	newargs->next = arglist;
	arglist = newargs;
	if(Use_This_Rule(node, 3, "Exp", "COMMA", "Args")){
		if(LAB3_DEBUG)	printf("Args := Exp COMMA Args\n");
		if(params != NULL) params = params->next;
		CodeList args = Translate_Args(node->firstChild->bro->bro, arglist, params);
		return Merge_CodeList(Exp, args);
	}
	else if(Use_This_Rule(node, 1, "Exp")){
		if(LAB3_DEBUG)	printf("Args := Exp\n");
		return Exp;
	}
	else{
                printf("Error!No This analyse!\n");
                return NULL;
        }
}

CodeList Translate_Cond(struct Node* node, Operand TrueLabel, Operand FalseLabel){
	if(LAB3_DEBUG){
                printf("Go in Cond translate\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return NULL;
	if(equal_string(node->firstChild->nodeName, "NOT")){
		return Translate_Cond(node, FalseLabel, TrueLabel);
	}
	else if(Use_This_Rule(node, 3, "Exp", "RELOP", "Exp")){
		if(LAB3_DEBUG)  printf("Exp := Exp RELOP Exp\n");
		Operand Temp1 = CreateTemp();
		Operand Temp2 = CreateTemp();
		CodeList Exp1 = Translate_Exp(node->firstChild, Temp1);
		CodeList Exp2 = Translate_Exp(node->firstChild->bro->bro, Temp2);
		IRCode trueircode = CreateIRCode(IR_IF_GOTO);
		trueircode->inform.if_goto.ifopleft = Temp1;
		trueircode->inform.if_goto.ifopright = Temp2;
		strcpy(trueircode->inform.if_goto.relop, node->firstChild->bro->Valstr);
		trueircode->inform.if_goto.gotoLabelID = TrueLabel;
		CodeList truelist = CreateNewCodeList(trueircode);
		CodeList falselist = CreateOpCodeList(FalseLabel, IR_GOTO);
		CodeList Exp = Merge_CodeList(Exp1, Exp2);
		CodeList Cond = Merge_CodeList(truelist,falselist);
		return Merge_CodeList(Exp, Cond);
	}
	else if(Use_This_Rule(node, 3, "Exp", "AND", "Exp")){
		if(LAB3_DEBUG)  printf("Exp := Exp AND Exp\n");
		Operand TempLabel = CreateLabel();
		 // 短路运算
		CodeList list1 = Translate_Cond(node->firstChild, TempLabel, FalseLabel);
		CodeList list2 = Translate_Cond(node->firstChild->bro->bro, TrueLabel, FalseLabel);
		Codelist midlabel = CreateOpCodeList(TempLabel, IR_LABEL);
		return Merge_CodeList(Merge_CodeList(list1, midlabel), list2);
	}
	else if(Use_This_Rule(node, 3, "Exp", "OR", "Exp")){
		if(LAB3_DEBUG)  printf("Exp := Exp OR Exp\n");
		Operand TempLabel = CreateLabel();
                 // 短路运算
                CodeList list1 = Translate_Cond(node->firstChild, TrueLabel, TempLabel);
                CodeList list2 = Translate_Cond(node->firstChild->bro->bro, TrueLabel, FalseLabel);
                Codelist midlabel = CreateOpCodeList(TempLabel, IR_LABEL);
                return Merge_CodeList(Merge_CodeList(list1, midlabel), list2);
	}
	else{
		if(LAB3_DEBUG)  printf("Other Exp Conditions\n");
		Operand op1 = CreateTemp();
		CodeList Exp = Translate_Exp(node, op1);
		IRCode trueir = CreateIRCode(IR_IF_GOTO);
		strcpy(trueir->inform.if_goto.relop, "!=");
		trueir->inform.if_goto.ifopleft = op1;
		trueir->inform.if_goto.ifopright = CreateConstant(0);
		trueir->inform.if_goto.gotoLabelID = TrueLabel;
		CodeList truelist = Merge_CodeList(Exp, CreateNewCodeList(trueir));
		CodeList falselist = CreateOpCodeList(FalseLabel. IR_GOTO);
		return Merge_CodeList(truelist, falselist);
	}
}

CodeList Translate_DefList(struct Node* node){
	if(LAB3_DEBUG){
                printf("Go in DefList translate\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return NULL;
	if(Use_This_Rule(node, 2, "Def", "DefList")){
		if(LAB3_DEBUG)  printf("DefList := Def DefList\n");
		return Merge_CodeList(Translate_Def(node->firstChild), Translate_DefList(node->firstChild->bro));
	}
	else{
		printf("Error!No This analyse!\n");
		return NULL;
	}
}

CodeList Translate_Def(struct Node* node){
	if(LAB3_DEBUG){
                printf("Go in Def translate\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return NULL;
	if(Use_This_Rule(node, 3, "Specifier", "DecList", "SEMI")){
		if(LAB3_DEBUG)	printf("Def := Specifier DecList SEMI\n");
		return Translate_DecList(node->firstChild->bro);
	}
	else{
                printf("Error!No This analyse!\n");
                return NULL;
        }
}

CodeList Translate_DecList(struct Node*node){
	if(LAB3_DEBUG){
                printf("Go in DecList translate\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return NULL;
	if(Use_This_Rule(node, 1, "Dec")){
		if(LAB3_DEBUG)	printf("DecList := Dec\n");
		return Translate_Dec(node->firstChild);
	}
	else if(Use_This_Rule(node, 3, "Dec", "COMMA", "DecList")){
		if(LAB3_DEBUG)  printf("DecList := Dec COMMA DecList\n");
		return Merge_CodeList(Translate_Dec(node->firstChild), Translate_DecList(node->firstChild->bro->bro));
	}
	else{
                printf("Error!No This analyse!\n");
                return NULL;
        }
}

CodeList Translate_Dec(struct Node*node){
	if(LAB3_DEBUG){
                printf("Go in Dec translate\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return NULL;
	if(Use_This_Rule(node, 1, "VarDec")){
		if(LAB3_DEBUG)  printf("Dec := VarDec\n");
		return NULL;
	}
	else if(Use_This_Rule(node, 3 , "VarDec", "ASSIGNOP", "Exp")){
		if(LAB3_DEBUG)  printf("Dec := VarDec ASSIGNOP Exp\n");
		Operand VarDec = Translate_VarDec(node->firstChild);
		Operand Temp = CreateTemp();
		CodeList Exp = Translate_Exp(node->firstChild->bro->bro, Temp);
		IRCode ircode = CreateIRCode(IR_ASSIGN);
		ircode->inform.assign.left = VarDec;
		ircode->inform.assign.right = Temp;
		return Merge_CodeList(Exp, CreateNewCodeList(ircode));
	}
	else{
                printf("Error!No This analyse!\n");
                return NULL;
        }
}

Operand Translate_VarDec(struct Node*node){
	if(LAB3_DEBUG){
                printf("Go in Dec translate\n");
        }
        //判断节点是否为空
        if(node == NULL)
                return NULL;
	if(Use_This_Rule(node, 1, "ID")){
		if(LAB3_DEBUG)	printf("VarDec := ID\n");
		Operand op = FindVar(node->firstChild->Valstr);
		return op;
	}
	else if(Use_This_Rule(node, 4, "VarDec", "LB", "INT", "RB")){
		if(LAB3_DEBUG)	printf("VarDec := VarDec LB INT RB\n");
		Type array;
		struct Node* curNode = node;
		while(!equal_string(curNode->firstChild->nodeName, "ID")){
			curNode = curNode->firstChild;
		}
		Operand op = FindVar(curNode->firsChild->Valstr);
		array = Type_get(curNode->firstChild);
		op->type = array;
		return op;
	}
	else{
                printf("Error!No This analyse!\n");
                return NULL;
        }
}
