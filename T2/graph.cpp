#include "graph.hpp"
#include <queue>
#include <stack>
#include <map>

std::stack<Vertice*> pilha;

int retornaConexoes(Vertice *v)
{
  int i = 0;
  for (auto it = v->interferencias.begin(); it != v->interferencias.end(); ++it) {
    Vertice* interferencia = it->second;
    if(interferencia->valid){
      i++;
    }
  }
  return i;
}


int potencialSpill(Graph* grafo)
{
    int num = -1;
    Vertice *salva_v_spill;
    int id  = -1;
    std::map<int, bool> visitados_spill;

    for (auto it = grafo->vertices.begin(); it != grafo->vertices.end(); ++it) {
        Vertice* vertice = it->second;
        visitados_spill[vertice->id_vertice] = false;
    }

    std::queue<Vertice*> fila_spill;

    if (!grafo->vertices.empty()) {
        fila_spill.push(grafo->vertices.begin()->second);
    }

    while (!fila_spill.empty()) {
        Vertice* verticeAtual = fila_spill.front();
        fila_spill.pop();
        //printf("\n%d\n", verticeAtual->id_vertice);

        if (!visitados_spill[verticeAtual->id_vertice]) {
            visitados_spill[verticeAtual->id_vertice] = true;
            
            if(verticeAtual->valid && verticeAtual->is_virtual){
              int conexoes_vertice = retornaConexoes(verticeAtual);

              if(conexoes_vertice > num)
              {
                num = conexoes_vertice;
                //salva_v_spill = verticeAtual;
                id = verticeAtual->id_vertice;
              }else if(conexoes_vertice == num)
              {
                if(verticeAtual->id_vertice < salva_v_spill->id_vertice)  {  
                  num = conexoes_vertice;
                  //salva_v_spill = verticeAtual;
                  id = verticeAtual->id_vertice;
                }
              }
            }


            for (auto it = verticeAtual->interferencias.begin(); it != verticeAtual->interferencias.end(); ++it) {
                Vertice* interferencia = it->second;
                fila_spill.push(interferencia);
            }
      }
  }
    //return salva_v_spill;
    return id;

}




void Simplify(Graph* grafo, int k) {

    int num = 100000000000000000;
    Vertice *salva_v;
    std::map<int, bool> visitados;
    bool s =false;


    for (auto it = grafo->vertices.begin(); it != grafo->vertices.end(); ++it) {
        Vertice* vertice = it->second;
        visitados[vertice->id_vertice] = false;
    }

    std::queue<Vertice*> fila;

    if (!grafo->vertices.empty()) {
        fila.push(grafo->vertices.begin()->second);
    }

    while (!fila.empty()) {
        Vertice* verticeAtual = fila.front();
        fila.pop();
                
        if (!visitados[verticeAtual->id_vertice]) {
            visitados[verticeAtual->id_vertice] = true;

            if(verticeAtual->valid && verticeAtual->is_virtual){
              int conexoes_vertice = retornaConexoes(verticeAtual);
  
              if(conexoes_vertice < num)
              {
                num = conexoes_vertice;
                salva_v = verticeAtual;
              }else if(conexoes_vertice == num)
              {
                if(verticeAtual->id_vertice < salva_v->id_vertice)  {  
                  num = conexoes_vertice;
                  salva_v = verticeAtual;
                }
              }
            }

            for (auto it = verticeAtual->interferencias.begin(); it != verticeAtual->interferencias.end(); ++it) {
                Vertice* interferencia = it->second;
                fila.push(interferencia);
            }
        }
    }

    if(num >= k)
    {
      int aaaa = potencialSpill(grafo);
      //printf("\naaaa %d\n", aaaa);
      if(aaaa != -1){
      //salva_v = potencialSpill(grafo);
        s = true;
        std::cout << "\nPush: " << aaaa;
        std::cout << " *";
        pilha.push(grafo->vertices[aaaa]);
        grafo->vertices[aaaa]->valid = false;
      }
    }
    else{

    pilha.push(salva_v);
    salva_v->valid = false;

    std::cout << "\nPush: " << salva_v->id_vertice;
    }
    if(pilha.size()!=grafo->num_reg_virtuais)
    {
      Simplify(grafo, k);
    }
}


bool select_Assign(Graph* grafo, int k)
{
    bool break_for = false;
    bool not_spill = false;
    bool alloc = true;

    int i;
    for(i = 0; i < grafo->num_reg_virtuais;i++)
    {
      Vertice *v = pilha.top();
      pilha.pop();
      v->valid = true;
      
      for(int j=0;j<k;j++){
        for (auto it = v->interferencias.begin(); it != v->interferencias.end(); ++it) 
        {
            Vertice* interferencia = it->second;
            if(j==interferencia->reg_alocado || j == interferencia->id_vertice){
              alloc = false;
              break;
            }
        }
        if(alloc){
          v->reg_alocado = j;
          not_spill = true;
          std::cout << "\nPop: "<< v->id_vertice << " -> " << j;
          break;
        }
        alloc = true;
      }
      if(!not_spill){
        
        std::cout << "\nPop: " <<v->id_vertice << " -> NO COLOR AVAILABLE";
        return false;
      }else
        not_spill = false;

    }
  return true;
}

void resetAll(Graph *grafo)
{
  
    std::map<int, bool> visitados;

    for (auto it = grafo->vertices.begin(); it != grafo->vertices.end(); ++it) {
        Vertice* vertice = it->second;
        visitados[vertice->id_vertice] = false;
    }

    std::queue<Vertice*> fila;

    if (!grafo->vertices.empty()) {
        fila.push(grafo->vertices.begin()->second);
    }

    while (!fila.empty()) {
        Vertice* verticeAtual = fila.front();
        fila.pop();
        if (!visitados[verticeAtual->id_vertice]) {
            visitados[verticeAtual->id_vertice] = true;
        verticeAtual->reg_alocado = -1;
        verticeAtual->spill = false;
        verticeAtual->valid = true;
      
      for (auto it = verticeAtual->interferencias.begin(); it != verticeAtual->interferencias.end(); ++it) {
          Vertice* interferencia = it->second;
          fila.push(interferencia);
      }
    }
    }
    while(!pilha.empty()){
      pilha.pop();
    }
}