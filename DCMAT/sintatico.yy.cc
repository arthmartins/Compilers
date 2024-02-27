/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatico.y"

#include <stdio.h>
#include "comandos.hh"
#include <list>
#include "hash.hh"
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include "ast.hh"

#define QUIT_VALUE 329179
#define CONTINUE_VALUE 0


extern int yylex();
extern char* yytext;

extern int yychar;
extern void yylex_destroy(void);

extern bool not_existId;
bool matriz_exp = false;
extern bool break_matriz;
bool dont_worry = false;

std::string universal;
std::string str;
std::string str_aux;
std::string str_aux2;

std::vector<std::vector<float>>* matriz_global;

std::vector<std::vector<float>> matriz_exp_global;

HashTable hashTable;

std::list<float> listMatriz;
std::list<int> elemtsPlinha;

int elementosLinha = 0;
int maisElementosLinha = 0;
float valorExp = 0;
int sinal = 1;

TreeNode* AST = NULL;
TreeNode* PLOT_EXP = NULL;

extern void printarExpressao();
extern void AtribuirValor();
extern void yyerror(char*); 


#line 125 "sintatico.yy.cc"

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

#include "sintatico.yy.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_ABOUT = 4,                      /* ABOUT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_PI = 6,                         /* PI  */
  YYSYMBOL_SETTINGS = 7,                   /* SETTINGS  */
  YYSYMBOL_ABS = 8,                        /* ABS  */
  YYSYMBOL_H_VIEW = 9,                     /* H_VIEW  */
  YYSYMBOL_PLOT = 10,                      /* PLOT  */
  YYSYMBOL_SHOW = 11,                      /* SHOW  */
  YYSYMBOL_AXIS = 12,                      /* AXIS  */
  YYSYMBOL_INTEGRAL_STEPS = 13,            /* INTEGRAL_STEPS  */
  YYSYMBOL_PRECISION = 14,                 /* PRECISION  */
  YYSYMBOL_SOLVE = 15,                     /* SOLVE  */
  YYSYMBOL_CONNECT_DOTS = 16,              /* CONNECT_DOTS  */
  YYSYMBOL_INTEGRATE = 17,                 /* INTEGRATE  */
  YYSYMBOL_QUIT = 18,                      /* QUIT  */
  YYSYMBOL_SUM = 19,                       /* SUM  */
  YYSYMBOL_COS = 20,                       /* COS  */
  YYSYMBOL_LINEAR_SYSTEM = 21,             /* LINEAR_SYSTEM  */
  YYSYMBOL_RESET = 22,                     /* RESET  */
  YYSYMBOL_SYMBOLS = 23,                   /* SYMBOLS  */
  YYSYMBOL_DETERMINANT = 24,               /* DETERMINANT  */
  YYSYMBOL_MATRIX = 25,                    /* MATRIX  */
  YYSYMBOL_RPN = 26,                       /* RPN  */
  YYSYMBOL_TAN = 27,                       /* TAN  */
  YYSYMBOL_E = 28,                         /* E  */
  YYSYMBOL_OFF = 29,                       /* OFF  */
  YYSYMBOL_SEN = 30,                       /* SEN  */
  YYSYMBOL_V_VIEW = 31,                    /* V_VIEW  */
  YYSYMBOL_ERASE = 32,                     /* ERASE  */
  YYSYMBOL_ON = 33,                        /* ON  */
  YYSYMBOL_SET = 34,                       /* SET  */
  YYSYMBOL_X = 35,                         /* X  */
  YYSYMBOL_PLUS = 36,                      /* PLUS  */
  YYSYMBOL_MINUS = 37,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 38,                  /* MULTIPLY  */
  YYSYMBOL_DIV = 39,                       /* DIV  */
  YYSYMBOL_REMAINDER = 40,                 /* REMAINDER  */
  YYSYMBOL_POW = 41,                       /* POW  */
  YYSYMBOL_SEMICOLON = 42,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 43,                     /* COMMA  */
  YYSYMBOL_COLON = 44,                     /* COLON  */
  YYSYMBOL_L_PAREN = 45,                   /* L_PAREN  */
  YYSYMBOL_R_PAREN = 46,                   /* R_PAREN  */
  YYSYMBOL_L_SQUARE_BRACKET = 47,          /* L_SQUARE_BRACKET  */
  YYSYMBOL_R_SQUARE_BRACKET = 48,          /* R_SQUARE_BRACKET  */
  YYSYMBOL_EQUAL = 49,                     /* EQUAL  */
  YYSYMBOL_ATRIBUTE = 50,                  /* ATRIBUTE  */
  YYSYMBOL_NUM_INTEGER = 51,               /* NUM_INTEGER  */
  YYSYMBOL_NUM_REAL = 52,                  /* NUM_REAL  */
  YYSYMBOL_EOL = 53,                       /* EOL  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_Programa = 55,                  /* Programa  */
  YYSYMBOL_ManipulacaoSimbolos = 56,       /* ManipulacaoSimbolos  */
  YYSYMBOL_Comandos = 57,                  /* Comandos  */
  YYSYMBOL_OnlyComandos = 58,              /* OnlyComandos  */
  YYSYMBOL_FuncoesSet = 59,                /* FuncoesSet  */
  YYSYMBOL_ValorIntOrFloat = 60,           /* ValorIntOrFloat  */
  YYSYMBOL_Sinal = 61,                     /* Sinal  */
  YYSYMBOL_ONorOFF = 62,                   /* ONorOFF  */
  YYSYMBOL_ComandosPlus = 63,              /* ComandosPlus  */
  YYSYMBOL_Grafico = 64,                   /* Grafico  */
  YYSYMBOL_InfoPlot = 65,                  /* InfoPlot  */
  YYSYMBOL_66_1 = 66,                      /* $@1  */
  YYSYMBOL_FuncaoRpn = 67,                 /* FuncaoRpn  */
  YYSYMBOL_Sum = 68,                       /* Sum  */
  YYSYMBOL_Matrix = 69,                    /* Matrix  */
  YYSYMBOL_ChamaCreateMatrix = 70,         /* ChamaCreateMatrix  */
  YYSYMBOL_CreateMatrix = 71,              /* CreateMatrix  */
  YYSYMBOL_CreateMatrixAux = 72,           /* CreateMatrixAux  */
  YYSYMBOL_73_2 = 73,                      /* $@2  */
  YYSYMBOL_74_3 = 74,                      /* $@3  */
  YYSYMBOL_RepeatValuesMatrixOne = 75,     /* RepeatValuesMatrixOne  */
  YYSYMBOL_76_4 = 76,                      /* $@4  */
  YYSYMBOL_RepeatValuesMatrixTwo = 77,     /* RepeatValuesMatrixTwo  */
  YYSYMBOL_78_5 = 78,                      /* $@5  */
  YYSYMBOL_79_6 = 79,                      /* $@6  */
  YYSYMBOL_Integral = 80,                  /* Integral  */
  YYSYMBOL_IntegralAux = 81,               /* IntegralAux  */
  YYSYMBOL_Expressao_matematica_Direta = 82, /* Expressao_matematica_Direta  */
  YYSYMBOL_Funcao_Integral = 83,           /* Funcao_Integral  */
  YYSYMBOL_Integral_aux = 84,              /* Integral_aux  */
  YYSYMBOL_Integral_DivMul = 85,           /* Integral_DivMul  */
  YYSYMBOL_Integral_Complemento = 86,      /* Integral_Complemento  */
  YYSYMBOL_87_7 = 87,                      /* $@7  */
  YYSYMBOL_continua_id = 88,               /* continua_id  */
  YYSYMBOL_89_8 = 89,                      /* $@8  */
  YYSYMBOL_continua_atribute = 90,         /* continua_atribute  */
  YYSYMBOL_Expressao_matematica = 91,      /* Expressao_matematica  */
  YYSYMBOL_Exp_aux = 92,                   /* Exp_aux  */
  YYSYMBOL_Exp_DivMul = 93,                /* Exp_DivMul  */
  YYSYMBOL_Exp_Complemento = 94            /* Exp_Complemento  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   126,   126,   127,   128,   129,   131,   133,   134,   136,
     137,   138,   139,   140,   144,   145,   146,   147,   148,   149,
     150,   153,   154,   156,   157,   158,   162,   163,   165,   166,
     167,   168,   169,   172,   175,   175,   176,   181,   187,   192,
     193,   194,   195,   197,   202,   204,   205,   204,   208,   208,
     209,   211,   212,   211,   214,   219,   221,   225,   228,   231,
     233,   242,   251,   252,   261,   271,   281,   281,   305,   315,
     323,   332,   342,   351,   353,   362,   371,   371,   372,   373,
     375,   377,   384,   385,   387,   388,   396,   403,   404,   411,
     419,   426,   444,   449,   454,   459,   465,   473,   480,   485
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER", "ABOUT",
  "FLOAT", "PI", "SETTINGS", "ABS", "H_VIEW", "PLOT", "SHOW", "AXIS",
  "INTEGRAL_STEPS", "PRECISION", "SOLVE", "CONNECT_DOTS", "INTEGRATE",
  "QUIT", "SUM", "COS", "LINEAR_SYSTEM", "RESET", "SYMBOLS", "DETERMINANT",
  "MATRIX", "RPN", "TAN", "E", "OFF", "SEN", "V_VIEW", "ERASE", "ON",
  "SET", "X", "PLUS", "MINUS", "MULTIPLY", "DIV", "REMAINDER", "POW",
  "SEMICOLON", "COMMA", "COLON", "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET",
  "R_SQUARE_BRACKET", "EQUAL", "ATRIBUTE", "NUM_INTEGER", "NUM_REAL",
  "EOL", "$accept", "Programa", "ManipulacaoSimbolos", "Comandos",
  "OnlyComandos", "FuncoesSet", "ValorIntOrFloat", "Sinal", "ONorOFF",
  "ComandosPlus", "Grafico", "InfoPlot", "$@1", "FuncaoRpn", "Sum",
  "Matrix", "ChamaCreateMatrix", "CreateMatrix", "CreateMatrixAux", "$@2",
  "$@3", "RepeatValuesMatrixOne", "$@4", "RepeatValuesMatrixTwo", "$@5",
  "$@6", "Integral", "IntegralAux", "Expressao_matematica_Direta",
  "Funcao_Integral", "Integral_aux", "Integral_DivMul",
  "Integral_Complemento", "$@7", "continua_id", "$@8", "continua_atribute",
  "Expressao_matematica", "Exp_aux", "Exp_DivMul", "Exp_Complemento", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-192)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     134,   -23,  -192,   -12,    -7,    75,   -17,    24,  -192,    32,
      35,    56,    36,    44,    47,  -192,    50,   100,  -192,  -192,
    -192,     4,  -192,    97,    46,    48,  -192,    -1,  -192,  -192,
    -192,  -192,  -192,  -192,    68,  -192,   -19,     5,  -192,  -192,
       4,  -192,    78,    80,    81,    83,    91,    99,    25,   136,
       4,   101,   103,     4,     4,     4,   132,    25,    -4,    96,
      -4,    25,   138,   113,    10,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,     4,     4,     4,     4,   111,     4,  -192,
    -192,  -192,  -192,  -192,  -192,    23,   112,   122,   120,  -192,
     129,  -192,  -192,   121,   131,   135,    25,    23,  -192,  -192,
    -192,  -192,  -192,    23,    -4,  -192,  -192,   -28,     5,     5,
    -192,  -192,  -192,   139,   140,   144,   127,  -192,    25,   141,
     146,  -192,  -192,   142,   147,   148,  -192,   137,  -192,  -192,
    -192,    25,  -192,   150,    23,   153,  -192,  -192,    25,    25,
    -192,   103,    23,   145,  -192,  -192,    23,    23,   149,  -192,
       0,   154,   155,   156,  -192,  -192,  -192,  -192,   158,   159,
     160,  -192,   161,  -192,   157,    51,     2,    67,    69,  -192,
       4,     4,    25,   152,    51,    51,    51,    51,  -192,    30,
    -192,  -192,    51,    51,    51,    51,  -192,   162,    23,  -192,
     163,   165,   166,   167,  -192,    69,    69,  -192,  -192,   172,
    -192,   164,  -192,  -192,  -192,  -192,  -192,   156,   133,  -192,
    -192,    25,    23,  -192,   156,   168,  -192,   164,  -192
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      25,     0,    74,     0,    36,     0,     0,     0,    11,     0,
       0,     0,     0,     0,     0,    75,     0,     0,    71,    23,
      24,    25,     5,     0,     0,     0,     7,     0,     8,    28,
      29,    31,    32,    30,     0,    57,    58,    59,    62,    13,
      25,    34,     0,     0,     0,     0,     0,     0,    25,     0,
      25,     0,     0,    25,    25,    25,     0,    25,     0,     0,
       0,    25,     0,     0,     0,     1,     3,     2,    66,    21,
      22,    65,     4,    25,    25,    25,    25,     0,    25,    33,
       9,     6,    40,    42,    41,     0,     0,     0,     0,    10,
       0,    39,    43,     0,     0,     0,    25,     0,    27,    26,
      16,    20,    18,     0,     0,    12,    73,    79,    60,    61,
      63,    64,    72,     0,     0,     0,     0,    68,    25,     0,
       0,    70,    69,     0,     0,     0,    17,     0,    76,    67,
      35,    25,    55,     0,     0,     0,    37,    19,    25,    25,
      78,    82,     0,     0,    45,    44,     0,     0,     0,    77,
      25,     0,     0,    50,    14,    15,    81,    96,     0,     0,
       0,    97,     0,    95,     0,    25,     0,    83,    84,    87,
      25,    25,    25,     0,    25,    25,    25,    25,    80,     0,
      91,    90,    25,    25,    25,    25,    56,     0,     0,    46,
       0,     0,     0,     0,    99,    85,    86,    88,    89,     0,
      48,    54,    98,    92,    94,    93,    38,    50,     0,    47,
      49,    25,     0,    51,    50,     0,    52,    54,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -192,  -192,  -192,  -192,  -192,  -192,   -82,   -48,   -49,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,    60,  -192,  -192,  -192,
    -192,  -191,  -192,     1,  -192,  -192,  -192,  -192,  -192,   -52,
     194,    37,    18,  -192,  -192,  -192,  -192,  -192,    52,   -68,
      -2
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    23,    24,    25,    26,    63,    71,    27,   100,    28,
      29,    42,    78,    30,    31,    32,    91,    92,   119,   153,
     201,   173,   207,   209,   214,   217,    33,    86,    34,    35,
      36,    37,    38,   107,   129,   141,   149,   150,   167,   168,
     169
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      85,    93,    68,   114,    46,   180,   157,    47,   158,    97,
       2,   102,     3,   103,   127,   124,   210,    73,    74,    39,
     159,   125,   128,   215,    10,    98,   113,   160,   161,    99,
     162,    14,    15,    40,    16,   163,    19,    20,    41,    18,
      19,    20,   164,    75,    76,   165,    73,    74,   123,    21,
      69,    70,   144,    69,    70,   126,   106,   157,    77,   158,
     151,    19,    20,    51,   154,   155,   182,   183,    88,    48,
     134,   159,    94,    95,    69,    70,   194,    49,   160,   161,
      50,   162,    43,   142,   181,    52,   163,    19,    20,    53,
     146,   147,    54,   110,   111,    55,   165,    65,    44,    66,
      45,    67,   166,   182,   183,    56,   200,   184,   185,    57,
     108,   109,    58,    59,   195,   196,    60,   166,   186,   187,
      79,    72,    80,    81,   188,    82,   166,   166,   166,   166,
     213,    61,    62,    83,   166,   166,   166,   166,     1,    87,
       2,    84,     3,    89,     4,     5,    96,   101,   104,     6,
      90,     7,     8,     9,    10,   105,    11,   112,   115,    12,
      13,    14,    15,   212,    16,   116,   117,   120,    17,    18,
      19,    20,   190,   191,   192,   193,   118,   121,   133,    21,
     211,   122,   197,   198,   131,   130,   132,    22,   136,   135,
     140,   138,   139,   137,   143,   145,   152,   170,   171,   172,
     189,   148,   156,   174,   175,   176,   177,   208,   199,   202,
     178,   203,   204,   205,   206,    64,   216,   179,   218
};

static const yytype_uint8 yycheck[] =
{
      48,    53,     3,    85,    21,     3,     6,    24,     8,    57,
       6,    60,     8,    61,    42,    97,   207,    36,    37,    42,
      20,   103,    50,   214,    20,    29,    78,    27,    28,    33,
      30,    27,    28,    45,    30,    35,    36,    37,    45,    35,
      36,    37,    42,    38,    39,    45,    36,    37,    96,    45,
      51,    52,   134,    51,    52,   104,    46,     6,    40,     8,
     142,    36,    37,     7,   146,   147,    36,    37,    50,    45,
     118,    20,    54,    55,    51,    52,    46,    45,    27,    28,
      45,    30,     7,   131,   166,    49,    35,    36,    37,    45,
     138,   139,    45,    75,    76,    45,    45,     0,    23,    53,
      25,    53,   150,    36,    37,     5,   188,    38,    39,     9,
      73,    74,    12,    13,   182,   183,    16,   165,   170,   171,
      42,    53,    42,    42,   172,    42,   174,   175,   176,   177,
     212,    31,    32,    42,   182,   183,   184,   185,     4,     3,
       6,    42,     8,    42,    10,    11,    14,    51,    10,    15,
      47,    17,    18,    19,    20,    42,    22,    46,    46,    25,
      26,    27,    28,   211,    30,    43,    46,    46,    34,    35,
      36,    37,   174,   175,   176,   177,    47,    46,    51,    45,
      47,    46,   184,   185,    44,    46,    42,    53,    42,    48,
      53,    44,    44,    51,    44,    42,    51,    43,    43,    43,
      48,   141,    53,    45,    45,    45,    45,    43,    46,    46,
      53,    46,    46,    46,    42,    21,    48,   165,   217
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     6,     8,    10,    11,    15,    17,    18,    19,
      20,    22,    25,    26,    27,    28,    30,    34,    35,    36,
      37,    45,    53,    55,    56,    57,    58,    61,    63,    64,
      67,    68,    69,    80,    82,    83,    84,    85,    86,    42,
      45,    45,    65,     7,    23,    25,    21,    24,    45,    45,
      45,     7,    49,    45,    45,    45,     5,     9,    12,    13,
      16,    31,    32,    59,    84,     0,    53,    53,     3,    51,
      52,    60,    53,    36,    37,    38,    39,    86,    66,    42,
      42,    42,    42,    42,    42,    61,    81,     3,    86,    42,
      47,    70,    71,    83,    86,    86,    14,    61,    29,    33,
      62,    51,    62,    61,    10,    42,    46,    87,    85,    85,
      86,    86,    46,    83,    60,    46,    43,    46,    47,    72,
      46,    46,    46,    61,    60,    60,    62,    42,    50,    88,
      46,    44,    42,    51,    61,    48,    42,    51,    44,    44,
      53,    89,    61,    44,    60,    42,    61,    61,    70,    90,
      91,    60,    51,    73,    60,    60,    53,     6,     8,    20,
      27,    28,    30,    35,    42,    45,    61,    92,    93,    94,
      43,    43,    43,    75,    45,    45,    45,    45,    53,    92,
       3,    60,    36,    37,    38,    39,    83,    83,    61,    48,
      94,    94,    94,    94,    46,    93,    93,    94,    94,    46,
      60,    74,    46,    46,    46,    46,    42,    76,    43,    77,
      75,    47,    61,    60,    78,    75,    48,    79,    77
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    56,    57,    57,    58,
      58,    58,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    60,    60,    61,    61,    61,    62,    62,    63,    63,
      63,    63,    63,    64,    66,    65,    65,    67,    68,    69,
      69,    69,    69,    70,    71,    73,    74,    72,    76,    75,
      75,    78,    79,    77,    77,    80,    81,    82,    83,    84,
      84,    84,    85,    85,    85,    86,    87,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    89,    88,    88,    88,
      90,    90,    91,    91,    92,    92,    92,    93,    93,    93,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     1,     3,     1,     1,     3,
       3,     1,     3,     2,     6,     6,     2,     3,     2,     4,
       2,     1,     1,     1,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     4,     0,     5,    11,     3,
       3,     3,     3,     1,     4,     0,     0,     8,     0,     5,
       0,     0,     0,     9,     0,     5,     7,     1,     1,     1,
       3,     3,     1,     3,     3,     2,     0,     4,     4,     4,
       4,     1,     4,     3,     1,     1,     0,     3,     2,     0,
       3,     2,     0,     2,     1,     3,     3,     1,     3,     3,
       2,     2,     4,     4,     4,     1,     1,     1,     4,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Programa: Comandos EOL  */
