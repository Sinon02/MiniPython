/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "minipy-lab.y" /* yacc.c:339  */

   /* definition */
   #include <stdio.h>
   #include <ctype.h>
   #include <time.h>
   using namespace std;
   #include <iostream>
   #include <string>
   #include <vector>
   #include <map>
   #include <cmath>
   #include "lex.yy.c"
   #include <string.h>
   #include <iomanip>
   #include "types.h"
#define INIT_LIST_SIZE 10
#define INIT_TABLE_SIZE 20

TABLE *table;
int tablelen=0;
int tablesize=INIT_TABLE_SIZE;
vector<unsigned long> print_stack;


#line 91 "y.tab.c" /* yacc.c:339  */

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
    ID = 258,
    INT = 259,
    REAL = 260,
    STRING_LITERAL = 261
  };
#endif
/* Tokens.  */
#define ID 258
#define INT 259
#define REAL 260
#define STRING_LITERAL 261

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 151 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   87

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  21
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  70

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   261

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       7,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    20,     2,     2,
      15,    16,    18,     9,    17,    10,    14,    19,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    11,     2,
       2,     8,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    12,     2,    13,     2,     2,     2,     2,     2,     2,
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
       5,     6
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    29,    29,    31,    32,    33,    34,    36,    38,    41,
      60,    64,    65,    67,    68,    81,    99,   105,   106,   107,
     109,   110,   119,   120,   122,   123,   151,   180,   181,   358,
     394,   401,   403,   404,   406,   407,   410,   417,   419,   482,
     538,   540,   624,   634,   659
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INT", "REAL", "STRING_LITERAL",
  "'\\n'", "'='", "'+'", "'-'", "':'", "'['", "']'", "'.'", "'('", "')'",
  "','", "'*'", "'/'", "'%'", "$accept", "Start", "Lines", "prompt",
  "stat", "assignExpr", "number", "factor", "atom", "slice_op", "sub_expr",
  "atom_expr", "arglist", "List", "opt_comma", "List_items", "add_expr",
  "mul_expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,    10,    61,    43,
      45,    58,    91,    93,    46,    40,    41,    44,    42,    47,
      37
};
# endif

#define YYPACT_NINF -15

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-15)))

#define YYTABLE_NINF -6

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -15,     1,    33,   -15,     5,    55,   -15,   -15,   -15,   -15,
     -15,   -15,    65,    65,    44,    17,   -15,   -15,   -15,   -15,
       3,   -15,    63,    62,   -15,   -15,    64,   -15,   -15,   -11,
      63,   -15,    65,    65,    29,     4,    65,    65,    65,    65,
      65,    65,    22,   -15,   -15,    30,    13,   -15,   -15,    34,
      63,    62,    62,   -15,   -15,   -15,    63,   -15,    65,   -15,
      65,    39,    52,    63,    63,   -15,    65,    53,    63,   -15
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     0,     1,     0,     2,     6,    16,    11,    12,
      17,     7,     0,     0,     0,     0,     8,    19,    44,    24,
      15,    18,    10,    40,     4,    13,    15,    14,    32,    34,
      36,     7,     0,    22,     0,     0,     0,     0,     0,     0,
       0,    35,     0,     3,     9,     0,    23,    27,    29,    34,
      30,    38,    39,    41,    42,    43,    37,    33,    22,    26,
      35,     0,    20,    23,    31,    28,     0,     0,    21,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -15,   -15,   -15,    -6,   -15,    54,   -15,   -10,   -15,   -15,
      27,    -1,   -15,   -15,    38,   -15,   -14,    47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     5,     2,    15,    16,    17,    18,    19,    67,
      45,    26,    49,    21,    42,    29,    22,    23
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      30,     3,    25,    27,    20,    24,    41,     7,     8,     9,
      10,    32,     6,    12,    13,    33,    14,    34,    35,    46,
      48,    50,    36,    37,    31,    43,    59,    56,    53,    54,
      55,    20,    47,    -5,     4,    57,    -5,    -5,    -5,    -5,
      -5,    58,    -5,    -5,    63,    -5,    64,     7,     8,     9,
      10,    60,    68,    12,    13,    65,    14,    28,     7,     8,
       9,    10,    11,    66,    12,    13,    69,    14,     7,     8,
       9,    10,    36,    37,    12,    13,    33,    14,    34,    35,
      38,    39,    40,    51,    52,    62,    44,    61
};

