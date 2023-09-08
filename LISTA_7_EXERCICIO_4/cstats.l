%option noyywrap

%{

int total_lines = 0;
int blank_lines = 0;
int linesw_comment = 0;
int nc_lines = 0;
int semi_colons = 0;
int preproc = 0;

%}

<START>{
"\n" { total_lines++;}
^[ ]*\n {blank_lines++; total_lines++;}
"//"  {linesw_comment++;}
";" {semi_colons++;}
"#include" {preproc++;}
"#define" {preproc++;}
"/*" {BEGIN(BLOCK_COMMENT);}
}

<BLOCK_COMMENT>{
"*/"    { linesw_comment++; BEGIN(START); }
[^*\n]+ 
"*"
[\n] { linesw_comment++; total_lines++; }
}


%%

""

%%

int main(int argc, char* argv[]){

    yylex();
    return 0;
}