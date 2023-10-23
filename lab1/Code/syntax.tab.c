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
#line 2 "syntax.y"

    #include <stdio.h>
    #include <string.h>
    #include <stdarg.h>
    #include "lex.yy.c"

    void yyerror(const char* s);

    int errorflag = 0;
    int lastErrorLineno = 0;

    enum NodeType { NTML, NVL, VL };
    struct Node {
        char* nodeName;
        enum NodeType nodeType;
        int lineNum;
        union {
            int Valint;
            float Valfloat;
            char* Valstr;
        };
        struct Node* firstChild;
        struct Node* bro;
    };

    struct Node* Root = NULL;

    struct Node* constructNode(char* nodeName, enum NodeType nodeType, int lineNum);
    void construct(struct Node* fatherNode, int index, ...);
    void Print_Tree(struct Node* rootNode,int SpaceNum);
    void destroyTree(struct Node* rootNode);

    void printError(char errorType, int lineno, char* msg);
    int isNewError(int errorLineno);

#line 106 "syntax.tab.c"

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
    SEMI = 262,
    COMMA = 263,
    RELOP = 264,
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
#line 39 "syntax.y"

 int type_int;
 float type_float;
 double type_double;
 char* type_string;
 struct Node* type_pnode;

#line 197 "syntax.tab.c"

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
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

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
       0,    86,    86,    91,    95,    99,   103,   108,   113,   117,
     121,   125,   130,   136,   142,   147,   154,   159,   162,   166,
     168,   174,   178,   187,   193,   201,   205,   213,   221,   224,
     228,   233,   237,   239,   243,   247,   253,   257,   261,   265,
     270,   274,   280,   287,   295,   302,   305,   308,   311,   314,
     317,   320,   323,   326,   329,   332,   335,   341,   345,   349,
     354,   357,   359,   363,   368,   369,   371,   375,   380,   386,
     391,   396,   401,   406,   411,   416,   421,   426,   432,   437,
     442,   450,   458,   464,   471,   477,   483,   489,   492,   495,
     498,   501,   504,   507,   510,   513,   516,   519,   522,   525,
     528,   531,   535,   540
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "ID", "TYPE", "SEMI",
  "COMMA", "RELOP", "ASSIGNOP", "PLUS", "MINUS", "STAR", "DIV", "AND",
  "OR", "DOT", "NOT", "LP", "RP", "LB", "RB", "LC", "RC", "STRUCT",
  "RETURN", "IF", "ELSE", "WHILE", "LOWER_THAN_ELSE", "$accept", "Program",
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

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-63)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,   -68,    12,     7,   171,     0,   144,   -68,    46,    65,
      71,   -68,   -68,   -68,   -68,   -68,     5,   -68,    78,   110,
      57,     0,    43,   122,   -68,   -68,    91,    54,    95,     0,
     -68,    11,   100,     0,   161,     9,    90,   -68,    14,   107,
     135,   -68,   -68,   146,   167,   -68,    47,   181,   104,    55,
      53,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   169,   -68,
      22,   -68,   -68,    75,   -68,   -68,   172,   209,   214,   233,
     238,    62,    83,   -68,   177,    47,   367,   -68,   243,   -68,
     -68,    91,    91,   -68,   -68,   -68,   -68,   204,   182,   482,
     182,    99,   182,   149,     1,   380,   233,   262,   233,   267,
     -68,   -68,   -68,   272,   291,   296,   301,   320,   325,   330,
     349,   201,   354,   182,   447,   -68,   -68,   182,   -68,   394,
      52,   -68,   -68,   -68,   -68,   421,   191,   166,   434,   200,
     183,   182,   480,   182,   447,   182,   482,   182,   482,   182,
      99,   182,    99,   182,   469,   182,   458,   -68,   124,   407,
     233,   -68,   -68,    74,   103,    74,    86,    74,   103,    74,
      74,   -68,   -68,   -68,   197,   202,   203,    -2,   207,   -68,
     -68,   -68,   -68,    74,    74,    74,    74,    74,   -68,   -68,
     -68,   -68,   -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,    13,     0,     0,     0,     5,     0,    14,     0,    22,
       0,    16,     1,     3,     4,     9,    23,     7,     0,     0,
       0,    58,     0,     0,     6,    12,     0,     0,     0,    58,
       8,     0,     0,    58,     0,     0,    28,    27,     0,     0,
      31,    23,    11,     0,     0,    36,     0,     0,    66,     0,
       0,    19,    57,    18,    17,    15,    29,    34,    33,    26,
       0,    25,    24,     0,    85,    86,    84,     0,     0,     0,
       0,     0,     0,    40,     0,     0,     0,    60,     0,    61,
      59,    65,     0,    32,    30,    46,    88,     0,    99,    78,
     100,    79,     0,     0,     0,     0,     0,     0,     0,     0,
      35,    37,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,    67,    64,    63,    90,    81,   103,
       0,   101,    77,    45,    41,     0,     0,     0,     0,     0,
       0,    94,    72,    91,    69,    95,    73,    96,    74,    97,
      75,    98,    76,    92,    70,    93,    71,    83,     0,     0,
       0,    89,    80,     0,    88,     0,     0,     0,    88,     0,
       0,    87,    82,   102,    48,    47,    49,     0,    42,    54,
      55,    56,    44,     0,     0,     0,     0,     0,    50,    51,
      52,    53,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   224,   -68,   223,     4,   -68,   -68,   -68,     8,
     -68,   180,   -68,   234,   178,   -20,   119,   -68,    92,   -68,
     -67,   108
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    18,    31,     7,    10,    11,    48,
      20,    39,    40,    73,    74,    75,    32,    33,    49,    50,
      76,   120
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      89,    91,    93,    95,     6,    85,     1,    12,   123,     6,
      54,   114,    47,     8,    19,    57,    41,     9,    86,    41,
     119,    86,    45,    83,    23,     2,   176,    38,     1,   125,
     127,   128,   130,    55,    19,   -21,   132,   134,   136,   138,
     140,   142,   144,   146,    34,   149,    58,     2,    63,     1,
      64,    65,    66,   151,    81,    43,    79,    44,    28,    67,
     -62,    82,    80,    96,    38,    68,    69,   -58,     2,    21,
      29,   -38,   152,    70,    71,    63,    72,    64,    65,    66,
      29,    97,    85,   119,    98,    24,    67,   167,   -20,    64,
      65,    66,    68,    69,    22,    86,    41,    29,    67,    45,
      70,    71,    99,    72,    68,    69,    64,    65,    66,    29,
      56,    25,    70,    71,    78,    72,   111,   -10,    26,    45,
     112,    68,    69,    36,    51,    27,    29,    59,     1,    70,
      71,    27,    72,   164,   165,   166,   168,   169,   170,   171,
     172,    35,    37,    60,    86,    15,   161,     2,    46,    16,
     121,    17,    52,   178,   179,   180,   181,   182,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   155,    61,   122,
     112,    -2,    13,   115,   116,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   159,    53,   156,   112,    77,    62,
      27,    87,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   100,    86,   160,   112,   117,   147,    64,    65,    66,
      88,   154,    64,    65,    66,    90,    67,    64,    65,    66,
     158,    67,    68,    69,   118,   173,    67,    68,    69,    14,
     174,   175,    68,    69,    92,   177,    64,    65,    66,    94,
      84,    64,    65,    66,   113,    67,    64,    65,    66,    42,
      67,    68,    69,   101,    30,    67,    68,    69,   163,     0,
       0,    68,    69,   126,     0,    64,    65,    66,   129,     0,
      64,    65,    66,   131,    67,    64,    65,    66,     0,    67,
      68,    69,     0,     0,    67,    68,    69,     0,     0,     0,
      68,    69,   133,     0,    64,    65,    66,   135,     0,    64,
      65,    66,   137,    67,    64,    65,    66,     0,    67,    68,
      69,     0,     0,    67,    68,    69,     0,     0,     0,    68,
      69,   139,     0,    64,    65,    66,   141,     0,    64,    65,
      66,   143,    67,    64,    65,    66,     0,    67,    68,    69,
       0,     0,    67,    68,    69,     0,     0,     0,    68,    69,
     145,     0,    64,    65,    66,   148,     0,    64,    65,    66,
       0,    67,     0,     0,     0,     0,    67,    68,    69,     0,
       0,     0,    68,    69,   102,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,     0,   124,   112,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,     0,
       0,   112,   150,   103,   104,   105,   106,   107,   108,   109,
     110,   111,     0,     0,     0,   112,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,     0,     0,   112,   162,
     103,   104,   105,   106,   107,   108,   109,   110,   111,     0,
       0,   153,   112,   103,   104,   105,   106,   107,   108,   109,
     110,   111,     0,     0,   157,   112,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,     0,   103,   112,   105,
     106,   107,   108,   109,     0,   111,     0,     0,   103,   112,
     105,   106,   107,   108,     0,     0,   111,     0,     0,     0,
     112,   105,   106,   107,   108,   107,   108,   111,     0,   111,
       0,   112,     0,   112
};

