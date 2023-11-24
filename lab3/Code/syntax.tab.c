/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "./syntax.y"

    	#include <stdio.h>
    	#include <string.h>
   	#include <stdarg.h>
    	#include "lex.yy.c"
    	#include "syntaxTree.h"
    	

    	void yyerror(const char* s);
    	
	int errorflag = 0;
	int lastErrorLineno = 0;
	struct Node* Root = NULL;
	
	
	//对Error的打印
	void printError(char* errorType, int lineno, char* msg);
	int isNewError(int errorLineno);





#line 94 "./syntax.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    ID = 260,
    TYPE = 261,
    RELOP = 262,
    SEMI = 263,
    COMMA = 264,
    ASSIGNOP = 265,
    PLUS = 266,
    MINUS = 267,
    STAR = 268,
    DIV = 269,
    AND = 270,
    OR = 271,
    DOT = 272,
    NOT = 273,
    LP = 274,
    RP = 275,
    LB = 276,
    RB = 277,
    LC = 278,
    RC = 279,
    STRUCT = 280,
    RETURN = 281,
    IF = 282,
    ELSE = 283,
    WHILE = 284,
    LOWER_THAN_ELSE = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "./syntax.y"

 int type_int;
 float type_float;
 double type_double;
 char* type_string;
 struct Node* type_pnode;

#line 185 "./syntax.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   503

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

#define YYUNDEFTOK  2
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    79,    83,    87,    91,    96,   101,   105,
     110,   114,   118,   123,   129,   135,   140,   147,   152,   155,
     159,   161,   167,   171,   180,   186,   194,   198,   206,   214,
     217,   221,   226,   230,   232,   236,   240,   246,   250,   254,
     258,   263,   267,   273,   280,   288,   295,   298,   301,   304,
     307,   310,   313,   316,   319,   322,   325,   328,   334,   338,
     342,   347,   350,   352,   356,   361,   362,   364,   368,   373,
     379,   384,   389,   394,   401,   406,   411,   416,   421,   427,
     432,   437,   445,   453,   459,   466,   472,   478,   484,   487,
     490,   493,   496,   499,   502,   505,   508,   511,   514,   517,
     520,   523,   526,   530,   535
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "ID", "TYPE", "RELOP",
  "SEMI", "COMMA", "ASSIGNOP", "PLUS", "MINUS", "STAR", "DIV", "AND", "OR",
  "DOT", "NOT", "LP", "RP", "LB", "RB", "LC", "RC", "STRUCT", "RETURN",
  "IF", "ELSE", "WHILE", "LOWER_THAN_ELSE", "$accept", "Program",
  "ExtDefList", "ExtDef", "ExtDecList", "Specifier", "StructSpecifier",
  "OptTag", "Tag", "VarDec", "FunDec", "VarList", "ParamDec", "CompSt",
  "StmtList", "Stmt", "DefList", "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285
};
# endif

