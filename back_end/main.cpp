#include <iostream>
#include <string>
#include "functions.h"
#include "colors.h"

using namespace std;

int main(){
  // Declarar variaveis
  int opc;
  int base_s;
  int base_e;
  
  string num =  "";
  string binary = "";
  
  for(;;){
    cout << GREEN << "***BitwiseWizard***" << RESET << endl << endl;
    cout << "[1] - Converter bases." << endl;
    cout << "[2] - Operacoes aritmeticas." << endl;
    cout << "[0] - Sair. " << endl;
    cout << ">> ";
    
    cin >> opc;
    cout << endl;
    
    if(opc == 1){
      cout << BOLD << "CONVERSOR DE BASES" << RESET << endl << endl;
      cin.ignore();
      cout << "Binario (0b), Octal (0), Hexadecimal(0x)" << endl;
      cout << "Digite o numero: ";
      getline(cin, num);

      cout << "Digite a base de saida (2, 8, 10, 16): ";
      cin >> base_s;
      
      base_e = detectBase(num);

      if(base_e == base_s){
        cout << "Bases iguais" << endl << endl;
        continue;
      } 
      else{
        if(base_s == 2){
          binary = decimalBinary(baseToDecimal(num, base_e));
          cout << BOLD <<  num << RESET << " da base " << BOLD << base_e << RESET << " para a base " << BOLD << base_s << RESET << endl;
          cout << BOLD << "Resultado: " << RESET << binary << endl << endl;
          
          continue;
        }
        //CONVERTER BINARIO PARA OCTAL E HEXADECIMAL/ ou decimal para alguma dessas
        // Fazer função para transformar o int que retorna do baseToDecimal em string
        else if(base_s == 8){

          continue;
        }
        else if(base_s == 10){
          string decimal = to_string(baseToDecimal(num, base_e));
          
          cout << BOLD << num << RESET << " da base " << BOLD << base_e << RESET << " para a base " << BOLD << base_s << RESET << endl;
          cout << BOLD << "Resultado: " << RESET << decimal << endl << endl;
          continue;
        }
        else if(base_s == 16){

          continue;
        }
        else{
          cout << "Base não comportada" << endl << endl;
          continue;
        }
      }
      continue;
    }
    else if(opc == 2){
      cout << BOLD << "OPERACOES ARITMETICAS" <<  RESET << endl;

      continue;
    }
    else if(opc == 0){
      cout << RED << "Saindo............................" << RESET << endl;
      break;
    }
    else {
      cout << RED << "Opcao invalida" << RESET << endl;
      continue;
    }
  }
  return 0;
}