static const yytype_int16 yycheck[] =
{
      67,    68,    69,    70,     0,     7,     6,     0,     7,     5,
       1,    78,     1,     1,     6,     1,     5,     5,    20,     5,
      87,    20,    24,     1,    19,    25,    28,    23,     6,    96,
      97,    98,    99,    24,    26,    23,   103,   104,   105,   106,
     107,   108,   109,   110,     1,   112,    38,    25,     1,     6,
       3,     4,     5,     1,     1,     1,     1,     3,     1,    12,
       7,     8,     7,     1,    60,    18,    19,    24,    25,    23,
      23,    24,    20,    26,    27,     1,    29,     3,     4,     5,
      23,    19,     7,   150,     1,     7,    12,     1,    23,     3,
       4,     5,    18,    19,    23,    20,     5,    23,    12,    24,
      26,    27,    19,    29,    18,    19,     3,     4,     5,    23,
      20,     1,    26,    27,    10,    29,    17,     7,     8,    24,
      21,    18,    19,     1,    24,    21,    23,    20,     6,    26,
      27,    21,    29,   153,   154,   155,   156,   157,   158,   159,
     160,    22,    20,     8,    20,     1,    22,    25,    29,     5,
       1,     7,    33,   173,   174,   175,   176,   177,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     1,    22,    20,
      21,     0,     1,    81,    82,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     1,    24,    20,    21,     7,    22,
      21,    19,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    24,    20,    20,    21,     1,     5,     3,     4,     5,
       1,    20,     3,     4,     5,     1,    12,     3,     4,     5,
      20,    12,    18,    19,    20,    28,    12,    18,    19,     5,
      28,    28,    18,    19,     1,    28,     3,     4,     5,     1,
      60,     3,     4,     5,     1,    12,     3,     4,     5,    26,
      12,    18,    19,    75,    20,    12,    18,    19,   150,    -1,
      -1,    18,    19,     1,    -1,     3,     4,     5,     1,    -1,
       3,     4,     5,     1,    12,     3,     4,     5,    -1,    12,
      18,    19,    -1,    -1,    12,    18,    19,    -1,    -1,    -1,
      18,    19,     1,    -1,     3,     4,     5,     1,    -1,     3,
       4,     5,     1,    12,     3,     4,     5,    -1,    12,    18,
      19,    -1,    -1,    12,    18,    19,    -1,    -1,    -1,    18,
      19,     1,    -1,     3,     4,     5,     1,    -1,     3,     4,
       5,     1,    12,     3,     4,     5,    -1,    12,    18,    19,
      -1,    -1,    12,    18,    19,    -1,    -1,    -1,    18,    19,
       1,    -1,     3,     4,     5,     1,    -1,     3,     4,     5,
      -1,    12,    -1,    -1,    -1,    -1,    12,    18,    19,    -1,
      -1,    -1,    18,    19,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,     7,    21,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    21,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    21,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    21,    22,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    20,    21,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    20,    21,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,     9,    21,    11,
      12,    13,    14,    15,    -1,    17,    -1,    -1,     9,    21,
      11,    12,    13,    14,    -1,    -1,    17,    -1,    -1,    -1,
      21,    11,    12,    13,    14,    13,    14,    17,    -1,    17,
      -1,    21,    -1,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    25,    32,    33,    34,    36,    37,     1,     5,
      38,    39,     0,     1,    33,     1,     5,     7,    35,    40,
      41,    23,    23,    19,     7,     1,     8,    21,     1,    23,
      44,    36,    47,    48,     1,    47,     1,    20,    36,    42,
      43,     5,    35,     1,     3,    24,    47,     1,    40,    49,
      50,    24,    47,    24,     1,    24,    20,     1,    40,    20,
       8,    22,    22,     1,     3,     4,     5,    12,    18,    19,
      26,    27,    29,    44,    45,    46,    51,     7,    10,     1,
       7,     1,     8,     1,    42,     7,    20,    19,     1,    51,
       1,    51,     1,    51,     1,    51,     1,    19,     1,    19,
      24,    45,     7,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    21,     1,    51,    49,    49,     1,    20,    51,
      52,     1,    20,     7,     7,    51,     1,    51,    51,     1,
      51,     1,    51,     1,    51,     1,    51,     1,    51,     1,
      51,     1,    51,     1,    51,     1,    51,     5,     1,    51,
       8,     1,    20,    20,    20,     1,    20,    20,    20,     1,
      20,    22,    22,    52,    46,    46,    46,     1,    46,    46,
      46,    46,    46,    28,    28,    28,    28,    28,    46,    46,
      46,    46,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    32,    33,    33,    34,    34,    34,    34,
      35,    35,    35,    36,    36,    37,    37,    37,    37,    37,
      38,    38,    39,    40,    40,    40,    41,    41,    41,    41,
      42,    42,    42,    43,    43,    44,    44,    45,    45,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    47,    47,    48,
      48,    48,    49,    49,    49,    49,    50,    50,    50,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    52,    52
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     3,     2,     3,     2,
       1,     3,     2,     1,     1,     5,     2,     5,     5,     5,
       1,     0,     1,     1,     4,     4,     4,     3,     3,     4,
       3,     1,     3,     2,     2,     4,     2,     2,     0,     2,
       1,     3,     5,     7,     5,     3,     2,     5,     5,     5,
       7,     7,     7,     7,     5,     5,     5,     2,     0,     3,
       3,     3,     1,     3,     3,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       4,     3,     4,     3,     1,     1,     1,     4,     2,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     3,     1
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
#line 86 "syntax.y"
                     {
            (yyval.type_pnode) = constructNode("Program", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 1, (yyvsp[0].type_pnode));
            Root = (yyval.type_pnode);
        }
#line 1674 "syntax.tab.c"
    break;

  case 3:
#line 91 "syntax.y"
                       {
            (yyval.type_pnode) = NULL;
        }
#line 1682 "syntax.tab.c"
    break;

  case 4:
#line 95 "syntax.y"
                               {
            (yyval.type_pnode) = constructNode("ExtDefList", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, (yyvsp[-1].type_pnode), (yyvsp[0].type_pnode));
        }
#line 1691 "syntax.tab.c"
    break;

  case 5:
#line 99 "syntax.y"
                  {
            (yyval.type_pnode) = NULL;
        }
#line 1699 "syntax.tab.c"
    break;

  case 6:
#line 103 "syntax.y"
                                   {
            struct Node* nodeSEMI = constructNode("SEMI", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("ExtDef", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), (yyvsp[-1].type_pnode), nodeSEMI);
        }
#line 1709 "syntax.tab.c"
    break;

  case 7:
#line 108 "syntax.y"
                     {
            struct Node* nodeSEMI = constructNode("SEMI", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("ExtDef", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, (yyvsp[-1].type_pnode), nodeSEMI);
        }
#line 1719 "syntax.tab.c"
    break;

  case 8:
#line 113 "syntax.y"
                              {
            (yyval.type_pnode) = constructNode("ExtDef", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), (yyvsp[-1].type_pnode), (yyvsp[0].type_pnode));
        }
#line 1728 "syntax.tab.c"
    break;

  case 9:
#line 117 "syntax.y"
                      {
            (yyval.type_pnode) = NULL;
        }
#line 1736 "syntax.tab.c"
    break;

  case 10:
#line 121 "syntax.y"
                    {
            (yyval.type_pnode) = constructNode("ExtDecList", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 1, (yyvsp[0].type_pnode));
        }
#line 1745 "syntax.tab.c"
    break;

  case 11:
#line 125 "syntax.y"
                              {
            struct Node* nodeCOMMA = constructNode("COMMA", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("ExtDecList", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeCOMMA, (yyvsp[0].type_pnode));
        }
#line 1755 "syntax.tab.c"
    break;

  case 12:
#line 130 "syntax.y"
                   {
    	    (yyval.type_pnode) = NULL;
    }
#line 1763 "syntax.tab.c"
    break;

  case 13:
#line 136 "syntax.y"
                 {
            struct Node* nodeTYPE = constructNode("TYPE", VL, (yylsp[0]).first_line);
            nodeTYPE->Valstr = (yyvsp[0].type_string);
            (yyval.type_pnode) = constructNode("Specifier", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 1, nodeTYPE);
        }
#line 1774 "syntax.tab.c"
    break;

  case 14:
#line 142 "syntax.y"
                      {
            (yyval.type_pnode) = constructNode("Specifier", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 1, (yyvsp[0].type_pnode));
        }
#line 1783 "syntax.tab.c"
    break;

  case 15:
#line 147 "syntax.y"
                                              {
            struct Node* nodeSTRUCT = constructNode("STRUCT", NVL, (yylsp[-4]).first_line);
            struct Node* nodeLC = constructNode("LC", NVL, (yylsp[-2]).first_line);
            struct Node* nodeRC = constructNode("RC", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("StructSpecifier", NTML, (yyloc).first_line);           
            construct((yyval.type_pnode), 5, nodeSTRUCT, (yyvsp[-3].type_pnode), nodeLC, (yyvsp[-1].type_pnode), nodeRC);          
        }
#line 1795 "syntax.tab.c"
    break;

  case 16:
#line 154 "syntax.y"
                 {
            struct Node* nodeSTRUCT = constructNode("STRUCT", NVL, (yylsp[-1]).first_line);           
            (yyval.type_pnode) = constructNode("StructSpecifier", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, nodeSTRUCT, (yyvsp[0].type_pnode));
        }
#line 1805 "syntax.tab.c"
    break;

  case 17:
#line 159 "syntax.y"
                                     {
            (yyval.type_pnode) = NULL;
        }
#line 1813 "syntax.tab.c"
    break;

  case 18:
#line 162 "syntax.y"
                               {
            (yyval.type_pnode) = NULL;
	}
#line 1821 "syntax.tab.c"
    break;

  case 19:
#line 166 "syntax.y"
                                { (yyval.type_pnode) = NULL;}
#line 1827 "syntax.tab.c"
    break;

  case 20:
#line 168 "syntax.y"
            {
            struct Node* nodeID = constructNode("ID", VL, (yylsp[0]).first_line);
            nodeID->Valstr = (yyvsp[0].type_string);
            (yyval.type_pnode) = constructNode("OptTag", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 1, nodeID);
        }
#line 1838 "syntax.tab.c"
    break;

  case 21:
#line 174 "syntax.y"
                  {
            (yyval.type_pnode) = NULL;
        }
#line 1846 "syntax.tab.c"
    break;

  case 22:
#line 178 "syntax.y"
         {
            struct Node* nodeID =  constructNode("ID", VL, (yylsp[0]).first_line);
            nodeID->Valstr = (yyvsp[0].type_string);
            (yyval.type_pnode) = constructNode("Tag", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 1, nodeID);
        }
#line 1857 "syntax.tab.c"
    break;

  case 23:
#line 187 "syntax.y"
            {
            struct Node* nodeID = constructNode("ID", VL, (yylsp[0]).first_line);
            nodeID->Valstr = (yyvsp[0].type_string);
            (yyval.type_pnode) = constructNode("VarDec", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = nodeID;
        }
#line 1868 "syntax.tab.c"
    break;

  case 24:
#line 193 "syntax.y"
                       {
            struct Node* nodeLB = constructNode("LB", NVL, (yylsp[-2]).first_line);
            struct Node* nodeINT = constructNode("INT", VL, (yylsp[-1]).first_line);
            nodeINT->Valint = (yyvsp[-1].type_int);
            struct Node* nodeRB = constructNode("RB", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("VarDec", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 4, (yyvsp[-3].type_pnode), nodeLB, nodeINT, nodeRB);
        }
#line 1881 "syntax.tab.c"
    break;

  case 25:
#line 201 "syntax.y"
                         {
            (yyval.type_pnode) = NULL;
        }
#line 1889 "syntax.tab.c"
    break;

  case 26:
#line 205 "syntax.y"
                          {
            struct Node* nodeID = constructNode("ID", VL, (yylsp[-3]).first_line);
            nodeID->Valstr = (yyvsp[-3].type_string);
            struct Node* nodeLP = constructNode("LP", NVL, (yylsp[-2]).first_line);
            struct Node* nodeRP = constructNode("RP", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("FunDec", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 4, nodeID, nodeLP, (yyvsp[-1].type_pnode), nodeRP);
        }
#line 1902 "syntax.tab.c"
    break;

  case 27:
#line 213 "syntax.y"
               {
            struct Node* nodeID = constructNode("ID", VL, (yylsp[-2]).first_line);
            nodeID->Valstr = (yyvsp[-2].type_string);
            struct Node* nodeLP = constructNode("LP", NVL, (yylsp[-1]).first_line);
            struct Node* nodeRP =constructNode("RP", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("FunDec", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, nodeID, nodeLP, nodeRP);
        }
#line 1915 "syntax.tab.c"
    break;

  case 28:
#line 221 "syntax.y"
                  {
            (yyval.type_pnode) = NULL;
        }
#line 1923 "syntax.tab.c"
    break;

  case 29:
#line 224 "syntax.y"
                     {
            (yyval.type_pnode) = NULL;
        }
#line 1931 "syntax.tab.c"
    break;

  case 30:
#line 228 "syntax.y"
                                 {
            struct Node* nodeCOMMA = constructNode("COMMA", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("VarList", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeCOMMA, (yyvsp[0].type_pnode));
        }
#line 1941 "syntax.tab.c"
    break;

  case 31:
#line 233 "syntax.y"
               {
            (yyval.type_pnode) = constructNode("VarList", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = (yyvsp[0].type_pnode);
        }
#line 1950 "syntax.tab.c"
    break;

  case 32:
#line 237 "syntax.y"
                           { (yyval.type_pnode) = NULL;}
#line 1956 "syntax.tab.c"
    break;

  case 33:
#line 239 "syntax.y"
                            {
            (yyval.type_pnode) = constructNode("ParamDec", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, (yyvsp[-1].type_pnode), (yyvsp[0].type_pnode));
        }
#line 1965 "syntax.tab.c"
    break;

  case 34:
#line 243 "syntax.y"
                      { (yyval.type_pnode) = NULL;}
#line 1971 "syntax.tab.c"
    break;

  case 35:
#line 247 "syntax.y"
                                {
            struct Node* nodeLC = constructNode("LC", NVL, (yylsp[-3]).first_line);
            struct Node* nodeRC = constructNode("RC", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("CompSt", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 4, nodeLC, (yyvsp[-2].type_pnode), (yyvsp[-1].type_pnode), nodeRC);
        }
#line 1982 "syntax.tab.c"
    break;

  case 36:
#line 253 "syntax.y"
               {
            (yyval.type_pnode) = NULL;
        }
#line 1990 "syntax.tab.c"
    break;

  case 37:
#line 257 "syntax.y"
                         {
            (yyval.type_pnode) = constructNode("StmtList", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, (yyvsp[-1].type_pnode), (yyvsp[0].type_pnode));
        }
#line 1999 "syntax.tab.c"
    break;

  case 38:
#line 261 "syntax.y"
                  {
            (yyval.type_pnode) = NULL;
        }
#line 2007 "syntax.tab.c"
    break;

  case 39:
#line 265 "syntax.y"
                {
            struct Node* nodeSEMI = constructNode("SEMI", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("Stmt", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, (yyvsp[-1].type_pnode), nodeSEMI);
        }
#line 2017 "syntax.tab.c"
    break;

  case 40:
#line 270 "syntax.y"
             {
            (yyval.type_pnode) = constructNode("Stmt", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = (yyvsp[0].type_pnode);
        }
#line 2026 "syntax.tab.c"
    break;

  case 41:
#line 274 "syntax.y"
                      {
            struct Node* nodeRETURN = constructNode("RETURN", NVL, (yylsp[-2]).first_line);
            struct Node* nodeSEMI = constructNode("SEMI", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("Stmt", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, nodeRETURN, (yyvsp[-1].type_pnode), nodeSEMI);
        }
#line 2037 "syntax.tab.c"
    break;

  case 42:
#line 280 "syntax.y"
                                              {
            struct Node* nodeIF = constructNode("IF", NVL, (yylsp[-4]).first_line);
            struct Node* nodeLP = constructNode("LP", NVL, (yylsp[-3]).first_line);
            struct Node* nodeRP = constructNode("RP", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Stmt", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 5, nodeIF, nodeLP, (yyvsp[-2].type_pnode), nodeRP, (yyvsp[0].type_pnode));
        }
#line 2049 "syntax.tab.c"
    break;

  case 43:
#line 287 "syntax.y"
                                  {
            struct Node* nodeIF = constructNode("IF", NVL, (yylsp[-6]).first_line);
            struct Node* nodeLP = constructNode("LP", NVL, (yylsp[-5]).first_line);
            struct Node* nodeRP = constructNode("RP", NVL, (yylsp[-3]).first_line);
            struct Node* nodeELSE = constructNode("ELSE", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Stmt", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 7, nodeIF, nodeLP, (yyvsp[-4].type_pnode), nodeRP, (yyvsp[-2].type_pnode), nodeELSE, (yyvsp[0].type_pnode));
        }
#line 2062 "syntax.tab.c"
    break;

  case 44:
#line 295 "syntax.y"
                           {
            struct Node* nodeWHILE = constructNode("WHILE", NVL, (yylsp[-4]).first_line);
            struct Node* nodeLP = constructNode("LP", NVL, (yylsp[-3]).first_line);
            struct Node* nodeRP = constructNode("RP", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Stmt", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 5, nodeWHILE, nodeLP, (yyvsp[-2].type_pnode), nodeRP, (yyvsp[0].type_pnode));
        }
#line 2074 "syntax.tab.c"
    break;

  case 45:
#line 302 "syntax.y"
                        {
            (yyval.type_pnode) = NULL;
        }
#line 2082 "syntax.tab.c"
    break;

  case 46:
#line 305 "syntax.y"
                 {
            (yyval.type_pnode) = NULL;
        }
#line 2090 "syntax.tab.c"
    break;

  case 47:
#line 308 "syntax.y"
                                                {
            (yyval.type_pnode) = NULL;
        }
#line 2098 "syntax.tab.c"
    break;

  case 48:
#line 311 "syntax.y"
                                                 {
            (yyval.type_pnode) = NULL;
        }
#line 2106 "syntax.tab.c"
    break;

  case 49:
#line 314 "syntax.y"
                                                 {
            (yyval.type_pnode) = NULL;
        }
#line 2114 "syntax.tab.c"
    break;

  case 50:
#line 317 "syntax.y"
                                     {
            (yyval.type_pnode) = NULL;
        }
#line 2122 "syntax.tab.c"
    break;

  case 51:
#line 320 "syntax.y"
                                    {
            (yyval.type_pnode) = NULL;
        }
#line 2130 "syntax.tab.c"
    break;

  case 52:
#line 323 "syntax.y"
                                     {
            (yyval.type_pnode) = NULL;
        }
#line 2138 "syntax.tab.c"
    break;

  case 53:
#line 326 "syntax.y"
                                  {
	    (yyval.type_pnode) = NULL;    
    	}
#line 2146 "syntax.tab.c"
    break;

  case 54:
#line 329 "syntax.y"
                              {
            (yyval.type_pnode) = NULL;
        }
#line 2154 "syntax.tab.c"
    break;

  case 55:
#line 332 "syntax.y"
                             {
            (yyval.type_pnode) = NULL;
        }
#line 2162 "syntax.tab.c"
    break;

  case 56:
#line 335 "syntax.y"
                              {
            (yyval.type_pnode) = NULL;
        }
#line 2170 "syntax.tab.c"
    break;

  case 57:
#line 341 "syntax.y"
                      {
            (yyval.type_pnode) = constructNode("DefList", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, (yyvsp[-1].type_pnode), (yyvsp[0].type_pnode));
        }
#line 2179 "syntax.tab.c"
    break;

  case 58:
#line 345 "syntax.y"
                  {
            (yyval.type_pnode) = NULL;
        }
#line 2187 "syntax.tab.c"
    break;

  case 59:
#line 349 "syntax.y"
                             {
            struct Node* nodeSEMI = constructNode("SEMI", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("Def", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), (yyvsp[-1].type_pnode), nodeSEMI);
        }
#line 2197 "syntax.tab.c"
    break;

  case 60:
#line 354 "syntax.y"
                           {
            (yyval.type_pnode) = NULL;
        }
#line 2205 "syntax.tab.c"
    break;

  case 61:
#line 357 "syntax.y"
                              { (yyval.type_pnode) = NULL;}
#line 2211 "syntax.tab.c"
    break;

  case 62:
#line 359 "syntax.y"
              {
            (yyval.type_pnode) = constructNode("DecList", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = (yyvsp[0].type_pnode);
        }
#line 2220 "syntax.tab.c"
    break;

  case 63:
#line 363 "syntax.y"
                        {
            struct Node* nodeCOMMA = constructNode("COMMA", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("DecList", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeCOMMA, (yyvsp[0].type_pnode));
        }
#line 2230 "syntax.tab.c"
    break;

  case 64:
#line 368 "syntax.y"
                        { (yyval.type_pnode) = NULL;}
#line 2236 "syntax.tab.c"
    break;

  case 65:
#line 369 "syntax.y"
                { (yyval.type_pnode) = NULL;}
#line 2242 "syntax.tab.c"
    break;

  case 66:
#line 371 "syntax.y"
             {
            (yyval.type_pnode) = constructNode("Dec", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = (yyvsp[0].type_pnode);
        }
#line 2251 "syntax.tab.c"
    break;

  case 67:
#line 375 "syntax.y"
                          {
            struct Node* nodeASSIGNOP = constructNode("ASSIGNOP", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Dec", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeASSIGNOP, (yyvsp[0].type_pnode));
        }
#line 2261 "syntax.tab.c"
    break;

  case 68:
#line 380 "syntax.y"
                            {
            (yyval.type_pnode) = NULL;
        }
#line 2269 "syntax.tab.c"
    break;

  case 69:
#line 386 "syntax.y"
                       {
            struct Node* nodeASSIGNOP = constructNode("ASSIGNOP", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeASSIGNOP, (yyvsp[0].type_pnode));
        }
#line 2279 "syntax.tab.c"
    break;

  case 70:
#line 391 "syntax.y"
                  {
            struct Node* nodeAND = constructNode("AND", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeAND, (yyvsp[0].type_pnode));
        }
#line 2289 "syntax.tab.c"
    break;

  case 71:
#line 396 "syntax.y"
                 {
            struct Node* nodeOR = constructNode("OR", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeOR, (yyvsp[0].type_pnode));
        }
#line 2299 "syntax.tab.c"
    break;

  case 72:
#line 401 "syntax.y"
                    {
            struct Node* nodeRELOP = constructNode("RELOP", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeRELOP, (yyvsp[0].type_pnode));
        }
#line 2309 "syntax.tab.c"
    break;

  case 73:
#line 406 "syntax.y"
                   {
            struct Node* nodePLUS = constructNode("PLUS", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodePLUS, (yyvsp[0].type_pnode));
        }
#line 2319 "syntax.tab.c"
    break;

  case 74:
#line 411 "syntax.y"
                    {
            struct Node* nodeMINUS = constructNode("MINUS", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeMINUS, (yyvsp[0].type_pnode));
        }
#line 2329 "syntax.tab.c"
    break;

  case 75:
#line 416 "syntax.y"
                   {
            struct Node* nodeSTAR = constructNode("STAR", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeSTAR, (yyvsp[0].type_pnode));
        }
#line 2339 "syntax.tab.c"
    break;

  case 76:
#line 421 "syntax.y"
                  {
            struct Node* nodeDIV = constructNode("DIV", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeDIV, (yyvsp[0].type_pnode));
        }
#line 2349 "syntax.tab.c"
    break;

  case 77:
#line 426 "syntax.y"
                {
            struct Node* nodeLP = constructNode("LP", NVL, (yylsp[-2]).first_line);
            struct Node* nodeRP = constructNode("RP", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, nodeLP, (yyvsp[-1].type_pnode), nodeRP);
        }
#line 2360 "syntax.tab.c"
    break;

  case 78:
#line 432 "syntax.y"
                {
            struct Node* nodeMINUS = constructNode("MINUS", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, nodeMINUS, (yyvsp[0].type_pnode));
        }
#line 2370 "syntax.tab.c"
    break;

  case 79:
#line 437 "syntax.y"
              {
            struct Node* nodeNOT = constructNode("NOT", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 2, nodeNOT, (yyvsp[0].type_pnode));
        }
#line 2380 "syntax.tab.c"
    break;

  case 80:
#line 442 "syntax.y"
                    {
            struct Node* nodeID = constructNode("ID", VL, (yylsp[-3]).first_line);
            nodeID->Valstr = (yyvsp[-3].type_string);
            struct Node* nodeLP = constructNode("LP", NVL, (yylsp[-2]).first_line);
            struct Node* nodeRP = constructNode("RP", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 4, nodeID, nodeLP, (yyvsp[-1].type_pnode), nodeRP);
        }
#line 2393 "syntax.tab.c"
    break;

  case 81:
#line 450 "syntax.y"
               {
            struct Node* nodeID = constructNode("ID", VL, (yylsp[-2]).first_line);
            nodeID->Valstr = (yyvsp[-2].type_string);
            struct Node* nodeLP = constructNode("LP", NVL, (yylsp[-1]).first_line);
            struct Node* nodeRP = constructNode("RP", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, nodeID, nodeLP, nodeRP);
        }
#line 2406 "syntax.tab.c"
    break;

  case 82:
#line 458 "syntax.y"
                    {
            struct Node* nodeLB = constructNode("LB", NVL, (yylsp[-2]).first_line);
            struct Node* nodeRB = constructNode("RB", NVL, (yylsp[0]).first_line);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 4, (yyvsp[-3].type_pnode), nodeLB, (yyvsp[-1].type_pnode), nodeRB);
        }
#line 2417 "syntax.tab.c"
    break;

  case 83:
#line 464 "syntax.y"
                 {
            struct Node* nodeDOT = constructNode("DOT", NVL, (yylsp[-1]).first_line);
            struct Node* nodeID = constructNode("ID", VL, (yylsp[0]).first_line);
            nodeID->Valstr = (yyvsp[0].type_string);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeDOT, nodeID);
        }
#line 2429 "syntax.tab.c"
    break;

  case 84:
#line 471 "syntax.y"
         {
            struct Node* nodeID = constructNode("ID", VL, (yylsp[0]).first_line);
            nodeID->Valstr = (yyvsp[0].type_string);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = nodeID;
        }
#line 2440 "syntax.tab.c"
    break;

  case 85:
#line 477 "syntax.y"
          {
            struct Node* nodeINT = constructNode("INT", VL, (yylsp[0]).first_line);
            nodeINT->Valint = (yyvsp[0].type_int);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = nodeINT;
        }
#line 2451 "syntax.tab.c"
    break;

  case 86:
#line 483 "syntax.y"
            {
            struct Node* nodeFLOAT = constructNode("FLOAT", VL, (yylsp[0]).first_line);
            nodeFLOAT->Valfloat = (yyvsp[0].type_float);
            (yyval.type_pnode) = constructNode("Exp", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = nodeFLOAT;
        }
#line 2462 "syntax.tab.c"
    break;

  case 87:
#line 489 "syntax.y"
                      {
            (yyval.type_pnode) = NULL;
        }
#line 2470 "syntax.tab.c"
    break;

  case 88:
#line 492 "syntax.y"
               {
            (yyval.type_pnode) = NULL;
        }
#line 2478 "syntax.tab.c"
    break;

  case 89:
#line 495 "syntax.y"
                       {
            (yyval.type_pnode) = NULL;
        }
#line 2486 "syntax.tab.c"
    break;

  case 90:
#line 498 "syntax.y"
                  {
            (yyval.type_pnode) = NULL;
        }
#line 2494 "syntax.tab.c"
    break;

  case 91:
#line 501 "syntax.y"
                         {
            (yyval.type_pnode) = NULL;
        }
#line 2502 "syntax.tab.c"
    break;

  case 92:
#line 504 "syntax.y"
                    {
            (yyval.type_pnode) = NULL;
        }
#line 2510 "syntax.tab.c"
    break;

  case 93:
#line 507 "syntax.y"
                   {
            (yyval.type_pnode) = NULL;
        }
#line 2518 "syntax.tab.c"
    break;

  case 94:
#line 510 "syntax.y"
                      {
            (yyval.type_pnode) = NULL;
        }
#line 2526 "syntax.tab.c"
    break;

  case 95:
#line 513 "syntax.y"
                     {
            (yyval.type_pnode) = NULL;
        }
#line 2534 "syntax.tab.c"
    break;

  case 96:
#line 516 "syntax.y"
                      {
            (yyval.type_pnode) = NULL;
        }
#line 2542 "syntax.tab.c"
    break;

  case 97:
#line 519 "syntax.y"
                     {
            (yyval.type_pnode) = NULL;
        }
#line 2550 "syntax.tab.c"
    break;

  case 98:
#line 522 "syntax.y"
                    {
            (yyval.type_pnode) = NULL;
        }
#line 2558 "syntax.tab.c"
    break;

  case 99:
#line 525 "syntax.y"
                  {
            (yyval.type_pnode) = NULL;
        }
#line 2566 "syntax.tab.c"
    break;

  case 100:
#line 528 "syntax.y"
                {
            (yyval.type_pnode) = NULL;
        }
#line 2574 "syntax.tab.c"
    break;

  case 101:
#line 531 "syntax.y"
                   {
            (yyval.type_pnode) = NULL;
        }
#line 2582 "syntax.tab.c"
    break;

  case 102:
#line 535 "syntax.y"
                      {
            struct Node* nodeCOMMA = constructNode("COMMA", NVL, (yylsp[-1]).first_line);
            (yyval.type_pnode) = constructNode("Args", NTML, (yyloc).first_line);
            construct((yyval.type_pnode), 3, (yyvsp[-2].type_pnode), nodeCOMMA, (yyvsp[0].type_pnode));
        }
#line 2592 "syntax.tab.c"
    break;

  case 103:
#line 540 "syntax.y"
          {
            (yyval.type_pnode) = constructNode("Args", NTML, (yyloc).first_line);
            (yyval.type_pnode)->firstChild = (yyvsp[0].type_pnode);
        }
#line 2601 "syntax.tab.c"
    break;


#line 2605 "syntax.tab.c"

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
#line 546 "syntax.y"

struct Node* constructNode(char* nodeName, enum NodeType nodeType, int lineNum) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->nodeName = nodeName;
    newNode->nodeType = nodeType;
    newNode->lineNum = lineNum;
    newNode->firstChild = NULL;
    newNode->bro = NULL;
    return newNode;
}

void construct(struct Node* fatherNode, int index, ...) {
    va_list valist;
    va_start(valist, index);
    struct Node* firstChild = NULL;
    struct Node* lastChild = NULL;
    for (int i = 0; i < index; i++) {
        struct Node* nowNode = va_arg(valist, struct Node*);
        if (firstChild == NULL) {
            if (nowNode != NULL) {
                firstChild = nowNode;
                lastChild = firstChild;
            }
        } else {
            if (nowNode != NULL) {
                lastChild->bro = nowNode;
                lastChild = nowNode;
            }
        }
    }
    va_end(valist);
    fatherNode->firstChild = firstChild;
}

void Print_Tree(struct Node* rootNode, int SpaceNum) {
    if (rootNode == NULL)
        return;
    for (int i = 0; i < SpaceNum; i++) {
        printf(" ");
    }
    switch (rootNode->nodeType) {
        case NTML:
            printf("%s (%d)\n", rootNode->nodeName, rootNode->lineNum);
            break;
        case NVL:
            printf("%s\n", rootNode->nodeName);
            break;
        case VL:
            printf("%s: ", rootNode->nodeName);
            if ((strcmp(rootNode->nodeName, "TYPE") == 0) || (strcmp(rootNode->nodeName, "ID") == 0)) {
                printf("%s\n", rootNode->Valstr);
            } else if (strcmp(rootNode->nodeName, "INT") == 0) {
                printf("%d\n", rootNode->Valint);
            } else if (strcmp(rootNode->nodeName, "FLOAT") == 0) {
                printf("%f\n", rootNode->Valfloat);
            } else {
                printf("ERROR!\n");
            }
            break;
        default:
            printf("ERROR!\n");
    }
    Print_Tree(rootNode->firstChild, SpaceNum + 2);
    Print_Tree(rootNode->bro, SpaceNum);
}


void yyerror(const char* s) {
	if(isNewError(yylineno)){
		fprintf(stdout, "Error type B at Line %d: %s.\n", yylineno, yytext);
		errorflag = 1;
	}
}

void printError(char errorType, int lineno, char* msg) {
    fprintf(stderr, "Error type %c at Line %d: %s.\n", errorType, lineno, msg);
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

void destroyTree(struct Node* rootNode) {
    if (rootNode == NULL) {
        return;
    }
    while (rootNode->firstChild != NULL) {
        struct Node* nowNode = rootNode->firstChild;
        rootNode->firstChild = nowNode->bro;
        destroyTree(nowNode);
    }
    if ((strcmp(rootNode->nodeName, "TYPE") == 0) || (strcmp(rootNode->nodeName, "ID") == 0)) {
        free(rootNode->Valstr);
        rootNode->Valstr = NULL;
    }
    return;
    free(rootNode);
    rootNode = NULL;
}
