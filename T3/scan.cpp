#include "scan.hpp"
#include <vector>

void LinearScan(int k, std::vector<Register> registers)
{
  std::vector<Register> registers_ativos;
  std::vector<int> reg_disponiveis;

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
      

    }
  }

}