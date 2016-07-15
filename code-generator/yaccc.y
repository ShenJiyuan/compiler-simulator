%{
#include "node.h"
#include <ctype.h>
#include <stdlib.h> 
#include <stdarg.h>

#define YYDEBUG 0
#define CODE_LEN 800
#define ID_NUMBER 200

NodeT * root;
NodeT * createInnerNode(char *d, int num,...);
IDT * stack;
FUNC * list;

int yylex(void);
int yyerror(char *s);
FILE * fout;
extern int yydebug;
int counter = 0;
int stack_p = 0;
int list_p = 0;
int scope = 0; //record scope
%}

%union {
    NodeT *Node;             	    /* node pointer */
};

%token <Node> SEMI COMMA ASSIGNOP DOT LC RC LP RP LB RB PD DV MD PL MI 
%token <Node> SL SR GT GE LT LE ET NE BA BX BO LA LO 
%token <Node> BREAK CONT ELSE FOR ID IF INT RETURN STRUCT TYPE
%token <Node> PLS BMS PDS DVS BAS BXS BOS SLS SRS LN PREI PRED BN

%type <Node> PROGRAM EXTDEFS EXTDEF EXTVARS SPEC STSPEC OPTTAG VAR FUNC PARAS PARA 
%type <Node> STMTBLOCK STMTS STMT ESTMT DEFS DEF DECS DEC INIT FEXP EXP ARRS ARGS 

%start PROGRAM

%right AS PLS BMS PDS DVS BAS BXS BOS SLS SRS
%left LO
%left LA
%left BO
%left BX
%left BA
%left ET NE
%left GT GE LT LE 
%left SL SR
%left PL MI
%left PD DV MD
%right LN PREI PRED BN
%left LP RP LB RB DOT

%%

PROGRAM		:EXTDEFS	{$$ = createInnerNode("PROGRAM", 1, $1);}
		;	
EXTDEFS 	:EXTDEF EXTDEFS		{$$ = createInnerNode("EXTDEFS", 2, $1, $2);}
		|	{$$ = createInnerNode("EXTDEFS", 0);}
		;
EXTDEF 		:SPEC EXTVARS SEMI	{$$ = createInnerNode("EXTDEF", 3, $1, $2, $3);}
		|SPEC FUNC STMTBLOCK	{$$ = createInnerNode("EXTDEF", 3, $1, $2, $3);}
		;
EXTVARS 	:DEC	{$$ = createInnerNode("EXTVARS", 1, $1);}
		|DEC COMMA EXTVARS	{$$ = createInnerNode("EXTVARS", 3, $1, $2, $3);}
		|	{$$ = createInnerNode("EXTVARS", 0);}
		;
SPEC 		:TYPE		{$$ = createInnerNode("SPEC", 1, $1);}
		|STSPEC		{$$ = createInnerNode("SPEC", 1, $1);}
		;
STSPEC		:STRUCT OPTTAG LC DEFS RC	{$$ = createInnerNode("STSPEC", 5, $1, $2, $3, $4, $5);}
		|STRUCT ID	{$$ = createInnerNode("STSPEC", 2, $1, $2);}
		;
OPTTAG 		:ID	{$$ = createInnerNode("OPTTAG", 1, $1);}
		|	{$$ = createInnerNode("OPTTAG", 0);}
		;
VAR 		:ID	{$$ = createInnerNode("VAR", 1, $1);}
		|VAR LB INT RB		{$$ = createInnerNode("VAR", 4, $1, $2, $3, $4);}
		;
FUNC 		:ID LP PARAS RP		{$$ = createInnerNode("FUNC", 4, $1, $2, $3, $4);}
		;
PARAS 		:PARA COMMA PARAS	{$$ = createInnerNode("PARAS", 3, $1, $2, $3);}
		|PARA		{$$ = createInnerNode("PARAS", 1, $1);}
		|	{$$ = createInnerNode("PARAS", 0);}	
		;
PARA 		:SPEC VAR	{$$ = createInnerNode("PARA", 2, $1, $2);}
		;
STMTBLOCK 	:LC DEFS STMTS RC	{$$ = createInnerNode("STMTBLOCK", 4, $1, $2, $3, $4);}
		;
STMTS		:STMT STMTS 	{$$ = createInnerNode("STMTS", 2, $1, $2);}
		|	{$$ = createInnerNode("STMTS", 0);}	
		;
STMT 		:EXP SEMI	{$$ = createInnerNode("STMT", 2, $1, $2);}
		|STMTBLOCK	{$$ = createInnerNode("STMT", 1, $1);}
		|RETURN EXP SEMI	{$$ = createInnerNode("STMT", 3, $1, $2, $3);}
		|IF LP EXP RP STMT ESTMT	{$$ = createInnerNode("STMT", 6, $1, $2, $3, $4, $5, $6);}
		|FOR LP FEXP SEMI FEXP SEMI FEXP RP STMT	{$$ = createInnerNode("STMT", 9, $1, $2, $3, $4, $5, $6, $7, $8, $9);}
		|CONT SEMI	{$$ = createInnerNode("STMT", 2, $1, $2);}
		|BREAK SEMI	{$$ = createInnerNode("STMT", 2, $1, $2);}
		;
ESTMT 		:ELSE STMT	{$$ = createInnerNode("ESTMT", 2, $1, $2);}
		|	{$$ = createInnerNode("ESTMT", 0);}
		;
