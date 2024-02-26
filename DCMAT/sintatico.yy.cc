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

std::string universal;
std::string str;
std::string str_aux;
std::string str_aux2;

std::vector<std::vector<float>> matriz_global;

HashTable hashTable;

std::list<float> listMatriz;
std::list<int> elemtsPlinha;

int elementosLinha = 0;
int maisElementosLinha = 0;
float valorExp = 0;
int sinal = 1;

TreeNode* AST = NULL;

extern void yyerror(char*); 


#line 118 "sintatico.yy.cc"

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
  YYSYMBOL_Comandos = 56,                  /* Comandos  */
  YYSYMBOL_OnlyComandos = 57,              /* OnlyComandos  */
  YYSYMBOL_FuncoesSet = 58,                /* FuncoesSet  */
  YYSYMBOL_ValorIntOrFloat = 59,           /* ValorIntOrFloat  */
  YYSYMBOL_Sinal = 60,                     /* Sinal  */
  YYSYMBOL_ONorOFF = 61,                   /* ONorOFF  */
  YYSYMBOL_ComandosPlus = 62,              /* ComandosPlus  */
  YYSYMBOL_Grafico = 63,                   /* Grafico  */
  YYSYMBOL_InfoPlot = 64,                  /* InfoPlot  */
  YYSYMBOL_FuncaoPlot = 65,                /* FuncaoPlot  */
  YYSYMBOL_InsideFuncoes = 66,             /* InsideFuncoes  */
  YYSYMBOL_FuncaoRpn = 67,                 /* FuncaoRpn  */
  YYSYMBOL_Integral = 68,                  /* Integral  */
  YYSYMBOL_IntegralAux = 69,               /* IntegralAux  */
  YYSYMBOL_Funcao_Integral = 70,           /* Funcao_Integral  */
  YYSYMBOL_Integral_aux = 71,              /* Integral_aux  */
  YYSYMBOL_Integral_DivMul = 72,           /* Integral_DivMul  */
  YYSYMBOL_Integral_Complemento = 73,      /* Integral_Complemento  */
  YYSYMBOL_74_1 = 74,                      /* $@1  */
  YYSYMBOL_Sum = 75,                       /* Sum  */
  YYSYMBOL_Matrix = 76,                    /* Matrix  */
  YYSYMBOL_ChamaCreateMatrix = 77,         /* ChamaCreateMatrix  */
  YYSYMBOL_CreateMatrix = 78,              /* CreateMatrix  */
  YYSYMBOL_CreateMatrixAux = 79,           /* CreateMatrixAux  */
  YYSYMBOL_80_2 = 80,                      /* $@2  */
  YYSYMBOL_81_3 = 81,                      /* $@3  */
  YYSYMBOL_RepeatValuesMatrixOne = 82,     /* RepeatValuesMatrixOne  */
  YYSYMBOL_83_4 = 83,                      /* $@4  */
  YYSYMBOL_RepeatValuesMatrixTwo = 84,     /* RepeatValuesMatrixTwo  */
  YYSYMBOL_85_5 = 85,                      /* $@5  */
  YYSYMBOL_86_6 = 86,                      /* $@6  */
  YYSYMBOL_ManipulacaoSimbolos = 87,       /* ManipulacaoSimbolos  */
  YYSYMBOL_continua_id = 88,               /* continua_id  */
  YYSYMBOL_89_7 = 89,                      /* $@7  */
  YYSYMBOL_continua_atribute = 90,         /* continua_atribute  */
  YYSYMBOL_Expressao_matematica_Direta = 91, /* Expressao_matematica_Direta  */
  YYSYMBOL_Expressao_matematica = 92,      /* Expressao_matematica  */
  YYSYMBOL_Exp_aux = 93,                   /* Exp_aux  */
  YYSYMBOL_Exp_DivMul = 94,                /* Exp_DivMul  */
  YYSYMBOL_Exp_Complemento = 95,           /* Exp_Complemento  */
  YYSYMBOL_Funcoes = 96,                   /* Funcoes  */
  YYSYMBOL_OperadoresBinarios = 97,        /* OperadoresBinarios  */
  YYSYMBOL_Constantes = 98                 /* Constantes  */
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
#define YYLAST   246

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  245

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
       0,   119,   119,   120,   121,   122,   124,   125,   127,   128,
     129,   130,   131,   135,   136,   137,   138,   139,   140,   141,
     144,   145,   147,   148,   149,   153,   154,   156,   157,   158,
     159,   160,   163,   166,   167,   169,   171,   172,   173,   174,
     175,   176,   180,   184,   186,   189,   192,   194,   203,   212,
     213,   222,   232,   242,   242,   264,   274,   282,   291,   301,
     310,   312,   321,   333,   336,   337,   338,   339,   341,   347,
     349,   350,   349,   353,   353,   354,   356,   357,   356,   359,
     365,   368,   368,   369,   370,   372,   373,   380,   386,   387,
     389,   390,   398,   405,   406,   413,   421,   428,   442,   447,
     452,   457,   463,   471,   478,   483,   488,   489,   490,   492,
     493,   494,   495,   496,   497,   500,   501
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
  "EOL", "$accept", "Programa", "Comandos", "OnlyComandos", "FuncoesSet",
  "ValorIntOrFloat", "Sinal", "ONorOFF", "ComandosPlus", "Grafico",
  "InfoPlot", "FuncaoPlot", "InsideFuncoes", "FuncaoRpn", "Integral",
  "IntegralAux", "Funcao_Integral", "Integral_aux", "Integral_DivMul",
  "Integral_Complemento", "$@1", "Sum", "Matrix", "ChamaCreateMatrix",
  "CreateMatrix", "CreateMatrixAux", "$@2", "$@3", "RepeatValuesMatrixOne",
  "$@4", "RepeatValuesMatrixTwo", "$@5", "$@6", "ManipulacaoSimbolos",
  "continua_id", "$@7", "continua_atribute", "Expressao_matematica_Direta",
  "Expressao_matematica", "Exp_aux", "Exp_DivMul", "Exp_Complemento",
  "Funcoes", "OperadoresBinarios", "Constantes", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-229)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,     2,  -229,    -3,     7,    15,     6,     9,  -229,    17,
      21,    73,    46,    37,    55,  -229,    58,   161,  -229,  -229,
    -229,    84,  -229,   105,    70,  -229,     4,  -229,  -229,  -229,
    -229,  -229,     0,    50,  -229,  -229,  -229,    82,    88,  -229,
      84,    95,   118,   137,   138,   139,   140,   141,    81,   181,
      84,   143,   142,    84,    84,    84,   172,    81,    54,   136,
      54,    81,   184,   149,   102,  -229,  -229,  -229,  -229,  -229,
    -229,    84,    84,    84,    84,  -229,  -229,   150,  -229,  -229,
    -229,   151,   153,  -229,  -229,  -229,  -229,  -229,  -229,    80,
     154,   152,   155,  -229,   156,  -229,  -229,   158,   159,   160,
      81,    80,  -229,  -229,  -229,  -229,  -229,    80,    54,  -229,
    -229,   -21,    50,    50,  -229,  -229,  -229,  -229,    33,   163,
     157,   162,  -229,    81,   166,   167,  -229,  -229,   164,   173,
     174,  -229,   168,  -229,  -229,  -229,  -229,    33,  -229,  -229,
    -229,  -229,  -229,  -229,    33,    33,   165,    33,    33,    81,
    -229,   175,    80,   178,  -229,  -229,    81,    81,  -229,   142,
    -229,   170,  -229,  -229,  -229,  -229,    80,   171,  -229,  -229,
      80,    80,   176,  -229,    71,    33,   180,   182,   183,  -229,
    -229,  -229,  -229,   179,   185,   186,  -229,   187,  -229,   188,
     122,     8,    97,    98,  -229,  -229,    84,    84,    81,   189,
     122,   122,   122,   122,  -229,   132,  -229,  -229,   122,   122,
     122,   122,  -229,   190,    80,  -229,   192,   193,   194,   196,
    -229,    98,    98,  -229,  -229,   191,  -229,   200,  -229,  -229,
    -229,  -229,  -229,   183,   197,  -229,  -229,    81,    80,  -229,
     183,   198,  -229,   200,  -229
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      24,     0,    61,     0,    34,     0,     0,     0,    10,     0,
       0,     0,     0,     0,     0,    62,     0,     0,    58,    22,
      23,    24,     5,     0,     0,     6,     0,     7,    27,    28,
      29,    87,    45,    46,    49,    30,    31,     0,     0,    12,
      24,     0,     0,     0,     0,     0,     0,     0,    24,     0,
      24,     0,     0,    24,    24,    24,     0,    24,     0,     0,
       0,    24,     0,     0,     0,     1,     2,    53,    20,    21,
      52,    24,    24,    24,    24,     3,     4,     0,   106,   108,
     107,     0,     0,    32,     8,    80,    65,    67,    66,     0,
       0,     0,     0,     9,     0,    64,    68,     0,     0,     0,
      24,     0,    26,    25,    15,    19,    17,     0,     0,    11,
      60,    84,    47,    48,    50,    51,    59,    33,    41,     0,
       0,     0,    55,    24,     0,     0,    57,    56,     0,     0,
       0,    16,     0,    81,    54,   115,   116,    41,   109,   110,
     111,   112,   114,   113,    41,    41,     0,    41,    41,    24,
      43,     0,     0,     0,    42,    18,    24,    24,    83,    88,
      37,     0,    40,    35,    38,    39,     0,     0,    70,    69,
       0,     0,     0,    82,    24,    41,     0,     0,    75,    13,
      14,    86,   102,     0,     0,     0,   103,     0,   101,     0,
      24,     0,    89,    90,    93,    36,    24,    24,    24,     0,
      24,    24,    24,    24,    85,     0,    97,    96,    24,    24,
      24,    24,    44,     0,     0,    71,     0,     0,     0,     0,
     105,    91,    92,    94,    95,     0,    73,    79,   104,    98,
     100,    99,    63,    75,     0,    72,    74,    24,     0,    76,
      75,     0,    77,    79,    78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -229,  -229,  -229,  -229,  -229,   -26,   -47,   -41,  -229,  -229,
    -229,  -229,   -51,  -229,  -229,  -229,   -50,   206,   100,    -9,
    -229,  -229,  -229,    43,  -229,  -229,  -229,  -229,  -228,  -229,
     -35,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,    20,
     -33,  -153,  -229,  -229,  -229
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    23,    24,    25,    63,   145,    26,   104,    27,    28,
      42,    81,   146,    29,    30,    90,    31,    32,    33,    34,
     111,    35,    36,    95,    96,   124,   178,   227,   199,   233,
     235,   240,   243,    37,   134,   159,   173,    38,   174,   192,
     193,   194,    82,   147,   148
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      70,    89,     1,    97,     2,   236,     3,    67,     4,     5,
     101,   206,   241,     6,   107,     7,     8,     9,    10,   106,
      11,   132,    43,    12,    13,    14,    15,    46,    16,   133,
      47,    77,    17,    18,    19,    20,    71,    72,    44,   135,
      45,    92,    40,    21,    39,    98,    99,   216,   217,   218,
     219,    22,    41,   128,    48,    68,    69,   223,   224,    68,
      69,   136,    49,   119,   114,   115,    50,   131,   137,   138,
     139,   140,   141,   142,   143,   129,   152,   182,   144,   183,
      51,   130,    53,   102,    68,    69,   160,   103,    73,    74,
       2,   184,     3,   161,   162,    52,   164,   165,   185,   186,
      54,   187,   166,    55,    10,    65,   188,    19,    20,   170,
     171,    14,    15,   189,    16,    78,   190,    19,    20,    18,
      19,    20,    79,    66,   195,    80,   168,   191,   182,    21,
     183,    68,    69,   208,   209,    75,   210,   211,    71,    72,
     176,    76,   184,   191,   179,   180,   212,   213,   110,   185,
     186,   214,   187,   191,   191,   191,   191,   188,    19,    20,
      83,   191,   191,   191,   191,   207,    56,   190,   208,   209,
      57,   112,   113,    58,    59,   221,   222,    60,   220,    84,
      85,    86,    87,    88,    91,    93,   100,   105,   226,    94,
     238,   109,    61,    62,   108,   121,   116,   117,   118,   150,
     120,   122,   172,   123,   125,   126,   127,   149,   244,   154,
     205,   163,   239,   151,   153,   155,   175,   156,   157,   167,
     169,   158,   177,   196,   200,   197,   198,    64,     0,   181,
     201,   202,   203,   232,     0,     0,   225,   215,   228,   229,
     230,   204,   231,   234,   237,     0,   242
};

