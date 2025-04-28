#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
using namespace std;

//Bases
int detectBase(string &num);
int baseToDecimal(string num, int base);
bool isOctal(string &num);
bool isBinary(string &num);
bool isHexadecimal(string &num);
bool isDecimal(string &num);

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
string conversorbase_soperacao(string num);

string sum(string &num1,string &num2, int base1, int base2);
string sub(string &num1, string &num2, int base1, int base2);
string mult(string &num, string &num2, int base1, int base2);
string div(string &num, string &num2, int base1, int base2);

//Ponto flutuante
string floatpoint(string &num, int base);
double baseToDecimalfloat(string num, int base);
string floatdecimalBinary(double decimal);
string toTwosComplementfloat(double decimal);
string toOnesComplementfloat(double decimal);
string toSignedMagnitudefloat(double decimal);
double valueAbsolutefloat(double num);
string addOneToBinaryfloat(string binary);
string doubletostring(double num);

bool isnotainteger(double num);

bool isFloat(string num, int base);

#endif