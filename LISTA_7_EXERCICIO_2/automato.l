%option noyywrap

%{
#include <string.h>
%}


%%

"if" {  
        printf("%s",yytext); 
        printf(" IF\n"); 
    }
    
("i"([0-9a-eg-z]|"f"[0-9a-z])|([a-hj-z]))[0-9a-z]* { 
        printf("%s",yytext);  printf(" ID\n"); 
    }
" " { 
        printf("white space\n"); 
    }
"." { 
        printf("%s",yytext); printf(" error\n"); 
    }
"."([0-9]+) { 
        printf("%s",yytext); printf(" REAL\n");       
    }

[0-9]+ {
        printf("%s",yytext); printf(" NUM\n");                   
    }

[0-9]+"."[0-9]* {
        printf("%s",yytext); printf(" REAL\n");                   
    }
"-" { 
        printf("%s",yytext); printf(" error\n"); 
    }
"--" { 
        printf("%s",yytext); printf(" error\n"); 
    }
"--"[a-z]*\n { 

        yytext[strlen(yytext) - 1] = '\0';
        printf("%s",yytext); printf(" comment\n"); 
    }
\n { }
. { 
    printf("%s",yytext); printf(" error\n");   
  }

%%

int main(int argc, char* argv[]){

    yylex();
    return 0;
}