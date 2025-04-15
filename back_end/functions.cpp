#include <iostream>
#include <cmath>
#include <string>
#include "functions.h"

using namespace std;

int detectBase(string &num){
  // Retorna o int relacionado ao tipo de base
  if(num.substr(0, 2) != "0b" && num[0] != '0' && num.substr(0, 2) != "0x"){
    return 10;
  }
  if(num.substr(0, 2) == "0b"){
    return 2;
  }
  if(num[0] == '0' && isOctal(num) && num.length() > 1 && num[1] != 'x'){
    return 8;
  }
  if(num.substr(0, 2) == "0x"){
    return 16;
  }
  return 0;
}

bool isOctal(string &num){
  // Retorna TRUE se a string num for composta por 01234567
  return num.find_first_not_of("01234567") == string::npos;
}

int baseToDecimal(string &num, int base){
  int i;
  int value;
  int decimal = 0;
  int power = 1;
  char digit;

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

  return decimal;
}

string decimalBinary(int decimal){
  string binary = "";

  if (decimal == 0)
    return "0";

  while(decimal > 0){
    binary = (decimal % 2 == 0 ? "0" : "1") + binary;
    decimal /= 2;
  }
  return binary;
}

string removePrefix(string &num, int base){
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