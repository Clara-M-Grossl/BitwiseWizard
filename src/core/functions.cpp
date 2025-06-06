#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <cstdint>
#include "functions.hpp"

// Cabeçalho das funções

//Detecta qual o tipo de base
int detectBase(string &num){
  // Retorna o int relacionado ao tipo de base
  if(num.substr(0, 2) == "0b" || num.substr(0, 3) == "-0b"){
    if(isBinary(num)){
      return 2;
    }
    return 0;
  }
  if(num.substr(0, 2) == "0x" || num.substr(0, 3) == "-0x"){
    if(isHexadecimal(num)){
      return 16;
    }
    return 0;
  }
  if(num[0] == '0' && num[1] != 'x' || num.substr(0,2) == "-0"){
    if(isOctal(num)){
      return 8;
    }
    return 0;
  }
  if(isDecimal(num)){
    return 10;
  }
  return 0;
}
bool isBinary(string &num){
  return num.find_first_not_of("-b01.,") == string::npos;
}
bool isOctal(string &num){
  // Retorna TRUE se a string num for composta por 01234567
  // '-' pra considerar o negativo
  return num.find_first_not_of("-01234567.,") == string::npos;
}
bool isHexadecimal(string &num){
  return num.find_first_not_of("-x0123456789ABCDEFabcdef.,") == string::npos;
}
bool isDecimal(string &num){
  return num.find_first_not_of("-0123456789.,") == string::npos;
}
bool isnotainteger(double num){
  return floor (num) != num; // floor(num) vai arredondar o numero para baixo, e se for inteiro o numero vai permanecer igual
}
bool isFloat(string num, int base){
  size_t point;

  if(num[0] == '-'){
    num = num.substr(1);
  }
  string CleanNum = removePrefix(num, base);

  for(char &c : CleanNum){
    if (c == ',') c = '.';
  }
  point = CleanNum.find('.');

  if(point != string::npos){
    return true;
  }
  return false;
}

// Formatação
int valueAbsolute(int num){
  return (num < 0) ? -num : num;
}
string removePrefix(string num, int base){
  if(base == 2) {
    return num.substr(2); //Retira o '0b'
  }
  else if(base == 8) {
    return num.substr(1); //Retira o '0'
  }
  else if(base == 16) {
    return num.substr(2); //Retira o '0x'
  }
  return num;
}
string formatNumber(string &num){
  //Retira os zeros não necessarios
  size_t point;

  if(num[0] == '-'){
    num = num.substr(1);
  }
  string CleanNum = removePrefix(num, 10);

  for(char &c : CleanNum){
    if (c == ',') c = '.';
  }
  point = CleanNum.find('.');
  
  if(point == string::npos){
    return num;
  }
  string trimmed = num;
  trimmed.erase(trimmed.find_last_not_of('0') + 1, string::npos);

  if(trimmed.back() == '.'){
    trimmed.pop_back();
  }
  return trimmed;
}