#line 126 "sintatico.y"
                       {return CONTINUE_VALUE;}
#line 1352 "sintatico.yy.cc"
    break;

  case 3: /* Programa: ManipulacaoSimbolos EOL  */
#line 127 "sintatico.y"
                                  {return CONTINUE_VALUE;}
#line 1358 "sintatico.yy.cc"
    break;

  case 4: /* Programa: Expressao_matematica_Direta EOL  */
#line 128 "sintatico.y"
                                          {return CONTINUE_VALUE;}
#line 1364 "sintatico.yy.cc"
    break;

  case 5: /* Programa: EOL  */
#line 129 "sintatico.y"
              {return CONTINUE_VALUE;}
#line 1370 "sintatico.yy.cc"
    break;

  case 6: /* ManipulacaoSimbolos: SHOW SYMBOLS SEMICOLON  */
#line 131 "sintatico.y"
                                            { hashTable.printAll();}
#line 1376 "sintatico.yy.cc"
    break;

  case 7: /* Comandos: OnlyComandos  */
#line 133 "sintatico.y"
                       {}
#line 1382 "sintatico.yy.cc"
    break;

  case 8: /* Comandos: ComandosPlus  */
#line 134 "sintatico.y"
                       {}
#line 1388 "sintatico.yy.cc"
    break;

  case 9: /* OnlyComandos: SHOW SETTINGS SEMICOLON  */
