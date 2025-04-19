#include <iostream>
#include "functions.h"
#include "colors.h"

int main(){
  // Declarar variaveis
  int opc;
  int opc_arit;
  int base_s;
  int base_e;
  int tipo_bin;
  
  string num =  "";
  string num1 = "";
  string num2 = "";
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
          cout << "Escolha o formato" << endl;
          cout << "[1] - Binario sem sinal" << endl;
          cout << "[2] - Sinal magnetude" << endl;
          cout << "[3] - Complemento de 1" << endl;
          cout << "[4] - Complemento de 2" << endl;
          cout << "[0] - Sair" << endl;
          cout << ">> ";
          cin >> tipo_bin;

          if(tipo_bin == 1){
            binary = decimalBinary(baseToDecimal(num, base_e));
          }
          else if(tipo_bin == 2){
            binary = toSignedMagnitude(baseToDecimal(num, base_e));
          }
          else if(tipo_bin == 3){
            binary = toOnesComplement(baseToDecimal(num, base_e));
          }
          else if(tipo_bin == 4){
            binary = toTwosComplement(baseToDecimal(num, base_e));
          }
          else if(tipo_bin == 0){
            cout << RED << "Saindo............................" << RESET << endl;
            break;
          }
          else{
            cout << RED << "Opcao invalida" << RESET << endl;
            continue;
          }

          cout << BOLD <<  num << RESET << " da base " << BOLD << base_e << RESET << " para a base " << BOLD << base_s << RESET << endl;
          cout << BOLD << "Resultado: " << RESET << binary << endl << endl;
          
          continue;
        }
        //CONVERTER BINARIO PARA OCTAL E HEXADECIMAL/ ou decimal para alguma dessas
        // Fazer função para transformar o int que retorna do baseToDecimal em string => existe uma função pra isso => to_string()
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
      cin.ignore();
      cout << "Qual operacao aritimetica vai ser realizada?" << endl;
      cout << "1. Soma, 2. subtracao, 3. multiplicacao ou 4. divisao?" <<endl;
      cin >> opc_arit;
      if (opc_arit == 1){
        cout << BOLD << "SOMA" <<  RESET << endl;
        cin.ignore();
        cout << "Binario (0b), Octal (0), Hexadecimal(0x)" << endl;
        cout << "Digite o numero: ";
        getline(cin, num);  
        cin.ignore();
        //aplicar detector de base
        cout << "Digite o primeiro numero da operacao: " << endl;
        getline(cin, num);
        //aplicar conversor para base 10
        cin.ignore();
        cout << "Digite o segundo numero da operacao: " << endl;
        getline(cin, num);
        //aplicar conversor para base 10
        //aplicar função soma
        cout << BOLD << num1 << RESET << " + " << BOLD << num2 << RESET << " = " << BOLD << soma << RESET << endl;

      }
      else if(opc_arit == 2){//fazer o mesmo para as próximas operações
        cout << BOLD << "SUBTRACAO" <<  RESET << endl;
        
      }
      else if(opc_arit == 3){
        cout << BOLD << "MULTIPLICACAO" <<  RESET << endl;

      }
      else if(opc_arit == 4){//verificar ponto flutuante
        cout << BOLD << "DIVISAO" <<  RESET << endl;

      }
      else{
        cout << RED << "Opcao invalida" <<  RESET << endl;
        break;
      }
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
