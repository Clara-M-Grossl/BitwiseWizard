#include <string>
using namespace std;
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int detectBase(string &num);
int baseToDecimal(string &num, int base);

string decimalBinary(int decimal);
string removePrefix(string &num, int base);

bool isOctal(string &num);

//Operações aritiméticas
string soma(string &num1,string &num2);
string sub(string &num1, string &num2);
string mult(string &num, string &num2);
string div(string &num, string &num2);

#endif