#line 136 "sintatico.y"
                                      { showSettings();}
#line 1394 "sintatico.yy.cc"
    break;

  case 10: /* OnlyComandos: RESET SETTINGS SEMICOLON  */
#line 137 "sintatico.y"
                                       { setDefaultValues(); }
#line 1400 "sintatico.yy.cc"
    break;

  case 11: /* OnlyComandos: QUIT  */
#line 138 "sintatico.y"
                   { return QUIT_VALUE;}
#line 1406 "sintatico.yy.cc"
    break;

  case 12: /* OnlyComandos: SET FuncoesSet SEMICOLON  */
#line 139 "sintatico.y"
                                       {}
#line 1412 "sintatico.yy.cc"
    break;

  case 13: /* OnlyComandos: ABOUT SEMICOLON  */
#line 140 "sintatico.y"
                              { printAbout(); }
#line 1418 "sintatico.yy.cc"
    break;

  case 14: /* FuncoesSet: H_VIEW Sinal ValorIntOrFloat COLON Sinal ValorIntOrFloat  */
#line 144 "sintatico.y"
                                                                     { setH_view((yyvsp[-4].inteiro)*(yyvsp[-3].real), (yyvsp[-1].inteiro)*(yyvsp[0].real)); }
#line 1424 "sintatico.yy.cc"
    break;

  case 15: /* FuncoesSet: V_VIEW Sinal ValorIntOrFloat COLON Sinal ValorIntOrFloat  */