#define YYPACT_NINF (-69)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-64)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,   -69,    13,    12,   125,    -1,    56,   -69,   -16,    -6,
       0,   -69,   -69,   -69,   -69,   -69,    31,   -69,    51,    47,
      46,    -1,    57,   123,   -69,   -69,    65,   144,    38,   -69,
      -1,   -69,    21,    49,    -1,    62,    20,    92,   -69,   116,
     124,    80,   -69,   -69,    73,   138,   -69,    48,   153,    -2,
     141,   110,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   150,
     -69,     9,   -69,   -69,    76,   -69,   -69,   159,   215,   220,
     239,   244,    84,    96,   -69,   164,    48,   386,   -69,   249,
     -69,   -69,    65,    65,   -69,   -69,   -69,   -69,   210,   154,
     482,   154,   129,   154,   152,     8,   398,   239,   268,   239,
     273,   -69,   -69,   278,   -69,   297,   302,   307,   326,   331,
     336,   355,   189,   360,   154,   447,   -69,   -69,   154,   -69,
     411,     5,   -69,   -69,   -69,   -69,   423,   171,   169,   435,
     175,   186,   154,   480,   154,   447,   154,   482,   154,   482,
     154,   129,   154,   129,   154,   469,   154,   458,   -69,   155,
     370,   239,   -69,   -69,    75,   104,    75,    87,    75,   104,
      75,    75,   -69,   -69,   -69,   177,   181,   182,   184,   198,
     -69,   -69,   -69,   -69,    75,    75,    75,    75,    75,   -69,
     -69,   -69,   -69,   -69
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,    14,     0,     0,     0,     5,     0,    15,     0,    23,
       0,    17,     1,     3,     4,    10,    24,     7,     0,     0,
       0,    59,     0,     0,     6,    13,     0,     0,     0,     9,
      59,     8,     0,     0,    59,     0,     0,    29,    28,     0,
       0,    32,    24,    12,     0,     0,    37,     0,     0,    67,
       0,     0,    20,    58,    19,    18,    16,    30,    35,    34,
      27,     0,    26,    25,     0,    86,    87,    85,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,    61,     0,
      62,    60,    66,     0,    33,    31,    47,    89,     0,   100,
      79,   101,    80,     0,     0,     0,     0,     0,     0,     0,
       0,    36,    38,     0,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    68,    65,    64,    91,    82,
     104,     0,   102,    78,    46,    42,     0,     0,     0,     0,
       0,     0,    95,    73,    92,    70,    96,    74,    97,    75,
      98,    76,    99,    77,    93,    71,    94,    72,    84,     0,
       0,     0,    90,    81,     0,    89,     0,     0,     0,    89,
       0,     0,    88,    83,   103,    49,    48,    50,     0,    43,
      55,    56,    57,    45,     0,     0,     0,     0,     0,    51,
      52,    53,    54,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -69,   -69,   212,   -69,   205,     4,   -69,   -69,   -69,     7,
     -69,   174,   -69,   216,   161,   -20,    98,   -69,    69,   -69,
     -68,    90
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    18,    32,     7,    10,    11,    49,
      20,    40,    41,    74,    75,    76,    33,    34,    50,    51,
      77,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      90,    92,    94,    96,     6,     1,   152,    21,    79,     6,
      84,   115,    12,    19,     8,     1,   124,   -21,     9,    27,
     120,    55,    48,    22,     2,   153,    42,    39,    87,   126,
     128,   129,   131,    19,     2,   133,   -22,   135,   137,   139,
     141,   143,   145,   147,    56,   150,    59,    28,    25,    64,
      23,    65,    66,    67,    29,   -11,    26,    15,    35,    24,
      68,    16,    46,     1,    17,    39,    69,    70,    27,    30,
      42,    30,   -39,    52,    71,    72,    64,    73,    65,    66,
      67,   -59,     2,   120,    86,    97,    54,    68,   168,    61,
      65,    66,    67,    69,    70,    62,    87,    99,    30,    68,
      46,    71,    72,    98,    73,    69,    70,    65,    66,    67,
      30,    82,    57,    71,    72,   100,    73,    58,   -63,    83,
      36,    42,    69,    70,    37,    -2,    13,    30,    47,     1,
      71,    72,    53,    73,   165,   166,   167,   169,   170,   171,
     172,   173,    80,    38,    60,    44,   112,    45,     2,    81,
     113,   116,   117,   122,   179,   180,   181,   182,   183,   103,
      63,    78,   105,   106,   107,   108,   109,   110,   111,   112,
     156,    27,   123,   113,    87,    87,   103,   162,    88,   105,
     106,   107,   108,   109,   110,   111,   112,   160,   101,   157,
     113,   155,    86,   103,   148,   159,   105,   106,   107,   108,
     109,   110,   111,   112,    87,   174,   161,   113,    46,   175,
     176,   118,   177,    65,    66,    67,    89,    14,    65,    66,
      67,    91,    68,    65,    66,    67,   178,    68,    69,    70,
     119,    43,    68,    69,    70,    85,    31,   102,    69,    70,
      93,   164,    65,    66,    67,    95,     0,    65,    66,    67,
     114,    68,    65,    66,    67,     0,    68,    69,    70,     0,
       0,    68,    69,    70,     0,     0,     0,    69,    70,   127,
       0,    65,    66,    67,   130,     0,    65,    66,    67,   132,
      68,    65,    66,    67,     0,    68,    69,    70,     0,     0,
      68,    69,    70,     0,     0,     0,    69,    70,   134,     0,
      65,    66,    67,   136,     0,    65,    66,    67,   138,    68,
      65,    66,    67,     0,    68,    69,    70,     0,     0,    68,
      69,    70,     0,     0,     0,    69,    70,   140,     0,    65,
      66,    67,   142,     0,    65,    66,    67,   144,    68,    65,
      66,    67,     0,    68,    69,    70,     0,     0,    68,    69,
      70,     0,     0,     0,    69,    70,   146,     0,    65,    66,
      67,   149,     0,    65,    66,    67,     0,    68,     0,     0,
       0,     0,    68,    69,    70,     0,     0,   103,    69,    70,
     105,   106,   107,   108,   109,   110,   111,   112,     0,     0,
       0,   113,   163,   103,   104,     0,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   103,   125,   113,   105,   106,
     107,   108,   109,   110,   111,   112,     0,     0,   103,   113,
     151,   105,   106,   107,   108,   109,   110,   111,   112,     0,
     103,     0,   113,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   103,   154,   113,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   103,   158,   113,   105,   106,   107,
     108,   109,   110,   111,   112,   103,     0,     0,   113,   106,
     107,   108,   109,   110,     0,   112,   103,     0,     0,   113,
     106,   107,   108,   109,     0,     0,   112,     0,     0,     0,
     113,   106,   107,   108,   109,   108,   109,   112,     0,   112,
       0,   113,     0,   113
};

