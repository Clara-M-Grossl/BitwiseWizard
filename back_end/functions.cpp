#include <iostream>
#include "functions.h"

using namespace std;

int menu_bases(){
  int opc;
  cout << "**Menu de Bases***" << endl;
  cout << "Escolha a base:" << endl;
  cout << "[1] - Base Binaria." << endl;
  cout << "[2] - Base Octal." << endl;
  cout << "[3] - Base Decimal." << endl;
  cout << "[4] - Base Hexadecimal." << endl;
  cout << "[0] - Sair." << endl;
  
  cout << ">> ";
  cin >> opc;
  
  return opc;
}