#line 145 "sintatico.y"
                                                                       {setV_view((yyvsp[-4].inteiro)*(yyvsp[-3].real), (yyvsp[-1].inteiro)*(yyvsp[0].real));}
#line 1430 "sintatico.yy.cc"
    break;

  case 16: /* FuncoesSet: AXIS ONorOFF  */
#line 146 "sintatico.y"
                           {setAxis((yyvsp[0].inteiro));}
#line 1436 "sintatico.yy.cc"
    break;

  case 17: /* FuncoesSet: ERASE PLOT ONorOFF  */
#line 147 "sintatico.y"
                                 {setErase((yyvsp[0].inteiro));}
#line 1442 "sintatico.yy.cc"
    break;

  case 18: /* FuncoesSet: CONNECT_DOTS ONorOFF  */
#line 148 "sintatico.y"
                                   {setConnectDots((yyvsp[0].inteiro));}
#line 1448 "sintatico.yy.cc"
    break;

  case 19: /* FuncoesSet: FLOAT PRECISION Sinal NUM_INTEGER  */
#line 149 "sintatico.y"
                                                {setFloatPrecision((yyvsp[-1].inteiro)*(yyvsp[0].inteiro));}
#line 1454 "sintatico.yy.cc"
    break;

  case 20: /* FuncoesSet: INTEGRAL_STEPS NUM_INTEGER  */
#line 150 "sintatico.y"
                                         {setIntegralSteps((yyvsp[0].inteiro));}
#line 1460 "sintatico.yy.cc"
    break;

  case 21: /* ValorIntOrFloat: NUM_INTEGER  */
#line 153 "sintatico.y"
                             {(yyval.real) = (yyvsp[0].inteiro);}
#line 1466 "sintatico.yy.cc"
    break;

  case 22: /* ValorIntOrFloat: NUM_REAL  */
#line 154 "sintatico.y"
                     {(yyval.real) = (yyvsp[0].real);}
#line 1472 "sintatico.yy.cc"
    break;

  case 23: /* Sinal: PLUS  */
#line 156 "sintatico.y"
            {(yyval.inteiro) = 1;}
#line 1478 "sintatico.yy.cc"
    break;

  case 24: /* Sinal: MINUS  */
#line 157 "sintatico.y"
            {(yyval.inteiro) = -1;}
#line 1484 "sintatico.yy.cc"
    break;

  case 25: /* Sinal: %empty  */
#line 158 "sintatico.y"
      {(yyval.inteiro) = 1;}
#line 1490 "sintatico.yy.cc"
    break;

  case 26: /* ONorOFF: ON  */
#line 162 "sintatico.y"
            {(yyval.inteiro) = 1;}
#line 1496 "sintatico.yy.cc"
    break;

  case 27: /* ONorOFF: OFF  */
