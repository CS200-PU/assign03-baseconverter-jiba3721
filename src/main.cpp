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

using namespace std;

int hexCharToInt(char hexDigit);
char getBase(const string &strNumber);
string getNumber(const string &prompt);
void printTitle(const string &myTitle);
string binaryToDecimal(const string &strNumber);
string decimalToBinary(const string &strNumber);

int main () {

  cout << "Hello World" << endl;
  
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

}

string decimalToBinary(const string &strNumber){
  int transition;
  string newString;

  transition = stoi(strNumber);

  while(transition > 0){
    newstring = 
  }
  
}