static const yytype_uint8 yycheck[] =
{
      14,     0,    12,    13,     5,    11,    17,     3,     4,     5,
       6,     8,     7,     9,    10,    12,    12,    14,    15,    33,
      16,    35,     9,    10,     7,    31,    13,    41,    38,    39,
      40,    32,     3,     0,     1,    13,     3,     4,     5,     6,
       7,    11,     9,    10,    58,    12,    60,     3,     4,     5,
       6,    17,    66,     9,    10,    16,    12,    13,     3,     4,
       5,     6,     7,    11,     9,    10,    13,    12,     3,     4,
       5,     6,     9,    10,     9,    10,    12,    12,    14,    15,
      18,    19,    20,    36,    37,    58,    32,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    24,     0,     1,    23,     7,     3,     4,     5,
       6,     7,     9,    10,    12,    25,    26,    27,    28,    29,
      32,    34,    37,    38,    24,    28,    32,    28,    13,    36,
      37,     7,     8,    12,    14,    15,     9,    10,    18,    19,
      20,    17,    35,    24,    26,    31,    37,     3,    16,    33,
      37,    38,    38,    28,    28,    28,    37,    13,    11,    13,
      17,    35,    31,    37,    37,    16,    11,    30,    37,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    21,    22,    23,    23,    23,    23,    24,    25,    26,
      26,    27,    27,    28,    28,    28,    29,    29,    29,    29,
      30,    30,    31,    31,    32,    32,    32,    32,    32,    32,
      33,    33,    34,    34,    35,    35,    36,    36,    37,    37,
      37,    38,    38,    38,    38
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     3,     0,     2,     0,     1,     3,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       0,     2,     0,     1,     1,     7,     4,     3,     5,     3,
       1,     3,     2,     4,     0,     1,     1,     3,     3,     3,
       1,     3,     3,     3,     1
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
        case 6:
#line 34 "minipy-lab.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 36 "minipy-lab.y" /* yacc.c:1646  */
    {cout << "\nminiPy> ";}
#line 1277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 41 "minipy-lab.y" /* yacc.c:1646  */
    {
					switch((yyvsp[-2]).type)
					{
					case 0:
					case 1:
					case 2:
					case 3:yyerror("assign to right value");break;
					case 4:{	
							*((yyvsp[-2]).data.v)=pack((yyvsp[0]));
				 			int i=FIND((yyvsp[-2]).name);
							if(table[i].Res==1)
							{
								table[i].Res=0;
							}
							break;
					}
					case 5:if((yyvsp[0]).type==3)setslice((yyvsp[-2]).data.slice,(yyvsp[0]).data.l);else {yyerror("type error");YYERROR;}
					}
					}
#line 1301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 60 "minipy-lab.y" /* yacc.c:1646  */
    {
			print((yyvsp[0]));
			}
#line 1309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 68 "minipy-lab.y" /* yacc.c:1646  */
    {
				switch((yyvsp[0]).type)
				{
					case 0: (yyval).data.i=-(yyvsp[0]).data.i;(yyval).type=(yyvsp[0]).type;break;
					case 1: (yyval).data.f=-(yyvsp[0]).data.f;(yyval).type=(yyvsp[0]).type;break;
					case 2:	yyerror("TypeError: bad operand type for unary -: 'str'");
						YYERROR;
					case 3: yyerror("TypeError: bad operand type for unary -: 'list'");
						YYERROR;
					default: yyerror("TypeError: bad operand type");
						YYERROR;
				}	
			}
#line 1327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 81 "minipy-lab.y" /* yacc.c:1646  */
    {
			{
				switch((yyvsp[0]).type)
				{	
					case 4: 
						(yyval)=unpack(*((yyvsp[0]).data.v));
						break;
					case 5:
						(yyval).type=3;
						(yyval).data.l=slice((yyvsp[0]).data.slice); 
						break;
					default:
						break;
				}
			}
		}
#line 1348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 99 "minipy-lab.y" /* yacc.c:1646  */
    {
			(yyval).name=(char *)malloc(sizeof(char)*strlen((yyvsp[0]).data.s));
			strcpy((yyval).name,(yyvsp[0]).data.s);
			(yyval).data.v=&(table[FIND((yyvsp[0]).data.s)].val);
			(yyval).type=4;
		}
#line 1359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 109 "minipy-lab.y" /* yacc.c:1646  */
    {(yyval).type=1; (yyval).data.i=1;}
#line 1365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 110 "minipy-lab.y" /* yacc.c:1646  */
    {
			if((yyvsp[-1]).type!=0)
			{
				yyerror("type error"); 
				YYERROR;
			}
			else (yyval)=(yyvsp[0]);
			}
#line 1378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 119 "minipy-lab.y" /* yacc.c:1646  */
    {(yyval).type=-1;}
#line 1384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 120 "minipy-lab.y" /* yacc.c:1646  */
    {if((yyvsp[0]).type!=0) {yyerror("type error");YYERROR;}}
#line 1390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 123 "minipy-lab.y" /* yacc.c:1646  */
    {
				if((yyvsp[-6]).type==5)
				{
					(yyval).type=5;
					(yyval).data.slice.l=(yyvsp[-6]).data.slice.l;
					(yyval).data.slice.end=(yyvsp[-2]).type==0?((yyvsp[-6]).data.slice.begin+(yyvsp[-6]).data.slice.step*(yyvsp[-2]).data.i):(yyvsp[-6]).data.slice.end;
					(yyval).data.slice.begin+=(yyvsp[-6]).data.slice.step*((yyvsp[-4]).type==0?(yyvsp[-4]).data.i:0);
					(yyval).data.slice.step=(yyvsp[-6]).data.slice.step*(yyvsp[-1]).data.i;
				} 
				else if((yyvsp[-6]).type==3)
				{
					(yyval).data.l=slice((yyvsp[-6]).data.l,(yyvsp[-4]).type==0?(yyvsp[-4]).data.i:0,(yyvsp[-2]).type==0?(yyvsp[-2]).data.i:(yyvsp[-6]).data.l.len,(yyvsp[-1]).data.i);
					(yyval).type=3;
				}
				else if((yyvsp[-6]).type==4)
				{
					if((*((yyvsp[-6]).data.v)).flag==3)
					{
						(yyval).data.slice.l=&((*((yyvsp[-6]).data.v)).DATA.l);
						(yyval).data.slice.end=(yyvsp[-2]).type==0?(yyvsp[-2]).data.i:((*((yyvsp[-6]).data.v)).DATA.l.len);
						(yyval).data.slice.begin=(yyvsp[-4]).type==0?(yyvsp[-4]).data.i:0;
						(yyval).data.slice.step=(yyvsp[-1]).data.i;
						(yyval).type=5;
					}	
					else {yyerror("type error");YYERROR;}
				}
				else {yyerror("type error");YYERROR;}
				}
#line 1423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 151 "minipy-lab.y" /* yacc.c:1646  */
    {
				if((yyvsp[-3]).type==5)
				{
					if((yyvsp[-1]).type==0)
					{	
						(yyvsp[-1]).data.i=(yyvsp[-3]).data.slice.begin+(yyvsp[-3]).data.slice.step*(yyvsp[-1]).data.i;
						(yyvsp[-3]).type=3;(yyvsp[-3]).data.l=*((yyvsp[-3]).data.slice.l);
					}
					else
					{
						yyerror("type error");
						YYERROR;
					}
				}
				else if((yyvsp[-3]).type==4) {(yyvsp[-3])=unpack(*((yyvsp[-3]).data.v));}
				if((yyvsp[-1]).type==0&&(yyvsp[-3]).type==3)
				{
					if((yyvsp[-1]).data.i<(yyvsp[-3]).data.l.len)
					{
						(yyval).type=4;(yyval).data.v=(yyvsp[-3]).data.l.val+(yyvsp[-1]).data.i;
					}
					else yyerror("index out of bound");
				}
				else 
				{
					yyerror("type error");
					YYERROR;
				}
			}
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 180 "minipy-lab.y" /* yacc.c:1646  */
    {(yyval).name=(yyvsp[0]).data.s;}
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 181 "minipy-lab.y" /* yacc.c:1646  */
    {
			if(!strcmp((yyvsp[-4]).name,"len"))
			{
				int i=FIND((yyvsp[-4]).name);
				if(table[i].Res==0)
				{
					yyerror("TypeError: object is not callable");
					YYERROR;
				}
				int len=(yyvsp[-2]).data.l.len;
				if(len>1)
				{
					yyerror("TypeError: len() takes exactly one argument");
					YYERROR;
				}
				int type=(yyvsp[-2]).data.l.val[0].flag;
				if(type==2)
				{
					(yyval).data.i=strlen((yyvsp[-2]).data.l.val[0].DATA.s);
				}
				else if(type==3)
				{
					(yyval).data.i=(yyvsp[-2]).data.l.val[0].DATA.l.len;
				}
				else{
					yyerror("TypeError: object has no len()");
					YYERROR;
				}
				(yyval).type=0;
			}
			else if(!strcmp((yyvsp[-4]).name,"range"))
			{	
				int i=FIND((yyvsp[-4]).name);
				if(table[i].Res==0)
				{
					yyerror("TypeError: object is not callable");
					YYERROR;
				}
				int len=(yyvsp[-2]).data.l.len;
				for(i=0;i<len;i++)
				{
					if((yyvsp[-2]).data.l.val[i].flag==3)
					{
						yyerror("TypeError: range() integer end argument expected, got list.");
						YYERROR;
					}
				}
				
				if(len==1)
				{
					struct list l;
					l=newlist();
					for(int i=0;i<(yyvsp[-2]).data.l.val[0].DATA.i;i++)
					{
						VAL val;
						val.flag=0;
						val.DATA.i=i;
						append(l,val);
					}
				    (yyval).data.l=l;
					(yyval).type=3;
				}
				else if(len==2)
				{
					struct list l;
					l=newlist();
					int start=(yyvsp[-2]).data.l.val[0].DATA.i;
					int end=(yyvsp[-2]).data.l.val[1].DATA.i;
					for(int i=start;i<end;i++)
					{
						VAL val;
						val.flag=0;
						val.DATA.i=i;
						append(l,val);
					}
					(yyval).data.l=l;
					(yyval).type=3;
				}
				else if(len==3)
				{
					struct list l;
					l=newlist();
					int start=(yyvsp[-2]).data.l.val[0].DATA.i;
					int end=(yyvsp[-2]).data.l.val[1].DATA.i;
					int step=(yyvsp[-2]).data.l.val[2].DATA.i;
					for(int i=start;i!=end;i+=step)
					{
						VAL val;
						val.flag=0;
						val.DATA.i=i;
						append(l,val);
					}
					(yyval).data.l=l;
					(yyval).type=3;
				}
				else
				{
					yyerror("TypeError: range expected at most 3 arguments");
					YYERROR;
				}
			}
			else if(!strcmp((yyvsp[-4]).name,"print"))
			{
				int i=FIND((yyvsp[-4]).name);
				if(table[i].Res==0)
				{
					yyerror("TypeError: object is not callable");
					YYERROR;
				}
				int len=(yyvsp[-2]).data.l.len;
				for(int i=0;i<len;i++)
				{
					print((yyvsp[-2]).data.l.val[i]);
					cout<<" ";
				}
				yyerror("");
				YYERROR;
			}
			else if(!strcmp((yyvsp[-4]).name,"append"))
			{
				int len=(yyvsp[-2]).data.l.len;
				if(len==1)
				{
					if((yyvsp[-4]).type==4)
					append((*((yyval).data.v)).DATA.l,(yyvsp[-2]).data.l.val[0]);
					else if((yyvsp[-4]).type==3)
					append((yyval).data.l,(yyvsp[-2]).data.l.val[0]); 
					(yyval).type=-1;
				}
				else
				{
					yyerror("TypeError: append() takes exactly one argument");
					YYERROR;
				}
			}
			else if(!strcmp((yyvsp[-4]).name,"list"))
			{
				int i=FIND((yyvsp[-4]).name);
				if(table[i].Res==0)
				{
					yyerror("TypeError: object is not callable");
					YYERROR;
				}
				int len=(yyvsp[-2]).data.l.len;
				if(len>1)
				{
					yyerror("TypeError: list() takes at most 1 argument");
					YYERROR;
				}
				int type=(yyvsp[-2]).data.l.val[0].flag;
				if(type==2)
				{
					struct list l;
					l=newlist();
					int str_len=strlen((yyvsp[-2]).data.l.val[0].DATA.s);
					for(int i=0;i<str_len;i++)
					{
						VAL val;val.flag=2;val.DATA.s=(char *)malloc(sizeof(char));
						*val.DATA.s=(yyvsp[-2]).data.l.val[0].DATA.s[i];
						append(l,val);
					}
					(yyval).type=3;
					(yyval).data.l=l;
				}
				else if(type==3)
				{
					(yyval).type=3;
					(yyval).data.l=(yyvsp[-2]).data.l.val[0].DATA.l;
				}
				else
				{
					yyerror("TypeError: object is not iterable");
					YYERROR;
				}
			}
			free((yyvsp[-2]).data.l.val);
		}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 359 "minipy-lab.y" /* yacc.c:1646  */
    {
			if(!strcmp((yyvsp[-2]).name,"quit"))
			{
				int i=FIND((yyvsp[-2]).name);
				if(table[i].Res==0)
				{
					yyerror("TypeError: object is not callable");
					YYERROR;
				}
				exit(-1);
			}
			else if(!strcmp((yyvsp[-2]).name,"time"))
			{
				int i=FIND((yyvsp[-2]).name);
				if(table[i].Res==0)
				{
					yyerror("TypeError: object is not callable");
					YYERROR;
				}
				time_t t = time(NULL);
    			struct tm* stime=localtime(&t);
				char *tmp=(char*)malloc(sizeof(char)*32);
     			sprintf(tmp, "%04d-%02d-%02d %02d:%02d:%02d", 1900+stime->tm_year, 1+stime->tm_mon,stime->tm_mday, stime->tm_hour, stime->tm_min, stime->tm_sec);
				(yyval).data.s=tmp;
				(yyval).type=2;
			}
			else if(!strcmp((yyvsp[-2]).name,"list"))/*TODO:list.append(5)*/
			{
				struct list l;
				l=newlist();
				(yyval).data.l=l;
				(yyval).type=3;
			}
		}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 394 "minipy-lab.y" /* yacc.c:1646  */
    {
				struct list l;
				l=newlist();
				append(l,pack((yyvsp[0])));
				(yyval).type=3;
				(yyval).data.l=l;
			}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 401 "minipy-lab.y" /* yacc.c:1646  */
    {append((yyvsp[-2]).data.l,pack((yyvsp[0])));(yyval)=(yyvsp[-2]);}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 403 "minipy-lab.y" /* yacc.c:1646  */
    {(yyval).type=3;(yyval).data.l=newlist();}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 404 "minipy-lab.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-2]);}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 410 "minipy-lab.y" /* yacc.c:1646  */
    {
					struct list l;
					l=newlist();
					append(l,pack((yyvsp[0])));
					(yyval).type=3;
					(yyval).data.l=l;
				}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 417 "minipy-lab.y" /* yacc.c:1646  */
    {append((yyvsp[-2]).data.l,pack((yyvsp[0])));(yyval)=(yyvsp[-2]);}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 419 "minipy-lab.y" /* yacc.c:1646  */
    {
	 			if((yyvsp[-2]).type==-1||(yyvsp[0]).type==-1)
				{
					yyerror("TypeError: unsupported operand type(s) for +: 'NoneType'");
					YYERROR;
				}
	 			switch((yyvsp[-2]).type)
				{
				case 0:
					switch((yyvsp[0]).type)
					{
						case 0: (yyval).type=0;(yyval).data.i=(yyvsp[-2]).data.i+(yyvsp[0]).data.i;break;
						case 1: (yyval).type=1;(yyval).data.f=(yyvsp[-2]).data.i+(yyvsp[0]).data.f;break;
						case 2: 
						case 3: yyerror("type error");YYERROR; break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 1:
					switch((yyvsp[0]).type)
					{
						case 0: (yyval).type=1;(yyval).data.f=(yyvsp[-2]).data.f+(yyvsp[0]).data.i;break;
						case 1: (yyval).type=1;(yyval).data.f=(yyvsp[-2]).data.f+(yyvsp[0]).data.f;break;
						case 2:
						case 3: yyerror("type error");YYERROR; break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 2:
					switch((yyvsp[0]).type)
					{
					case 2:	{
						int sum_len = strlen((yyvsp[-2]).data.s)+strlen((yyvsp[0]).data.s)+1;
						char *temp = (char *)malloc(sizeof(char)*sum_len);
						sprintf(temp,"%s%s",(yyvsp[-2]).data.s,(yyvsp[0]).data.s);
						(yyval).type=2;
						(yyval).data.s=temp;  
						break;
					} 
					case 1:
					case 0:
					case 3: yyerror("type error");YYERROR; break;
					case 4:
					case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 3:
					switch((yyvsp[0]).type)
					{
						case 0: 
						case 1:
						case 2: yyerror("type error");YYERROR; break;
						case 3: (yyval).type=3;(yyval).data.l=newlist();add((yyval).data.l,(yyvsp[-2]).data.l);add((yyval).data.l,(yyvsp[0]).data.l);break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 4:
				case 5: yyerror("internal error");YYERROR;
				}
				}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 482 "minipy-lab.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).type==-1||(yyvsp[0]).type==-1)
				{
					yyerror("TypeError: unsupported operand type(s) for -: 'NoneType'");
					YYERROR;
				}
	 			switch((yyvsp[-2]).type)
				{
				case 0:
					switch((yyvsp[0]).type)
					{
						case 0: (yyval).type=0;(yyval).data.i=(yyvsp[-2]).data.i-(yyvsp[0]).data.i;break;
						case 1: (yyval).type=1;(yyval).data.f=(yyvsp[-2]).data.i-(yyvsp[0]).data.f;break;
						case 2: 
						case 3: yyerror("type error");YYERROR; break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 1:
					switch((yyvsp[0]).type)
					{
						case 0: (yyval).type=1;(yyval).data.f=(yyvsp[-2]).data.f-(yyvsp[0]).data.i;break;
						case 1: (yyval).type=1;(yyval).data.f=(yyvsp[-2]).data.f-(yyvsp[0]).data.f;break;
						case 2:
						case 3: yyerror("type error"); YYERROR;break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 2:
					switch((yyvsp[0]).type)
					{
						case 2: yyerror("TypeError: unsupported operand type(s) for -: 'str' and 'str'");YYERROR;  break; 
						case 1:
						case 0:
						case 3: yyerror("type error");YYERROR; break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 3:
					switch((yyvsp[0]).type)
					{
						case 0: 
						case 1:
						case 2: 
						case 3: yyerror("type error"); YYERROR;break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 4:
				case 5: yyerror("internal error");YYERROR;
				}
				}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 540 "minipy-lab.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).type==-1||(yyvsp[0]).type==-1)
				{
					yyerror("TypeError: unsupported operand type(s) for *: 'NoneType'");
					YYERROR;
				}
	 			switch((yyvsp[-2]).type)
				{
				case 0:
					switch((yyvsp[0]).type)
					{
						case 0: (yyval).type=0;(yyval).data.i=(yyvsp[-2]).data.i*(yyvsp[0]).data.i;break;
						case 1: (yyval).type=1;(yyval).data.f=(yyvsp[-2]).data.i*(yyvsp[0]).data.f;break;
						case 2:
							{
							int sum_len = strlen((yyvsp[0]).data.s)*(yyvsp[-2]).data.i+1;
							char *temp = (char *)malloc(sizeof(char)*sum_len);
							strcpy(temp,(yyvsp[0]).data.s);
							for(int i=0;i<(yyvsp[-2]).data.i-1;i++)
							{	
								sprintf(temp,"%s%s",temp,(yyvsp[0]).data.s);
							}
							(yyval).type=2;
							(yyval).data.s=temp;  
							break;
							} 
						case 3: (yyval).type=3;
								(yyval).data.l=newlist();
								for(int i=0;i<(yyvsp[-2]).data.i;i++) 
									add((yyval).data.l,(yyvsp[0]).data.l);
								break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 1:
					switch((yyvsp[0]).type)
					{
						case 0: (yyval).type=1;(yyval).data.f=(yyvsp[-2]).data.f*(yyvsp[0]).data.i;break;
						case 1: (yyval).type=1;(yyval).data.f=(yyvsp[-2]).data.f*(yyvsp[0]).data.f;break;
						case 2:
						case 3: yyerror("type error");YYERROR; break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 2:
					switch((yyvsp[0]).type)
					{
						case 0: 
						{
							int sum_len = strlen((yyvsp[-2]).data.s)*(yyvsp[0]).data.i+1;
							char *temp = (char *)malloc(sizeof(char)*sum_len);
							strcpy(temp,(yyvsp[-2]).data.s);
							for(int i=0;i<(yyvsp[0]).data.i-1;i++)
							{	
								sprintf(temp,"%s%s",temp,(yyvsp[-2]).data.s);
							}
							(yyval).type=2;
							(yyval).data.s=temp;  
							break;
						}
						case 1:
						case 2:
						case 3: yyerror("type error");YYERROR; break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 3:
					switch((yyvsp[0]).type)
					{
						case 0: (yyval).type=3;(yyval).data.l=newlist();for(int i=0;i<(yyvsp[0]).data.i;i++) add((yyval).data.l,(yyvsp[-2]).data.l); break;
						case 1:
						case 2:
						case 3: yyerror("type error"); YYERROR;break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 4:
				case 5: yyerror("internal error");YYERROR;
				}
				}
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 624 "minipy-lab.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).type==-1||(yyvsp[0]).type==-1)
				{
					yyerror("TypeError: unsupported operand type(s) for /: 'NoneType'");
					YYERROR;
				}
				if((yyvsp[-2]).type<2&&(yyvsp[0]).type<2) {(yyval).type=1;(yyval).data.f=((yyvsp[-2]).type?(yyvsp[-2]).data.f:(yyvsp[-2]).data.i)/((yyvsp[0]).type?(yyvsp[0]).data.f:(yyvsp[0]).data.i);}

				else {yyerror("type error");YYERROR;};
				}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 634 "minipy-lab.y" /* yacc.c:1646  */
    {
					if((yyvsp[-2]).type==-1||(yyvsp[0]).type==-1)
					{
						yyerror("TypeError: unsupported operand type(s) for /: 'NoneType'");
						YYERROR;
					}	
					if((yyvsp[-2]).type<2&&(yyvsp[0]).type<2)
					{
						if((yyvsp[-2]).type==0&&(yyvsp[0]).type==0)
						{
							(yyval).type=0;
							(yyval).data.i=MOD((yyvsp[-2]).data.i,(yyvsp[0]).data.i);
						}
						else
						{
							(yyval).type=1;
							(yyval).data.f=FMOD((yyvsp[-2]).type?(yyvsp[-2]).data.f:(yyvsp[-2]).data.i,(yyvsp[0]).type?(yyvsp[0]).data.f:(yyvsp[0]).data.i);
						}
					}
					else
					{
						yyerror("TypeError");
						YYERROR;
					}
				}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1999 "y.tab.c" /* yacc.c:1646  */
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
#line 662 "minipy-lab.y" /* yacc.c:1906  */


int main()
{	int i;
   	int FuncNum=10;
	table=(TABLE*)malloc(INIT_TABLE_SIZE*sizeof(TABLE));
	for(i=0;i<FuncNum;i++)
	{
		table[i].Res=1;
		table[i].name=(char *)malloc(sizeof(char)*10);
	}
	strcpy(table[0].name,"len");
	strcpy(table[1].name,"time");
	strcpy(table[2].name,"list");
	strcpy(table[3].name,"print");
	strcpy(table[4].name,"range");
	strcpy(table[5].name,"quit");
    
	tablelen=10;
	return yyparse();
}

void yyerror(const char *s)
{
   cout << s << endl<<"miniPy> "; 
}

int yywrap()
{ return 1; }        		    

VAL pack(YYSTYPE val)
{
	VAL r;
	switch(val.type)
	{
	default:
		r.flag=val.type;
		r.DATA=*((union vald*)(&(val.data)));
		break;
	case 4:
		r=*(val.data.v);
		break;
	case 5:
		r.flag=3;
		r.DATA.l=slice(val.data.slice);
		break;
	}
	return r;
}

YYSTYPE unpack(VAL val)
{
	YYSTYPE r;
	r.type=val.flag;
	r.data=*((union yyd*)(&(val.DATA)));
	return r;
}

int FIND(char *s)
{
	int i =0;
	for(i=0;i<tablelen;i++) if(!strcmp(s,table[i].name))
	{
		free(s);
		return i;
	} 
	if(tablelen>=tablesize)
	{
		tablesize*=2;
		table=(TABLE*)realloc(table,tablesize);
	}
	table[tablelen].name=s;
	table[tablelen].val.flag=-1;
	tablelen++;
	return i;
}

void print(VAL val)
{
	int i;
	switch(val.flag)
	{
		case -1:
			cout<<"None";
			break;
		case 0:
			cout<<val.DATA.i;
			break;
		case 1:
			PrintFloat(val.DATA.f);
			break;
		case 2:
			cout<<"'"<<val.DATA.s<<"'";
			break;
		case 3:
			for(auto& p : print_stack)
			{
				if(p==*(unsigned long *)(&val.DATA.l.val))
				{
					cout<<"[...]";
					return;
				}
			}
			print_stack.push_back(*(unsigned long *)(&val.DATA.l.val));
			cout<<'[';
			if(val.DATA.l.len>0) print(val.DATA.l.val[0]);
			for(i=1;i<val.DATA.l.len;i++)
			{
				cout<<", ";
				print(val.DATA.l.val[i]);
			}
			cout<<']';
			print_stack.pop_back();
			break;
	}
}

inline void print(YYSTYPE val)
{
	print(pack(val));
}

struct list newlist()  //TODO:gc
{
	struct list l;
	l.len=0;
	l.size=INIT_LIST_SIZE;
	l.val=(VAL*)malloc(INIT_LIST_SIZE*sizeof(VAL));
	if(l.val==0) 
	{
		yyerror("malloc fail");
	}
	return l;
}

void exlist(struct list &l) //extend
{
	l.size*=2;
	l.val=(VAL*)realloc(l.val,l.size*sizeof(VAL));
	if(l.val==0) 
	{
		yyerror("malloc fail");
	}
	return;
}

void append(struct list &l,VAL _val)
{
	if(l.len>=l.size) exlist(l);
	l.val[l.len++]=_val;
}

void add(struct list &l,struct list o)
{
	int i;
	while(l.len+o.len-1>=l.size) exlist(l);
	for(i=0;i<o.len;i++)l.val[l.len++]=o.val[i];
}

void insert(struct list &l,int index,VAL _val)
{
	int i;
	if(index>l.len) 
	{
		yyerror("index out of bound");
	}
	if(l.len>=l.size) exlist(l);
	for(i=l.len;i>index;i--) l.val[i]=l.val[i-1];
	l.len++;
	l.val[index]=_val;
}

VAL pop(struct list &l,int index)
{
	int i;
	VAL _val=l.val[index];
	for(i=index+1;i<l.len;i++) l.val[i-1]=l.val[i];
	l.len--;
	return _val;
}

struct list slice(struct list l,int begin,int end,int step)
{
	struct list _val;
	int i;
	_val=newlist();
	while(begin<0) begin+=l.len;
	while(end<0) begin+=l.len;
	for(i=begin;i<end;i+=step) append(_val,l.val[i]);
	return _val;
}

inline struct list slice(struct slice s)
{
	return slice(*(s.l),s.begin,s.end,s.step);
}

void setslice(struct list &l,int begin,int end,int step,struct list o)
{
	int i,j;
	if(begin<0||step<1||end>l.len) yyerror("index out of bound");
	if(step!=1)
	{
		if((int)ceil((double)(end-begin)/step)!=o.len) yyerror("incompatible length");
		for(i=begin,j=0;i<end;i+=step) l.val[i]=o.val[j++];
	}
	else//step=1
	{
		if(end-begin>o.len)
		{
			while(l.len+o.len-end+begin-1>=l.size) exlist(l);
			for(i=l.len+o.len-1-end+begin,j=l.len-1;j>=end;i--,j--) l.val[i]=l.val[j];
		}
		else if(end-begin<o.len)
		{
			for(i=begin+o.len,j=end;j<l.len;i++,j++) l.val[i]=l.val[j];

		}
		for(i=begin,j=0;j<o.len;i++,j++) l.val[i]=o.val[j]; 
		l.len=l.len+o.len-end+begin;
	}
	return;
}

inline void setslice(struct slice s,struct list o)
{
	setslice(*(s.l),s.begin,s.end,s.step,o);
	return;
}

int MOD(int n,int M)
{
	return (n%M+M)%M; 
}

float FMOD(float n,float M)
{
	return fmod(fmod(n,M)+M,M);
}

void PrintFloat(float a)
{
    std::streamsize ss = std::cout.precision();
	if(a==(int)a)
	{	
		std::cout<<std::setprecision(1)<<std::fixed<<a;
	}
	else
	{
		std::cout<<a;
	}
    	std::cout << std::defaultfloat << std::setprecision(ss);
}