#line 163 "sintatico.y"
             {(yyval.inteiro) = 0;}
#line 1502 "sintatico.yy.cc"
    break;

  case 28: /* ComandosPlus: Grafico  */
#line 165 "sintatico.y"
                      {}
#line 1508 "sintatico.yy.cc"
    break;

  case 29: /* ComandosPlus: FuncaoRpn  */
#line 166 "sintatico.y"
                        {}
#line 1514 "sintatico.yy.cc"
    break;

  case 30: /* ComandosPlus: Integral  */
#line 167 "sintatico.y"
                       {}
#line 1520 "sintatico.yy.cc"
    break;

  case 31: /* ComandosPlus: Sum  */
#line 168 "sintatico.y"
                  {}
#line 1526 "sintatico.yy.cc"
    break;

  case 32: /* ComandosPlus: Matrix  */
#line 169 "sintatico.y"
                     {}
#line 1532 "sintatico.yy.cc"
    break;

  case 33: /* Grafico: PLOT InfoPlot SEMICOLON  */
#line 172 "sintatico.y"
                                 {plotarGrafico(PLOT_EXP, hashTable); dont_worry = false; }
#line 1538 "sintatico.yy.cc"
    break;

  case 34: /* $@1: %empty  */
#line 175 "sintatico.y"
                  {dont_worry = true;}
#line 1544 "sintatico.yy.cc"
    break;

  case 35: /* InfoPlot: L_PAREN $@1 Funcao_Integral R_PAREN  */
#line 175 "sintatico.y"
                                                               {PLOT_EXP = AST; }
#line 1550 "sintatico.yy.cc"
    break;

  case 36: /* InfoPlot: %empty  */
#line 176 "sintatico.y"
          {}
#line 1556 "sintatico.yy.cc"
    break;

  case 37: /* FuncaoRpn: RPN L_PAREN Funcao_Integral R_PAREN SEMICOLON  */
#line 181 "sintatico.y"
                                                         {    RpnFunc(AST); /*Delete_Tree(AST);*/ }
#line 1562 "sintatico.yy.cc"
    break;

  case 38: /* Sum: SUM L_PAREN IDENTIFIER COMMA NUM_INTEGER COLON NUM_INTEGER COMMA Funcao_Integral R_PAREN SEMICOLON  */
#line 187 "sintatico.y"
                                                                                                        {somatorio((yyvsp[-8].string_id), (yyvsp[-6].inteiro), (yyvsp[-4].inteiro), AST,hashTable); /*Delete_Tree(AST);*/}
#line 1568 "sintatico.yy.cc"
    break;

  case 39: /* Matrix: MATRIX EQUAL ChamaCreateMatrix  */
#line 192 "sintatico.y"
                                       {}
#line 1574 "sintatico.yy.cc"
    break;

  case 40: /* Matrix: SHOW MATRIX SEMICOLON  */
#line 193 "sintatico.y"
                                { showMatriz(); return CONTINUE_VALUE;}
#line 1580 "sintatico.yy.cc"
    break;

  case 41: /* Matrix: SOLVE DETERMINANT SEMICOLON  */
#line 194 "sintatico.y"
                                    { determinanteMatriz(); return CONTINUE_VALUE;}
#line 1586 "sintatico.yy.cc"
    break;

  case 42: /* Matrix: SOLVE LINEAR_SYSTEM SEMICOLON  */
#line 195 "sintatico.y"
                                      { solveLinearSystem();  return CONTINUE_VALUE;}
#line 1592 "sintatico.yy.cc"
    break;

  case 43: /* ChamaCreateMatrix: CreateMatrix  */
#line 197 "sintatico.y"
                                {    
                                 matriz_global = createMatriz(listMatriz,elemtsPlinha,maisElementosLinha); elementosLinha = 0; maisElementosLinha = 0;
 /* destruir listas aqui */ }
#line 1600 "sintatico.yy.cc"
    break;

  case 44: /* CreateMatrix: L_SQUARE_BRACKET CreateMatrixAux R_SQUARE_BRACKET SEMICOLON  */
#line 202 "sintatico.y"
                                                                          {}
#line 1606 "sintatico.yy.cc"
    break;

  case 45: /* $@2: %empty  */
#line 204 "sintatico.y"
                                                        { elementosLinha++; listMatriz.push_back((yyvsp[-1].inteiro)*(yyvsp[0].real)); }
#line 1612 "sintatico.yy.cc"
    break;

  case 46: /* $@3: %empty  */
#line 205 "sintatico.y"
                                                 { elemtsPlinha.push_back(elementosLinha); maisElementosLinha = (elementosLinha > maisElementosLinha) ? elementosLinha : maisElementosLinha;
                                         elementosLinha = 0; }
#line 1619 "sintatico.yy.cc"
    break;

  case 47: /* CreateMatrixAux: L_SQUARE_BRACKET Sinal ValorIntOrFloat $@2 RepeatValuesMatrixOne R_SQUARE_BRACKET $@3 RepeatValuesMatrixTwo  */
#line 206 "sintatico.y"
                                                                                    { }
#line 1625 "sintatico.yy.cc"
    break;

  case 48: /* $@4: %empty  */
#line 208 "sintatico.y"
                                                   {elementosLinha++; listMatriz.push_back((yyvsp[-1].inteiro)*(yyvsp[0].real)); }
#line 1631 "sintatico.yy.cc"
    break;

  case 49: /* RepeatValuesMatrixOne: COMMA Sinal ValorIntOrFloat $@4 RepeatValuesMatrixOne  */
#line 208 "sintatico.y"
                                                                                                                           {}
#line 1637 "sintatico.yy.cc"
    break;

  case 50: /* RepeatValuesMatrixOne: %empty  */
#line 209 "sintatico.y"
                      {}
#line 1643 "sintatico.yy.cc"
    break;

  case 51: /* $@5: %empty  */
#line 211 "sintatico.y"
                                                                    {elementosLinha++; listMatriz.push_back((yyvsp[-1].inteiro)*(yyvsp[0].real));  }
#line 1649 "sintatico.yy.cc"
    break;

  case 52: /* $@6: %empty  */
#line 212 "sintatico.y"
                                                { elemtsPlinha.push_back(elementosLinha); maisElementosLinha = (elementosLinha > maisElementosLinha) ? elementosLinha : maisElementosLinha;
                                         elementosLinha = 0; }
#line 1656 "sintatico.yy.cc"
    break;

  case 53: /* RepeatValuesMatrixTwo: COMMA L_SQUARE_BRACKET Sinal ValorIntOrFloat $@5 RepeatValuesMatrixOne R_SQUARE_BRACKET $@6 RepeatValuesMatrixTwo  */
