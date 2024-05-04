%option noyywrap
%{
    #include <sintatico.tab.h>
    extern YYSTYPE yylval;
%}

%%
      
<INITIAL>{

" "                     {  }
"Grafo"                 { return GRAPH; }
"K"                     { return K; }
"-->"                  { return ARROW; }
":"                     { return COLON; }
"="                     { return EQUAL; }
[0-9][0-9]*             { 
                            yylval.integer_value= atoi(yytext);
                            return NUM_INTEGER;
                        }
\n                      { return EOL; }
\r
.                       {}
}

%%
