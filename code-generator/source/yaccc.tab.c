/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yaccc.y" /* yacc.c:339  */

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

#line 91 "yaccc.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yaccc.tab.h".  */
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
#line 26 "yaccc.y" /* yacc.c:355  */

    NodeT *Node;             	    /* node pointer */

#line 190 "yaccc.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACCC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 205 "yaccc.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   609

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    56,    56,    58,    59,    61,    62,    64,    65,    66,
      68,    69,    71,    72,    74,    75,    77,    78,    80,    82,
      83,    84,    86,    88,    90,    91,    93,    94,    95,    96,
      97,    98,    99,   101,   102,   104,   105,   107,   109,   110,
     112,   113,   115,   116,   118,   119,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   161,   162,   164,   165
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMI", "COMMA", "ASSIGNOP", "DOT", "LC",
  "RC", "LP", "RP", "LB", "RB", "PD", "DV", "MD", "PL", "MI", "SL", "SR",
  "GT", "GE", "LT", "LE", "ET", "NE", "BA", "BX", "BO", "LA", "LO",
  "BREAK", "CONT", "ELSE", "FOR", "ID", "IF", "INT", "RETURN", "STRUCT",
  "TYPE", "PLS", "BMS", "PDS", "DVS", "BAS", "BXS", "BOS", "SLS", "SRS",
  "LN", "PREI", "PRED", "BN", "AS", "$accept", "PROGRAM", "EXTDEFS",
  "EXTDEF", "EXTVARS", "SPEC", "STSPEC", "OPTTAG", "VAR", "FUNC", "PARAS",
  "PARA", "STMTBLOCK", "STMTS", "STMT", "ESTMT", "DEFS", "DEF", "DECS",
  "DEC", "INIT", "FEXP", "EXP", "ARRS", "ARGS", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -158

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-158)))

#define YYTABLE_NINF -15

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -12,   -21,  -158,    24,  -158,   -12,    -6,  -158,    36,    68,
    -158,  -158,    33,    73,    -2,    70,    75,   -12,   -12,  -158,
     178,    44,   -12,  -158,    47,    47,    77,   -12,    47,    86,
     111,   185,   185,   185,    -4,  -158,   185,   185,   185,   185,
    -158,   408,    76,   174,  -158,  -158,   113,   114,  -158,  -158,
     106,  -158,   -12,   228,   112,   273,    35,   185,   185,  -158,
      35,    35,    35,    35,   185,   430,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,  -158,   116,   118,   126,   130,   185,  -158,
     132,   174,    84,  -158,    47,  -158,   185,  -158,  -158,   133,
     318,   408,    -4,   117,    35,    35,    35,   183,   183,    78,
      78,    17,    17,    17,    17,   586,   586,   565,   543,   520,
     496,   471,   408,   408,   408,   408,   408,   408,   408,   408,
     408,  -158,  -158,   185,   185,   131,  -158,  -158,  -158,  -158,
    -158,  -158,   151,   138,   408,   363,  -158,  -158,   185,   174,
     160,   134,   185,   174,  -158,   154,  -158,   174,  -158
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    15,    10,     0,     2,     4,     9,    11,    13,     0,
       1,     3,    16,     0,    40,     0,     7,    36,    21,     5,
       0,     0,    36,     6,     9,     0,     0,    36,     0,     0,
      20,     0,     0,     0,    86,    84,     0,     0,     0,     0,
      41,    42,     0,    25,    16,     8,     0,    39,    12,    35,
      22,    18,    21,    88,     0,     0,    79,     0,     0,    82,
      75,    76,    77,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,     0,     0,     0,     0,     0,    27,
       0,    25,     0,    37,     0,    19,     0,    43,    80,     0,
       0,    46,    83,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    32,    31,    45,     0,     0,    23,    24,    26,    38,
      87,    81,    86,     0,    44,     0,    28,    85,    45,     0,
       0,    34,    45,     0,    29,     0,    33,     0,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,   161,  -158,   141,    21,  -158,  -158,   140,  -158,
     119,  -158,   155,    81,  -157,  -158,    -7,  -158,    65,   -24,
    -158,  -154,   -20,    32,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    25,     7,     9,    14,    15,
      29,    30,    99,   100,   101,   164,    26,    27,    46,    16,
      40,   153,   102,    59,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    47,   161,    20,   160,    57,   166,    58,   165,    21,
     168,    53,    55,    56,     8,    43,    60,    61,    62,    63,
      49,     6,    64,    65,    10,   109,     6,     1,     2,    12,
      66,    67,    68,    69,    70,    71,    72,    53,   110,    28,
      64,    65,    18,   -14,   111,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    28,   150,    17,    19,    22,   145,    24,
      47,    42,    44,    64,    65,    48,    53,   148,    93,    64,
      65,    66,    67,    68,    69,    70,    51,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    52,   103,    21,   104,   141,
     107,   142,    64,   154,   155,    84,    85,    86,    87,    88,
      89,    90,    91,    92,   156,   143,    64,    65,   154,   144,
     146,   158,   154,   151,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    58,   162,   167,    45,    11,   163,    50,   149,
      23,   105,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    22,   147,    32,   157,    31,     0,    32,    64,    65,
       0,    33,     0,     0,    32,    33,    66,    67,    68,     0,
       0,     0,    33,     0,     0,    94,    95,     0,    96,    34,
      97,    35,    98,    34,     0,    35,     0,     0,     0,     0,
      34,     0,    35,     0,    36,    37,    38,    39,    36,    37,
      38,    39,   106,    64,    65,    36,    37,    38,    39,     0,
       0,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    64,    65,
       0,     0,     0,   108,     0,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    64,    65,     0,     0,     0,     0,     0,
     152,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    64,    65,
       0,     0,     0,   159,     0,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    64,    65,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    32,
       0,     0,     0,     0,     0,     0,     0,    33,     0,    84,
      85,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,   112,     0,    35,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    65,     0,     0,
      36,    37,    38,    39,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    64,    65,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    64,    65,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    64,    65,
       0,     0,     0,     0,     0,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      64,    65,     0,     0,     0,     0,     0,     0,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    64,    65,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76
};