#line 213 "sintatico.y"
                                                                                     {}
#line 1662 "sintatico.yy.cc"
    break;

  case 54: /* RepeatValuesMatrixTwo: %empty  */
#line 214 "sintatico.y"
                       {}
#line 1668 "sintatico.yy.cc"
    break;

  case 55: /* Integral: INTEGRATE L_PAREN IntegralAux R_PAREN SEMICOLON  */
#line 219 "sintatico.y"
                                                          {}
#line 1674 "sintatico.yy.cc"
    break;

  case 56: /* IntegralAux: Sinal ValorIntOrFloat COLON Sinal ValorIntOrFloat COMMA Funcao_Integral  */
#line 221 "sintatico.y"
                                                                                     { integrate((yyvsp[-6].inteiro)*(yyvsp[-5].real), (yyvsp[-3].inteiro)*(yyvsp[-2].real), AST,hashTable); /*Delete_Tree(AST);*/}
#line 1680 "sintatico.yy.cc"
    break;

  case 57: /* Expressao_matematica_Direta: Funcao_Integral  */
#line 225 "sintatico.y"
                                             {printarExpressao();}
#line 1686 "sintatico.yy.cc"
    break;

  case 58: /* Funcao_Integral: Integral_aux  */
#line 228 "sintatico.y"
                              { AST = (yyvsp[0].ast); if(!dont_worry){valorExp = calculate_Exp(AST, hashTable);} }
#line 1692 "sintatico.yy.cc"
    break;

  case 59: /* Integral_aux: Integral_DivMul  */
#line 231 "sintatico.y"
                              { (yyval.ast) = (yyvsp[0].ast);}
#line 1698 "sintatico.yy.cc"
    break;

  case 60: /* Integral_aux: Integral_aux PLUS Integral_DivMul  */
#line 233 "sintatico.y"
                                          {     TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = ADD;
                                                aux->value = 0;
                                                aux->name = "cos";
                                                aux->left = (yyvsp[-2].ast);
                                                aux->right = (yyvsp[0].ast);
                                                (yyval.ast) = aux;
                                        }
#line 1711 "sintatico.yy.cc"
    break;

  case 61: /* Integral_aux: Integral_aux MINUS Integral_DivMul  */
#line 242 "sintatico.y"
                                         {      TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = SUB;
                                                aux->value = 0;
                                                aux->name = "cos";
                                                aux->left = (yyvsp[-2].ast);
                                                aux->right = (yyvsp[0].ast);
                                                (yyval.ast) = aux;
                                        }
#line 1724 "sintatico.yy.cc"
    break;

  case 62: /* Integral_DivMul: Integral_Complemento  */
#line 251 "sintatico.y"
                                      { (yyval.ast) = (yyvsp[0].ast);}
#line 1730 "sintatico.yy.cc"
    break;

  case 63: /* Integral_DivMul: Integral_DivMul MULTIPLY Integral_Complemento  */
#line 252 "sintatico.y"
                                                        {       TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                                aux->node_type = MUL;
                                                                aux->value = 0;
                                                                aux->name = "cos";
                                                                aux->left = (yyvsp[-2].ast);
                                                                aux->right = (yyvsp[0].ast);
                                                                (yyval.ast) = aux;
                                                        }
#line 1743 "sintatico.yy.cc"
    break;

  case 64: /* Integral_DivMul: Integral_DivMul DIV Integral_Complemento  */
#line 261 "sintatico.y"
                                                    {   TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                        aux->node_type = DI;
                                                        aux->value = 0;
                                                        aux->name = "cos";
                                                        aux->left = (yyvsp[-2].ast);
                                                        aux->right = (yyvsp[0].ast);
                                                        (yyval.ast) = aux;
                                                        }
#line 1756 "sintatico.yy.cc"
    break;

  case 65: /* Integral_Complemento: Sinal ValorIntOrFloat  */
#line 271 "sintatico.y"
                                             { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = NUMBER;
                                                aux->value = (yyvsp[-1].inteiro)*(yyvsp[0].real);
                                                aux->name = "cos";
                                                aux->left = NULL;

                                                aux->right = NULL;
                                                (yyval.ast) = (TreeNode*) aux;
                                                }
#line 1770 "sintatico.yy.cc"
    break;

  case 66: /* $@7: %empty  */
#line 281 "sintatico.y"
                         {str_aux  = strdup((yyvsp[0].string_id)); }
#line 1776 "sintatico.yy.cc"
    break;

  case 67: /* Integral_Complemento: Sinal IDENTIFIER $@7 continua_id  */
#line 281 "sintatico.y"
                                                               {   
                                        
                                        TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                        aux->node_type = IDENTIFIER_NODE;
                                        if(hashTable.search(str) == NULL){
                                                aux->value = 0;
                                                
                                        }else if(hashTable.getType(str)== 0){
                                        aux->value = (yyvsp[-3].inteiro)*(*(static_cast<float*>(hashTable.search(str))));
                                        }else if(hashTable.getType(str)== 1){
                                                aux->value = 0;
                                                multiplyMatrixByScalar(*(static_cast<std::vector<std::vector<float>>*>(hashTable.search(str))), (yyvsp[-3].inteiro));
                                                matriz_exp = true;
                                                // if((*(static_cast<std::vector<std::vector<float>>*>(hashTable.search(str)))).size() == 2){
                                                //         return CONTINUE_VALUE;
                                                // }

                                        }
                                        aux->name = str;
                                        aux->left = NULL;
                                        aux->right = NULL;
                                        (yyval.ast) = (TreeNode*) aux; 
                        }
#line 1804 "sintatico.yy.cc"
    break;

  case 68: /* Integral_Complemento: COS L_PAREN Integral_Complemento R_PAREN  */
#line 305 "sintatico.y"
                                                   {    TreeNode* cosNode = (TreeNode*)malloc(sizeof(struct node));
                                                        
                                                        cosNode->node_type = COS_NODE;
                                                        cosNode->value = 0;
                                                        cosNode->name = "cos";
                                                        cosNode->left = (yyvsp[-1].ast); // AST do complemento
                                                        cosNode->right = NULL;
                                                        (yyval.ast) = (TreeNode*) cosNode;
                                                }
#line 1818 "sintatico.yy.cc"
    break;

  case 69: /* Integral_Complemento: SEN L_PAREN Integral_Complemento R_PAREN  */
#line 315 "sintatico.y"
                                                   {    TreeNode* senNode = (TreeNode*)malloc(sizeof(struct node));
                                                        senNode->node_type = SEN_NODE;
                                                        senNode->value = 0;
                                                        senNode->name = "cos";
                                                        senNode->left = (yyvsp[-1].ast); // AST do complemento
                                                        senNode->right = NULL;
                                                        (yyval.ast) = (TreeNode*) senNode;
                                                }
