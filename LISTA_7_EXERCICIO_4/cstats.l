%option noyywrap

%{

int total_lines = 1;
int blank_lines = 0;
int linesw_comment = 0;
int nc_lines = 0;
int semi_colons = 0;
int preproc = 0;

%}

%x BLOCK_COMMENT

%%

<INITIAL>{
"//"  {linesw_comment++;}
";" {semi_colons++;}
"#include" {preproc++;}
"#define" {preproc++;}
"/*" {BEGIN(BLOCK_COMMENT);}
^[ ]*"\n" {blank_lines++; total_lines++;}
"\n" { total_lines++;}
.
}

<BLOCK_COMMENT>{
"*/"    { linesw_comment++; BEGIN(INITIAL); }
[^*\n]+ 
"*"
[\n] { linesw_comment++; total_lines++; }
}


%%

int main(int argc, char* argv[]){

    int total_file_lines = 0;
    int total_blank_lines = 0;
    int total_linesw_comment = 0;
    int total_nc_lines = 0;
    int total_semi_colons = 0;
    int total_preproc = 0;

    printf("%6s%7s%10s%8s%8s%10s%8s\n", "total", "blank", "lines w/", "nb, nc", "semi-", "preproc.", "file");
    printf("%6s%7s%10s%8s%8s%10s\n", "lines", "lines", "comments", "lines", "colons", "direct.");
    printf("------+------+----------+-------+-------+--------+------\n");
    int i;

    if(argc < 2)
    {
        return(0);  
    }
    else{
        for(i=1; i<argc; i++){
            FILE *f = fopen(argv[i],"r");

            if(!f){
                perror(argv[i]);
                return(1);
            }
            yyrestart(f);
            yylex();
            

            nc_lines = total_lines - blank_lines - linesw_comment;
            printf("%4d%6d%11d%8d%8d%8d      -%s\n",total_lines,blank_lines,linesw_comment,nc_lines,semi_colons,preproc, argv[i]);
            
            fclose(f);
            total_file_lines += total_lines;
            total_blank_lines += blank_lines;
            total_linesw_comment += linesw_comment;
            total_nc_lines += nc_lines;
            total_semi_colons += semi_colons;
            total_preproc += preproc;
            
            total_lines = 1;
            blank_lines = 0;
            linesw_comment = 0;
            nc_lines = 0;
            semi_colons = 0;
            preproc = 0;
        }
    }
    printf("%4d%6d%11d%8d%8d%8d      %s\n",total_file_lines,total_blank_lines,total_linesw_comment,
                                        total_nc_lines,total_semi_colons,total_preproc, "total");
    return 0;
}