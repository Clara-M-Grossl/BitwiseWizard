#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
using namespace std;

//Bases
int detectBase(string &num);
int baseToDecimal(string num, int base);
bool isOctal(string &num);

//Binario
string decimalBinary(int decimal);
string toSignedMagnitude(int decimal);
string toOnesComplement(int decimal);
string toTwosComplement(int decimal);

//Formatação
int valueAbsolute(int num);
string removePrefix(string num, int base);
string completeBits(string bin);

string addOneToBinary(string binary);

//Operações aritiméticas
string soma(string &num1,string &num2);
string sub(string &num1, string &num2);
string mult(string &num, string &num2);
string div(string &num, string &num2);

#endif