#line 1831 "sintatico.yy.cc"
    break;

  case 70: /* Integral_Complemento: TAN L_PAREN Integral_Complemento R_PAREN  */
#line 323 "sintatico.y"
                                                   {    TreeNode* tanNode = (TreeNode*)malloc(sizeof(struct node));
                                                        tanNode->node_type = TAN_NODE;
                                                        tanNode->value = 0;
                                                        tanNode->name = "cos";
                                                        tanNode->left = (yyvsp[-1].ast); // AST do complemento
                                                        tanNode->right = NULL;
                                                        (yyval.ast) = (TreeNode*) tanNode;
                                                }
#line 1844 "sintatico.yy.cc"
    break;

  case 71: /* Integral_Complemento: X  */
#line 332 "sintatico.y"
          {     TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                aux->node_type = X_NODE;
                                aux->value = 0;
                               
                                                        aux->name = "cos";
                                aux->left = NULL;
                                aux->right = NULL;
                                (yyval.ast) = (TreeNode*) aux; 
                        }
#line 1858 "sintatico.yy.cc"
    break;

  case 72: /* Integral_Complemento: ABS L_PAREN Integral_Complemento R_PAREN  */
#line 342 "sintatico.y"
                                                 {      TreeNode* absNode = (TreeNode*)malloc(sizeof(struct node));
                                                        absNode->node_type = ABS_NODE;
                                                        absNode->value = 0;
                                                        absNode->name = "cos";
                                                        absNode->left = (yyvsp[-1].ast); // AST do complemento
                                                        absNode->right = NULL;
                                                        (yyval.ast) = (TreeNode*) absNode;
                                                }
#line 1871 "sintatico.yy.cc"
    break;

  case 73: /* Integral_Complemento: L_PAREN Integral_aux R_PAREN  */
#line 351 "sintatico.y"
                                       {(yyval.ast) = (yyvsp[-1].ast);}
#line 1877 "sintatico.yy.cc"
    break;

  case 74: /* Integral_Complemento: PI  */
#line 353 "sintatico.y"
           { TreeNode* piNode = (TreeNode*)malloc(sizeof(struct node));
            piNode->node_type = NUMBER;
            piNode->value = M_PI;
            piNode->name = "cos";
            piNode->left = NULL;
            piNode->right = NULL;
            (yyval.ast) = (TreeNode*) piNode;
            }
#line 1890 "sintatico.yy.cc"
    break;

  case 75: /* Integral_Complemento: E  */
#line 362 "sintatico.y"
          { TreeNode* eNode = (TreeNode*)malloc(sizeof(struct node));
            eNode->node_type = NUMBER;
            eNode->value = M_E;
                eNode->name = "cos";
            eNode->left = NULL;
            eNode->right = NULL;
            (yyval.ast) = (TreeNode*) eNode;
            }
#line 1903 "sintatico.yy.cc"
    break;

  case 76: /* $@8: %empty  */
#line 371 "sintatico.y"
                      {str_aux2 = str_aux;}
#line 1909 "sintatico.yy.cc"
    break;

  case 77: /* continua_id: ATRIBUTE $@8 continua_atribute  */
#line 371 "sintatico.y"
                                                              {}
#line 1915 "sintatico.yy.cc"
    break;

  case 78: /* continua_id: SEMICOLON EOL  */
#line 372 "sintatico.y"
                        {printValorSimbolo(str_aux, hashTable);  matriz_exp = false; return CONTINUE_VALUE;}
#line 1921 "sintatico.yy.cc"
    break;

  case 79: /* continua_id: %empty  */
#line 373 "sintatico.y"
          { }
#line 1927 "sintatico.yy.cc"
    break;

  case 80: /* continua_atribute: Expressao_matematica SEMICOLON EOL  */
#line 375 "sintatico.y"
                                                      { AtribuirValor(); return CONTINUE_VALUE;}
#line 1933 "sintatico.yy.cc"
    break;

  case 81: /* continua_atribute: ChamaCreateMatrix EOL  */
#line 377 "sintatico.y"
                                        {sinal = 1; hashTable.insert(str,matriz_global);
                /*Delete_Tree(AST);*/ not_existId = false; matriz_exp = false; return CONTINUE_VALUE;}
#line 1940 "sintatico.yy.cc"
    break;

  case 82: /* Expressao_matematica: %empty  */
#line 384 "sintatico.y"
                      {}
#line 1946 "sintatico.yy.cc"
    break;

  case 83: /* Expressao_matematica: Expressao_matematica Exp_aux  */
#line 385 "sintatico.y"
                                                     { AST = (yyvsp[0].ast); if(!not_existId && !matriz_exp){valorExp = calculate_Exp(AST, hashTable); }else if(!not_existId && matriz_exp){ matriz_exp_global = solve_Matriz_expressao(AST, hashTable); }  }
#line 1952 "sintatico.yy.cc"
    break;

  case 84: /* Exp_aux: Exp_DivMul  */
#line 387 "sintatico.y"
                    {  (yyval.ast) = (yyvsp[0].ast);}
#line 1958 "sintatico.yy.cc"
    break;

  case 85: /* Exp_aux: Exp_aux PLUS Exp_DivMul  */
#line 388 "sintatico.y"
                              {     TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = ADD;
                                                aux->value = 0;
                                                aux->left = (yyvsp[-2].ast);
                                                aux->right = (yyvsp[0].ast);
                                                (yyval.ast) = aux;  
                                        }
#line 1970 "sintatico.yy.cc"
    break;

  case 86: /* Exp_aux: Exp_aux MINUS Exp_DivMul  */
#line 396 "sintatico.y"
                               {   TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = SUB;
                                                aux->value = 0;
                                                aux->left = (yyvsp[-2].ast);
                                                aux->right = (yyvsp[0].ast);
                                                (yyval.ast) = aux;}
#line 1981 "sintatico.yy.cc"
    break;

  case 87: /* Exp_DivMul: Exp_Complemento  */
#line 403 "sintatico.y"
                            { (yyval.ast) = (yyvsp[0].ast); }
#line 1987 "sintatico.yy.cc"
    break;

  case 88: /* Exp_DivMul: Exp_DivMul MULTIPLY Exp_Complemento  */
#line 404 "sintatico.y"
                                              {    TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                                aux->node_type = MUL;
                                                                aux->value = 0;
                                                                aux->left = (yyvsp[-2].ast);
                                                                aux->right = (yyvsp[0].ast);
                                                                (yyval.ast) = aux;}