static const yytype_int16 yycheck[] =
{
      20,    25,   159,     5,   158,     9,   163,    11,   162,    11,
     167,    31,    32,    33,    35,    22,    36,    37,    38,    39,
      27,     0,     5,     6,     0,    57,     5,    39,    40,    35,
      13,    14,    15,    16,    17,    18,    19,    57,    58,    18,
       5,     6,     9,     7,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    52,   106,     7,     3,     7,    98,     4,
     104,    37,    35,     5,     6,     8,   106,     3,    12,     5,
       6,    13,    14,    15,    16,    17,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,     4,     3,    11,     4,     3,
       8,     3,     5,   143,   144,    41,    42,    43,    44,    45,
      46,    47,    48,    49,     3,     9,     5,     6,   158,     9,
       8,     3,   162,    10,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    11,     3,    10,    24,     5,    33,    28,   104,
      15,    52,    41,    42,    43,    44,    45,    46,    47,    48,
      49,     7,   101,     9,   152,     7,    -1,     9,     5,     6,
      -1,    17,    -1,    -1,     9,    17,    13,    14,    15,    -1,
      -1,    -1,    17,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    35,    -1,    37,    -1,    -1,    -1,    -1,
      35,    -1,    37,    -1,    50,    51,    52,    53,    50,    51,
      52,    53,     4,     5,     6,    50,    51,    52,    53,    -1,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,     5,     6,
      -1,    -1,    -1,    10,    -1,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,     5,     6,    -1,    -1,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,     5,     6,
      -1,    -1,    -1,    10,    -1,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,    -1,
      50,    51,    52,    53,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    40,    56,    57,    58,    60,    61,    35,    62,
       0,    57,    35,    59,    63,    64,    74,     7,     9,     3,
       5,    11,     7,    67,     4,    60,    71,    72,    60,    65,
      66,     7,     9,    17,    35,    37,    50,    51,    52,    53,
      75,    77,    37,    71,    35,    59,    73,    74,     8,    71,
      63,    10,     4,    77,    79,    77,    77,     9,    11,    78,
      77,    77,    77,    77,     5,     6,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    12,    31,    32,    34,    36,    38,    67,
      68,    69,    77,     3,     4,    65,     4,     8,    10,    79,
      77,    77,    35,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,     3,     3,     9,     9,    77,     8,    68,     3,    73,
      79,    10,    12,    76,    77,    77,     3,    78,     3,    10,
      76,    69,     3,    33,    70,    76,    69,    10,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    59,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    64,    65,
      65,    65,    66,    67,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    70,    70,    71,    71,    72,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     1,     3,     0,
       1,     1,     5,     2,     1,     0,     1,     4,     4,     3,
       1,     0,     2,     4,     2,     0,     2,     1,     3,     6,
       9,     2,     2,     2,     0,     2,     0,     3,     3,     1,
       1,     3,     1,     3,     1,     0,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       3,     4,     2,     3,     1,     4,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 56 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("PROGRAM", 1, (yyvsp[0].Node));}
