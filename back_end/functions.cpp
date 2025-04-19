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