DEFS   		:DEF DEFS	{$$ = createInnerNode("DEFS", 2, $1, $2);}
		|	{$$ = createInnerNode("DEFS", 0);}
		;
DEF 		:SPEC DECS SEMI		{$$ = createInnerNode("DEF", 3, $1, $2, $3);}
		;
DECS 		:DEC COMMA DECS		{$$ = createInnerNode("DECS", 3, $1, $2, $3);}
		|DEC	{$$ = createInnerNode("DECS", 1, $1);}
		;
DEC		:VAR	{$$ = createInnerNode("DEC", 1, $1);}
		|VAR ASSIGNOP INIT	{$$ = createInnerNode("DEC", 3, $1, $2, $3);}
		;
INIT 		:EXP	{$$ = createInnerNode("INIT", 1, $1);}
		|LC ARGS RC	{$$ = createInnerNode("INIT", 3, $1, $2, $3);}
		;
FEXP            :EXP    {$$ = createInnerNode("FEXP", 1, $1);}
                |       {$$ = createInnerNode("FEXP", 0);}
                ;
EXP 		:EXP ASSIGNOP EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP DOT EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP PD EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP DV EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP MD EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP PL EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP MI EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP SL EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP SR EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP GT EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP GE EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP LT EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP LE EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP ET EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP NE EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP BA EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP BX EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP BO EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP LA EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP LO EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP PLS EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP BMS EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP PDS EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP DVS EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP BAS EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP BXS EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP BOS EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP SLS EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|EXP SRS EXP	{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|LN EXP		{$$ = createInnerNode("EXP", 2, $1, $2);}
		|PREI EXP		{$$ = createInnerNode("EXP", 2, $1, $2);}
		|PRED EXP		{$$ = createInnerNode("EXP", 2, $1, $2);}
		|BN EXP		{$$ = createInnerNode("EXP", 2, $1, $2);}
		|MI EXP	%prec PREI	{$$ = createInnerNode("EXP", 2, $1, $2);}
		|LP EXP RP		{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|ID LP ARGS RP		{$$ = createInnerNode("EXP", 4, $1, $2, $3, $4);}
		|ID ARRS		{$$ = createInnerNode("EXP", 2, $1, $2);}
		|EXP DOT ID		{$$ = createInnerNode("EXP", 3, $1, $2, $3);}
		|INT			{$$ = createInnerNode("EXP", 1, $1);}
		;
ARRS		:LB EXP RB ARRS		{$$ = createInnerNode("ARRS", 4, $1, $2, $3, $4);}
		|	{$$ = createInnerNode("ARRS", 0);}
		;
ARGS 		:EXP COMMA ARGS		{$$ = createInnerNode("ARGS", 3, $1, $2, $3);}
		|EXP			{$$ = createInnerNode("ARGS", 1, $1);}
		;
		
%%
void updateAttr(NodeT* n, AttrT attr);
void push_stack(char* var_id, int space, int isPara, char * num);
void add_list(char* func_id, char* func_type);
int getID_space(char* id);
void pop_stack(int space);
char* getID_eliminatePara(char* id);
char* getVAR_ID(NodeT* n);
char* get_TMP();
char * getID_num(char* id);

void cwrite(NodeT * n);
void cread(NodeT * n);
void cPROGRAM(NodeT * n);
void cEXTDEFS(NodeT * n);
void cEXTDEF(NodeT * n);
void cEXTVARS(NodeT * n, char * t);
char * cSPEC(NodeT * n);
char * cSTSPEC(NodeT * n);
void cOPTTAG(NodeT * n);
char * cVAR(NodeT * n);
char * cFUNC(NodeT * n, char * t);
char * cPARAS(NodeT * n);
char * cPARA(NodeT * n, int mode);
void cSTMTBLOCK(NodeT * n);
void cSTMTS(NodeT * n);
void cSTMT(NodeT * n);
void cESTMT(NodeT * n);
void cDEFS(NodeT * n);
void cDEF(NodeT * n);
void cDECS(NodeT * n, char * t);
void cDEC(NodeT * n, char * t);
char * cINIT(NodeT * n);
char * cFEXP(NodeT * n);
char * cEXP(NodeT * n);
char * cARRS(NodeT * n);
char * cARGS(NodeT * n);


//int i;
//for (i=0;i<10;i++) funcList[i]=NULL;
/****************************************************************************************************************************************/
/****************************************************************************************************************************************/
/****************************************************************************************************************************************/
/****************************************************************************************************************************************/

void add_list(char * func_id, char* func_type) {
        list[list_p].name = strdup(func_id);
        list[list_p].ftype = strdup(func_type);
        list_p++;
        return;
}

//===============================================================================更新节点n及其下树部分所有节点的Attr
void updateAttr(NodeT * n, AttrT attr) {
	n->attr = attr;
	n = n->son;
	while (n!=NULL) {
		updateAttr(n, attr);
		n = n->sibling;
	}
	return;
}
//===============================================================================加一个stack号
void push_stack(char * var_id, int space, int isPara, char * num) {
	stack[stack_p].id = strdup(var_id);
	stack[stack_p].space = space;
	stack[stack_p].isPara = isPara;
	stack[stack_p].num = num;
	stack_p++;
	return;
}
//===============================================================================退同一个space中的所有stack号
void pop_stack(int space){
	while (stack[stack_p-1].space == space) {
		stack_p--;
	}
	return;
}
//================================================================================得到stack中id对应的space号
int getID_space(char* id) {
	int i;
	for (i = 0; i < stack_p; ++i) {
		if (strcmp(id, stack[i].id) == 0)
			return stack[i].space;
	}
	return 0;	
}
//================================================================================是stack中id对应的，并且是参数的，     返回id.addr
char* getID_eliminatePara(char* id){
	int i;
	for (i = 0; i < stack_p; ++i) {
		if ((strcmp(id, stack[i].id) == 0) && (stack[i].isPara == 1)){
			char* ret;
			ret = (char*)malloc(sizeof(char)*CODE_LEN);
			sprintf(ret, "%s.addr", id);
			return ret;
		}
	}
	return id;
}    
//================================================================================                                    返回%tmp_counter
char* get_TMP() {
	char* ret;
	ret = malloc(sizeof(char)*70);
	sprintf(ret, "%%tmp_%d", counter++);
	return ret;
}
//================================================================================得到stack中id对应的num号
char * getID_num(char* id) {
	int i;
	for (i = 0; i < stack_p; ++i) {
		if (strcmp(id, stack[i].id) == 0)
			return stack[i].num;
	}
	return "";
}

//================================================================================有counter和cARGS返回的reg，       4返回%callcounter...reg
void cwrite(NodeT * n){     //parameter is right
	//fprintf(fout, "cwrite!\n");
	
	char * reg;
	reg = cARGS(n->son->sibling->sibling);
	fprintf(fout, "%%call%d = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), %s)\n", counter, reg);
	counter++;
	
	return;
}
//================================================================================有counter和cARGS返回的reg，       3返回%callcounter...reg
void cread(NodeT * n){
	//fprintf(fout, "cread!\n");

	AttrT tmp_attr = {n->attr.space, 1};
	n->son->sibling->sibling->attr = tmp_attr;
	updateAttr(n->son->sibling->sibling, tmp_attr);   //dont  need?????
	//fprintf(fout, "%s\n", a);/////////////////
	char * reg;
	reg = cARGS(n->son->sibling->sibling);
	fprintf(fout, "%%call%d = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), %s)\n", counter, reg);
	counter++;
	
	return;
}

/****************************************************************************************************************************************/
/****************************************************************************************************************************************/
/****************************************************************************************************************************************/
/****************************************************************************************************************************************/

void cPROGRAM(NodeT * n){
	//fprintf(fout, "cPROGRAM!\n");
	//show in the front of the code
	fprintf(fout, "@.str = private unnamed_addr constant [3 x i8] c\"%%d\\00\", align 1\n");
	fprintf(fout, "@.str1 = private unnamed_addr constant [2 x i8] c\"\\0A\\00\", align 1\n");
	cEXTDEFS(n->son);
	fprintf(fout, "\ndeclare i32 @__isoc99_scanf #1 (i8*, ...)\n");	
	fprintf(fout, "declare i32 @printf #1 (i8*, ...)\n");
	return;
}
void cEXTDEFS(NodeT * n){
	//fprintf(fout, "cEXTDEFS!\n");
	if(n->son == NULL){   //null
		return;
	}
	else{              //EXTDEF EXTDEFS
		n = n->son;
		cEXTDEF(n);
		cEXTDEFS(n->sibling);	
	}
	return;
}
void cEXTDEF(NodeT * n){
	//fprintf(fout, "cEXTDEF!\n");
	
	//char * code;
	//char code[CODE_LEN] = "";
	char * t;

	n = n->son;
	t = cSPEC(n);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	n = n->sibling;
	if(strcmp(n->stri, "EXTVARS")==0){   //SPEC EXTVARS SEMI
		cEXTVARS(n, t);
	}
	else{   //SPEC FUNC STMTBLOCK
		//we need to change working space here
		AttrT tmp_attr = {n->attr.space+1};
		updateAttr(n, tmp_attr);
		updateAttr(n->sibling, tmp_attr);

                scope++;
		cFUNC(n, t);
		n = n->sibling;	
		//fprintf(fout, "%s\n",n->stri);/////	
		cSTMTBLOCK(n);
		fprintf(fout, "}\n");
                scope--;

		pop_stack(n->attr.space);//pop variables when quit the function		
	}
	return;

}
void cEXTVARS(NodeT * n, char * t){
	//fprintf(fout, "cEXTVARS!\n");
	
	if(n->son == NULL){
	
	}
	else{
		n = n->son;
		cDEC(n, t);		
		if(n->sibling == NULL){    //DEC, already handled before
					
		}
		else{		//DEC COMMA EXTVARS
			cEXTVARS(n->sibling->sibling, t);
		}
	
	}
	return;
}

char * cSPEC(NodeT * n){
	//fprintf(fout, "cSPEC!\n");
	//fprintf(fout, "%s\n",n->stri);/////
	n = n->son;
	//fprintf(fout, "%s\n",n->stri);//////
	if(strcmp(n->stri,"int")==0) 
                 return "i32";  //TYPE
	else return cSTSPEC(n);                  //STSPEC

}
char * cSTSPEC(NodeT * n){    
	//fprintf(fout, "cSTSPEC!\n");
	n =  n->son;
	
	
	n = n->sibling;
	if(strcmp(n->stri, "OPTTAGE")==0){  //STRUCT OPTTAG LC DEFS RC
		cOPTTAG(n);         
                n=n->sibling->sibling; //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		cDEFS(n);
		return "struct";
	}
	else{    //STRUCT ID

	return "struct";
	}
}
void cOPTTAG(NodeT * n){
	//fprintf(fout, "cOPTTAG!\n");
        return;
}

char * cVAR(NodeT * n){
	//fprintf(fout, "cVAR!\n");

	char *code;
	n = n->son;
	//fprintf(fout, "%s\n",n->stri);/////
	if(n->sibling == NULL){              //ID
		code = strdup(n->stri); 
                
                int index; int result1=0;                                                                                      //semantic2
                for (index=0;index<stack_p;index++) {
                        if (strcmp(n->stri,stack[index].id)==0) {
                              result1=1;break;
                        }
                }
                if (result1==1) printf("ERROR IN SEMANTIC CHECKING: Variable redeclared!\n");                                  //semantic2
		//fprintf(fout, "var: %s\n", code);	
                    
                int result2=0;                                                                                                 //semantic3
                if ((strcmp(n->stri,"int")==0) || (strcmp(n->stri,"struct")==0) || (strcmp(n->stri,"return")==0) || (strcmp(n->stri,"continue")==0) || (strcmp(n->stri,"break")==0) || (strcmp(n->stri,"if")==0) || (strcmp(n->stri,"else")==0) || (strcmp(n->stri,"for")==0)) result2=1;
                if (result2==1) printf("ERROR IN SEMENTIC CHECKING: Reserved word uses as identifier!\n");                     //semantic3
	}
	else{                //VAR LB INT RB
		code = cVAR(n);                          //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	}
	return code;	
}

char * cFUNC(NodeT * n, char * t){  //ID LP PARAS RP
	//fprintf(fout, "cFUNC!\n");
        int index; int result=0;                                                                                               //semantic2
        for (index=0;index<list_p;index++){
                if (strcmp(n->son->stri,list[index].name)==0) {
                       result=1;break;
                }
        }
        if (result==1) printf("ERROR IN SEMANTIC CHEXKING: Function redeclared!\n");                                           //semantic2

	char * func_name;
	char * paras;
	n = n->son;
        add_list(n->stri);
	func_name = strdup(n->stri);
	paras = cPARAS(n->sibling->sibling);
	fprintf(fout, "define %s @%s(%s", t, func_name, paras);
	return;
}

char * cPARAS(NodeT * n){
	//fprintf(fout, "cPARAS!\n");
	
	char * code;    
	code = (char*)malloc(sizeof(char)*CODE_LEN);	
	char init[CODE_LEN] = "";
	
	if(n->son == NULL){  //null
	
	}
	else { //PARA   or  PARA COMMA PARAS
		n = n->son;
		strcat(code, cPARA(n, 0));
		strcat(init, cPARA(n, 1));
		while(n->sibling != NULL){  //PARA COMMA PARAS
			n = n->sibling->sibling;
			if(n->son != NULL){
				n = n->son;
				strcat(code, ", ");
				strcat(code, cPARA(n, 0));
				strcat(init, cPARA(n, 1));	
			}
			else break;
		}
	}
	
	strcat(code, ") {\nentry:\n");//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	strcat(code, init);
	return code;
}
char * cPARA(NodeT * n, int mode){
	//fprintf(fout, "cPARA!\n");

	//SPEC VAR
	n = n->son;
	char* code;
	code = (char*)malloc(sizeof(char)*CODE_LEN);
	char * t = cSPEC(n);
	char * var =   cVAR(n->sibling);
	
	if(mode == 0){			// get parameter code
		sprintf( code, "%s %%%s", t, var);
	}
	else {						// init parameter code
		sprintf( code, "%%%s.addr = alloca i32, align 4\nstore i32 %%%s, i32* %%%s.addr, align 4\n", var, var, var);
		push_stack(var, n->attr.space, 1, 0);
	}
	return code;
}
void cSTMTBLOCK(NodeT * n){
	//fprintf(fout, "cSTMTBLOCK!\n");
	
	n = n->son->sibling;//LC DEFS STMTS RC
	cDEFS(n);	
	n = n->sibling;
	cSTMTS(n);
	return;
}


void cSTMTS(NodeT * n){
	//fprintf(fout, "cSTMTS!\n");
	//fprintf(fout, "%s\n", n->stri);//////
	if(n->son == NULL){   //null
		
	}
	else{          //STMT STMTS
		n = n->son;
		cSTMT(n);    
                if ((strcmp(n->stri,"break")==0) || (strcmp(n->stri,"continue")==0)) {           //semantic8
                       printf("ERROR IN SEMANTIC CHECKING: Break and continue can not used in IF!\n");  
                }
		cSTMTS(n->sibling);	
	}
	return;
}
void cSTMT(NodeT * n){
	//fprintf(fout, "cSTMT!\n");
	//fprintf(fout, "%s\n", n->stri);//////
	char *code;
	n = n->son;
	
	if(strcmp(n->stri, "EXP")==0){//EXP SEMI
		//fprintf(fout, "%s\n", n->stri);
		code = cEXP(n);
	}
	else if(strcmp(n->stri, "STMTBLOCK")==0){//STMTBLOCK
		cSTMTBLOCK(n);
	}
	else if(strcmp(n->stri, "return")==0){//RETURN EXP SEMI
		code = cEXP(n->sibling);
		//fprintf(fout, "111%s\n", n->sibling->stri);
		fprintf(fout, "ret i32 %s\n", code);
	}
	else if(strcmp(n->stri, "if")==0){//IF LP EXP RP STMT ESTMT
		int tag = counter;
		counter++;
		code = cEXP(n->sibling->sibling);
		//ignore the i32 type, assume all the types are i1
		fprintf(fout, "br i1 %s, label %%if.then%d, label %%if.else%d\n", code, tag, tag);
				
		fprintf(fout,  "if.then%d:\n", tag);
		cSTMT(n->sibling->sibling->sibling->sibling);
		fprintf(fout,  "br label %%if.end%d\n", tag);   
 
                if ((strcmp(n->sibling->sibling->sibling->sibling->stri,"break")==0) || (strcmp(n->sibling->sibling->sibling->sibling->stri,"continue")==0)) {           //semantic8
                       printf("ERROR IN SEMANTIC CHECKING: Break and continue can not used in IF!\n");  
                }

		fprintf(fout,  "if.else%d:\n", tag);
		cESTMT(n->sibling->sibling->sibling->sibling->sibling);
		fprintf(fout,  "br label %%if.end%d\n", tag);

		fprintf(fout,  "if.end%d:\n", tag);


	}
	else if(strcmp(n->stri, "for")==0){//FOR LP FEXP SEMI FEXP SEMI FEXP RP STMT
		int tag = counter;
		counter++;
		n = n->sibling->sibling;
		code = cFEXP(n);
		fprintf(fout, "br label %%for.cond%d\n", tag);
		
		fprintf(fout, "for.cond%d:\n", tag);
		//fprintf(fout,  "entry\n");
		n = n->sibling->sibling;
		code = cFEXP(n);
		char *t = get_TMP();
		if(strcmp(n->son->stri, "x")==0) {fprintf(fout, "%s = icmp ne i32 %s, 0\n", t, code);
		fprintf(fout, "br i1 %s, label %%for.body%d, label %%for.end%d\n", t, tag, tag);
		}
		else fprintf(fout, "br i1 %s, label %%for.body%d, label %%for.end%d\n", code, tag, tag);
		
		fprintf(fout, "for.body%d:\n", tag);
		cSTMT(n->sibling->sibling->sibling->sibling);
		fprintf(fout, "br label %%for.inc%d\n", tag);

		fprintf(fout,  "for.inc%d:\n", tag);
		code = cFEXP(n->sibling->sibling);
		fprintf(fout,  "br label %%for.cond%d\n", tag);

		fprintf(fout,  "for.end%d:\n", tag);
	}

	else if(strcmp(n->stri, "continue")==0){//CONT SEMI

	}
	else if(strcmp(n->stri, "break")==0){//BREAK SEMI

	}
	else{}
	

	return;
}

void cESTMT(NodeT * n){
	//fprintf(fout, "cESTMT\n");
	
	if(n->son == NULL){   //null
	}
	else {    //ELSE STMT
		cSTMT(n->son->sibling);    
                if ((strcmp(n->son->sibling->stri,"break")==0) || (strcmp(n->son->sibling->stri,"continue")==0)) {           //semantic8
                       printf("ERROR IN SEMANTIC CHECKING: Break and continue can not used in IF!\n");  
                }
	}
	return;
}
void cDEFS(NodeT * n){
	//fprintf(fout, "cDEFS!\n");
	if(n->son == NULL);  //null
	else{        //def defs
		cDEF(n->son);
		cDEFS(n->son->sibling);		
	}
	return;
}
void cDEF(NodeT * n){   //SPEC DECS SEMI
	//fprintf(fout, "cDEF!\n");
	char * code;
	code = (char*) malloc(sizeof(char)*CODE_LEN);
	//sprintf( code, "");
	char * t;
	
        counter++;
        int dig=counter;
        counter++;
        fprintf(fout, "%%%d = alloca i32, align 4\n", dig);
	n = n->son;
	t = cSPEC(n);
	n = n->sibling;
	cDECS(n,t);	
        fprintf(fout, "store i32 0, i32* %%%d\n", dig);
	return;
	
}
void cDECS(NodeT * n, char * t){
	//fprintf(fout, "cDECS!\n");
	n = n->son;
	cDEC(n, t);//!!!!!!!!!!!!!!!!
	if(n->sibling != NULL){    //DEC COMMA DECS
		cDECS(n->sibling->sibling, t);
	}
	return;     //DEC, already handled before
	 
}
void cDEC(NodeT * n, char * t){//declaration
	//fprintf(fout, "cDEC!\n");
	char code[CODE_LEN]="";
	char tmp[CODE_LEN]="";
	n = n->son;
	char * var;
	char * value;
	if(n->sibling == NULL){           //VAR,handled before
		if(n->son->sibling != NULL){   //array
	
			var = cVAR(n->son);			
			if (n->attr.space == 0) sprintf( code, "@%s = common global [%s x %s] zeroinitializer, align 4\n", var, n->son->sibling->sibling->stri, t);
			else sprintf( code, "%%%s = alloca [%s ], align 4\n", var, t);//not finished
			push_stack(var, n->attr.space, 0, n->son->sibling->sibling->stri);
		}
		else {	   //int
			
			var = cVAR(n);
			if (n->attr.space == 0) sprintf(code, "@%s = common global %s.%s 0, align 4\n", var, t , n->son->stri);
			else sprintf( code, "%%%s = alloca %s, align 4\n", var, t);
			push_stack(var, n->attr.space, 0, "0");
		}
				

	}
	else{                           //VAR ASSIGNOP INIT
		value = cINIT(n->sibling->sibling);
		//fprintf(fout, "enterq1111111111\n"); 		
		if(n->son->sibling != NULL) {   //array		
		
			var = cVAR(n->son);			
			if (n->attr.space == 0){
				sprintf( code, "@%s = global [%s x %s] [%s], align 4\n", var, n->son->sibling->sibling->stri, t, value);
				push_stack(var, n->attr.space, 0, n->son->sibling->sibling->stri);
			}
			//because the variables are separated, can't use cINIT			
			else {
				sprintf( code, "%%ans = alloca [2 x i32], align 4\n");
				strcat(code, "%arrayans.d0 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 0\n");	
				strcat(code, "store i32 0, i32* %arrayans.d0\n");
				strcat(code, "%arrayans.d1 = getelementptr inbounds i32* %arrayans.d0, i32 1\n");
				strcat(code, "store i32 1, i32* %arrayans.d1\n");
				push_stack(var, n->attr.space, 0, "2");
			}
		}
		else{//int
			//fprintf(fout, "enter\n");
			var = cVAR(n);
			if (n->attr.space == 0) sprintf( code, "@%s = global %s %s, align 4\n", var, t, value);
			else sprintf( code, "%%%s = alloca %s, align 4\nstore %s %s, %s* %%%s, align 4\n", var, t, t, value, t, var);	
			push_stack(var, n->attr.space, 0, "0");
		}		
	}
	 
	fprintf(fout,  "%s", code);
	return;
}


char * cINIT(NodeT * n){
	//fprintf(fout, "cINIT!\n");

	//fprintf(fout, "%s\n", n->stri);  //////////////////
	char * code;
	n = n->son;
	if(strcmp(n->stri, "EXP")==0){    //EXP
		code = cEXP(n);
	}
	else{     //LC ARGS RC 
		code = cARGS(n->sibling);////////////////////
	}
	
	return code;	
}


char * cFEXP(NodeT * n){
        char * code;
        code = malloc(sizeof(char)*CODE_LEN);
        
        if (n->son == NULL){  //null
        }
        else { //EXP
            code = cEXP(n);
        }
        return code;
}

// if EXP is a INT, return that INT
//else return the name of the register which store the EXP result
//         if EXP is left value, the register store a address
char * cEXP(NodeT * n){
	//fprintf(fout, "cEXP!\n");
	//if(n->sibling != NULL)fprintf(fout, "%s\n", n->sibling->stri);
	char * code;
	code = malloc(sizeof(char)*CODE_LEN);
	
	//if(n->son == NULL){     //null
		//fprintf(fout, "1\n");///////////////
	//}
        if(n->son->sibling == NULL){     //INT
		
		code = strdup(n->son->stri); 
		//fprintf(fout, "6\n");////////////////
	}
	else if(strcmp(n->son->stri, "EXP")==0){
		char *a;
		char *b;
		n = n->son;
		//fprintf(fout, "2\n");////////////////
		

		if(strcmp(n->sibling->stri, "=")==0){//EXP ASSIGNOP EXP
                        if (n->nType==1) printf("ERROR IN SEMANTIC CHECKING: Right value can not be assigned!\n");
			//fprintf(fout, "enter!!\n");//////////////
			n->attr.isLeft = 1;
			//fprintf(fout, "isleft = %d\n", n->attr.isLeft);
			//fprintf(fout, "%s\n", n->stri);/////////////
			a = cEXP(n);
			b = cEXP(n->sibling->sibling);
			code = get_TMP();
			fprintf(fout,  "store i32 %s, i32* %s, align 4\n", b, a);

		}
                /*else if(strcmp(n->sibling->stri, ".")==0){          //EXP DOT EXP                                                semantic7
                        a = cEXP(n);
                        b = cEXP(n->sibling->sibling);
                        if (strcmp(a,"int")==0) printf("ERROR IN SEMANTIC CHECKING: Operator '.' applied to integer variable!\n");
                }*/
		else if(strcmp(n->sibling->stri, "+")==0){          //EXP PL EXP
			a = cEXP(n);
			b = cEXP(n->sibling->sibling);
			code = get_TMP();
			fprintf(fout, "%s = add i32 %s, %s\n", code, a, b);	
		}
		else if(strcmp(n->sibling->stri, "-")==0){          //EXP MI EXP
			a = cEXP(n);
			b = cEXP(n->sibling->sibling);
			code = get_TMP();
			fprintf(fout, "%s = sub i32 %s, %s\n", code, a, b);	
		}
		else if(strcmp(n->sibling->stri, "*")==0){          //EXP PD EXP
			a = cEXP(n);
			b = cEXP(n->sibling->sibling);
			code = get_TMP();
			fprintf(fout,  "%s = mul i32 %s, %s\n", code, a, b);
		}
		else if(strcmp(n->sibling->stri, "==")==0){   //EXP ET EXP
			a = cEXP(n);
			b = cEXP(n->sibling->sibling);
			code = get_TMP();
			fprintf(fout, "%s = icmp eq i32 %s, %s\n", code, a, b);
		}
		else if(strcmp(n->sibling->stri, ">")==0){   //EXP GT EXP
			a = cEXP(n);
			b = cEXP(n->sibling->sibling);
			code = get_TMP();
			fprintf(fout,  "%s = icmp sgt i32 %s, %s\n", code, a, b);
		}
		else if(strcmp(n->sibling->stri, "<")==0){   //EXP LT EXP
			a = cEXP(n);
			b = cEXP(n->sibling->sibling);
			code = get_TMP();
			fprintf(fout, "%s = icmp slt i32 %s, %s\n", code, a, b);
		}
		else if(strcmp(n->sibling->stri, "%")==0){  //EXP MD EXP
			a = cEXP(n);
			b = cEXP(n->sibling->sibling);
			code = get_TMP();
			fprintf(fout,  "%s = srem i32 %s, %s\n", code, a, b);
		}
		else if(strcmp(n->sibling->stri, "&&")==0){   //EXP LA EXP
			a = cEXP(n);
			b = cEXP(n->sibling->sibling);
			code = get_TMP();
			fprintf(fout,  "%s = and i1 %s, %s\n", code, a, b);
		}
		else if(strcmp(n->sibling->stri, "&")==0){   //EXP BA EXP
			a = cEXP(n);
			b = cEXP(n->sibling->sibling);
			char * code2 = get_TMP();
			fprintf(fout,  "%s = and i32 %s, %s\n", code2, a, b);
			code = get_TMP();
			fprintf(fout,  "%s = icmp ne i32 %s, 0\n", code, code2);
		}
		else if(strcmp(n->sibling->stri, ">>=")==0){  //EXP SRS EXP
			a = cEXP(n);
			b = cEXP(n->sibling->sibling);
			code = get_TMP();
			fprintf(fout, "%s = lshr i32 %s, %s \n", code, a, b);
			
			AttrT attr = n->attr; //very important!  these steps are to insure return "%a" at the end of store
			attr.isLeft = 1;
			updateAttr(n, attr);
			a = cEXP(n);
			fprintf(fout,  "store i32 %s, i32* %s, align 4\n", code, a);
		}		
	}
	else if(strcmp(n->son->stri, "++")==0){  //PREI EXP
		//fprintf(fout, "3\n");////////////////
		n = n->son;
		char *a = cEXP(n->sibling);
		code = get_TMP();
		fprintf(fout,  "%s = add i32 %s, 1 \n", code, a);

		AttrT attr = n->attr; //very important!  these steps are to insure return "%a" at the end of store
		attr.isLeft = 1;
		updateAttr(n->sibling, attr);
		a = cEXP(n->sibling);
		fprintf(fout,  "store i32 %s, i32* %s, align 4\n", code, a);
	} 
	else if(strcmp(n->son->stri, "!")==0){  //LN EXP
		
		n = n->son;
		code = get_TMP();
		fprintf(fout,  "%s = icmp eq i32 %s, 0\n", code, cEXP(n->sibling));
		
	}   
	else if(strcmp(n->son->stri, "-")==0){  //MI EXP
		//fprintf(fout, "7\n");////////////////
		
		n = n->son;
		char *a = cEXP(n->sibling);
		code = get_TMP(n->sibling);
		fprintf(fout,  "%s = sub i32 0, %s\n", code, a);
	}  
	else if(strcmp(n->son->sibling->stri, "ARRS")==0){  //ID ARRS
		//fprintf(fout, "5\n");////////////////
		//fprintf(fout, "%s\n", n->son->sibling->stri);
		//fprintf(fout, "isleft = %d\n", n->attr.isLeft);	
                int index; int result=0;                                                                                       //semantic1
                for (index=0;index<stack_p;index++){
                      if (strcmp(n->son->stri,stack[index].id)==0) {
                              result=1;break;
                      }
                }	
                if (result==0) printf("ERROR IN SEMANTIC CHECKING: Not defined variable used!\n");                             //semantic1
                //code generation
		if(n->son->sibling == NULL){    //ID
			//fprintf(fout, "%s\n", n->stri);
			char c;
			if (getID_space(n->son->stri) == 0) c = '@';
			else c = '%';
			//fprintf(fout, "isleft = %d\n", n->attr.isLeft);/////////
			if (n->attr.isLeft == 0) {//if it is right value, then we should load the value into register
				code = get_TMP();
				fprintf(fout,  "%s = load i32* %c%s, align 4\n", code, c, getID_eliminatePara(n->son->stri));
			}
			else {//if it is left value, "%x" stands for the address				
				code = get_TMP();	
				sprintf( code, "%c%s", c, getID_eliminatePara(n->son->stri));
			}
		}
		else{   //ID ARRS
			
		 	code = get_TMP();
			char c;
			char * arrs;
			arrs = cARRS(n->son->sibling);
                        int prt;
                        if (n->son->sibling==NULL) prt=0;
                        else prt=1;
			if (getID_space(n->son->stri) == 0) c = '@';
			else c = '%';
			if (n->attr.isLeft == 0) {
                            if (prt){
				//char* reg = get_TMP();   ///???????
				fprintf(fout, "%%tmp_%d = getelementptr inbounds [%s x i32]* %c%s, i32 0, i32 %s\n", counter, getID_num(n->son->stri), c, getID_eliminatePara(n->son->stri), arrs);
				fprintf(fout, "%s = load i32* %s, align 4\n", code, getID_eliminatePara(n->son->stri));
				//n->attr.type = strdup("i32");//////
                            }
                            else fprintf(fout, "%s = load i32* %s, align 4\n", code, getID_eliminatePara(n->son->stri));
			}
			else {
                              if (prt){
				fprintf(fout, "%s = getelementptr inbounds [%s x i32]* %c%s, i32 0, i32 %s\n", code, getID_num(n->son->stri), c, getID_eliminatePara(n->son->stri), arrs);
				//n->attr.type = strdup("i32*");///////
                              }
                              else  fprintf(fout, "%s = load i32* %s, align 4\n", code, getID_eliminatePara(n->son->stri));
			}
		}
	}    
	else if(strcmp(n->son->sibling->sibling->stri, "ARGS")==0){//ID LP ARGS RP  
                //semantic checking for func                                                                                    semantic1
                int i;int j=0;
                for (i=0;i<list_p;i++) {
                        if (strcmp(n->son->stri,list[i].name)==0) {
                             j=1;break;
                        }
                }                                                                                                             //semantic1
  
		//fprintf(fout, "4\n");////////////////
		//fprintf(fout, "%s\n", n->stri);
		if(strcmp(n->son->stri,"read")==0) {cread(n);j=1;}
		else if(strcmp(n->son->stri,"write")==0) {cwrite(n);j=1;}
		else{
			code = cARGS(n->son->sibling->sibling);			
			fprintf(fout, "%%call%d = call i32 @%s (%s)\n", counter, n->son->stri, code);
			sprintf(code, "%%call%d", counter);
			counter++;
		}
                if (j==0) printf("ERROR IN SEMANTIC CHECKING: Not declared function called!\n");                               //semantic1
	}
	
	else if(strcmp(n->son->stri,"(")){   //LP EXP RP
		code = cEXP(n->son->sibling);//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	}
	else {}
	
	return code;
}
char * cARRS(NodeT * n){
	//fprintf(fout, "cARRS!\n");	
	char * code;
	if(n->son == NULL){    //null
	
	}
	else {    //LB EXP RB ARRS
		code = cEXP(n->son->sibling);
	}
	return code;
}

char * cARGS(NodeT * n){
	//fprintf(fout, "cARGS!\n");
	
	char* code;
	code = (char*) malloc(sizeof(char)*CODE_LEN);
	//sprintf(code, "");
	char tmp[CODE_LEN] = "";
	char * exp;

	char c;
	if (n->attr.isLeft == 0) c = ' ';
	else c = '*';

	n = n->son;
	exp = cEXP(n);
	sprintf( tmp, "i32%c %s", c, exp);
	if(n->sibling == NULL){    //EXP
		strcat(code,tmp); 
	}
	else {        //EXP COMMA ARGS
		exp = cARGS(n->sibling->sibling);
		sprintf(code, "%s,%s", tmp, exp);
	}
	return code;
}

/****************************************************************************************************************************************/
/****************************************************************************************************************************************/
/****************************************************************************************************************************************/
/****************************************************************************************************************************************/

NodeT * createInnerNode(char *d, int num,...){
	va_list ap;
	NodeT *res;
	NodeT *tmp1;
	NodeT *tmp2;
	int i;
	
	/*allocate node*/
	if ((res = malloc(sizeof(NodeT))) == NULL)
        	yyerror("out of memory");
	/*create the new node and link together*/
	res->nType = 4;
	res->stri = (char*)malloc(sizeof(char)*70);
	strcpy(res->stri,d);
        res->attr.isLeft = 0;
	res->sibling = NULL;
	if(num==0){res->son = NULL; root = res; return res;}
	va_start(ap, num);
	for(i = 0; i<num; ++i){
		if(i==0){tmp2 = res->son = va_arg(ap, NodeT*);}
		else {
			tmp1 = tmp2->sibling = va_arg(ap, NodeT*);
			tmp2 = tmp1;			
		}
	}
	tmp2->sibling = NULL;
	va_end(ap);
	root = res;
	return res;	
}

int traversal(NodeT *n, int layer){
	if(strcmp(n->stri,"PROGRAM")==0) cPROGRAM(n);
	
	return 0;
}

int main(int argc, char* argv[]){
	//yydebug=1;
	freopen(argv[1], "r", stdin);
        fout = fopen(argv[2], "w");
	//fprintf(fout, " begin!!!\n");
	yyparse();


	stack = (IDT*)malloc(sizeof(IDT)*ID_NUMBER);
        list = (FUNC*)malloc(sizeof(FUNC)*10);
	traversal(root,0);
     
        int index; int result=0;
        for (index=0;index<list_p;index++) {
              // if ((strcmp(list[index].ftype,"int")==0) && (strcmp(list[index].name,"main")==0)) {
                if (strcmp(list[index].name,"main")==0) {
                      result=1;break;
               }
        }
        if (result==0) printf("ERROR IN SEMANTIC CHECKING: No 'int main' function included!\n");

	return 0;

}
int yyerror(char *s){
        fprintf(fout,  "ERROR! %s\n", s);
        exit(0);
        return 0;
}

	


	



