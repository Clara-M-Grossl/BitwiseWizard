#include <iostream>
#include "functions.h"

using namespace std;

int main(){
  // Declarar variaveis
  int opc_1;
  
  for(;;){
    cout << "***BitwiseWizard***" << endl << endl;
    cout << "[1] - Converter bases." << endl;
    cout << "[2] - Operacoes aritmeticas." << endl;
    cout << "[0] - Sair. " << endl;
    cout << ">> ";
    
    cin >> opc_1;
    
    if(opc_1 == 1){
      int opc_2 = menu_bases();
      
      if(opc_2 == 1){
        // Binaria
        int opc_3;
        
        cout << "Base Binaria para:" << endl;
        cout << "[1] - Base Octal." << endl;
        cout << "[2] - Base Decimal." << endl;
        cout << "[3] - Base Hexadecimal." << endl;
        cout << "[0] - Sair." << endl;

        
        cin >> opc_3;
        
        if(opc_3 == 1){
          continue;
        }
        if(opc_3 == 2){
          continue;
        }
        if(opc_3 == 3){
          continue;
        }
        if(opc_3 == 0){
          cout << "Saindo............................" << endl;
          break;
        }
        continue;
        
      }
      if(opc_2 == 2){
        // Octal
        int opc_3;
        
        cout << "Base Octal para:" << endl;
        cout << "[1] - Base Binaria." << endl;
        cout << "[2] - Base Decimal." << endl;
        cout << "[3] - Base Hexadecimal." << endl;
        cout << "[0] - Sair." << endl;
        
        cin >> opc_3;
        if(opc_3 == 1){
          continue;
        }
        if(opc_3 == 2){
          continue;
        }
        if(opc_3 == 3){
          continue;
        }
        if(opc_3 == 0){
          cout << "Saindo............................" << endl;
          break;
        }
        continue;
        
      }
      if(opc_2 == 3){
        // Decimal
        int opc_3;
        
        cout << "Base Decimal para:" << endl;
        cout << "[1] - Base Binaria." << endl;
        cout << "[2] - Base Octal." << endl;
        cout << "[3] - Base Hexadecimal." << endl;
        cout << "[0] - Sair." << endl;
        
        cin >> opc_3;
        if(opc_3 == 1){
          continue;
        }
        if(opc_3 == 2){
          continue;
        }
        if(opc_3 == 3){
          continue;
        }
        if(opc_3 == 0){
          cout << "Saindo............................" << endl;
          break;
        }
        continue;
        
      }
      if(opc_2 == 4){
        // Hexadecimal
        int opc_3;

        cout << "Base Hexadecimal para:" << endl;
        cout << "[1] - Base Binaria." << endl;
        cout << "[2] - Base Octal." << endl;
        cout << "[3] - Base Decimal." << endl;
        cout << "[0] - Sair." << endl;
        
        cin >> opc_3;
        for(;;){
          if(opc_3 == 1){
            continue;
          }
          if(opc_3 == 2){
            continue;
          }
          if(opc_3 == 3){
            continue;
          }
          if(opc_3 == 0){
            cout << "Saindo............................" << endl;
            break;
          }
        }
        continue;

      }
      if(opc_2 == 0){
        cout << "Saindo............................" << endl;
        break;
    }
    continue;
    }

    if(opc_1 == 2){
      int opc_4;

      cout << "**Operacoes Aritmeticas**" << endl;
      cout << "Escolha a operacao: " << endl;
      cout << "[1] - Soma." << endl;
      cout << "[2] - Subtracao." << endl;
      cout << "[3] - Multiplicacao." << endl;
      cout << "[4] - Divisao." << endl;
      cout << "[0] - Sair." << endl;
      cout << ">> ";

      cin >> opc_4;
      if(opc_4 == 1){
        // Soma
        int opc_5 = menu_bases();
        continue;
      }
      if(opc_4 == 2){
        // Subtração
        int opc_5 = menu_bases();
        continue;
      }
      if(opc_4 == 3){
        // Multiplicação
        int opc_5 = menu_bases();
        continue;
      }
      if(opc_4 == 4){
        // Divisão
        int opc_5 = menu_bases();
        continue;
      }
      if(opc_4 == 0){
        cout << "Saindo............................" << endl;
        break;
      }
      continue;
    }
    if(opc_1 == 0){
      cout << "Saindo............................" << endl;
      break;
    }
  }
  return 0;
}
