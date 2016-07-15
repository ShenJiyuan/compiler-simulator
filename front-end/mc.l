%{
    #include "common.h"
    #include "y.tab.h"
    int yywrap(void);
    int yylex(void);
    extern int yylineno;
#define trans \
{\
	yylval=malloc(sizeof(struct Node));\
	strcpy(yylval->name,yytext);\
        yylval->children=NULL;\
	yylval->sibling=NULL;\
}
%}
TYPE	int
SPACE	[ \t\r]+
digit	[0-9]
letter	[a-zA-Z]
dec	[1-9]{digit}*
oct	0[0-7]*
hex	0(x|X)[0-9a-fA-F]*
INT     {dec}|{oct}
ID	{letter}({letter}|{digit})*
UNARYOP	"!"|"~"|"++"|"--"
ASSIGN	"+="|"-="|"*="|"/="|"&="|"^="|"|="|"<<="|">>="
%%
{SPACE}	        ;
\n	        yylineno++;
{dec}	        {trans;yylval->num=atoi(yytext);return INT;}
{hex}	        {trans;yylval->num=strtol(yytext,NULL,16);return INT;}
{oct}	        {trans;yylval->num=strtol(yytext,NULL,8);return INT;}
struct       	{trans;return STRUCT;}
return  	{trans;return RETURN;}
if	        {trans;return IF;}
else	        {trans;return ELSE;}
break    	{trans;return BREAK;}
continue	{trans;return CONT;}
for	        {trans;return FOR;}
{TYPE}	        {trans;strcpy(yylval->id,yytext);return TYPE;}
{ID}	        {trans;strcpy(yylval->id,yytext);return ID;}
{ASSIGN}	{trans;strcpy(yylval->id,yytext);return ASSIGN;}
{UNARYOP}	{trans;strcpy(yylval->id,yytext);return UNARYOP;}
"("	        {trans;return '(';}
")"	        {trans;return ')';}
"["	        {trans;return '[';}
"]"	        {trans;return ']';}
"{"	        {trans;return '{';}
"}"	        {trans;return '}';}
";"	        {trans;return ';';}
","	        {trans;return ',';}
"."	        {trans;return '.';}
"="	        {trans;return '=';}
"+"	        {trans;return '+';}
"-"	        {trans;return '-';}
"*"	        {trans;return '*';}
"/"	        {trans;return '/';}
"%"	        {trans;return '%';}
"&"	        {trans;return '&';}
"^"	        {trans;return '^';}
"|"	        {trans;return '|';}
"<"	        {trans;return '<';}
">"	        {trans;return '>';}
"<<"	        {trans;return SL;}
">>"	        {trans;return SR;}
"<="	        {trans;return LE;}
">="	        {trans;return BE;}
"=="	        {trans;return EQ;}
"!="	        {trans;return NE;}
"&&"	        {trans;return LAND;}
"||"	        {trans;return LOR;}
.	        yyerror("invalid character!\n");
%%
yywrap(void)
{
	//printf("--yywrap--\n");
}
