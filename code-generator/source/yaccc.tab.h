/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_YACCC_TAB_H_INCLUDED
# define YY_YY_YACCC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMI = 258,
    COMMA = 259,
    ASSIGNOP = 260,
    DOT = 261,
    LC = 262,
    RC = 263,
    LP = 264,
    RP = 265,
    LB = 266,
    RB = 267,
    PD = 268,
    DV = 269,
    MD = 270,
    PL = 271,
    MI = 272,
    SL = 273,
    SR = 274,
    GT = 275,
    GE = 276,
    LT = 277,
    LE = 278,
    ET = 279,
    NE = 280,
    BA = 281,
    BX = 282,
    BO = 283,
    LA = 284,
    LO = 285,
    BREAK = 286,
    CONT = 287,
    ELSE = 288,
    FOR = 289,
    ID = 290,
    IF = 291,
    INT = 292,
    RETURN = 293,
    STRUCT = 294,
    TYPE = 295,
    PLS = 296,
    BMS = 297,
    PDS = 298,
    DVS = 299,
    BAS = 300,
    BXS = 301,
    BOS = 302,
    SLS = 303,
    SRS = 304,
    LN = 305,
    PREI = 306,
    PRED = 307,
    BN = 308,
    AS = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 26 "yaccc.y" /* yacc.c:1909  */

    NodeT *Node;             	    /* node pointer */

#line 113 "yaccc.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACCC_TAB_H_INCLUDED  */
