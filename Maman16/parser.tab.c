
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"


#include <stdio.h>
#include <malloc.h>
#include "symtab.h"
#include "gen.h"

extern int yylex (void);
int yyerror(char *s);
extern int line;

int number = 0;
int errorExist = 0;
varNode *currentVar = NULL, *nextVar = NULL;
command *currentCommand = NULL;
commandList *tempList = NULL;
char *num = NULL;
int p = 0;
char casevalue[10] ;


/* Line 189 of yacc.c  */
#line 95 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     CASE = 259,
     INT = 260,
     FLOAT = 261,
     OUTPUT = 262,
     INPUT = 263,
     IF = 264,
     ELSE = 265,
     SWITCH = 266,
     WHILE = 267,
     DEFAULT = 268,
     BREAK = 269,
     ADDOP = 270,
     NUM = 271,
     MULOP = 272,
     CAST = 273,
     OR = 274,
     AND = 275,
     NOT = 276,
     RELOP = 277
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 24 "parser.y"

	struct number {
		          char value[VARLEN];
		          char type;
	                        } num;

               struct exp {
		    command *head;
                                     commandList *false;
		    char last[VARLEN];
		    char type;
	                 } expression;
	
	struct bool {
		       commandList *false;
		       command *head;
	                   } boolean;

	char id[VARLEN];	
	char type;
	char op; 
                char castOp;	
	 command *stmt;	
	int relop; 



/* Line 214 of yacc.c  */
#line 181 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 193 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   105

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNRULES -- Number of states.  */
#define YYNSTATES  98

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      27,    28,     2,     2,    25,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    23,    24,
       2,    26,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,    30,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    11,    17,    19,    21,
      25,    27,    29,    31,    33,    35,    37,    39,    41,    43,
      48,    54,    60,    68,    74,    85,    91,    92,    95,    99,
     102,   103,   107,   109,   113,   115,   120,   124,   128,   130,
     134,   136,   140,   145,   147
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      32,     0,    -1,    33,    47,    -1,    33,    34,    -1,    -1,
      -1,    37,    23,    36,    35,    24,    -1,     5,    -1,     6,
      -1,    37,    25,     3,    -1,     3,    -1,    39,    -1,    40,
      -1,    41,    -1,    42,    -1,    43,    -1,    44,    -1,    46,
      -1,    47,    -1,     3,    26,    52,    24,    -1,     8,    27,
       3,    28,    24,    -1,     7,    27,    52,    28,    24,    -1,
       9,    27,    49,    28,    38,    10,    38,    -1,    12,    27,
      49,    28,    38,    -1,    11,    27,    52,    28,    29,    45,
      13,    23,    48,    30,    -1,    45,     4,    16,    23,    48,
      -1,    -1,    14,    24,    -1,    29,    48,    30,    -1,    48,
      38,    -1,    -1,    49,    19,    50,    -1,    50,    -1,    50,
      20,    51,    -1,    51,    -1,    21,    27,    49,    28,    -1,
      52,    22,    52,    -1,    52,    15,    53,    -1,    53,    -1,
      53,    17,    54,    -1,    54,    -1,    27,    52,    28,    -1,
      18,    27,    52,    28,    -1,     3,    -1,    16,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,   104,   105,   108,   108,   111,   112,   115,
     116,   119,   120,   121,   122,   123,   124,   125,   126,   129,
     132,   143,   150,   163,   176,   199,   217,   221,   223,   226,
     227,   232,   243,   250,   255,   262,   270,   281,   286,   294,
     300,   308,   316,   333,   348
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "CASE", "INT", "FLOAT", "OUTPUT",
  "INPUT", "IF", "ELSE", "SWITCH", "WHILE", "DEFAULT", "BREAK", "ADDOP",
  "NUM", "MULOP", "CAST", "OR", "AND", "NOT", "RELOP", "':'", "';'", "','",
  "'='", "'('", "')'", "'{'", "'}'", "$accept", "program", "declarations",
  "declaration", "$@1", "type", "idlist", "stmt", "assignment_stmt",
  "input_stmt", "output_stmt", "if_stmt", "while_stmt", "switch_stmt",
  "caselist", "break_stmt", "stmt_block", "stmtlist", "boolexpr",
  "boolterm", "boolfactor", "expression", "term", "factor", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    58,    59,    44,    61,    40,    41,   123,
     125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    33,    33,    35,    34,    36,    36,    37,
      37,    38,    38,    38,    38,    38,    38,    38,    38,    39,
      40,    41,    42,    43,    44,    45,    45,    46,    47,    48,
      48,    49,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    54,    54
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     0,     5,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       5,     5,     7,     5,    10,     5,     0,     2,     3,     2,
       0,     3,     1,     3,     1,     4,     3,     3,     1,     3,
       1,     3,     4,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,    10,    30,     3,     0,     2,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    11,    12,    13,    14,    15,    16,    17,    18,     7,
       8,     5,     9,     0,     0,     0,     0,     0,     0,    27,
       0,    43,    44,     0,     0,     0,    38,    40,     0,     0,
       0,     0,    32,    34,     0,     0,     0,     6,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,    37,    39,    21,    20,     0,    31,
       0,    33,    36,    26,    23,    42,    35,     0,     0,    22,
       0,     0,     0,    30,    30,     0,    25,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     6,    40,    31,     7,    20,    21,    22,
      23,    24,    25,    26,    88,    27,    28,     9,    51,    52,
      53,    54,    46,    47
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -57
static const yytype_int8 yypact[] =
{
     -57,    21,    -1,   -57,   -57,   -57,   -57,    57,   -57,     5,
       4,     2,     7,    38,    54,    56,    58,    59,    42,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,    40,    40,    69,    36,    40,    36,   -57,
      52,   -57,   -57,    60,    40,    -9,    67,   -57,    -8,    61,
      63,    12,    68,   -57,    49,    34,    13,   -57,    40,    45,
      40,   -57,    40,    53,    70,    36,    36,    39,    36,    40,
      62,    39,    46,   -57,    67,   -57,   -57,   -57,    50,    68,
      82,   -57,    78,   -57,   -57,   -57,   -57,    39,    66,   -57,
      79,    73,    74,   -57,   -57,    15,    39,   -57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -12,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,    96,   -56,   -35,    33,
      32,   -33,    41,    43
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      45,    48,     4,    56,    55,    32,    60,    60,    12,    29,
      30,    59,    13,    14,    15,    61,    16,    17,    12,    18,
      63,     3,    13,    14,    15,    72,    16,    17,     5,    18,
      78,    66,    66,    33,     5,    19,    82,    95,    96,    41,
      67,    71,    12,    41,     5,    97,    13,    14,    15,    60,
      16,    17,    42,    18,    43,    80,    42,    50,    43,    84,
      60,    60,    70,    44,    60,    34,    39,    44,     5,    66,
      90,    69,    49,    73,    85,    89,    57,    76,    86,    91,
      10,    35,    11,    36,    62,    37,    38,    58,    68,    64,
      65,    83,    87,    60,    77,    92,    93,    94,     8,    79,
      81,    74,     0,     0,     0,    75
};

