%{
#include "node.h"
#include "yaccc.tab.h"  
NodeT *createTerminal(char * Text, int typeNode);
int lineco = 0;
%}
digit		[0-9]
dec	        [1-9]{digit}*
oct	        0[0-7]*
hex	        0(x|X)[0-9a-fA-F]*
integer 	{dec}|{oct}|{hex}
space 		[ \t\r]+
letter		[a-zA-Z]
id 		(_|{letter})(_|{letter}|{digit})*
%%
{space} 	{/*no action*/}
\n      	{lineco++;}
int  		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return TYPE;}
struct 		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return STRUCT;}
if 		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return IF;}
else 		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return ELSE;}
break 		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return BREAK;}
continue	{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return CONT;}
for		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return FOR;}
return		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return RETURN;}

{integer}	{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 1); return INT;}
{id} 		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 2); return ID;}
";"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return SEMI;}
"," 		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return COMMA;}

"{"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return LC;}
"}"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return RC;}
"("		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return LP;}
")"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return RP;}
"["		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return LB;}
"]"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return RB;}
"."		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return DOT;}
"!" 		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return LN;}
"++"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return PREI;}
"--"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return PRED;}
"~"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return BN;}
"*"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return PD;}
"/"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return DV;}
"%"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return MD;}
"+"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return PL;}
"-"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return MI;}
"<<"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return SL;}
">>"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return SR;}
">"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return GT;}
">="		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return GE;}
"<"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return LT;}
"<="		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return LE;}
"=="		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return ET;}
"!="		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return NE;}
"&"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return BA;}
"^"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return BX;}
"|"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return BO;}
"&&"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return LA;}
"||"		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return LO;}
"="		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return ASSIGNOP;}
"+="		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return PLS;}
"-="		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return BMS;}
"*="		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return PDS;}
"/="		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return DVS;}
"&="		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return BAS;}
"^="		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return BXS;}
"|="		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return BOS;}
"<<="		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return SLS;}
">>="		{printf("%s\n", yytext); yylval.Node = createTerminal(yytext, 3); return SRS;}

.	        yyerror("invalid character!\n");

%%

NodeT * createTerminal(char * Text, int typeNode){
	NodeT *tmp = malloc(sizeof(NodeT));
	tmp->nType = typeNode;
	tmp->son = tmp->sibling = NULL;
	switch(typeNode){
		case 0: 
			printf("Default type.\n");
			break;
		case 1:		//int
			tmp->stri = (char*)malloc(sizeof(char)*70);
			strcpy(tmp->stri,Text);
			break;
		case 2:		//id
			tmp->stri = (char*)malloc(sizeof(char)*70);
			strcpy(tmp->stri,Text);
			break;
		case 3:		//operator
			tmp->stri = (char*)malloc(sizeof(char)*70);
			strcpy(tmp->stri,Text);
			break;
		default: 
			printf("Error in creating terminals!\n");
			break;	
	}
	return tmp;
}

yywrap(void){
	//printf("------yywrap------\n");
}


