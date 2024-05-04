%{
#include "graph.hpp"
#include <vector>


    extern int yylex(void);
    extern char* yytext;
    extern int yychar;
    extern void yyerror(char *s);
    extern void yylex_destroy(void);


    Graph *graph = new Graph();
    std::vector<int> interf;
    bool vertices_dif = true;

%}

%union {
    int integer_value;
}

%token GRAPH
%token K
%token ARROW
%token<integer_value> NUM_INTEGER
%token EOL
%token COLON
%token EQUAL

%type <integer_value> Graph_Number
%type <integer_value> Available_Registers

%start Programa

%%

Programa: Begin_grafo Interferencias {}

Begin_grafo: Graph_Number EOL Available_Registers EOL {graph->id_grafo = $1; graph->num_reg = $3; graph->num_reg_virtuais = 0;}

Graph_Number: GRAPH NUM_INTEGER COLON {$$ = $2;}

Available_Registers: K EQUAL NUM_INTEGER { $$ = $3;}

Interferencias: Interferencias_aux EOL Interferencias {}
            | { }
        
Interferencias_aux: NUM_INTEGER ARROW {graph->num_reg_virtuais++; } Int_aux {

    if(graph->vertices[$1] == nullptr){
        Vertice* vertice = new Vertice();
        vertice->id_vertice = $1;
        vertice->valid = true;
        vertice->spill = false;
        vertice->reg_alocado = -1;
        graph->vertices[$1] = vertice;
        
    }
    graph->vertices[$1]->is_virtual = true;
    
    int i;
    for (i = 0; i < interf.size(); i++) {

        if(graph->vertices[interf[i]] == nullptr){

            Vertice* vertice_inf = new Vertice();
            vertice_inf->id_vertice = interf[i];
            vertice_inf->valid = true;
            vertice_inf->spill = false; 
            vertice_inf->reg_alocado = -1;
            graph->vertices[interf[i]] = vertice_inf;
            vertice_inf->is_virtual = false;
            //graph->num_reg_virtuais++;
    }
        
        for (auto it = graph->vertices[$1]->interferencias.begin(); it != graph->vertices[$1]->interferencias.end(); it++) {
            Vertice* v = it->second;
           if(v->id_vertice == interf[i])
           {
            vertices_dif = false;
            break;
           }
    
        }
        if(vertices_dif){
            graph->vertices[$1]->interferencias[interf[i]] = graph->vertices[interf[i]];
        }

        vertices_dif = true;
        
        for (auto it = graph->vertices[interf[i]]->interferencias.begin(); it != graph->vertices[interf[i]]->interferencias.end(); it++) {
            Vertice* v = it->second;

           if(v->id_vertice == interf[$1])
           {
            vertices_dif = false;
            break;
           }
    
        }
         if(vertices_dif){
            graph->vertices[interf[i]]->interferencias[$1] = graph->vertices[$1];
        }

        vertices_dif = true;

    }
    interf.clear();

}

Int_aux: NUM_INTEGER Int_aux { interf.push_back($1); }
        | {}





%%

void yyerror(char *s){

 }

int main(int argc, char **argv) {

    yyparse();
    printf("Graph %d -> Physical Registers: %d",graph->id_grafo,graph->num_reg);
    printf("\n----------------------------------------");
    printf("\n----------------------------------------");
    std::vector<bool> sucess_alloc;
    int i;
    for(i = graph->num_reg; i > 1; i-- ){
        printf("\nK = %d\n", i);

        Simplify(graph,i);
        sucess_alloc.push_back(select_Assign(graph,i));
        resetAll(graph);
        printf("\n----------------------------------------");
    }
    printf("\n----------------------------------------");
    int j = 0;
    for(bool t : sucess_alloc){
        std::cout << "\nGraph " << graph->id_grafo << " -> K = "<< (graph->num_reg - j < 10 ? " " : "")<< graph->num_reg - j<< ": " << (t ? "Successful Allocation" : "SPILL");
        j++;
    }
    yylex_destroy();

    for(auto it = graph->vertices.begin(); it != graph->vertices.end(); it++){
        if(it->second != nullptr){
            delete it->second;
        }
    }
    delete graph;
}