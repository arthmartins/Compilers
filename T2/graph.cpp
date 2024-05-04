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



Vertice* potencialSpill(Graph* grafo)
{
    int num = -1;
    Vertice *salva_v_spill;
    std::map<int, bool> visitados_spill;

    for (auto it = grafo->vertices.begin(); it != grafo->vertices.end(); ++it) {
        Vertice* vertice = it->second;
        visitados_spill[vertice->id_vertice] = false;
    }


    for (const auto (&par) : grafo->vertices) {
        Vertice* verticeAtual = par.second;
        //printf("\n%d\n", verticeAtual->id_vertice);

        if (!visitados_spill[verticeAtual->id_vertice]) {
            visitados_spill[verticeAtual->id_vertice] = true;
            if(verticeAtual->valid && verticeAtual->is_virtual){
              int conexoes_vertice = retornaConexoes(verticeAtual);

              if(conexoes_vertice > num)
              {
                num = conexoes_vertice;
                salva_v_spill = verticeAtual;
              }else if(conexoes_vertice == num)
              {
                if(verticeAtual->id_vertice < salva_v_spill->id_vertice)  {  
                  num = conexoes_vertice;
                  salva_v_spill = verticeAtual;
                }
              }
            }
      }
  }
    return salva_v_spill;

}


void Simplify(Graph* grafo, int k) {

    int num = 100000000000000000;
    Vertice *salva_v;
    std::map<int, bool> visitados;
    bool s =false;
    bool da_break = false;

    for (auto it = grafo->vertices.begin(); it != grafo->vertices.end(); ++it) {
        Vertice* vertice = it->second;
        visitados[vertice->id_vertice] = false;
    }


    for (const auto& par : grafo->vertices) {
        Vertice* verticeAtual = par.second;
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
        }
    }

    if(num >= k)
    {
      // int aaa = potencialSpill(grafo);
      // std::cout << "\nPush: " << aaa;
      // pilha.push(grafo->vertices[aaa]);
      // grafo->vertices[aaa]->valid = false;
      
      salva_v = potencialSpill(grafo);
      s = true;
      std::cout << "\nPush: " << salva_v->id_vertice;
      std::cout << " *";
      pilha.push(salva_v);
      grafo->vertices[salva_v->id_vertice]->valid = false;
    }
    else{

    pilha.push(salva_v);
    salva_v->valid = false;

    std::cout << "\nPush: " << salva_v->id_vertice;
    }

    if(pilha.size()!=grafo->num_reg_virtuais && !da_break)
    {
      Simplify(grafo, k);
    }
}





// void Simplify(Graph* grafo, int k) {

//     int num = 100000000000000000;
//     Vertice *salva_v;
//     std::map<int, bool> visitados;
//     bool s =false;
//     bool da_break = false;

//     for (auto it = grafo->vertices.begin(); it != grafo->vertices.end(); ++it) {
//         Vertice* vertice = it->second;
//         visitados[vertice->id_vertice] = false;
//     }

//     std::queue<Vertice*> fila;

//     if (!grafo->vertices.empty()) {
//         fila.push(grafo->vertices.begin()->second);
//     }

//     while (!fila.empty()) {
//         Vertice* verticeAtual = fila.front();
//         fila.pop();
//         if(verticeAtual->id_vertice == 137 || verticeAtual->id_vertice == 138 || verticeAtual->id_vertice == 139 || verticeAtual->id_vertice == 143)
//         {
//             std::cout << "id: " << verticeAtual->id_vertice << " - valid: " << verticeAtual->valid << " - is_virtual: " << verticeAtual->is_virtual << "\n";
//         }
//         if (!visitados[verticeAtual->id_vertice]) {
//             visitados[verticeAtual->id_vertice] = true;

//             if(verticeAtual->valid && verticeAtual->is_virtual){
//               int conexoes_vertice = retornaConexoes(verticeAtual);
  
//               if(conexoes_vertice < num)
//               {
//                 num = conexoes_vertice;
//                 salva_v = verticeAtual;
//               }else if(conexoes_vertice == num)
//               {
//                 if(verticeAtual->id_vertice < salva_v->id_vertice)  {  
//                   num = conexoes_vertice;
//                   salva_v = verticeAtual;
//                 }
//               }
//             }

//             for (auto it = verticeAtual->interferencias.begin(); it != verticeAtual->interferencias.end(); ++it) {
//                 Vertice* interferencia = it->second;
//                 fila.push(interferencia);
//             }
//         }
//     }

//     if(num >= k)
//     {
//       int aaa = potencialSpill(grafo);
//       std::cout << "\nPush: " << aaa;
//       pilha.push(grafo->vertices[aaa]);
//       grafo->vertices[aaa]->valid = false;
      
//       // salva_v = potencialSpill(grafo);
//       // s = true;
//       // std::cout << "\nPush: " << salva_v->id_vertice;
//       // std::cout << " *";
//       // pilha.push(salva_v);
//       // grafo->vertices[salva_v->id_vertice]->valid = false;
//     }
//     else{

//     pilha.push(salva_v);
//     salva_v->valid = false;

//     std::cout << "\nPush: " << salva_v->id_vertice;
//     }

//     if(pilha.size()!=grafo->num_reg_virtuais && !da_break)
//     {
//       Simplify(grafo, k);
//     }
// }


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

     for (const auto& par : grafo->vertices) {
        Vertice* verticeAtual = par.second;
      
        if (!visitados[verticeAtual->id_vertice]) {
            visitados[verticeAtual->id_vertice] = true;
        verticeAtual->reg_alocado = -1;
        verticeAtual->spill = false;
        verticeAtual->valid = true;
      
    }
    }
    while(!pilha.empty()){
      pilha.pop();
    }
}