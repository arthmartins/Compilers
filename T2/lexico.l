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

[a-zA-Z]+[_0-9a-zA-Z]* { yylval.string_id = strdup(yytext);  str = strdup(yytext);  return IDENTIFIER; }

\n                      { return EOL; }
\r
.                       {}
}

%%