static const yytype_int16 yycheck[] =
{
      26,    48,     4,    53,     6,   233,     8,     3,    10,    11,
      57,     3,   240,    15,    61,    17,    18,    19,    20,    60,
      22,    42,     7,    25,    26,    27,    28,    21,    30,    50,
      24,    40,    34,    35,    36,    37,    36,    37,    23,     6,
      25,    50,    45,    45,    42,    54,    55,   200,   201,   202,
     203,    53,    45,   100,    45,    51,    52,   210,   211,    51,
      52,    28,    45,    89,    73,    74,    45,   108,    35,    36,
      37,    38,    39,    40,    41,   101,   123,     6,    45,     8,
       7,   107,    45,    29,    51,    52,   137,    33,    38,    39,
       6,    20,     8,   144,   145,    49,   147,   148,    27,    28,
      45,    30,   149,    45,    20,     0,    35,    36,    37,   156,
     157,    27,    28,    42,    30,    20,    45,    36,    37,    35,
      36,    37,    27,    53,   175,    30,   152,   174,     6,    45,
       8,    51,    52,    36,    37,    53,    38,    39,    36,    37,
     166,    53,    20,   190,   170,   171,   196,   197,    46,    27,
      28,   198,    30,   200,   201,   202,   203,    35,    36,    37,
      42,   208,   209,   210,   211,   191,     5,    45,    36,    37,
       9,    71,    72,    12,    13,   208,   209,    16,    46,    42,
      42,    42,    42,    42,     3,    42,    14,    51,   214,    47,
     237,    42,    31,    32,    10,    43,    46,    46,    45,    42,
      46,    46,   159,    47,    46,    46,    46,    44,   243,    42,
     190,    46,   238,    51,    48,    51,    46,    44,    44,    44,
      42,    53,    51,    43,    45,    43,    43,    21,    -1,    53,
      45,    45,    45,    42,    -1,    -1,    46,    48,    46,    46,
      46,    53,    46,    43,    47,    -1,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     6,     8,    10,    11,    15,    17,    18,    19,
      20,    22,    25,    26,    27,    28,    30,    34,    35,    36,
      37,    45,    53,    55,    56,    57,    60,    62,    63,    67,
      68,    70,    71,    72,    73,    75,    76,    87,    91,    42,
      45,    45,    64,     7,    23,    25,    21,    24,    45,    45,
      45,     7,    49,    45,    45,    45,     5,     9,    12,    13,
      16,    31,    32,    58,    71,     0,    53,     3,    51,    52,
      59,    36,    37,    38,    39,    53,    53,    73,    20,    27,
      30,    65,    96,    42,    42,    42,    42,    42,    42,    60,
      69,     3,    73,    42,    47,    77,    78,    70,    73,    73,
      14,    60,    29,    33,    61,    51,    61,    60,    10,    42,
      46,    74,    72,    72,    73,    73,    46,    46,    45,    59,
      46,    43,    46,    47,    79,    46,    46,    46,    60,    59,
      59,    61,    42,    50,    88,     6,    28,    35,    36,    37,
      38,    39,    40,    41,    45,    59,    66,    97,    98,    44,
      42,    51,    60,    48,    42,    51,    44,    44,    53,    89,
      66,    66,    66,    46,    66,    66,    60,    44,    59,    42,
      60,    60,    77,    90,    92,    46,    59,    51,    80,    59,
      59,    53,     6,     8,    20,    27,    28,    30,    35,    42,
      45,    60,    93,    94,    95,    66,    43,    43,    43,    82,
      45,    45,    45,    45,    53,    93,     3,    59,    36,    37,
      38,    39,    70,    70,    60,    48,    95,    95,    95,    95,
      46,    94,    94,    95,    95,    46,    59,    81,    46,    46,
      46,    46,    42,    83,    43,    84,    82,    47,    60,    59,
      85,    82,    48,    86,    84
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    56,    56,    57,    57,
      57,    57,    57,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    60,    60,    60,    61,    61,    62,    62,    62,
      62,    62,    63,    64,    64,    65,    66,    66,    66,    66,
      66,    66,    67,    68,    69,    70,    71,    71,    71,    72,
      72,    72,    73,    74,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    75,    76,    76,    76,    76,    77,    78,
      80,    81,    79,    83,    82,    82,    85,    86,    84,    84,
      87,    89,    88,    88,    88,    90,    90,    91,    92,    92,
      93,    93,    93,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    96,    96,    96,    97,
      97,    97,    97,    97,    97,    98,    98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     1,     1,     1,     3,     3,
       1,     3,     2,     6,     6,     2,     3,     2,     4,     2,
       1,     1,     1,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     0,     4,     4,     2,     2,     2,
       2,     0,     5,     5,     7,     1,     1,     3,     3,     1,
       3,     3,     2,     0,     4,     4,     4,     4,     1,     4,
       3,     1,     1,    11,     3,     3,     3,     3,     1,     4,
       0,     0,     8,     0,     5,     0,     0,     0,     9,     0,
       3,     0,     3,     2,     0,     3,     2,     1,     0,     2,
       1,     3,     3,     1,     3,     3,     2,     2,     4,     4,
       4,     1,     1,     1,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
#line 119 "sintatico.y"
                       {return CONTINUE_VALUE;}
#line 1371 "sintatico.yy.cc"
    break;

  case 3: /* Programa: ManipulacaoSimbolos EOL  */
#line 120 "sintatico.y"
                                  {return CONTINUE_VALUE;}
#line 1377 "sintatico.yy.cc"
    break;

  case 4: /* Programa: Expressao_matematica_Direta EOL  */
#line 121 "sintatico.y"
                                          {return CONTINUE_VALUE;}
#line 1383 "sintatico.yy.cc"
    break;

  case 5: /* Programa: EOL  */
#line 122 "sintatico.y"
              {return CONTINUE_VALUE;}
#line 1389 "sintatico.yy.cc"
    break;

  case 6: /* Comandos: OnlyComandos  */
#line 124 "sintatico.y"
                       {}
#line 1395 "sintatico.yy.cc"
    break;

  case 7: /* Comandos: ComandosPlus  */
#line 125 "sintatico.y"
                       {}
#line 1401 "sintatico.yy.cc"
    break;

  case 8: /* OnlyComandos: SHOW SETTINGS SEMICOLON  */
#line 127 "sintatico.y"
                                      { showSettings();}
#line 1407 "sintatico.yy.cc"
    break;

  case 9: /* OnlyComandos: RESET SETTINGS SEMICOLON  */
#line 128 "sintatico.y"
                                       { setDefaultValues(); }
#line 1413 "sintatico.yy.cc"
    break;

  case 10: /* OnlyComandos: QUIT  */
#line 129 "sintatico.y"
                   { return QUIT_VALUE;}
#line 1419 "sintatico.yy.cc"
    break;

  case 11: /* OnlyComandos: SET FuncoesSet SEMICOLON  */
#line 130 "sintatico.y"
                                       {}
#line 1425 "sintatico.yy.cc"
    break;

  case 12: /* OnlyComandos: ABOUT SEMICOLON  */
#line 131 "sintatico.y"
                              { printAbout(); }
#line 1431 "sintatico.yy.cc"
    break;

  case 13: /* FuncoesSet: H_VIEW Sinal ValorIntOrFloat COLON Sinal ValorIntOrFloat  */
#line 135 "sintatico.y"
                                                                     { setH_view((yyvsp[-4].inteiro)*(yyvsp[-3].real), (yyvsp[-1].inteiro)*(yyvsp[0].real)); }
#line 1437 "sintatico.yy.cc"
    break;

  case 14: /* FuncoesSet: V_VIEW Sinal ValorIntOrFloat COLON Sinal ValorIntOrFloat  */
#line 136 "sintatico.y"
                                                                       {setV_view((yyvsp[-4].inteiro)*(yyvsp[-3].real), (yyvsp[-1].inteiro)*(yyvsp[0].real));}
#line 1443 "sintatico.yy.cc"
    break;

  case 15: /* FuncoesSet: AXIS ONorOFF  */
#line 137 "sintatico.y"
                           {setAxis((yyvsp[0].inteiro));}
#line 1449 "sintatico.yy.cc"
    break;

  case 16: /* FuncoesSet: ERASE PLOT ONorOFF  */
#line 138 "sintatico.y"
                                 {setErase((yyvsp[0].inteiro));}
#line 1455 "sintatico.yy.cc"
    break;

  case 17: /* FuncoesSet: CONNECT_DOTS ONorOFF  */
#line 139 "sintatico.y"
                                   {setConnectDots((yyvsp[0].inteiro));}
#line 1461 "sintatico.yy.cc"
    break;

  case 18: /* FuncoesSet: FLOAT PRECISION Sinal NUM_INTEGER  */
#line 140 "sintatico.y"
                                                {setFloatPrecision((yyvsp[-1].inteiro)*(yyvsp[0].inteiro));}
#line 1467 "sintatico.yy.cc"
    break;

  case 19: /* FuncoesSet: INTEGRAL_STEPS NUM_INTEGER  */
#line 141 "sintatico.y"
                                         {setIntegralSteps((yyvsp[0].inteiro));}
#line 1473 "sintatico.yy.cc"
    break;

  case 20: /* ValorIntOrFloat: NUM_INTEGER  */
#line 144 "sintatico.y"
                             {(yyval.real) = (yyvsp[0].inteiro);}
#line 1479 "sintatico.yy.cc"
    break;

  case 21: /* ValorIntOrFloat: NUM_REAL  */
#line 145 "sintatico.y"
                     {(yyval.real) = (yyvsp[0].real);}
#line 1485 "sintatico.yy.cc"
    break;

  case 22: /* Sinal: PLUS  */
#line 147 "sintatico.y"
            {(yyval.inteiro) = 1;}
#line 1491 "sintatico.yy.cc"
    break;

  case 23: /* Sinal: MINUS  */
#line 148 "sintatico.y"
            {(yyval.inteiro) = -1;}
#line 1497 "sintatico.yy.cc"
    break;

  case 24: /* Sinal: %empty  */
#line 149 "sintatico.y"
      {(yyval.inteiro) = 1;}
#line 1503 "sintatico.yy.cc"
    break;

  case 25: /* ONorOFF: ON  */
#line 153 "sintatico.y"
            {(yyval.inteiro) = 1;}
#line 1509 "sintatico.yy.cc"
    break;

  case 26: /* ONorOFF: OFF  */
#line 154 "sintatico.y"
             {(yyval.inteiro) = 0;}
#line 1515 "sintatico.yy.cc"
    break;

  case 27: /* ComandosPlus: Grafico  */
#line 156 "sintatico.y"
                      {}
#line 1521 "sintatico.yy.cc"
    break;

  case 28: /* ComandosPlus: FuncaoRpn  */
#line 157 "sintatico.y"
                        {}
#line 1527 "sintatico.yy.cc"
    break;

  case 29: /* ComandosPlus: Integral  */
#line 158 "sintatico.y"
                       {}
#line 1533 "sintatico.yy.cc"
    break;

  case 30: /* ComandosPlus: Sum  */
#line 159 "sintatico.y"
                  {}
#line 1539 "sintatico.yy.cc"
    break;

  case 31: /* ComandosPlus: Matrix  */
#line 160 "sintatico.y"
                     {}
#line 1545 "sintatico.yy.cc"
    break;

  case 32: /* Grafico: PLOT InfoPlot SEMICOLON  */
#line 163 "sintatico.y"
                                 {return CONTINUE_VALUE;}
#line 1551 "sintatico.yy.cc"
    break;

  case 33: /* InfoPlot: L_PAREN FuncaoPlot R_PAREN  */
#line 166 "sintatico.y"
                                     {return CONTINUE_VALUE;}
#line 1557 "sintatico.yy.cc"
    break;

  case 34: /* InfoPlot: %empty  */
#line 167 "sintatico.y"
          {}
#line 1563 "sintatico.yy.cc"
    break;

  case 35: /* FuncaoPlot: Funcoes L_PAREN InsideFuncoes R_PAREN  */
#line 169 "sintatico.y"
                                                  {return CONTINUE_VALUE;}
#line 1569 "sintatico.yy.cc"
    break;

  case 36: /* InsideFuncoes: L_PAREN InsideFuncoes R_PAREN InsideFuncoes  */
#line 171 "sintatico.y"
                                                          {}
#line 1575 "sintatico.yy.cc"
    break;

  case 37: /* InsideFuncoes: X InsideFuncoes  */
#line 172 "sintatico.y"
                             {}
#line 1581 "sintatico.yy.cc"
    break;

  case 38: /* InsideFuncoes: OperadoresBinarios InsideFuncoes  */
#line 173 "sintatico.y"
                                              {}
#line 1587 "sintatico.yy.cc"
    break;

  case 39: /* InsideFuncoes: Constantes InsideFuncoes  */
#line 174 "sintatico.y"
                                      {}
#line 1593 "sintatico.yy.cc"
    break;

  case 40: /* InsideFuncoes: ValorIntOrFloat InsideFuncoes  */
#line 175 "sintatico.y"
                                           {}
#line 1599 "sintatico.yy.cc"
    break;

  case 41: /* InsideFuncoes: %empty  */
#line 176 "sintatico.y"
              {}
#line 1605 "sintatico.yy.cc"
    break;

  case 42: /* FuncaoRpn: RPN L_PAREN Funcao_Integral R_PAREN SEMICOLON  */
#line 180 "sintatico.y"
                                                         {    RpnFunc(AST); /*Delete_Tree(AST);*/ }
#line 1611 "sintatico.yy.cc"
    break;

  case 43: /* Integral: INTEGRATE L_PAREN IntegralAux R_PAREN SEMICOLON  */
#line 184 "sintatico.y"
                                                          {}
#line 1617 "sintatico.yy.cc"
    break;

  case 44: /* IntegralAux: Sinal ValorIntOrFloat COLON Sinal ValorIntOrFloat COMMA Funcao_Integral  */
#line 186 "sintatico.y"
                                                                                     { integrate((yyvsp[-6].inteiro)*(yyvsp[-5].real), (yyvsp[-3].inteiro)*(yyvsp[-2].real), AST,hashTable); /*Delete_Tree(AST);*/}
#line 1623 "sintatico.yy.cc"
    break;

  case 45: /* Funcao_Integral: Integral_aux  */
#line 189 "sintatico.y"
                              { AST = (yyvsp[0].ast); valorExp = calculate_Exp(AST, hashTable); }
#line 1629 "sintatico.yy.cc"
    break;

  case 46: /* Integral_aux: Integral_DivMul  */
#line 192 "sintatico.y"
                              { (yyval.ast) = (yyvsp[0].ast);}
#line 1635 "sintatico.yy.cc"
    break;

  case 47: /* Integral_aux: Integral_aux PLUS Integral_DivMul  */
#line 194 "sintatico.y"
                                          {     TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = ADD;
                                                aux->value = 0;
                                                aux->name = "cos";
                                                aux->left = (yyvsp[-2].ast);
                                                aux->right = (yyvsp[0].ast);
                                                (yyval.ast) = aux;
                                        }
#line 1648 "sintatico.yy.cc"
    break;

  case 48: /* Integral_aux: Integral_aux MINUS Integral_DivMul  */
#line 203 "sintatico.y"
                                         {      TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = SUB;
                                                aux->value = 0;
                                                aux->name = "cos";
                                                aux->left = (yyvsp[-2].ast);
                                                aux->right = (yyvsp[0].ast);
                                                (yyval.ast) = aux;
                                        }
#line 1661 "sintatico.yy.cc"
    break;

  case 49: /* Integral_DivMul: Integral_Complemento  */
#line 212 "sintatico.y"
                                      { (yyval.ast) = (yyvsp[0].ast);}
#line 1667 "sintatico.yy.cc"
    break;

  case 50: /* Integral_DivMul: Integral_DivMul MULTIPLY Integral_Complemento  */
#line 213 "sintatico.y"
                                                        {       TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                                aux->node_type = MUL;
                                                                aux->value = 0;
                                                                aux->name = "cos";
                                                                aux->left = (yyvsp[-2].ast);
                                                                aux->right = (yyvsp[0].ast);
                                                                (yyval.ast) = aux;
                                                        }
#line 1680 "sintatico.yy.cc"
    break;

  case 51: /* Integral_DivMul: Integral_DivMul DIV Integral_Complemento  */
#line 222 "sintatico.y"
                                                    {   TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                        aux->node_type = DI;
                                                        aux->value = 0;
                                                        aux->name = "cos";
                                                        aux->left = (yyvsp[-2].ast);
                                                        aux->right = (yyvsp[0].ast);
                                                        (yyval.ast) = aux;
                                                        }
#line 1693 "sintatico.yy.cc"
    break;

  case 52: /* Integral_Complemento: Sinal ValorIntOrFloat  */
#line 232 "sintatico.y"
                                             { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = NUMBER;
                                                aux->value = (yyvsp[-1].inteiro)*(yyvsp[0].real);
                                                aux->name = "cos";
                                                aux->left = NULL;

                                                aux->right = NULL;
                                                (yyval.ast) = (TreeNode*) aux;
                                                }
#line 1707 "sintatico.yy.cc"
    break;

  case 53: /* $@1: %empty  */
#line 242 "sintatico.y"
                         {str_aux  = strdup((yyvsp[0].string_id)); }
#line 1713 "sintatico.yy.cc"
    break;

  case 54: /* Integral_Complemento: Sinal IDENTIFIER $@1 continua_id  */
#line 242 "sintatico.y"
                                                               {   
                                        
                                        TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                        aux->node_type = IDENTIFIER_NODE;
                                        if(hashTable.search(str) == NULL){
                                                aux->value = 0;
                                                
                                        }else if(hashTable.getType(str)== 0){
                                        aux->value = (yyvsp[-3].inteiro)*(*(static_cast<float*>(hashTable.search(str))));
                                        }else if(hashTable.getType(str)== 1){
                                                aux->value = 0;
                                                
                                                //multiplyMatrixByScalar(*(static_cast<std::vector<std::vector<float>>*>(hashTable.search(str))), $1);
                                                
                                                matriz_exp = true;
                                        }
                                        aux->name = str;
                                        aux->left = NULL;
                                        aux->right = NULL;
                                        (yyval.ast) = (TreeNode*) aux; 
                        }
#line 1739 "sintatico.yy.cc"
    break;

  case 55: /* Integral_Complemento: COS L_PAREN Integral_Complemento R_PAREN  */
#line 264 "sintatico.y"
                                                   {    TreeNode* cosNode = (TreeNode*)malloc(sizeof(struct node));
                                                        
                                                        cosNode->node_type = COS_NODE;
                                                        cosNode->value = 0;
                                                        cosNode->name = "cos";
                                                        cosNode->left = (yyvsp[-1].ast); // AST do complemento
                                                        cosNode->right = NULL;
                                                        (yyval.ast) = (TreeNode*) cosNode;
                                                }
#line 1753 "sintatico.yy.cc"
    break;

  case 56: /* Integral_Complemento: SEN L_PAREN Integral_Complemento R_PAREN  */
#line 274 "sintatico.y"
                                                   {    TreeNode* senNode = (TreeNode*)malloc(sizeof(struct node));
                                                        senNode->node_type = SEN_NODE;
                                                        senNode->value = 0;
                                                        senNode->name = "cos";
                                                        senNode->left = (yyvsp[-1].ast); // AST do complemento
                                                        senNode->right = NULL;
                                                        (yyval.ast) = (TreeNode*) senNode;
                                                }
#line 1766 "sintatico.yy.cc"
    break;

  case 57: /* Integral_Complemento: TAN L_PAREN Integral_Complemento R_PAREN  */
#line 282 "sintatico.y"
                                                   {    TreeNode* tanNode = (TreeNode*)malloc(sizeof(struct node));
                                                        tanNode->node_type = TAN_NODE;
                                                        tanNode->value = 0;
                                                        tanNode->name = "cos";
                                                        tanNode->left = (yyvsp[-1].ast); // AST do complemento
                                                        tanNode->right = NULL;
                                                        (yyval.ast) = (TreeNode*) tanNode;
                                                }
#line 1779 "sintatico.yy.cc"
    break;

  case 58: /* Integral_Complemento: X  */
#line 291 "sintatico.y"
          {     TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                aux->node_type = X_NODE;
                                aux->value = 0;
                               
                                                        aux->name = "cos";
                                aux->left = NULL;
                                aux->right = NULL;
                                (yyval.ast) = (TreeNode*) aux;
                        }
#line 1793 "sintatico.yy.cc"
    break;

  case 59: /* Integral_Complemento: ABS L_PAREN Integral_Complemento R_PAREN  */
#line 301 "sintatico.y"
                                                 {      TreeNode* absNode = (TreeNode*)malloc(sizeof(struct node));
                                                        absNode->node_type = ABS_NODE;
                                                        absNode->value = 0;
                                                        absNode->name = "cos";
                                                        absNode->left = (yyvsp[-1].ast); // AST do complemento
                                                        absNode->right = NULL;
                                                        (yyval.ast) = (TreeNode*) absNode;
                                                }
#line 1806 "sintatico.yy.cc"
    break;

  case 60: /* Integral_Complemento: L_PAREN Integral_aux R_PAREN  */
#line 310 "sintatico.y"
                                       {(yyval.ast) = (yyvsp[-1].ast);}
#line 1812 "sintatico.yy.cc"
    break;

  case 61: /* Integral_Complemento: PI  */
#line 312 "sintatico.y"
           { TreeNode* piNode = (TreeNode*)malloc(sizeof(struct node));
            piNode->node_type = NUMBER;
            piNode->value = M_PI;
            piNode->name = "cos";
            piNode->left = NULL;
            piNode->right = NULL;
            (yyval.ast) = (TreeNode*) piNode;
            }
#line 1825 "sintatico.yy.cc"
    break;

  case 62: /* Integral_Complemento: E  */
#line 321 "sintatico.y"
          { TreeNode* eNode = (TreeNode*)malloc(sizeof(struct node));
            eNode->node_type = NUMBER;
            eNode->value = M_E;
                eNode->name = "cos";
            eNode->left = NULL;
            eNode->right = NULL;
            (yyval.ast) = (TreeNode*) eNode;
            }
#line 1838 "sintatico.yy.cc"
    break;

  case 63: /* Sum: SUM L_PAREN IDENTIFIER COMMA NUM_INTEGER COLON NUM_INTEGER COMMA Funcao_Integral R_PAREN SEMICOLON  */
#line 333 "sintatico.y"
                                                                                                        {somatorio((yyvsp[-8].string_id), (yyvsp[-6].inteiro), (yyvsp[-4].inteiro), AST,hashTable); /*Delete_Tree(AST);*/}
#line 1844 "sintatico.yy.cc"
    break;

  case 64: /* Matrix: MATRIX EQUAL ChamaCreateMatrix  */
#line 336 "sintatico.y"
                                       {}
#line 1850 "sintatico.yy.cc"
    break;

  case 65: /* Matrix: SHOW MATRIX SEMICOLON  */
#line 337 "sintatico.y"
                                { showMatriz(); return CONTINUE_VALUE;}
#line 1856 "sintatico.yy.cc"
    break;

  case 66: /* Matrix: SOLVE DETERMINANT SEMICOLON  */
#line 338 "sintatico.y"
                                    { determinanteMatriz(); return CONTINUE_VALUE;}
#line 1862 "sintatico.yy.cc"
    break;

  case 67: /* Matrix: SOLVE LINEAR_SYSTEM SEMICOLON  */
#line 339 "sintatico.y"
                                      { solveLinearSystem();  return CONTINUE_VALUE;}
#line 1868 "sintatico.yy.cc"
    break;

  case 68: /* ChamaCreateMatrix: CreateMatrix  */
#line 341 "sintatico.y"
                                {  
                                
                                 matriz_global = createMatriz(listMatriz,elemtsPlinha,maisElementosLinha); elementosLinha = 0; maisElementosLinha = 0;
 /* destruir listas aqui */ }
#line 1877 "sintatico.yy.cc"
    break;

  case 69: /* CreateMatrix: L_SQUARE_BRACKET CreateMatrixAux R_SQUARE_BRACKET SEMICOLON  */
#line 347 "sintatico.y"
                                                                          {}
#line 1883 "sintatico.yy.cc"
    break;

  case 70: /* $@2: %empty  */
#line 349 "sintatico.y"
                                                        { elementosLinha++; listMatriz.push_back((yyvsp[-1].inteiro)*(yyvsp[0].real)); }
#line 1889 "sintatico.yy.cc"
    break;

  case 71: /* $@3: %empty  */
#line 350 "sintatico.y"
                                                 { elemtsPlinha.push_back(elementosLinha); maisElementosLinha = (elementosLinha > maisElementosLinha) ? elementosLinha : maisElementosLinha;
                                         elementosLinha = 0; }
#line 1896 "sintatico.yy.cc"
    break;

  case 72: /* CreateMatrixAux: L_SQUARE_BRACKET Sinal ValorIntOrFloat $@2 RepeatValuesMatrixOne R_SQUARE_BRACKET $@3 RepeatValuesMatrixTwo  */
#line 351 "sintatico.y"
                                                                                    { }
#line 1902 "sintatico.yy.cc"
    break;

  case 73: /* $@4: %empty  */
#line 353 "sintatico.y"
                                                   {elementosLinha++; listMatriz.push_back((yyvsp[-1].inteiro)*(yyvsp[0].real)); }
#line 1908 "sintatico.yy.cc"
    break;

  case 74: /* RepeatValuesMatrixOne: COMMA Sinal ValorIntOrFloat $@4 RepeatValuesMatrixOne  */
#line 353 "sintatico.y"
                                                                                                                           {}
#line 1914 "sintatico.yy.cc"
    break;

  case 75: /* RepeatValuesMatrixOne: %empty  */
#line 354 "sintatico.y"
                      {}
#line 1920 "sintatico.yy.cc"
    break;

  case 76: /* $@5: %empty  */
#line 356 "sintatico.y"
                                                                    {elementosLinha++; listMatriz.push_back((yyvsp[-1].inteiro)*(yyvsp[0].real));  }
#line 1926 "sintatico.yy.cc"
    break;

  case 77: /* $@6: %empty  */
#line 357 "sintatico.y"
                                                { elemtsPlinha.push_back(elementosLinha); maisElementosLinha = (elementosLinha > maisElementosLinha) ? elementosLinha : maisElementosLinha;
                                         elementosLinha = 0; }
#line 1933 "sintatico.yy.cc"
    break;

  case 78: /* RepeatValuesMatrixTwo: COMMA L_SQUARE_BRACKET Sinal ValorIntOrFloat $@5 RepeatValuesMatrixOne R_SQUARE_BRACKET $@6 RepeatValuesMatrixTwo  */
#line 358 "sintatico.y"
                                                                                     {}
#line 1939 "sintatico.yy.cc"
    break;

  case 79: /* RepeatValuesMatrixTwo: %empty  */
#line 359 "sintatico.y"
                       {}
#line 1945 "sintatico.yy.cc"
    break;

  case 80: /* ManipulacaoSimbolos: SHOW SYMBOLS SEMICOLON  */
#line 365 "sintatico.y"
                                            { hashTable.printAll();}
#line 1951 "sintatico.yy.cc"
    break;

  case 81: /* $@7: %empty  */
#line 368 "sintatico.y"
                      {str_aux2 = str_aux;}
#line 1957 "sintatico.yy.cc"
    break;

  case 82: /* continua_id: ATRIBUTE $@7 continua_atribute  */
#line 368 "sintatico.y"
                                                              {}
#line 1963 "sintatico.yy.cc"
    break;

  case 83: /* continua_id: SEMICOLON EOL  */
#line 369 "sintatico.y"
                        {printValorSimbolo(str_aux, hashTable);  matriz_exp = false; return CONTINUE_VALUE;}
#line 1969 "sintatico.yy.cc"
    break;

  case 84: /* continua_id: %empty  */
#line 370 "sintatico.y"
          { }
#line 1975 "sintatico.yy.cc"
    break;

  case 85: /* continua_atribute: Expressao_matematica SEMICOLON EOL  */
#line 372 "sintatico.y"
                                                      { sinal = 1; if(!not_existId){hashTable.insert(str_aux2,valorExp);} not_existId = false; /*Delete_Tree(AST);*/; return CONTINUE_VALUE;}
#line 1981 "sintatico.yy.cc"
    break;

  case 86: /* continua_atribute: ChamaCreateMatrix EOL  */
#line 373 "sintatico.y"
                                        {sinal = 1; hashTable.insert(str,matriz_global);/*Delete_Tree(AST);*/ not_existId = false; matriz_exp = false; return CONTINUE_VALUE;}
#line 1987 "sintatico.yy.cc"
    break;

  case 87: /* Expressao_matematica_Direta: Funcao_Integral  */
#line 380 "sintatico.y"
                                             {if(!not_existId && !matriz_exp){printValorCalculoExp(valorExp);} matriz_exp =false; not_existId = false; /*Delete_Tree(AST);*/}
#line 1993 "sintatico.yy.cc"
    break;

  case 88: /* Expressao_matematica: %empty  */
#line 386 "sintatico.y"
                      {}
#line 1999 "sintatico.yy.cc"
    break;

  case 89: /* Expressao_matematica: Expressao_matematica Exp_aux  */
#line 387 "sintatico.y"
                                                     { AST = (yyvsp[0].ast); if(!not_existId) {valorExp = calculate_Exp(AST, hashTable); } not_existId = false; }
#line 2005 "sintatico.yy.cc"
    break;

  case 90: /* Exp_aux: Exp_DivMul  */
#line 389 "sintatico.y"
                    {  (yyval.ast) = (yyvsp[0].ast);}
#line 2011 "sintatico.yy.cc"
    break;

  case 91: /* Exp_aux: Exp_aux PLUS Exp_DivMul  */
#line 390 "sintatico.y"
                              {     TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = ADD;
                                                aux->value = 0;
                                                aux->left = (yyvsp[-2].ast);
                                                aux->right = (yyvsp[0].ast);
                                                (yyval.ast) = aux;  
                                        }
#line 2023 "sintatico.yy.cc"
    break;

  case 92: /* Exp_aux: Exp_aux MINUS Exp_DivMul  */
#line 398 "sintatico.y"
                               {   TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = SUB;
                                                aux->value = 0;
                                                aux->left = (yyvsp[-2].ast);
                                                aux->right = (yyvsp[0].ast);
                                                (yyval.ast) = aux;}
#line 2034 "sintatico.yy.cc"
    break;

  case 93: /* Exp_DivMul: Exp_Complemento  */
#line 405 "sintatico.y"
                            { (yyval.ast) = (yyvsp[0].ast); }
#line 2040 "sintatico.yy.cc"
    break;

  case 94: /* Exp_DivMul: Exp_DivMul MULTIPLY Exp_Complemento  */
#line 406 "sintatico.y"
                                              {    TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                                aux->node_type = MUL;
                                                                aux->value = 0;
                                                                aux->left = (yyvsp[-2].ast);
                                                                aux->right = (yyvsp[0].ast);
                                                                (yyval.ast) = aux;}
#line 2051 "sintatico.yy.cc"
    break;

  case 95: /* Exp_DivMul: Exp_DivMul DIV Exp_Complemento  */
#line 413 "sintatico.y"
                                         { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                        aux->node_type = DI;
                                                        aux->value = 0;
                                                        aux->left = (yyvsp[-2].ast);
                                                        aux->right = (yyvsp[0].ast);
                                                        (yyval.ast) = aux;}
#line 2062 "sintatico.yy.cc"
    break;

  case 96: /* Exp_Complemento: Sinal ValorIntOrFloat  */
#line 421 "sintatico.y"
                                       { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = NUMBER;
                                                aux->value = (yyvsp[-1].inteiro)*(yyvsp[0].real);
                                                aux->left = NULL;
                                                aux->right = NULL;
                                                (yyval.ast) = (TreeNode*) aux; }
#line 2073 "sintatico.yy.cc"
    break;

  case 97: /* Exp_Complemento: Sinal IDENTIFIER  */
#line 428 "sintatico.y"
                            {TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                        aux->node_type = IDENTIFIER_NODE;
                                        if(hashTable.search(str) == NULL){
                                                aux->value = 0;
                                        }else{

                                        aux->value = (yyvsp[-1].inteiro)*(*(static_cast<float*>(hashTable.search(str))));
                                        }
                                       
                                        aux->name = str;
                                        aux->left = NULL;
                                        aux->right = NULL;
                                        (yyval.ast) = (TreeNode*) aux; }
#line 2091 "sintatico.yy.cc"
    break;

  case 98: /* Exp_Complemento: COS L_PAREN Exp_Complemento R_PAREN  */
#line 442 "sintatico.y"
                                              {  TreeNode* cosNode = (TreeNode*)malloc(sizeof(struct node));
                                                        cosNode->node_type = COS_NODE;
                                                        cosNode->left = (yyvsp[-1].ast); // AST do complemento
                                                        cosNode->right = NULL;
                                                        (yyval.ast) = (TreeNode*) cosNode;}
#line 2101 "sintatico.yy.cc"
    break;

  case 99: /* Exp_Complemento: SEN L_PAREN Exp_Complemento R_PAREN  */
#line 447 "sintatico.y"
                                              {  TreeNode* senNode = (TreeNode*)malloc(sizeof(struct node));
                                                        senNode->node_type = SEN_NODE;
                                                        senNode->left = (yyvsp[-1].ast); // AST do complemento
                                                        senNode->right = NULL;
                                                        (yyval.ast) = (TreeNode*) senNode;}
#line 2111 "sintatico.yy.cc"
    break;

  case 100: /* Exp_Complemento: TAN L_PAREN Exp_Complemento R_PAREN  */
#line 452 "sintatico.y"
                                              { TreeNode* tanNode = (TreeNode*)malloc(sizeof(struct node));
                                                        tanNode->node_type = TAN_NODE;
                                                        tanNode->left = (yyvsp[-1].ast); // AST do complemento
                                                        tanNode->right = NULL;
                                                        (yyval.ast) = (TreeNode*) tanNode; }
#line 2121 "sintatico.yy.cc"
    break;

  case 101: /* Exp_Complemento: X  */
#line 457 "sintatico.y"
            { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                aux->node_type = X_NODE;
                                aux->value = 0;
                                aux->left = NULL;
                                aux->right = NULL;
                                (yyval.ast) = (TreeNode*) aux; }
#line 2132 "sintatico.yy.cc"
    break;

  case 102: /* Exp_Complemento: PI  */
#line 463 "sintatico.y"
             { TreeNode* piNode = (TreeNode*)malloc(sizeof(struct node));
            piNode->node_type = NUMBER;
            piNode->value = M_PI;
            piNode->left = NULL;
            piNode->right = NULL;
            (yyval.ast) = (TreeNode*) piNode;
            }
#line 2144 "sintatico.yy.cc"
    break;

  case 103: /* Exp_Complemento: E  */
#line 471 "sintatico.y"
          { TreeNode* eNode = (TreeNode*)malloc(sizeof(struct node));
            eNode->node_type = NUMBER;
            eNode->value = M_E;
            eNode->left = NULL;
            eNode->right = NULL;
            (yyval.ast) = (TreeNode*) eNode;
            }
#line 2156 "sintatico.yy.cc"
    break;

  case 104: /* Exp_Complemento: ABS L_PAREN Exp_Complemento R_PAREN  */
#line 478 "sintatico.y"
                                              { TreeNode* absNode = (TreeNode*)malloc(sizeof(struct node));
                                                        absNode->node_type = ABS_NODE;
                                                        absNode->left = (yyvsp[-1].ast); // AST do complemento
                                                        absNode->right = NULL;
                                                        (yyval.ast) = (TreeNode*) absNode; }
#line 2166 "sintatico.yy.cc"
    break;

  case 105: /* Exp_Complemento: L_PAREN Exp_aux R_PAREN  */
#line 483 "sintatico.y"
                                  { (yyval.ast) = (yyvsp[-1].ast); }
#line 2172 "sintatico.yy.cc"
    break;

  case 106: /* Funcoes: COS  */
#line 488 "sintatico.y"
             {}
#line 2178 "sintatico.yy.cc"
    break;

  case 107: /* Funcoes: SEN  */
#line 489 "sintatico.y"
              {}
#line 2184 "sintatico.yy.cc"
    break;

  case 108: /* Funcoes: TAN  */
#line 490 "sintatico.y"
              {}
#line 2190 "sintatico.yy.cc"
    break;

  case 109: /* OperadoresBinarios: PLUS  */
#line 492 "sintatico.y"
                         {(yyval.inteiro) = 1;}
#line 2196 "sintatico.yy.cc"
    break;

  case 110: /* OperadoresBinarios: MINUS  */
#line 493 "sintatico.y"
                            {(yyval.inteiro) = -1;}
#line 2202 "sintatico.yy.cc"
    break;

  case 111: /* OperadoresBinarios: MULTIPLY  */
#line 494 "sintatico.y"
                               {}
#line 2208 "sintatico.yy.cc"
    break;

  case 112: /* OperadoresBinarios: DIV  */
#line 495 "sintatico.y"
                          {}
#line 2214 "sintatico.yy.cc"
    break;

  case 113: /* OperadoresBinarios: POW  */
#line 496 "sintatico.y"
                          {}
#line 2220 "sintatico.yy.cc"
    break;

  case 114: /* OperadoresBinarios: REMAINDER  */
#line 497 "sintatico.y"
                                {}
#line 2226 "sintatico.yy.cc"
    break;

  case 115: /* Constantes: PI  */
#line 500 "sintatico.y"
               {(yyval.real) = M_PI;}
#line 2232 "sintatico.yy.cc"
    break;

  case 116: /* Constantes: E  */
#line 501 "sintatico.y"
                {(yyval.real) = M_E;}
#line 2238 "sintatico.yy.cc"
    break;


#line 2242 "sintatico.yy.cc"

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

#line 507 "sintatico.y"


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