static const yytype_int16 yycheck[] =
{
      68,    69,    70,    71,     0,     6,     1,    23,    10,     5,
       1,    79,     0,     6,     1,     6,     8,    23,     5,    21,
      88,     1,     1,    23,    25,    20,     5,    23,    20,    97,
      98,    99,   100,    26,    25,   103,    23,   105,   106,   107,
     108,   109,   110,   111,    24,   113,    39,     1,     1,     1,
      19,     3,     4,     5,     8,     8,     9,     1,     1,     8,
      12,     5,    24,     6,     8,    61,    18,    19,    21,    23,
       5,    23,    24,    24,    26,    27,     1,    29,     3,     4,
       5,    24,    25,   151,     8,     1,    24,    12,     1,     9,
       3,     4,     5,    18,    19,    22,    20,     1,    23,    12,
      24,    26,    27,    19,    29,    18,    19,     3,     4,     5,
      23,     1,    20,    26,    27,    19,    29,     1,     8,     9,
      22,     5,    18,    19,     1,     0,     1,    23,    30,     6,
      26,    27,    34,    29,   154,   155,   156,   157,   158,   159,
     160,   161,     1,    20,    20,     1,    17,     3,    25,     8,
      21,    82,    83,     1,   174,   175,   176,   177,   178,     7,
      22,     8,    10,    11,    12,    13,    14,    15,    16,    17,
       1,    21,    20,    21,    20,    20,     7,    22,    19,    10,
      11,    12,    13,    14,    15,    16,    17,     1,    24,    20,
      21,    20,     8,     7,     5,    20,    10,    11,    12,    13,
      14,    15,    16,    17,    20,    28,    20,    21,    24,    28,
      28,     1,    28,     3,     4,     5,     1,     5,     3,     4,
       5,     1,    12,     3,     4,     5,    28,    12,    18,    19,
      20,    26,    12,    18,    19,    61,    20,    76,    18,    19,
       1,   151,     3,     4,     5,     1,    -1,     3,     4,     5,
       1,    12,     3,     4,     5,    -1,    12,    18,    19,    -1,
      -1,    12,    18,    19,    -1,    -1,    -1,    18,    19,     1,
      -1,     3,     4,     5,     1,    -1,     3,     4,     5,     1,
      12,     3,     4,     5,    -1,    12,    18,    19,    -1,    -1,
      12,    18,    19,    -1,    -1,    -1,    18,    19,     1,    -1,
       3,     4,     5,     1,    -1,     3,     4,     5,     1,    12,
       3,     4,     5,    -1,    12,    18,    19,    -1,    -1,    12,
      18,    19,    -1,    -1,    -1,    18,    19,     1,    -1,     3,
       4,     5,     1,    -1,     3,     4,     5,     1,    12,     3,
       4,     5,    -1,    12,    18,    19,    -1,    -1,    12,    18,
      19,    -1,    -1,    -1,    18,    19,     1,    -1,     3,     4,
       5,     1,    -1,     3,     4,     5,    -1,    12,    -1,    -1,
      -1,    -1,    12,    18,    19,    -1,    -1,     7,    18,    19,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    21,    22,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,     7,     8,    21,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,     7,    21,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
       7,    -1,    21,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,     7,    20,    21,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,     7,    20,    21,    10,    11,    12,
      13,    14,    15,    16,    17,     7,    -1,    -1,    21,    11,
      12,    13,    14,    15,    -1,    17,     7,    -1,    -1,    21,
      11,    12,    13,    14,    -1,    -1,    17,    -1,    -1,    -1,
      21,    11,    12,    13,    14,    13,    14,    17,    -1,    17,
      -1,    21,    -1,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    25,    32,    33,    34,    36,    37,     1,     5,
      38,    39,     0,     1,    33,     1,     5,     8,    35,    40,
      41,    23,    23,    19,     8,     1,     9,    21,     1,     8,
      23,    44,    36,    47,    48,     1,    47,     1,    20,    36,
      42,    43,     5,    35,     1,     3,    24,    47,     1,    40,
      49,    50,    24,    47,    24,     1,    24,    20,     1,    40,
      20,     9,    22,    22,     1,     3,     4,     5,    12,    18,
      19,    26,    27,    29,    44,    45,    46,    51,     8,    10,
       1,     8,     1,     9,     1,    42,     8,    20,    19,     1,
      51,     1,    51,     1,    51,     1,    51,     1,    19,     1,
      19,    24,    45,     7,     8,    10,    11,    12,    13,    14,
      15,    16,    17,    21,     1,    51,    49,    49,     1,    20,
      51,    52,     1,    20,     8,     8,    51,     1,    51,    51,
       1,    51,     1,    51,     1,    51,     1,    51,     1,    51,
       1,    51,     1,    51,     1,    51,     1,    51,     5,     1,
      51,     9,     1,    20,    20,    20,     1,    20,    20,    20,
       1,    20,    22,    22,    52,    46,    46,    46,     1,    46,
      46,    46,    46,    46,    28,    28,    28,    28,    28,    46,
      46,    46,    46,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    32,    33,    33,    34,    34,    34,    34,
      34,    35,    35,    35,    36,    36,    37,    37,    37,    37,
      37,    38,    38,    39,    40,    40,    40,    41,    41,    41,
      41,    42,    42,    42,    43,    43,    44,    44,    45,    45,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    47,    47,
      48,    48,    48,    49,    49,    49,    49,    50,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    52,    52
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     3,     2,     3,     3,
       2,     1,     3,     2,     1,     1,     5,     2,     5,     5,
       5,     1,     0,     1,     1,     4,     4,     4,     3,     3,
       4,     3,     1,     3,     2,     2,     4,     2,     2,     0,
       2,     1,     3,     5,     7,     5,     3,     2,     5,     5,
       5,     7,     7,     7,     7,     5,     5,     5,     2,     0,
       3,     3,     3,     1,     3,     3,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     4,     3,     4,     3,     1,     1,     1,     4,     2,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 74 "./syntax.y"
                     {
            (yyval.type_pnode) = constructNode("Program", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 1, (yyvsp[0].type_pnode));
            Root = (yyval.type_pnode);
        }
#line 1662 "./syntax.tab.c"
    break;

  case 3:
#line 79 "./syntax.y"
                       {
            (yyval.type_pnode) = NULL;
        }
#line 1670 "./syntax.tab.c"
    break;

  case 4:
#line 83 "./syntax.y"
                               {
            (yyval.type_pnode) = constructNode("ExtDefList", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, (yyvsp[-1].type_pnode), (yyvsp[0].type_pnode));
        }
#line 1679 "./syntax.tab.c"
    break;

  case 5:
#line 87 "./syntax.y"
                  {
            (yyval.type_pnode) = NULL;
        }
#line 1687 "./syntax.tab.c"
    break;

  case 6:
#line 91 "./syntax.y"
                                   {
            struct Node* nodeSEMI = constructNode("SEMI", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("ExtDef", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), (yyvsp[-1].type_pnode), nodeSEMI);
        }
#line 1697 "./syntax.tab.c"
    break;

  case 7:
#line 96 "./syntax.y"
                     {
            struct Node* nodeSEMI = constructNode("SEMI", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("ExtDef", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, (yyvsp[-1].type_pnode), nodeSEMI);
        }
#line 1707 "./syntax.tab.c"
    break;

  case 8:
#line 101 "./syntax.y"
                              {
            (yyval.type_pnode) = constructNode("ExtDef", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), (yyvsp[-1].type_pnode), (yyvsp[0].type_pnode));
        }
#line 1716 "./syntax.tab.c"
    break;

  case 9:
#line 105 "./syntax.y"
                            {
            (yyval.type_pnode) = constructNode("ExtDef", NTML, (yyloc).first_line);
            struct Node* nodeSEMI = constructNode("SEMI", NVL, (yylsp[-1]).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), (yyvsp[-1].type_pnode), nodeSEMI);
        }
