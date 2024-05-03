#include "scan.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <cstring>


void LinearScan(int k, std::vector<Register*> registers, historico* hist)
{
  std::vector<Register> registers_ativos;
  std::vector<int> reg_disponiveis;
  Register* r_spill;
  bool alocated = false;
  bool break_true = false;
  bool removed = false;
  int l = 0;
  int historico = -1;
  for (int i = 0; i < k; i++)
  {
    reg_disponiveis.push_back(1);
  }
  
  for(Register* r : registers)
  {
    historico++;
    alocated = false;
    //std::cout << historico << registers_ativos.size() << std::endl;
    if(registers_ativos.size()==0){
      for(int i : reg_disponiveis)
      {
        if(i==1)
        {
          r->reg_alocado = l;
          reg_disponiveis[l] = 0;
          break;
        }
        l++;
      }
      registers_ativos.push_back(*r);
      l = 0;
    }else{
      
      auto it = registers_ativos.begin();
      while (it != registers_ativos.end()) {
        if (r->begin >= it->end) {
          if(it->reg_alocado != -1){
            reg_disponiveis[it->reg_alocado] = 1;
           
          }
          registers_ativos.erase(it);
          removed = true;
        } else {
          ++it;
        }
      }
      if(removed){
        removed = false;
        for(int i : reg_disponiveis)
          {
            if(i==1)
            {
              r->reg_alocado = l;
              reg_disponiveis[l] = 0;
              break_true = true;
              break;
            }
            l++;
          }
          registers_ativos.push_back(*r);
          alocated = true;
          l=0;
      }
      l= 0;

      if(!alocated)
      {
       if(registers_ativos.size()<k){
          for(int i : reg_disponiveis)
          {
            if(i==1)
            {
              r->reg_alocado = l;
              reg_disponiveis[l] = 0;
              break;
            }
            l++;
          }
          registers_ativos.push_back(*r);
          l = 0;


        }else{
          
          r_spill = r;
         
          int j = 0;
          int do_spill = 0;
          auto it = registers_ativos.begin();
          while (it != registers_ativos.end()) {

            if(r_spill->end < it->end)
            {
              r_spill = &(*it);
              do_spill = j;
            }else if(r_spill->end == it->end)
            {
              if(r_spill->intervalo > it->intervalo)
              {
                r_spill = &(*it);
                do_spill = j;
                
              }else if(r_spill->intervalo == it->intervalo)
              {
                if(r_spill->begin > it->begin)
                {
                  r_spill = &(*it);
                  do_spill = j;
                }else if(r_spill->begin == it->begin)
                {
                  r_spill = &(*it);
                  do_spill = j;
                }
              }
            }
            j++;
            it++;
          }

          for(Register* r : registers)
          {
            if(strcmp(r->name.c_str(), r_spill->name.c_str()) == 0)
            {
              r->spill= true;
              hist->iteracoes.push_back(historico);

            }
          }
          if(r_spill->reg_alocado != -1){
            reg_disponiveis[r_spill->reg_alocado] = 1;
            registers_ativos.erase(registers_ativos.begin() + do_spill);
          
          }

          if(strcmp(r->name.c_str(), r_spill->name.c_str()) != 0)
          {
            
            for(int i : reg_disponiveis)
            {
              if(i==1)
              {
                r->reg_alocado = l;
                reg_disponiveis[l] = 0;
                break;
              }
              l++;
              
            }
            registers_ativos.push_back(*r);
            
            l = 0;
          }
          
        }
        
      }
      
    }
    
  }
}

void resetAll(std::vector<Register*> registers){
  for(Register* r : registers)
  {
    r->reg_alocado = -1;
    r->spill = false;
  }
}