#line 1483 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 58 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXTDEFS", 2, (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1489 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 59 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXTDEFS", 0);}
#line 1495 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 61 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXTDEF", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1501 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 62 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXTDEF", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1507 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 64 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXTVARS", 1, (yyvsp[0].Node));}
#line 1513 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 65 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXTVARS", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1519 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 66 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXTVARS", 0);}
#line 1525 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 68 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("SPEC", 1, (yyvsp[0].Node));}
#line 1531 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 69 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("SPEC", 1, (yyvsp[0].Node));}
#line 1537 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 71 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("STSPEC", 5, (yyvsp[-4].Node), (yyvsp[-3].Node), (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1543 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 72 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("STSPEC", 2, (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1549 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 74 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("OPTTAG", 1, (yyvsp[0].Node));}
#line 1555 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 75 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("OPTTAG", 0);}
#line 1561 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 77 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("VAR", 1, (yyvsp[0].Node));}
#line 1567 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 78 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("VAR", 4, (yyvsp[-3].Node), (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1573 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 80 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("FUNC", 4, (yyvsp[-3].Node), (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1579 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 82 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("PARAS", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1585 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 83 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("PARAS", 1, (yyvsp[0].Node));}
#line 1591 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 84 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("PARAS", 0);}
#line 1597 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 86 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("PARA", 2, (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1603 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 88 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("STMTBLOCK", 4, (yyvsp[-3].Node), (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1609 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 90 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("STMTS", 2, (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1615 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 91 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("STMTS", 0);}
#line 1621 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 93 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("STMT", 2, (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1627 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 94 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("STMT", 1, (yyvsp[0].Node));}
#line 1633 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 95 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("STMT", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1639 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 96 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("STMT", 6, (yyvsp[-5].Node), (yyvsp[-4].Node), (yyvsp[-3].Node), (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1645 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 97 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("STMT", 9, (yyvsp[-8].Node), (yyvsp[-7].Node), (yyvsp[-6].Node), (yyvsp[-5].Node), (yyvsp[-4].Node), (yyvsp[-3].Node), (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1651 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 98 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("STMT", 2, (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1657 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 99 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("STMT", 2, (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1663 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 101 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("ESTMT", 2, (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1669 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 102 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("ESTMT", 0);}
#line 1675 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 104 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("DEFS", 2, (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1681 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 105 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("DEFS", 0);}
#line 1687 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 107 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("DEF", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1693 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 109 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("DECS", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1699 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 110 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("DECS", 1, (yyvsp[0].Node));}
#line 1705 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 112 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("DEC", 1, (yyvsp[0].Node));}
#line 1711 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 113 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("DEC", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1717 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 115 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("INIT", 1, (yyvsp[0].Node));}
#line 1723 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 116 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("INIT", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1729 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 118 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("FEXP", 1, (yyvsp[0].Node));}
#line 1735 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 119 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("FEXP", 0);}
#line 1741 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 121 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1747 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 122 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1753 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 123 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1759 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 124 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1765 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 125 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1771 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 126 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1777 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 127 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1783 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 128 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1789 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 129 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1795 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 130 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1801 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 131 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1807 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 132 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1813 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 133 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1819 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 134 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1825 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 135 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1831 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 136 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1837 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 137 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1843 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 138 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1849 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 139 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1855 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 140 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1861 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 141 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1867 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 142 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1873 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 143 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1879 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 144 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1885 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 145 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1891 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 146 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1897 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 147 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1903 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 148 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1909 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 149 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1915 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 150 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 2, (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1921 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 151 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 2, (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1927 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 152 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 2, (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1933 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 153 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 2, (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1939 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 154 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 2, (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1945 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 155 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1951 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 156 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 4, (yyvsp[-3].Node), (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1957 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 157 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 2, (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1963 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 158 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1969 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 159 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("EXP", 1, (yyvsp[0].Node));}
#line 1975 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 161 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("ARRS", 4, (yyvsp[-3].Node), (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1981 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 162 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("ARRS", 0);}
#line 1987 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 164 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("ARGS", 3, (yyvsp[-2].Node), (yyvsp[-1].Node), (yyvsp[0].Node));}
#line 1993 "yaccc.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 165 "yaccc.y" /* yacc.c:1646  */
    {(yyval.Node) = createInnerNode("ARGS", 1, (yyvsp[0].Node));}
#line 1999 "yaccc.tab.c" /* yacc.c:1646  */
    break;


#line 2003 "yaccc.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 168 "yaccc.y" /* yacc.c:1906  */

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
        add_list(n->stri,t);
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

	


	



