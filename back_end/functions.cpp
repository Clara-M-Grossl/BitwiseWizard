#include <iostream>
#include <cmath>
#include "functions.h"

int detectBase(string &num){
  // Retorna o int relacionado ao tipo de base
  if(num.substr(0, 2) == "0b" || num.substr(0, 3) == "-0b"){
    return 2;
  }
  if(num.substr(0, 2) == "0x" || num.substr(0, 3) == "-0x"){
    return 16;
  }
  if(num[0] == '0' && isOctal(num) && num.length() > 1 && num[1] != 'x' || num.substr(0,2) == "-0"){
    return 8;
  }
  return 10;
}

bool isOctal(string &num){
  // Retorna TRUE se a string num for composta por 01234567
  return num.find_first_not_of("01234567") == string::npos;
}

int baseToDecimal(string num, int base){
  int i;
  int value;
  int decimal = 0;
  int power = 1;
  char digit;

  bool negative = false;

  
  if(num[0] == '-'){
    num = num.substr(1);
    negative = true;
  }
  
  string CleanNum = removePrefix(num, base);
  // percorre da direita para a esquerda
  for(i = CleanNum.length() - 1; i >= 0; i --){
    digit = toupper(CleanNum[i]);
    //converter string para int
    if(digit >= '0' && digit <= '9'){
      value = digit - '0';
    }
    else if(digit >= 'A' && digit <= 'F'){
      value = digit - 'A' + 10;
    }
    decimal += value * power;
    power *= base; //power = power * bas
  }

  if(negative){
    decimal = -decimal;
  }

  return decimal;
}

string decimalBinary(int decimal){
  string binary = "";

  if (decimal == 0)
    return "0";

  decimal = valueAbsolute(decimal);

  while(decimal > 0){
    binary = (decimal % 2 == 0 ? "0" : "1") + binary;
    decimal /= 2;
  }

  return completeBits(binary);
}

string toSignedMagnitude(int decimal){
  bool negative = false;
  string binary = completeBits(decimalBinary(decimal));

  if(decimal < 0){
    negative = true;
  }
  
  if(negative){
    binary[0] = '1';
  }
  else{
    binary[0] = '0';
  }
  return binary;
}
string toOnesComplement(int decimal){
  string binary = completeBits(decimalBinary(decimal));
  
  if(decimal < 0){
    for(char &c : binary){
      c = (c == '0') ? '1' : '0';
    }
  }
  return binary;
}
string toTwosComplement(int decimal){
  string binary = completeBits(decimalBinary(decimal));

  if(decimal < 0){
    binary = addOneToBinary(toOnesComplement(decimal));
  }
  return binary;
}

// Formatação
string removePrefix(string num, int base){
  if(base == 2) {
    return num.substr(2);
  }
  else if(base == 8) {
    return num.substr(1);
  }
  else if(base == 16) {
    return num.substr(2);
  }
  return num;
}
string completeBits(string bin){
  while(bin.length() < 8){
    bin = "0" + bin;
  }
  return bin;
}
int valueAbsolute(int num){
  return (num < 0) ? -num : num;
}

string addOneToBinary(string binary){
  int i;
  bool carry = true;

  for (i = binary.length() - 1; i >= 0; i--){
    if(binary[i] ==  '0'){
      binary[i] = '1';
      carry = false;
      break;
    }
    else{
      binary[i] = '0';
    }
  }
  if(carry){
    return "1" + binary;
  }
  return binary;
}

string conversorbase_soperacao(string num){

  int tipo_bin;
  string res;
  const int base_e = 10;
  int base_s;

  cout << "Digite a base de saida (2, 8, 10, 16): ";
  cin >> base_s;
  
  if(base_e == base_s){
    return num;
  } 
  else{
    if(base_s == 2){
      do{
        cout << "Escolha o formato" << endl;
        cout << "[1] - Binario sem sinal" << endl;
        cout << "[2] - Sinal magnetude" << endl;
        cout << "[3] - Complemento de 1" << endl;
        cout << "[4] - Complemento de 2" << endl;
        cout << "[0] - Sair" << endl;
        cout << ">> ";
        cin >> tipo_bin;

        if(tipo_bin == 1){
          res = decimalBinary(baseToDecimal(num, base_e));
        }
        else if(tipo_bin == 2){
          res = toSignedMagnitude(baseToDecimal(num, base_e));
        }
        else if(tipo_bin == 3){
          res = toOnesComplement(baseToDecimal(num, base_e));
        }
        else if(tipo_bin == 4){
          res = toTwosComplement(baseToDecimal(num, base_e));
        }
        else if(tipo_bin == 0){
          cout << "Saindo............................" << endl;
          break;
        }
        else{
          cout << "Opcao invalida" << endl;
          continue;
        }
        return res;
      }while(true);
    }
    //CONVERTER BINARIO PARA OCTAL E HEXADECIMAL/ ou decimal para alguma dessas
    // Fazer função para transformar o int que retorna do baseToDecimal em string => existe uma função pra isso => to_string()
    else if(base_s == 8){
      return res;
    }
    else if(base_s == 16){
      return res;
    }
    else{
      cout << "Base nao comportada" << endl << endl;
      return "ERRO - base nao comportada";
    }
  }
}



string sum(string &num1,string &num2, int base1, int base2){
  int n1 , n2 , sum;
  n1 = baseToDecimal(num1, base1);
  n2 = baseToDecimal(num2, base2);

  sum = n1 + n2;

  cout << "TESTE: " << sum << endl;

  string resultado = to_string(sum);

  string sumconverted = conversorbase_soperacao(resultado);
  return sumconverted;
}

string sub(string &num1, string &num2, int base1, int base2){
  
  int n1 , n2 , sub;
  n1 = baseToDecimal(num1, base1);
  n2 = baseToDecimal(num2, base2);

  sub = n1 - n2;

  cout << "TESTE: " << sub << endl;

  string resultado = to_string(sub);

  string sumconverted = conversorbase_soperacao(resultado);

  return sumconverted;
}

string mult(string &num1, string &num2, int base1, int base2){
  
  int n1 , n2 , mult;
  n1 = baseToDecimal(num1, base1);
  n2 = baseToDecimal(num2, base2);

  mult = n1 * n2;

  string resultado = to_string(mult);

  string sumconverted = conversorbase_soperacao(resultado);

  return sumconverted;
}

string div(string &num1, string &num2, int base1, int base2){
  
  int n1 , n2;
  double div;
  n1 = baseToDecimal(num1, base1);
  n2 = baseToDecimal(num2, base2);

  div = n1 / n2;

  string resultado = to_string(div);
  // olhar ponto flutuante
  string sumconverted = conversorbase_soperacao(resultado);

  return sumconverted;
}