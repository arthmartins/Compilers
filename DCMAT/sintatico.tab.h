/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SINTATICO_TAB_H_INCLUDED
# define YY_YY_SINTATICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    ABOUT = 259,                   /* ABOUT  */
    FLOAT = 260,                   /* FLOAT  */
    PI = 261,                      /* PI  */
    SETTINGS = 262,                /* SETTINGS  */
    ABS = 263,                     /* ABS  */
    H_VIEW = 264,                  /* H_VIEW  */
    PLOT = 265,                    /* PLOT  */
    SHOW = 266,                    /* SHOW  */
    AXIS = 267,                    /* AXIS  */
    INTEGRAL_STEPS = 268,          /* INTEGRAL_STEPS  */
    PRECISION = 269,               /* PRECISION  */
    SOLVE = 270,                   /* SOLVE  */
    CONNECT_DOTS = 271,            /* CONNECT_DOTS  */
    INTEGRATE = 272,               /* INTEGRATE  */
    QUIT = 273,                    /* QUIT  */
    SUM = 274,                     /* SUM  */
    COS = 275,                     /* COS  */
    LINEAR_SYSTEM = 276,           /* LINEAR_SYSTEM  */
    RESET = 277,                   /* RESET  */
    SYMBOLS = 278,                 /* SYMBOLS  */
    DETERMINANT = 279,             /* DETERMINANT  */
    MATRIX = 280,                  /* MATRIX  */
    RPN = 281,                     /* RPN  */
    TAN = 282,                     /* TAN  */
    E = 283,                       /* E  */
    OFF = 284,                     /* OFF  */
    SEN = 285,                     /* SEN  */
    V_VIEW = 286,                  /* V_VIEW  */
    ERASE = 287,                   /* ERASE  */
    ON = 288,                      /* ON  */
    SET = 289,                     /* SET  */
    X = 290,                       /* X  */
    PLUS = 291,                    /* PLUS  */
    MINUS = 292,                   /* MINUS  */
    MULTIPLY = 293,                /* MULTIPLY  */
    DIV = 294,                     /* DIV  */
    REMAINDER = 295,               /* REMAINDER  */
    POW = 296,                     /* POW  */
    SEMICOLON = 297,               /* SEMICOLON  */
    COMMA = 298,                   /* COMMA  */
    COLON = 299,                   /* COLON  */
    L_PAREN = 300,                 /* L_PAREN  */
    R_PAREN = 301,                 /* R_PAREN  */
    L_SQUARE_BRACKET = 302,        /* L_SQUARE_BRACKET  */
    R_SQUARE_BRACKET = 303,        /* R_SQUARE_BRACKET  */
    EQUAL = 304,                   /* EQUAL  */
    ATRIBUTE = 305,                /* ATRIBUTE  */
    NUM_INTEGER = 306,             /* NUM_INTEGER  */
    NUM_REAL = 307,                /* NUM_REAL  */
    EOL = 308                      /* EOL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 69 "sintatico.y"

        
TreeNode* ast;
int inteiro;
char* string_id;
float real; 

#line 125 "sintatico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINTATICO_TAB_H_INCLUDED  */