#line 1998 "sintatico.yy.cc"
    break;

  case 89: /* Exp_DivMul: Exp_DivMul DIV Exp_Complemento  */
#line 411 "sintatico.y"
                                         { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                        aux->node_type = DI;
                                                        aux->value = 0;
                                                        aux->left = (yyvsp[-2].ast);
                                                        aux->right = (yyvsp[0].ast);
                                                        (yyval.ast) = aux;}
#line 2009 "sintatico.yy.cc"
    break;

  case 90: /* Exp_Complemento: Sinal ValorIntOrFloat  */
#line 419 "sintatico.y"
                                       { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = NUMBER;
                                                aux->value = (yyvsp[-1].inteiro)*(yyvsp[0].real);
                                                aux->left = NULL;
                                                aux->right = NULL;
                                                (yyval.ast) = (TreeNode*) aux; }
#line 2020 "sintatico.yy.cc"
    break;

  case 91: /* Exp_Complemento: Sinal IDENTIFIER  */
#line 426 "sintatico.y"
                            {TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                        aux->node_type = IDENTIFIER_NODE;
                                        if(hashTable.search(str) == NULL){
                                                aux->value = 0;
                                        } else if(hashTable.getType(str)== 0){
                                        aux->value = (yyvsp[-1].inteiro)*(*(static_cast<float*>(hashTable.search(str))));
                                        }else if(hashTable.getType(str)== 1){
                                                aux->value = 0;
                                                multiplyMatrixByScalar(*(static_cast<std::vector<std::vector<float>>*>(hashTable.search(str))), (yyvsp[-1].inteiro));
                                                matriz_exp = true;
                                                
                                        }
                                       
                                        aux->name = str;
                                        aux->left = NULL;
                                        aux->right = NULL;
                                        (yyval.ast) = (TreeNode*) aux; }
#line 2042 "sintatico.yy.cc"
    break;

  case 92: /* Exp_Complemento: COS L_PAREN Exp_Complemento R_PAREN  */
#line 444 "sintatico.y"
                                              {  TreeNode* cosNode = (TreeNode*)malloc(sizeof(struct node));
                                                        cosNode->node_type = COS_NODE;
                                                        cosNode->left = (yyvsp[-1].ast); // AST do complemento
                                                        cosNode->right = NULL;
                                                        (yyval.ast) = (TreeNode*) cosNode;}
#line 2052 "sintatico.yy.cc"
    break;

  case 93: /* Exp_Complemento: SEN L_PAREN Exp_Complemento R_PAREN  */
#line 449 "sintatico.y"
                                              {  TreeNode* senNode = (TreeNode*)malloc(sizeof(struct node));
                                                        senNode->node_type = SEN_NODE;
                                                        senNode->left = (yyvsp[-1].ast); // AST do complemento
                                                        senNode->right = NULL;
                                                        (yyval.ast) = (TreeNode*) senNode;}
#line 2062 "sintatico.yy.cc"
    break;

  case 94: /* Exp_Complemento: TAN L_PAREN Exp_Complemento R_PAREN  */
#line 454 "sintatico.y"
                                              { TreeNode* tanNode = (TreeNode*)malloc(sizeof(struct node));
                                                        tanNode->node_type = TAN_NODE;
                                                        tanNode->left = (yyvsp[-1].ast); // AST do complemento
                                                        tanNode->right = NULL;
                                                        (yyval.ast) = (TreeNode*) tanNode; }
#line 2072 "sintatico.yy.cc"
    break;

  case 95: /* Exp_Complemento: X  */
#line 459 "sintatico.y"
            { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                aux->node_type = X_NODE;
                                aux->value = 0;
                                aux->left = NULL;
                                aux->right = NULL;
                                (yyval.ast) = (TreeNode*) aux; }
#line 2083 "sintatico.yy.cc"
    break;

  case 96: /* Exp_Complemento: PI  */
#line 465 "sintatico.y"
             { TreeNode* piNode = (TreeNode*)malloc(sizeof(struct node));
            piNode->node_type = NUMBER;
            piNode->value = M_PI;
            piNode->left = NULL;
            piNode->right = NULL;
            (yyval.ast) = (TreeNode*) piNode;
            }
#line 2095 "sintatico.yy.cc"
    break;

  case 97: /* Exp_Complemento: E  */
#line 473 "sintatico.y"
          { TreeNode* eNode = (TreeNode*)malloc(sizeof(struct node));
            eNode->node_type = NUMBER;
            eNode->value = M_E;
            eNode->left = NULL;
            eNode->right = NULL;
            (yyval.ast) = (TreeNode*) eNode;
            }
#line 2107 "sintatico.yy.cc"
    break;

  case 98: /* Exp_Complemento: ABS L_PAREN Exp_Complemento R_PAREN  */
#line 480 "sintatico.y"
                                              { TreeNode* absNode = (TreeNode*)malloc(sizeof(struct node));
                                                        absNode->node_type = ABS_NODE;
                                                        absNode->left = (yyvsp[-1].ast); // AST do complemento
                                                        absNode->right = NULL;
                                                        (yyval.ast) = (TreeNode*) absNode; }
#line 2117 "sintatico.yy.cc"
    break;

  case 99: /* Exp_Complemento: L_PAREN Exp_aux R_PAREN  */
#line 485 "sintatico.y"
                                  { (yyval.ast) = (yyvsp[-1].ast); }
#line 2123 "sintatico.yy.cc"
    break;


#line 2127 "sintatico.yy.cc"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 508 "sintatico.y"


void yyerror(char *s) {
	
        printf("\nSYNTAX ERROR: [%s]\n\n", yytext);
}

int main(int argc, char** argv)
{
    
    setDefaultValues();
    int input = 0;

    while(input != QUIT_VALUE){
    printf(">");
    input  = yyparse();
    
    } 
    
    printf("SUCCESSFUL COMPILATION.");
    return 0;
}

void printarExpressao(){
        if(!not_existId && !matriz_exp)
        {
                printValorCalculoExp(valorExp);

        }else if(!not_existId && matriz_exp){
                matriz_exp_global = solve_Matriz_expressao(AST, hashTable); 
                if(!break_matriz){
                printMatriz(matriz_exp_global);
                }else{
                        break_matriz = false;
                }
        } 

        matriz_exp =false; 
        not_existId = false; 
        /*Delete_Tree(AST);*/
}

void AtribuirValor(){
         sinal = 1; 
         if(!not_existId && !matriz_exp){

                hashTable.insert(str_aux2,valorExp);

        }else if(!not_existId && matriz_exp){
                if(!break_matriz){

                hashTable.insert(str_aux2,matriz_exp_global);

                }else{
                        break_matriz = false;
                }

        } 
        not_existId = false; 
        matriz_exp = false; 
}
