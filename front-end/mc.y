%{
#include "common.h"
unsigned char flag=1;
extern YYSTYPE *yyvsp;
extern int yylex(void);
extern int yylineno;
extern char *yytext;
extern FILE *yyout;
void CreateT(YYSTYPE node,char *dsp);
void FreeT(YYSTYPE node);
void yyerror(const char *s);
#define add(s,n)\
{\
	int i;\
	yyval=malloc(sizeof(struct Node));\
	yyval->sibling=NULL;\
	strcpy(yyval->name,s);\
	if(n>0){\
		yyval->children=yyvsp[-n+1];\
		for(i=-n+1;i<0;i++) yyvsp[i]->sibling=yyvsp[i+1];\
	}\
	else yyval->children=NULL;\
}
%}
/* operators */
%right '=' ASSIGN
%left LOR
%left LAND
%left '|'
%left '^'
%left '&'
%left EQ NE
%left '<' '>' LE BE
%left SR SL
%left '+' '-'
%left '*' '/' '%'
%right UNARYOP
%left '.' '(' ')' '[' ']' '{' '}'

%token SEMI COMMA INT ID TYPE STRUCT IF ELSE BREAK CONT FOR RETURN 

%%
/* rules */
program	:	extdefs	
		{
			add("PROGRAM",1);
			fprintf(yyout,"program\n");
			if(flag) CreateT($1,"");
			FreeT($$);
		}
	;

extdefs	:	extdef extdefs	{add("EXTDEFS",2);}
	|	/* empty */ 	{add("EXTDEFS",0);}
	;

extdef	:	spec extvars ';'	{add("EXTDEF",3);}
	|	spec func stmtblock	{add("EXTDEF",3);}
	;

extvars	:	dec		{add("EXTVARS",1);}
	|	dec ',' extvars	{add("EXTVARS",3);}
	|	/* empty */	{add("EXTVARS",0);}
	;

spec	:	TYPE	{add("SPEC",1);}
	|	stspec	{add("SPEC",1);}
	;

stspec	:	STRUCT opttag '{' defs '}'	{add("STSPEC",5);}
	|	STRUCT ID			{add("STSPEC",2);}
	;

opttag	:	ID		{add("OPTTAG",1);}
	|	/* empty */	{add("OPTTAG",0);}
	;

var	:	ID			{add("VAR",1);}
	|	var '[' INT ']'		{add("VAR",4);}
	;

func	:	ID '(' paras ')'	{add("FUNC",4);}
	;

paras	:	para ',' paras	{add("PARAS",3);}
	|	para		{add("PARAS",1);}
	|	/*empty*/	{add("PARAS",0);}
	;

para	:	spec var	{add("PARA",2);}
	;

stmtblock :	'{' defs stmts '}'	{add("STMTBLOCK",4);}
	;

stmts	:	stmt stmts	{add("STMTS",2);}
	|	/* empty */	{add("STMTS",0);}
	;

stmt    :       exp ';'                                       {add("MATCHEDSTMT",2);}
	|       stmtblock                                     {add("MATCHEDSTMT",1);}
	|       RETURN exp ';'                                {add("MATCHEDSTMT",3);}
        |       IF '(' exp ')' stmt estmt                     {add("MATCHEDSTMT",6);}
	|       FOR '(' fexp ';' fexp ';' fexp ')' stmt       {add("MATCHEDSTMT",9);}
	|       CONT ';'                                      {add("MATCHEDSTMT",2);}
	|       BREAK ';'                                     {add("MATCHEDSTMT",2);}
	;

estmt   :	ELSE stmt                                     {add("OPENSTMT",2);}
	|       /* empty */                                   {add("OPENSTMT",0);}
	;

defs	:	def defs	{add("DEFS",2);}
	|	/* empty */	{add("DEFS",0);}
	;

def	:	spec decs ';'	{add("DEF",3);}
	;

