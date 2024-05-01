#include "scan.hpp"
#include <vector>

void LinearScan(int k, std::vector<Register> registers)
{
  std::vector<Register> registers_ativos;
  std::vector<int> reg_disponiveis;
  Register r_spill;
  bool alocated = false;

  for (int i = 0; i < k; i++)
  {
    reg_disponiveis.push_back(1);
  }
  for(Register r : registers)
  {
    if(registers_ativos.size()==0){
      registers_ativos.push_back(r);
      for(int i : reg_disponiveis)
      {
        if(i==1)
        {
          r.reg_alocado = i;
          i = 0;
          break;
        }
      }
    }else{

      auto it = registers_ativos.begin();
      while (it != registers_ativos.end()) {
        if (r.begin >= it->end) {
          it = registers_ativos.erase(it);
          for(int i : reg_disponiveis)
          {
            if(i==1)
            {
              r.reg_alocado = i;
              i = 0;
              break;
            }
          }
          reg_disponiveis[it->reg_alocado] = 1;
          registers_ativos.push_back(r);
          alocated = true;
        } else {
          ++it;
        }
      }
      if(!alocated)
      {
       if(registers_ativos.size()<k){
          registers_ativos.push_back(r);
          for(int i : reg_disponiveis)
          {
            if(i==1)
            {
              r.reg_alocado = i;
              i = 0;
              break;
            }
          }
        }else{
          r_spill = r;
          int j = 0;
          auto it = registers_ativos.begin();
          while (it != registers_ativos.end()) {
            if(r_spill.end < it->end)
            {
              r_spill = *it;
            }else if(r_spill.end == it->end)
            {
              if(r_spill.intervalo > it->intervalo)
              {
                r_spill = *it;
              }else if(r_spill.intervalo == it->intervalo)
              {
                if(r_spill.begin > it->begin)
                {
                  r_spill = *it;
                }
              }
            }
            j++;
          }
          r_spill.spill = true;
          registers_ativos.erase(registers_ativos.begin() + j);
          reg_disponiveis[r_spill.reg_alocado] = 1;
          if(r.begin != r_spill.begin)
          {
            registers_ativos.push_back(r);
            for(int i : reg_disponiveis)
            {
              if(i==1)
              {
                r.reg_alocado = i;
                i = 0;
                break;
              }
            }
          }
        }
      }
    }
  }
}