#line 1726 "./syntax.tab.c"
    break;

  case 10:
#line 110 "./syntax.y"
                      {
            (yyval.type_pnode) = NULL;
        }
#line 1734 "./syntax.tab.c"
    break;

  case 11:
#line 114 "./syntax.y"
                    {
            (yyval.type_pnode) = constructNode("ExtDecList", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 1, (yyvsp[0].type_pnode));
        }
#line 1743 "./syntax.tab.c"
    break;

  case 12:
#line 118 "./syntax.y"
                              {
            struct Node* nodeCOMMA = constructNode("COMMA", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("ExtDecList", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeCOMMA, (yyvsp[0].type_pnode));
        }
#line 1753 "./syntax.tab.c"
    break;

  case 13:
#line 123 "./syntax.y"
                   {
    	    (yyval.type_pnode) = NULL;
    }
#line 1761 "./syntax.tab.c"
    break;

  case 14:
#line 129 "./syntax.y"
                 {
            struct Node* nodeTYPE = constructNode("TYPE", VL, (yylsp[0]).first_line);
            nodeTYPE->Valstr = (yyvsp[0].type_string);
            (yyval.type_pnode) = constructNode("Specifier", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 1, nodeTYPE);
        }
#line 1772 "./syntax.tab.c"
    break;

  case 15:
#line 135 "./syntax.y"
                      {
            (yyval.type_pnode) = constructNode("Specifier", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 1, (yyvsp[0].type_pnode));
        }
#line 1781 "./syntax.tab.c"
    break;

  case 16:
#line 140 "./syntax.y"
                                              {
            struct Node* nodeSTRUCT = constructNode("STRUCT", NVL, (yylsp[-4]).first_line);
            struct Node* nodeLC = constructNode("LC", NVL, (yylsp[-2]).first_line);
            struct Node* nodeRC = constructNode("RC", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("StructSpecifier", NTML, (yyloc).first_line);           
            construct((yyval.type_pnode), 5, nodeSTRUCT, (yyvsp[-3].type_pnode), nodeLC, (yyvsp[-1].type_pnode), nodeRC);          
        }
#line 1793 "./syntax.tab.c"
    break;

  case 17:
#line 147 "./syntax.y"
                 {
            struct Node* nodeSTRUCT = constructNode("STRUCT", NVL, (yylsp[-1]).first_line);           
            (yyval.type_pnode) = constructNode("StructSpecifier", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, nodeSTRUCT, (yyvsp[0].type_pnode));
        }
#line 1803 "./syntax.tab.c"
    break;

  case 18:
#line 152 "./syntax.y"
                                     {
            (yyval.type_pnode) = NULL;
        }
#line 1811 "./syntax.tab.c"
    break;

  case 19:
#line 155 "./syntax.y"
                               {
            (yyval.type_pnode) = NULL;
	}
#line 1819 "./syntax.tab.c"
    break;

  case 20:
#line 159 "./syntax.y"
                                { (yyval.type_pnode) = NULL;}
#line 1825 "./syntax.tab.c"
    break;

  case 21:
#line 161 "./syntax.y"
            {
            struct Node* nodeID = constructNode("ID", VL, (yylsp[0]).first_line);
            nodeID->Valstr = (yyvsp[0].type_string);
            (yyval.type_pnode) = constructNode("OptTag", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 1, nodeID);
        }
#line 1836 "./syntax.tab.c"
    break;

  case 22:
#line 167 "./syntax.y"
                  {
            (yyval.type_pnode) = NULL;
        }
#line 1844 "./syntax.tab.c"
    break;

  case 23:
#line 171 "./syntax.y"
         {
            struct Node* nodeID =  constructNode("ID", VL, (yylsp[0]).first_line);
            nodeID->Valstr = (yyvsp[0].type_string);
            (yyval.type_pnode) = constructNode("Tag", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 1, nodeID);
        }
#line 1855 "./syntax.tab.c"
    break;

  case 24:
#line 180 "./syntax.y"
            {
            struct Node* nodeID = constructNode("ID", VL, (yylsp[0]).first_line);
            nodeID->Valstr = (yyvsp[0].type_string);
            (yyval.type_pnode) = constructNode("VarDec", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = nodeID;
        }
#line 1866 "./syntax.tab.c"
    break;

  case 25:
#line 186 "./syntax.y"
                       {
            struct Node* nodeLB = constructNode("LB", NVL, (yylsp[-2]).first_line);
            struct Node* nodeINT = constructNode("INT", VL, (yylsp[-1]).first_line);
            nodeINT->Valint = (yyvsp[-1].type_int);
            struct Node* nodeRB = constructNode("RB", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("VarDec", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 4, (yyvsp[-3].type_pnode), nodeLB, nodeINT, nodeRB);
        }
#line 1879 "./syntax.tab.c"
    break;

  case 26:
#line 194 "./syntax.y"
                         {
            (yyval.type_pnode) = NULL;
        }
#line 1887 "./syntax.tab.c"
    break;

  case 27:
#line 198 "./syntax.y"
                          {
            struct Node* nodeID = constructNode("ID", VL, (yylsp[-3]).first_line);
            nodeID->Valstr = (yyvsp[-3].type_string);
            struct Node* nodeLP = constructNode("LP", NVL, (yylsp[-2]).first_line);
            struct Node* nodeRP = constructNode("RP", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("FunDec", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 4, nodeID, nodeLP, (yyvsp[-1].type_pnode), nodeRP);
        }
#line 1900 "./syntax.tab.c"
    break;

  case 28:
#line 206 "./syntax.y"
               {
            struct Node* nodeID = constructNode("ID", VL, (yylsp[-2]).first_line);
            nodeID->Valstr = (yyvsp[-2].type_string);
            struct Node* nodeLP = constructNode("LP", NVL, (yylsp[-1]).first_line);
            struct Node* nodeRP =constructNode("RP", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("FunDec", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, nodeID, nodeLP, nodeRP);
        }
#line 1913 "./syntax.tab.c"
    break;

  case 29:
#line 214 "./syntax.y"
                  {
            (yyval.type_pnode) = NULL;
        }
#line 1921 "./syntax.tab.c"
    break;

  case 30:
#line 217 "./syntax.y"
                     {
            (yyval.type_pnode) = NULL;
        }
#line 1929 "./syntax.tab.c"
    break;

  case 31:
#line 221 "./syntax.y"
                                 {
            struct Node* nodeCOMMA = constructNode("COMMA", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("VarList", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeCOMMA, (yyvsp[0].type_pnode));
        }
#line 1939 "./syntax.tab.c"
    break;

  case 32:
#line 226 "./syntax.y"
               {
            (yyval.type_pnode) = constructNode("VarList", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = (yyvsp[0].type_pnode);
        }
#line 1948 "./syntax.tab.c"
    break;

  case 33:
#line 230 "./syntax.y"
                           { (yyval.type_pnode) = NULL;}
#line 1954 "./syntax.tab.c"
    break;

  case 34:
#line 232 "./syntax.y"
                            {
            (yyval.type_pnode) = constructNode("ParamDec", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, (yyvsp[-1].type_pnode), (yyvsp[0].type_pnode));
        }
#line 1963 "./syntax.tab.c"
    break;

  case 35:
#line 236 "./syntax.y"
                      { (yyval.type_pnode) = NULL;}
#line 1969 "./syntax.tab.c"
    break;

  case 36:
#line 240 "./syntax.y"
                                {
            struct Node* nodeLC = constructNode("LC", NVL, (yylsp[-3]).first_line);
            struct Node* nodeRC = constructNode("RC", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("CompSt", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 4, nodeLC, (yyvsp[-2].type_pnode), (yyvsp[-1].type_pnode), nodeRC);
        }
#line 1980 "./syntax.tab.c"
    break;

  case 37:
#line 246 "./syntax.y"
               {
            (yyval.type_pnode) = NULL;
        }
#line 1988 "./syntax.tab.c"
    break;

  case 38:
#line 250 "./syntax.y"
                         {
            (yyval.type_pnode) = constructNode("StmtList", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, (yyvsp[-1].type_pnode), (yyvsp[0].type_pnode));
        }
#line 1997 "./syntax.tab.c"
    break;

  case 39:
#line 254 "./syntax.y"
                  {
            (yyval.type_pnode) = NULL;
        }
#line 2005 "./syntax.tab.c"
    break;

  case 40:
#line 258 "./syntax.y"
                {
            struct Node* nodeSEMI = constructNode("SEMI", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("Stmt", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, (yyvsp[-1].type_pnode), nodeSEMI);
        }
#line 2015 "./syntax.tab.c"
    break;

  case 41:
#line 263 "./syntax.y"
             {
            (yyval.type_pnode) = constructNode("Stmt", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = (yyvsp[0].type_pnode);
        }
#line 2024 "./syntax.tab.c"
    break;

  case 42:
#line 267 "./syntax.y"
                      {
            struct Node* nodeRETURN = constructNode("RETURN", NVL, (yylsp[-2]).first_line);
            struct Node* nodeSEMI = constructNode("SEMI", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("Stmt", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, nodeRETURN, (yyvsp[-1].type_pnode), nodeSEMI);
        }
#line 2035 "./syntax.tab.c"
    break;

  case 43:
#line 273 "./syntax.y"
                                              {
            struct Node* nodeIF = constructNode("IF", NVL, (yylsp[-4]).first_line);
            struct Node* nodeLP = constructNode("LP", NVL, (yylsp[-3]).first_line);
            struct Node* nodeRP = constructNode("RP", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Stmt", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 5, nodeIF, nodeLP, (yyvsp[-2].type_pnode), nodeRP, (yyvsp[0].type_pnode));
        }
#line 2047 "./syntax.tab.c"
    break;

  case 44:
#line 280 "./syntax.y"
                                  {
            struct Node* nodeIF = constructNode("IF", NVL, (yylsp[-6]).first_line);
            struct Node* nodeLP = constructNode("LP", NVL, (yylsp[-5]).first_line);
            struct Node* nodeRP = constructNode("RP", NVL, (yylsp[-3]).first_line);
            struct Node* nodeELSE = constructNode("ELSE", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Stmt", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 7, nodeIF, nodeLP, (yyvsp[-4].type_pnode), nodeRP, (yyvsp[-2].type_pnode), nodeELSE, (yyvsp[0].type_pnode));
        }
#line 2060 "./syntax.tab.c"
    break;

  case 45:
#line 288 "./syntax.y"
                           {
            struct Node* nodeWHILE = constructNode("WHILE", NVL, (yylsp[-4]).first_line);
            struct Node* nodeLP = constructNode("LP", NVL, (yylsp[-3]).first_line);
            struct Node* nodeRP = constructNode("RP", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Stmt", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 5, nodeWHILE, nodeLP, (yyvsp[-2].type_pnode), nodeRP, (yyvsp[0].type_pnode));
        }
#line 2072 "./syntax.tab.c"
    break;

  case 46:
#line 295 "./syntax.y"
                        {
            (yyval.type_pnode) = NULL;
        }
#line 2080 "./syntax.tab.c"
    break;

  case 47:
#line 298 "./syntax.y"
                 {
            (yyval.type_pnode) = NULL;
        }
#line 2088 "./syntax.tab.c"
    break;

  case 48:
#line 301 "./syntax.y"
                                                {
            (yyval.type_pnode) = NULL;
        }
#line 2096 "./syntax.tab.c"
    break;

  case 49:
#line 304 "./syntax.y"
                                                 {
            (yyval.type_pnode) = NULL;
        }
#line 2104 "./syntax.tab.c"
    break;

  case 50:
#line 307 "./syntax.y"
                                                 {
            (yyval.type_pnode) = NULL;
        }
#line 2112 "./syntax.tab.c"
    break;

  case 51:
#line 310 "./syntax.y"
                                     {
            (yyval.type_pnode) = NULL;
        }
#line 2120 "./syntax.tab.c"
    break;

  case 52:
#line 313 "./syntax.y"
                                    {
            (yyval.type_pnode) = NULL;
        }
#line 2128 "./syntax.tab.c"
    break;

  case 53:
#line 316 "./syntax.y"
                                     {
            (yyval.type_pnode) = NULL;
        }
#line 2136 "./syntax.tab.c"
    break;

  case 54:
#line 319 "./syntax.y"
                                  {
	    (yyval.type_pnode) = NULL;    
    	}
#line 2144 "./syntax.tab.c"
    break;

  case 55:
#line 322 "./syntax.y"
                              {
            (yyval.type_pnode) = NULL;
        }
#line 2152 "./syntax.tab.c"
    break;

  case 56:
#line 325 "./syntax.y"
                             {
            (yyval.type_pnode) = NULL;
        }
#line 2160 "./syntax.tab.c"
    break;

  case 57:
#line 328 "./syntax.y"
                              {
            (yyval.type_pnode) = NULL;
        }
#line 2168 "./syntax.tab.c"
    break;

  case 58:
#line 334 "./syntax.y"
                      {
            (yyval.type_pnode) = constructNode("DefList", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, (yyvsp[-1].type_pnode), (yyvsp[0].type_pnode));
        }
#line 2177 "./syntax.tab.c"
    break;

  case 59:
#line 338 "./syntax.y"
                  {
            (yyval.type_pnode) = NULL;
        }
#line 2185 "./syntax.tab.c"
    break;

  case 60:
#line 342 "./syntax.y"
                             {
            struct Node* nodeSEMI = constructNode("SEMI", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("Def", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), (yyvsp[-1].type_pnode), nodeSEMI);
        }
#line 2195 "./syntax.tab.c"
    break;

  case 61:
#line 347 "./syntax.y"
                           {
            (yyval.type_pnode) = NULL;
        }
#line 2203 "./syntax.tab.c"
    break;

  case 62:
#line 350 "./syntax.y"
                              { (yyval.type_pnode) = NULL;}
#line 2209 "./syntax.tab.c"
    break;

  case 63:
#line 352 "./syntax.y"
              {
            (yyval.type_pnode) = constructNode("DecList", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = (yyvsp[0].type_pnode);
        }
#line 2218 "./syntax.tab.c"
    break;

  case 64:
#line 356 "./syntax.y"
                        {
            struct Node* nodeCOMMA = constructNode("COMMA", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("DecList", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeCOMMA, (yyvsp[0].type_pnode));
        }
#line 2228 "./syntax.tab.c"
    break;

  case 65:
#line 361 "./syntax.y"
                        { (yyval.type_pnode) = NULL;}
#line 2234 "./syntax.tab.c"
    break;

  case 66:
#line 362 "./syntax.y"
                { (yyval.type_pnode) = NULL;}
#line 2240 "./syntax.tab.c"
    break;

  case 67:
#line 364 "./syntax.y"
             {
            (yyval.type_pnode) = constructNode("Dec", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = (yyvsp[0].type_pnode);
        }
#line 2249 "./syntax.tab.c"
    break;

  case 68:
#line 368 "./syntax.y"
                          {
            struct Node* nodeASSIGNOP = constructNode("ASSIGNOP", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Dec", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeASSIGNOP, (yyvsp[0].type_pnode));
        }
#line 2259 "./syntax.tab.c"
    break;

  case 69:
#line 373 "./syntax.y"
                            {
            (yyval.type_pnode) = NULL;
        }
#line 2267 "./syntax.tab.c"
    break;

  case 70:
#line 379 "./syntax.y"
                       {
            struct Node* nodeASSIGNOP = constructNode("ASSIGNOP", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeASSIGNOP, (yyvsp[0].type_pnode));
        }
#line 2277 "./syntax.tab.c"
    break;

  case 71:
#line 384 "./syntax.y"
                  {
            struct Node* nodeAND = constructNode("AND", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeAND, (yyvsp[0].type_pnode));
        }
#line 2287 "./syntax.tab.c"
    break;

  case 72:
#line 389 "./syntax.y"
                 {
            struct Node* nodeOR = constructNode("OR", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeOR, (yyvsp[0].type_pnode));
        }
#line 2297 "./syntax.tab.c"
    break;

  case 73:
#line 394 "./syntax.y"
                    {
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            struct Node* nodeRELOP = constructNode("RELOP", NVL, (yylsp[-1]).first_line);
            nodeRELOP->Valstr = (yyvsp[-1].type_string);
            //printf("Relop is %s\n", nodeRELOP->Valstr);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeRELOP, (yyvsp[0].type_pnode));
        }
#line 2309 "./syntax.tab.c"
    break;

  case 74:
#line 401 "./syntax.y"
                   {
            struct Node* nodePLUS = constructNode("PLUS", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodePLUS, (yyvsp[0].type_pnode));
        }
#line 2319 "./syntax.tab.c"
    break;

  case 75:
#line 406 "./syntax.y"
                    {
            struct Node* nodeMINUS = constructNode("MINUS", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeMINUS, (yyvsp[0].type_pnode));
        }
#line 2329 "./syntax.tab.c"
    break;

  case 76:
#line 411 "./syntax.y"
                   {
            struct Node* nodeSTAR = constructNode("STAR", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeSTAR, (yyvsp[0].type_pnode));
        }
#line 2339 "./syntax.tab.c"
    break;

  case 77:
#line 416 "./syntax.y"
                  {
            struct Node* nodeDIV = constructNode("DIV", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeDIV, (yyvsp[0].type_pnode));
        }
#line 2349 "./syntax.tab.c"
    break;

  case 78:
#line 421 "./syntax.y"
                {
            struct Node* nodeLP = constructNode("LP", NVL, (yylsp[-2]).first_line);
            struct Node* nodeRP = constructNode("RP", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, nodeLP, (yyvsp[-1].type_pnode), nodeRP);
        }
#line 2360 "./syntax.tab.c"
    break;

  case 79:
#line 427 "./syntax.y"
                {
            struct Node* nodeMINUS = constructNode("MINUS", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, nodeMINUS, (yyvsp[0].type_pnode));
        }
#line 2370 "./syntax.tab.c"
    break;

  case 80:
#line 432 "./syntax.y"
              {
            struct Node* nodeNOT = constructNode("NOT", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, nodeNOT, (yyvsp[0].type_pnode));
        }
#line 2380 "./syntax.tab.c"
    break;

  case 81:
#line 437 "./syntax.y"
                    {
            struct Node* nodeID = constructNode("ID", VL, (yylsp[-3]).first_line);
            nodeID->Valstr = (yyvsp[-3].type_string);
            struct Node* nodeLP = constructNode("LP", NVL, (yylsp[-2]).first_line);
            struct Node* nodeRP = constructNode("RP", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 4, nodeID, nodeLP, (yyvsp[-1].type_pnode), nodeRP);
        }
#line 2393 "./syntax.tab.c"
    break;

  case 82:
#line 445 "./syntax.y"
               {
            struct Node* nodeID = constructNode("ID", VL, (yylsp[-2]).first_line);
            nodeID->Valstr = (yyvsp[-2].type_string);
            struct Node* nodeLP = constructNode("LP", NVL, (yylsp[-1]).first_line);
            struct Node* nodeRP = constructNode("RP", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, nodeID, nodeLP, nodeRP);
        }
#line 2406 "./syntax.tab.c"
    break;

  case 83:
#line 453 "./syntax.y"
                    {
            struct Node* nodeLB = constructNode("LB", NVL, (yylsp[-2]).first_line);
            struct Node* nodeRB = constructNode("RB", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 4, (yyvsp[-3].type_pnode), nodeLB, (yyvsp[-1].type_pnode), nodeRB);
        }
#line 2417 "./syntax.tab.c"
    break;

  case 84:
#line 459 "./syntax.y"
                 {
            struct Node* nodeDOT = constructNode("DOT", NVL, (yylsp[-1]).first_line);
            struct Node* nodeID = constructNode("ID", VL, (yylsp[0]).first_line);
            nodeID->Valstr = (yyvsp[0].type_string);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeDOT, nodeID);
        }
#line 2429 "./syntax.tab.c"
    break;

  case 85:
#line 466 "./syntax.y"
         {
            struct Node* nodeID = constructNode("ID", VL, (yylsp[0]).first_line);
            nodeID->Valstr = (yyvsp[0].type_string);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = nodeID;
        }
#line 2440 "./syntax.tab.c"
    break;

  case 86:
#line 472 "./syntax.y"
          {
            struct Node* nodeINT = constructNode("INT", VL, (yylsp[0]).first_line);
            nodeINT->Valint = (yyvsp[0].type_int);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = nodeINT;
        }
#line 2451 "./syntax.tab.c"
    break;

  case 87:
#line 478 "./syntax.y"
            {
            struct Node* nodeFLOAT = constructNode("FLOAT", VL, (yylsp[0]).first_line);
            nodeFLOAT->Valfloat = (yyvsp[0].type_float);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = nodeFLOAT;
        }
#line 2462 "./syntax.tab.c"
    break;

  case 88:
#line 484 "./syntax.y"
                      {
            (yyval.type_pnode) = NULL;
        }
#line 2470 "./syntax.tab.c"
    break;

  case 89:
#line 487 "./syntax.y"
               {
            (yyval.type_pnode) = NULL;
        }
#line 2478 "./syntax.tab.c"
    break;

  case 90:
#line 490 "./syntax.y"
                       {
            (yyval.type_pnode) = NULL;
        }
#line 2486 "./syntax.tab.c"
    break;

  case 91:
#line 493 "./syntax.y"
                  {
            (yyval.type_pnode) = NULL;
        }
#line 2494 "./syntax.tab.c"
    break;

  case 92:
#line 496 "./syntax.y"
                         {
            (yyval.type_pnode) = NULL;
        }
#line 2502 "./syntax.tab.c"
    break;

  case 93:
#line 499 "./syntax.y"
                    {
            (yyval.type_pnode) = NULL;
        }
#line 2510 "./syntax.tab.c"
    break;

  case 94:
#line 502 "./syntax.y"
                   {
            (yyval.type_pnode) = NULL;
        }
#line 2518 "./syntax.tab.c"
    break;

  case 95:
#line 505 "./syntax.y"
                      {
            (yyval.type_pnode) = NULL;
        }
#line 2526 "./syntax.tab.c"
    break;

  case 96:
#line 508 "./syntax.y"
                     {
            (yyval.type_pnode) = NULL;
        }
#line 2534 "./syntax.tab.c"
    break;

  case 97:
#line 511 "./syntax.y"
                      {
            (yyval.type_pnode) = NULL;
        }
#line 2542 "./syntax.tab.c"
    break;

  case 98:
#line 514 "./syntax.y"
                     {
            (yyval.type_pnode) = NULL;
        }
#line 2550 "./syntax.tab.c"
    break;

  case 99:
#line 517 "./syntax.y"
                    {
            (yyval.type_pnode) = NULL;
        }
#line 2558 "./syntax.tab.c"
    break;

  case 100:
#line 520 "./syntax.y"
                  {
            (yyval.type_pnode) = NULL;
        }
#line 2566 "./syntax.tab.c"
    break;

  case 101:
#line 523 "./syntax.y"
                {
            (yyval.type_pnode) = NULL;
        }
#line 2574 "./syntax.tab.c"
    break;

  case 102:
#line 526 "./syntax.y"
                   {
            (yyval.type_pnode) = NULL;
        }
#line 2582 "./syntax.tab.c"
    break;

  case 103:
#line 530 "./syntax.y"
                      {
            struct Node* nodeCOMMA = constructNode("COMMA", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Args", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeCOMMA, (yyvsp[0].type_pnode));
        }
#line 2592 "./syntax.tab.c"
    break;

  case 104:
#line 535 "./syntax.y"
          {
            (yyval.type_pnode) = constructNode("Args", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = (yyvsp[0].type_pnode);
        }
#line 2601 "./syntax.tab.c"
    break;


#line 2605 "./syntax.tab.c"

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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 541 "./syntax.y"


void yyerror(const char* s) {
	if(isNewError(yylineno)){
		fprintf(stdout, "Error type B at Line %d: %s.\n", yylineno, yytext);
		errorflag = 1;
	}
}


void printError(char* errorType, int lineno, char* msg) {
    if(isNewError(lineno)){
		fprintf(stderr, "Error type %s at Line %d: %s.\n", errorType, lineno, msg);
		errorflag = 1;
    }
}

int isNewError(int errorLineno) {
    if (lastErrorLineno != errorLineno) {
        errorflag = 1;
        lastErrorLineno = errorLineno;
        return 1;
    } else {
        return 0;
    }
}

