#include <vector>
#ifndef SCAN_HPP
#define SCAN_HPP

#include <iostream>
#include <string>


struct Register
{
  std::string name;
  int begin;
  int end;
  int intervalo;
  int reg_alocado;
  bool spill;
};


void LinearScan(int k, std::vector<Register> registers);


#endif