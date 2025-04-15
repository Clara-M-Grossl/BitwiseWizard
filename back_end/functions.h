#include <string>
using namespace std;
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int menu_bases();
int detectBase(string &num);
int baseToDecimal(string &num, int base);

string decimalBinary(int decimal);
string removePrefix(string &num, int base);

bool isOctal(string &num);

#endif