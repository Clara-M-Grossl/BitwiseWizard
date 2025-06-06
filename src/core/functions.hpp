#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <cstdint>


using namespace std;

//Detecta qual o tipo de base
int detectBase(string &num);
bool isBinary(string &num);
bool isOctal(string &num);
bool isDecimal(string &num);
bool isHexadecimal(string &num);
bool isnotainteger(double num);
bool isFloat(string num, int base);

//Formatação
int valueAbsolute(int num);
string removePrefix(string num, int base);
string formatNumber(string &num);

string completeBits(string bin);
string addOneToBinary(string binary);

double valueAbsolutefloat(double num);
string addOneToBinaryfloat(string binary);
string doubletostring(double num);

//Base->decimal
int baseToDecimal(string num, int base);
double baseToDecimalfloat(string num, int base);

// Decimal->Binary
// Int
string decimalBinary(int decimal);
string toSignedMagnitude(int decimal);
string toOnesComplement(int decimal);
string toTwosComplement(int decimal);
// Float
string floatdecimalBinary(double decimal);
string toTwosComplementfloat(double decimal);
string toOnesComplementfloat(double decimal);
string toSignedMagnitudefloat(double decimal);

// Decimal->Octal
string converterParteInteiraOctal(double parteInteira);
string converterParteFracionariaOctal(double parteFracionaria, int maxDigitos = 6);
string deciToOctal(double numero);

// Decimal->Hexadecimal
string converterParteInteiraHexa(double parteInteira);
string converterParteFracionariaHexa(double parteFracionaria, int maxDigitos = 6);
string deciToHexa(double numero);

//Operações aritiméticas
string sum(string &num1,string &num2, int base1, int base2);
string sub(string &num1, string &num2, int base1, int base2);
string mult(string &num, string &num2, int base1, int base2);
string div(string &num, string &num2, int base1, int base2);

#endif