decs	:	dec ',' decs	{add("DECS",3);}
	|	dec		{add("DECS",1);}
	;

dec	:	var		{add("DEC",1);}
	|	var '=' init	{add("DEC",3);}
	;

init	:	exp		{add("INIT",1);}
	|	'{' args '}'	{add("INIT",3);}
	;

exp	:	exp '+' exp		{add("EXP",3);}
	|	exp '-' exp		{add("EXP",3);}
	|	exp '*' exp		{add("EXP",3);}
	|	exp '/' exp		{add("EXP",3);}
	|	exp '%' exp		{add("EXP",3);}
	|	exp SL exp		{add("EXP",3);}
	|	exp SR exp		{add("EXP",3);}
	|	exp '>' exp		{add("EXP",3);}
	|	exp BE exp		{add("EXP",3);}
	|	exp '<' exp		{add("EXP",3);}
	|	exp LE exp		{add("EXP",3);}
	|	exp EQ exp		{add("EXP",3);}
	|	exp NE exp		{add("EXP",3);}
	|	exp '&' exp		{add("EXP",3);}
	|	exp '^' exp		{add("EXP",3);}
	|	exp '|' exp		{add("EXP",3);}
	|	exp LAND exp		{add("EXP",3);}
	|	exp LOR exp		{add("EXP",3);}
	|	'-' exp %prec UNARYOP	{add("EXP",2);}
	|	UNARYOP exp		{add("EXP",2);}
	|	exp '=' exp		{add("EXP",3);}
	|	exp ASSIGN exp		{add("EXP",3);}
	|	'(' exp ')'		{add("EXP",3);}
	|	ID '(' args ')'		{add("EXP",4);}
	|	ID arrs			{add("EXP",2);}
	|	exp '.' ID		{add("EXP",3);}
	|	INT			{add("EXP",1);}
	;

fexp    :       exp                     {add("FEXP",1);}
        |       /* empty */		{add("FEXP",0);}
        ;

arrs	:	'[' exp ']' arrs	{add("ARRS",4);}
	|	/* empty */		{add("ARRS",0);}
	;

args	:	exp ',' args	{add("ARGS",3);}
	|	exp		{add("ARGS",1);}
	;

%%
/*  user codes */
void CreateT(YYSTYPE node,char dsp[])
{

	if(node==NULL) return;
	char newgraph[100];
	strcpy(newgraph,dsp);
	fprintf(yyout,"%s",dsp);
	if(node->sibling==NULL) {
		fprintf(yyout,"└─");
		strcat(newgraph,"  ");
	}
	else
	{
		fprintf(yyout,"├─");
		strcat(newgraph,"│ ");
	}
	fprintf(yyout,"%s\n",node->name);
	CreateT(node->children,newgraph);
	CreateT(node->sibling,dsp);
}

void FreeT(YYSTYPE node)
{
	if(node==NULL) return;
	FreeT(node->children);
	FreeT(node->sibling);
	free(node);
}

void yyerror(const char *s)
{
	flag=0;
	fprintf(stderr,"Line %d: %s\n",yylineno,s);
	fprintf(stderr,"expected (not provided) before '%s' token\n",yytext);
}

int main(int argc,char *argv[])
{
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("err: Fail to open %s\n",argv[1]);
		return 1;
	}
	FILE *fout;
	if(argc>=3){
		fout=fopen(argv[2],"w");
		if (fout==NULL) fout=stdout;
	}
	else fout=stdout;
	extern FILE *yyin;
	yyout=fout;
	yyin=fin;
        fprintf(yyout,"\n=========================================================Parsing Tree of Your Test=========================================================\n\n");

	yyparse();

        if (flag==0)  fprintf(yyout,"ERROR happen.\nCheck error information in the terminal.\n");

        fprintf(yyout,"\n===========================================================================================================================================\n\n\n");
	close(fin);
	close(fout);
	return 0;
}