static const yytype_int8 yycheck[] =
{
      33,    34,     3,    38,    37,     3,    15,    15,     3,     5,
       6,    44,     7,     8,     9,    24,    11,    12,     3,    14,
      28,     0,     7,     8,     9,    58,    11,    12,    29,    14,
      65,    19,    19,    26,    29,    30,    69,    93,    94,     3,
      28,    28,     3,     3,    29,    30,     7,     8,     9,    15,
      11,    12,    16,    14,    18,    67,    16,    21,    18,    71,
      15,    15,    28,    27,    15,    27,    24,    27,    29,    19,
       4,    22,     3,    28,    28,    87,    24,    24,    28,    13,
      23,    27,    25,    27,    17,    27,    27,    27,    20,    28,
      27,    29,    10,    15,    24,    16,    23,    23,     2,    66,
      68,    60,    -1,    -1,    -1,    62
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    33,     0,     3,    29,    34,    37,    47,    48,
      23,    25,     3,     7,     8,     9,    11,    12,    14,    30,
      38,    39,    40,    41,    42,    43,    44,    46,    47,     5,
       6,    36,     3,    26,    27,    27,    27,    27,    27,    24,
      35,     3,    16,    18,    27,    52,    53,    54,    52,     3,
      21,    49,    50,    51,    52,    52,    49,    24,    27,    52,
      15,    24,    17,    28,    28,    27,    19,    28,    20,    22,
      28,    28,    52,    28,    53,    54,    24,    24,    49,    50,
      38,    51,    52,    29,    38,    28,    28,    10,    45,    38,
       4,    13,    16,    23,    23,    48,    48,    30
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 96 "parser.y"
    {
					                                  (yyvsp[(2) - (2)].stmt) = translateCommand((yyvsp[(2) - (2)].stmt),'H',"ALT","","","");
					                                   commandsPrint((yyvsp[(2) - (2)].stmt));
					                                   freeTree();
					                                   freeList((yyvsp[(2) - (2)].stmt));
				                                                ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    { setVarType((yyvsp[(3) - (3)].type));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 111 "parser.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    { setVarName((yyvsp[(3) - (3)].id));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    { setVarName((yyvsp[(1) - (1)].id));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 119 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    { (yyval.stmt) = addAssignmentCommand((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].expression).last, (yyvsp[(3) - (4)].expression).type, (yyvsp[(3) - (4)].expression).head);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    {
					                       (yyval.stmt) = NULL;
					                        if(!(currentVar = searchVar((yyvsp[(3) - (5)].id))))
						                   fprintf(stderr,"ERROR: unknown variable, not defined in the symbol table");
					                        else
						            (yyval.stmt) = translateCommand(NULL,currentVar->type,"INP",currentVar->name,"","");
				                                      ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    {
					                                             (yyval.stmt) = translateCommand((yyvsp[(3) - (5)].expression).head,(yyvsp[(3) - (5)].expression).type,"PRT",(yyvsp[(3) - (5)].expression).last,"","");		
					                                              freeState((yyvsp[(3) - (5)].expression).last);
				                                                           ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    {	
						(yyval.stmt) = mergeCommands((yyvsp[(3) - (7)].boolean).head, (yyvsp[(5) - (7)].stmt));
						(yyval.stmt) = translateCommand((yyval.stmt),'J',"UMP","","","");
						tempList = addCommandToList(NULL, getLastCommand((yyval.stmt))); 
						(yyval.stmt) = addLabel((yyval.stmt));
						updateList((yyvsp[(3) - (7)].boolean).false,getLastCommand((yyval.stmt)));
						(yyval.stmt) = mergeCommands((yyval.stmt), (yyvsp[(7) - (7)].stmt));
						(yyval.stmt) = addLabel((yyval.stmt));
						updateList(tempList, getLastCommand((yyval.stmt)));
					           ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    {
						(yyval.stmt) = addLabel(NULL);
						(yyval.stmt) = mergeCommands((yyval.stmt), (yyvsp[(3) - (5)].boolean).head);
						(yyval.stmt) = mergeCommands((yyval.stmt), (yyvsp[(5) - (5)].stmt));
						(yyval.stmt) = translateCommand((yyval.stmt),'J',"UMP","","","");
			                                                tempList = addCommandToList(NULL, getLastCommand((yyval.stmt)));
						updateList(tempList, (yyval.stmt));
						(yyval.stmt) = addLabel((yyval.stmt));
						updateList((yyvsp[(3) - (5)].boolean).false, getLastCommand((yyval.stmt)));
					;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 177 "parser.y"
    {  
                                                                                          
                                                                                     nextVar = createTempVar( currentVar->type );
                                                                                    currentCommand =  translateCommand(currentCommand, 'J', "MPZ", "",  nextVar->name, "");                                                                                                   
                                                                                    (yyvsp[(3) - (10)].expression).head = mergeCommands(currentCommand  , (yyvsp[(3) - (10)].expression).head);
                                                                                     tempList = addCommandToList(NULL, getLastCommand((yyvsp[(3) - (10)].expression).head)); 
				                     (yyvsp[(3) - (10)].expression).head = addLabel((yyvsp[(3) - (10)].expression).head);
				                     updateList(tempList, getLastCommand((yyvsp[(3) - (10)].expression).head)); 
                                                                                     currentCommand = NULL;
                                                                                       *num = casevalue[0];
                                                                                     currentCommand =  translateCommand(currentCommand, currentVar->type, "EQL", currentVar->name, nextVar->name, num);                                                                                    
                                                                                      (yyvsp[(3) - (10)].expression).head =mergeCommands(currentCommand , (yyvsp[(3) - (10)].expression).head);  
                                                                                      (yyval.stmt) = mergeCommands((yyvsp[(3) - (10)].expression).head , (yyvsp[(6) - (10)].stmt));  
                                                                                      (yyval.stmt) = translateCommand((yyval.stmt),'J',"UMP","","","");   
                                                                                      tempList = addCommandToList(NULL, getLastCommand((yyval.stmt)));                                                                                                   
				                      (yyval.stmt) = mergeCommands((yyval.stmt), (yyvsp[(9) - (10)].stmt));
				                                  (yyval.stmt) = addLabel((yyval.stmt));
						                updateList(tempList, getLastCommand((yyval.stmt)));   
					;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    {                                                                                                                          
					                                          num = (yyvsp[(3) - (5)].num).value;                                                                                                                        
                                                                                                                         casevalue[p] = *num;                                                                                                                     
					                                           p++ ;		                                                                                                      
                                                                                                                        nextVar= createTempVar( currentVar->type ); 
                                                                                                                      (yyval.stmt) = translateCommand((yyval.stmt), currentVar->type, "EQL", currentVar->name, nextVar->name, num);                                                                                                     
                                                                                                                      (yyval.stmt) = translateCommand((yyval.stmt), 'J', "MPZ", "", nextVar->name, "");   
                                                                                                                              tempList  = addCommandToList(NULL, getLastCommand((yyval.stmt))); 
					                       	(yyval.stmt) = addLabel((yyval.stmt));
						                updateList(tempList, getLastCommand((yyval.stmt)));                                                 
                                                                                                                       (yyval.stmt) = mergeCommands((yyvsp[(1) - (5)].stmt), (yyvsp[(5) - (5)].stmt));                                                                             
						                       (yyval.stmt) = translateCommand((yyval.stmt),'J',"UMP","","","");
						                       tempList = addCommandToList(NULL, getLastCommand((yyval.stmt)));
                                                                                                                      (yyval.stmt) = addLabel((yyval.stmt));
						                updateList(tempList, getLastCommand((yyval.stmt)));    
						                      
                          
                                                                                                                                           ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    {(yyval.stmt) = NULL;;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    {(yyval.stmt) = NULL;;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    {(yyval.stmt) = (yyvsp[(2) - (3)].stmt);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 226 "parser.y"
    {(yyval.stmt) = mergeCommands((yyvsp[(1) - (2)].stmt), (yyvsp[(2) - (2)].stmt));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 227 "parser.y"
    {(yyval.stmt) = NULL;;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 233 "parser.y"
    {
					                         (yyval.boolean).head = translateCommand((yyvsp[(1) - (3)].boolean).head,'J',"UMP","","","");
					                          tempList = addCommandToList(NULL, getLastCommand((yyval.boolean).head));
					                         (yyval.boolean).head = addLabel((yyval.boolean).head);
					                         updateList((yyvsp[(1) - (3)].boolean).false, getLastCommand((yyval.boolean).head));
					                         (yyval.boolean).head = mergeCommands((yyval.boolean).head, (yyvsp[(3) - (3)].boolean).head);
					                         addLabel((yyval.boolean).head);
					                         updateList(tempList, getLastCommand((yyval.boolean).head));
					                         (yyval.boolean).false = (yyvsp[(3) - (3)].boolean).false;
				                                        ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    {
					 (yyval.boolean).head = (yyvsp[(1) - (1)].boolean).head;
					 (yyval.boolean).false = (yyvsp[(1) - (1)].boolean).false;
				               ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 251 "parser.y"
    {
					                              (yyval.boolean).head = mergeCommands((yyvsp[(1) - (3)].boolean).head,(yyvsp[(3) - (3)].boolean).head);
					                              (yyval.boolean).false = mergeLists((yyvsp[(1) - (3)].boolean).false, (yyvsp[(3) - (3)].boolean).false);
				                                             ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 256 "parser.y"
    {
					     (yyval.boolean).false = (yyvsp[(1) - (1)].boolean).false;
					     (yyval.boolean).head = (yyvsp[(1) - (1)].boolean).head;
				                   ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 263 "parser.y"
    {
					                                    (yyval.boolean).head = translateCommand((yyvsp[(3) - (4)].boolean).head,'J',"UMP","","","");
					                                    (yyval.boolean).false = addCommandToList(NULL,  getLastCommand((yyval.boolean).head));
					                                    addLabel((yyval.boolean).head);
					                                    updateList((yyvsp[(3) - (4)].boolean).false,  getLastCommand((yyval.boolean).head));
				                                                 ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 271 "parser.y"
    {
					                                                    if((yyvsp[(1) - (3)].expression).type == 'I' && (yyvsp[(3) - (3)].expression).type == 'R') 
						                                    (yyvsp[(1) - (3)].expression).head = floatConvert((yyvsp[(1) - (3)].expression).head, (yyvsp[(1) - (3)].expression).last);
					                                                    else if((yyvsp[(3) - (3)].expression).type == 'I' && (yyvsp[(1) - (3)].expression).type == 'R')
						                                    (yyvsp[(3) - (3)].expression).head = floatConvert((yyvsp[(3) - (3)].expression).head, (yyvsp[(3) - (3)].expression).last);
					                                                    (yyval.boolean).head = addRelopCommand((yyvsp[(2) - (3)].relop), (yyvsp[(1) - (3)].expression).last, (yyvsp[(3) - (3)].expression).last, (yyvsp[(1) - (3)].expression).head, (yyvsp[(3) - (3)].expression).head, typeUpdate((yyvsp[(1) - (3)].expression).type, (yyvsp[(3) - (3)].expression).type));
					                                                    (yyval.boolean).false = addCommandToList(NULL, getLastCommand((yyval.boolean).head));
				                                                                  ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 282 "parser.y"
    {				
					                                   (yyval.expression).type = typeUpdate((yyvsp[(1) - (3)].expression).type, (yyvsp[(3) - (3)].expression).type);
					                                   (yyval.expression).head = addArithmeticCommand((yyvsp[(2) - (3)].op), (yyval.expression).type, (yyval.expression).last, (yyvsp[(1) - (3)].expression).last, (yyvsp[(3) - (3)].expression).last, (yyvsp[(1) - (3)].expression).type, (yyvsp[(3) - (3)].expression).type, (yyvsp[(1) - (3)].expression).head, (yyvsp[(3) - (3)].expression).head);
				                                                 ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 287 "parser.y"
    {
					                                  (yyval.expression).type = (yyvsp[(1) - (1)].expression).type;
					                                  (yyval.expression).head = (yyvsp[(1) - (1)].expression).head;
					                                  strcpy((yyval.expression).last, (yyvsp[(1) - (1)].expression).last);
				                                                ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 295 "parser.y"
    {
					                         (yyval.expression).type = typeUpdate((yyvsp[(1) - (3)].expression).type, (yyvsp[(3) - (3)].expression).type);
					                         (yyval.expression).head = addArithmeticCommand((yyvsp[(2) - (3)].op), (yyval.expression).type, (yyval.expression).last, (yyvsp[(1) - (3)].expression).last, (yyvsp[(3) - (3)].expression).last, (yyvsp[(1) - (3)].expression).type, (yyvsp[(3) - (3)].expression).type, (yyvsp[(1) - (3)].expression).head, (yyvsp[(3) - (3)].expression).head);
				                                      ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 301 "parser.y"
    {
				              (yyval.expression).type = (yyvsp[(1) - (1)].expression).type;
				              (yyval.expression).head = (yyvsp[(1) - (1)].expression).head;
				               strcpy((yyval.expression).last, (yyvsp[(1) - (1)].expression).last);
				           ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 309 "parser.y"
    {

					                  (yyval.expression).type = (yyvsp[(2) - (3)].expression).type;
					                  (yyval.expression).head = (yyvsp[(2) - (3)].expression).head;
					                   strcpy((yyval.expression).last,(yyvsp[(2) - (3)].expression).last);
				                              ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 316 "parser.y"
    {
                                                                                                            number = cast((yyvsp[(1) - (4)].castOp));
                                                                                                            if(number == 1 && (yyvsp[(3) - (4)].expression).type == 'R'){
                                                                                                                     (yyval.expression).head = intConvert((yyvsp[(3) - (4)].expression).head, (yyvsp[(3) - (4)].expression).last);                                                                                                                     
                                                                                                                      (yyval.expression).type == 'I';
                                                                                                               } else if (number == 2 && (yyvsp[(3) - (4)].expression).type == 'I') {
                                                                                                                     (yyval.expression).head = floatConvert((yyvsp[(3) - (4)].expression).head, (yyvsp[(3) - (4)].expression).last);                                                                                                                    
                                                                                                                       (yyval.expression).type == 'R';

                                                                                                               } 
                                                                                                                  else { 
                                                                                                                           (yyval.expression).type = (yyvsp[(3) - (4)].expression).type;                                                                                                             
					                                           (yyval.expression).head = (yyvsp[(3) - (4)].expression).head; 
                                                                                                                          }
					                              strcpy((yyval.expression).last,(yyvsp[(3) - (4)].expression).last);
				                                          ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 334 "parser.y"
    {
				         (yyval.expression).head = NULL;
			                         if(!(currentVar = searchVar((yyvsp[(1) - (1)].id)))) 
			                           {
				             fprintf(stderr,"ERROR: unknown variable, not defined in the symbol table");
				             (yyval.expression).type = 0;
			                            }
				         else
				            {
						strcpy((yyval.expression).last, (yyvsp[(1) - (1)].id));
						(yyval.expression).type = currentVar->type;
				             }
				       ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 349 "parser.y"
    {
					strcpy((yyval.expression).last, (yyvsp[(1) - (1)].num).value);
					(yyval.expression).type = (yyvsp[(1) - (1)].num).type;
					(yyval.expression).head = NULL;
				           ;}
    break;



/* Line 1455 of yacc.c  */
#line 1889 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 355 "parser.y"


int yyerror(char *err)
{
	fprintf(stderr, "ERROR: line %d: %s\n", line,  err);
	errorExist = 1;
	return 1;
}