string completeBits(string bin){
  while(bin.length() < 8){
    bin = "0" + bin;
  }
  return bin;
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

double valueAbsolutefloat(double num){  
  return (num < 0) ? -num : num;
}
string addOneToBinaryfloat(string binary){ //verificar
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
string doubletostring(double num){
  ostringstream oss;
  oss << fixed << setprecision(8) << num;
  return oss.str();
}

// Base->Decimal
int baseToDecimal(string num, int base){
  int i;
  int value;
  int decimal = 0;
  int power = 1;
  char digit;
  bool negative = false;

  // Se for negativo retira o '-'
  if(num[0] == '-'){
    num = num.substr(1);
    negative = true;
  }
  // Função que retira o '0b', '0', '0x'
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
    power *= base;
  }

  // Se for negativo coloca o '-'
  if(negative){
    decimal = -decimal;
  }

  return decimal;
}
double baseToDecimalfloat(string num, int base){
  int i;
  int value;
  double decimal = 0;
  int power = 1;
  double power2 = 1.0 / base;
  char digit;
  string intpart = "";
  string fractpart = "";
  size_t point;
  long long integer = 0;
  double fraction = 0.0;
  int precision = 8; // controlar nmr de casas pós a virgula

  bool negative = false;
  
  if(num[0] == '-'){
    num = num.substr(1);
    negative = true;
  }
  string CleanNum = removePrefix(num, base);

  //separando a string em parte inteira e fracionaria
  for(char &c : CleanNum){
    if (c == ',') c = '.';
  }

  point = CleanNum.find('.'); //Se não for encontrado, retorna string::npos, se não retorna a posição

  intpart = CleanNum.substr(0, point);

  if(point != string::npos)
    fractpart = CleanNum.substr(point + 1);
  else fractpart = "";

  // percorre da direita para a esquerda
  for(i = intpart.length() - 1; i >= 0; i --){
    digit = toupper(intpart[i]);
    //converter string para int
    if(digit >= '0' && digit <= '9'){
      value = digit - '0';
    }
    else if(digit >= 'A' && digit <= 'F'){
      value = digit - 'A' + 10;
    }

    integer += value * power;
    power *= base; //power = power * bas
  }
  for(i = 0; i < fractpart.length() && i < precision; i ++){
    digit = toupper(fractpart[i]);
    //converter string para int
    if(digit >= '0' && digit <= '9'){
      value = digit - '0';
    }
    else if(digit >= 'A' && digit <= 'F'){
      value = digit - 'A' + 10;
    }
    fraction += value * power2;
    power2 /= base; //power = power / base
  }

  decimal = integer + fraction;

  if(negative){
    decimal = -decimal;
  }

  return decimal; //to string ta arredondando para 6 digitos
}

// Decimal->Binary
// Int
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
//Float
string floatdecimalBinary(double decimal){
  string binary = "";
  string intbinary = "";
  string fracbinary = "";
  int integerpart;
  double fractionalpart;
  int precision = 8;

  if (decimal == 0.0)
    return "0";

  decimal = valueAbsolutefloat(decimal);

  //separação em parte inteira e fracionaria para conversão
  integerpart = static_cast<int>(decimal);
  fractionalpart = decimal - integerpart;

  while(integerpart > 0){
    intbinary = (integerpart % 2 == 0 ? "0" : "1") + intbinary;
    integerpart /= 2;
  }
  intbinary = completeBits(intbinary);

  while(fractionalpart >= 0.0 && precision--){
    fractionalpart *= 2;
      if (fractionalpart >= 1.0){
        fracbinary += "1";
        fractionalpart -=1;
      }
      else fracbinary += '0';

    binary = intbinary;
    if (!fracbinary.empty()) {
        binary += "." + fracbinary;
    }
  }
  return binary;
}
string toSignedMagnitudefloat(double decimal){
  bool negative = false;
  
  string binary = completeBits(floatdecimalBinary(decimal));

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
string toOnesComplementfloat(double decimal){
  string binary;
  if(isnotainteger(decimal) == true) return binary= "nao eh possivel fazer conversao de float para complemento de 1";
  binary = completeBits(floatdecimalBinary(decimal));
  
  if(decimal < 0){
    for(char &c : binary){
      c = (c == '0') ? '1' : '0';
    }
  }
  return binary;
}
string toTwosComplementfloat(double decimal){
  string binary;
  if(isnotainteger(decimal) == true) return binary = "nao eh possivel fazer conversao de float para complemento de 2";
  binary = completeBits(floatdecimalBinary(decimal));

  if(decimal < 0){
    binary = addOneToBinary(toOnesComplementfloat(decimal));
  }
  return binary;
}

// Decimal->Octal
string converterParteInteiraOctal(double parteInteira) {
  if (parteInteira == 0) {
      return "0";
  }
  string octal;
  uint64_t inteiro = static_cast<uint64_t>(parteInteira);
  while (inteiro > 0) {
      int resto = inteiro % 8;
      octal = to_string(resto) + octal;
      inteiro /= 8;
  }
  return octal;
}
string converterParteFracionariaOctal(double parteFracionaria, int maxDigitos) {
  if (parteFracionaria == 0.0) {
      return "";
  }
  string octal;
  while (parteFracionaria > 0.0 && maxDigitos-- > 0) {
      parteFracionaria *= 8.0;
      int digito = static_cast<int>(parteFracionaria);
      octal += to_string(digito);
      parteFracionaria -= static_cast<double>(digito);
  }
  // Remover zeros à direita
  size_t ultimoNaoZero = octal.find_last_not_of('0');
  if (ultimoNaoZero != string::npos) {
      octal = octal.substr(0, ultimoNaoZero + 1);
  } else {
      octal = ""; // Todos os dígitos eram zero
  }
  return octal;
}
string deciToOctal(double numero)
{
  bool negativo = false;
  string resultado;
  
  if (numero < 0) {
      negativo = true;
      numero = -numero;
  }
  
  double parteInteira;
  double parteFracionaria = modf(numero, &parteInteira);
  
  string octalInteiro = converterParteInteiraOctal(parteInteira);
  string octalFracionario = converterParteFracionariaOctal(parteFracionaria);
  
  if (negativo) {
      resultado = "-";
  } else {
      resultado = "";
  }
  
  resultado += octalInteiro;
  
  if (!octalFracionario.empty()) {
      resultado += "." + octalFracionario;
  }
  return resultado;
}

// Decimal->Hexadecimal
string converterParteInteiraHexa(double parteInteira)
{
    if (parteInteira == 0) {
        return "0";
    }
    
    string hexa;
    uint64_t inteiro = static_cast<uint64_t>(parteInteira);
    const char digitosHex[] = "0123456789ABCDEF";
    
    while (inteiro > 0) {
        int resto = inteiro % 16;
        hexa = digitosHex[resto] + hexa;
        inteiro /= 16;
    }
    
    return hexa;
} 
string converterParteFracionariaHexa(double parteFracionaria, int maxDigitos)
{
    if (parteFracionaria == 0.0) {
        return "";
    }
    
    string hexa;
    const char digitosHex[] = "0123456789ABCDEF";
    
    while (parteFracionaria > 0.0 && maxDigitos-- > 0) {
        parteFracionaria *= 16.0;
        int digito = static_cast<int>(parteFracionaria);
        hexa += digitosHex[digito];
        parteFracionaria -= static_cast<double>(digito);
    }
    
    size_t ultimoNaoZero = hexa.find_last_not_of('0');
    if (ultimoNaoZero != string::npos) {
        hexa = hexa.substr(0, ultimoNaoZero + 1);
    } else {
        hexa = "";
    }
    
    return hexa;
    
}
string deciToHexa(double numero)
{
    bool negativo = false;
    if (numero < 0) {
        negativo = true;
        numero = -numero;
    }

    double parteInteira;
    double parteFracionaria = modf(numero, &parteInteira);

    string hexInteiro = converterParteInteiraHexa(parteInteira);
    string hexFracionario = converterParteFracionariaHexa(parteFracionaria);

    string resultado;
    if (negativo) {
        resultado = "-";
    }
    
    resultado += hexInteiro;
    
    if (!hexFracionario.empty()) {
        resultado += "." + hexFracionario;
    }
    return resultado;
}

//Operações aritiméticas
string sum(string &num1,string &num2, int base1, int base2){
  double n1 , n2 , sum;
  n1 = baseToDecimalfloat(num1, base1);
  n2 = baseToDecimalfloat(num2, base2);

  sum = n1 + n2;

  string resultado = doubletostring(sum);
  resultado = formatNumber(resultado);
  return resultado;
}
string sub(string &num1, string &num2, int base1, int base2){
  
  double n1 , n2 , sub;
  n1 = baseToDecimalfloat(num1, base1);
  n2 = baseToDecimalfloat(num2, base2);

  sub = n1 - n2;

  string resultado = to_string(sub);

  resultado = formatNumber(resultado);
  return resultado;
}
string mult(string &num1, string &num2, int base1, int base2){
  
  double n1 , n2 , mult;
  n1 = baseToDecimalfloat(num1, base1);
  n2 = baseToDecimalfloat(num2, base2);

  mult = n1 * n2;

  string resultado = to_string(mult);

  resultado = formatNumber(resultado);
  return resultado;;
}
string div(string &num1, string &num2, int base1, int base2){
  
  double n1 , n2, div;
  n1 = baseToDecimalfloat(num1, base1);
  n2 = baseToDecimalfloat(num2, base2);

  div = n1 / n2;

  string resultado = to_string(div);

  resultado = formatNumber(resultado);
  return resultado;
}
