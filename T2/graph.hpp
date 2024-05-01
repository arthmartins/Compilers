#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <map>

struct Vertice{
  int id_vertice;
  bool valid;
  bool spill;
  int reg_alocado;
  bool is_virtual;
  std::map<int,Vertice*> interferencias;
    Vertice(){
      std::map<int,Vertice*>();
    }
};

struct Graph {
  int id_grafo;
  int num_reg;
  int num_reg_virtuais;
  std::map<int, Vertice*> vertices;

  Graph() {
        vertices = std::map<int,Vertice*>();
    }

};


void Simplify(Graph* grafo, int k);

bool select_Assign(Graph* grafo, int k);

void resetAll(Graph *grafo);
#endif