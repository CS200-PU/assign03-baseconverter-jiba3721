//******************************************************************************
// File name:   main.cpp
// Author:      CS Faculty
// Date:        xx/xx/xxxx (Replace xx/xx/xxxx with month/day/year)
// Class:       CS150-xx (Replace xx with your section number)
// Assignment:  Hello World
// Purpose:     Display the message Hello World to the screen
// Hours:       0.25
//******************************************************************************

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int hexCharToInt(char hexDigit);
char getBase(const string &strNumber);
string getNumber(const string &prompt);
void printTitle(const string &myTitle);
string binaryToDecimal(const string &strNumber);
string decimalToBinary(const string &strNumber);
string decimalToHex(const string &strNumber);
string hexToDecimal(const string &strNumber);
string hexToBinary(const string &strNumber);


int main () {
  string num;

  cout << "Hello World" << endl;

  num = decimalToBinary("216");

  cout << num;
  
  return EXIT_SUCCESS;
}

int hexCharToInt(char hexDigit){
  const int A = 10, B = 11, C = 12, D = 13, E = 14, F = 15;
  int value;

  if(hexDigit == 65){
    value = A;
  }
  else if(hexDigit == 66){
    value = B;
  }
  else if(hexDigit == 67){
    value = C;
  }
  else if(hexDigit == 68){
    value = D;
  }
  else if(hexDigit == 69){
    value = E;
  }
  else{
    value = F;
  }
  return value;
}

char getBase(const string &strNumber){
  char base = 'D';

  if(strNumber[1] == 'b'){
    base = 'B';
  }
  else if(strNumber[1] == 'x'){
    base = 'H';
  }
  return base;
}

string getNumber(const string &prompt){
  string number;

  cout << prompt;
  cin >> number;

  return number;
}

void printTitle(const string &myTitle){
  cout << "**************************************\n"
       << "*****" << myTitle << "*****\n"
       << "**************************************\n";
}

string binaryToDecimal(const string &strNumber){
  int addUp = 0, base = 2, power = 0;
  string newString;

  for(int i = strNumber.length() - 1; i >= 0; i--){
    if(strNumber[i] == '1'){
      addUp += pow(base, power);
    }
    power++;
  }
  return newString = to_string(addUp);
}

string decimalToBinary(const string &strNumber){
  int transition;
  string newString;

  transition = stoi(strNumber);

  while(transition > 0){
    newString += to_string(transition % 2);
    transition /= 2;
  }

  reverse(newString.begin(),newString.end());

  return "0b" + newString;
}

string decimalToHex(const string &strNumber){
  int transition;
  string newString;

  transition = stoi(strNumber);

  while(transition > 0){
    newString += to_string(transition % 16);
    transition /= 16;
  }

  reverse(newString.begin(),newString.end());

  for(int i = 0; i < newString.length(); i++){
    if(newString[i] >= 10){
      newString[i] = hexCharToInt(newString[i]);
    }
  }

  return "0x" + newString;
}

string hexToDecimal(const string &strNumber);

string hexToBinary(const string &strNumber);
