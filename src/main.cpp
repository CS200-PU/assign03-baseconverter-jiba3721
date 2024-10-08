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
string binaryToHex(const string &strNumber);


int main () {
  const string PROMPT = "HEX-DECIMAL-BINARY CONVERTER",
               PROMPT_TWO = "Enter your string to convert (q to quit): ";

  string choice, change;
  char base;

  printTitle(PROMPT);

  do{
     choice = getNumber(PROMPT_TWO);

     if(choice == "q"){
      exit (EXIT_FAILURE);
     }

     base = getBase(choice);

     if(base == 'D'){
      change = decimalToBinary(choice);

      cout << "The binary conversion is: " << change << endl;

      change = decimalToHex(choice);

      cout << "The hexadecimal conversion is: " << change << endl;
     }
     else if(base == 'B'){
      change = binaryToDecimal(choice);

      cout << "The decimal conversion is: " << change << endl;

      change = binaryToHex(choice);

      cout << "The hexadecimal conversion is: " << change << endl;
     }
     else if(base == 'H'){
      change = hexToDecimal(choice);

      cout << "The decimal conversion is: " << change << endl;

      change = hexToBinary(choice);

      cout << "The binary conversion is: " << change << endl;
     }
    
  }while(choice != "q");
  
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
  else if(hexDigit == 70){
    value = F;
  }
  else{
    value = hexDigit;
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

  cout << endl << prompt;
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

  if(transition == 0){
    newString = "0";
  }
  else{
    while(transition > 0){
      newString += to_string(transition % 2);
      transition /= 2;
    }
    reverse(newString.begin(),newString.end());
  }
  return "0b" + newString;
}

string decimalToHex(const string &strNumber){
  int transition, temp;
  string newString;
  char base;

  transition = stoi(strNumber);

  if(transition == 0){
    newString = "0";
  }
  else{
    while(transition > 0){
      temp = transition % 16;

      if(temp == 10){
        base = 'A';
        newString += base;
      }
      else if(temp == 11){
        base = 'B';
        newString += base;
      }
      else if(temp == 12){
        base = 'C';
        newString += base;
      }
      else if(temp == 13){
        base = 'D';
        newString += base;
      }
      else if(temp == 14){
        base = 'E';
        newString += base;
      }
      else if(temp == 15){
        base = 'F';
        newString += base;
      }
      else{
        newString += to_string(temp);
      }
      transition /= 16;
    }

    reverse(newString.begin(),newString.end());
  }
  return "0x" + newString;
}

string hexToDecimal(const string &strNumber){
 int addUp = 0, base = 16, power = 0, minus = 48;
  string newString;

  for(int i = strNumber.length() - 1; i >= 2; i--){
    if(strNumber[i] == 'A' || strNumber[i] == 'B' || strNumber[i] == 'C'
       || strNumber[i] == 'D' || strNumber[i] == 'E' || strNumber[i] == 'F'){
        addUp += pow(base, power) * hexCharToInt(strNumber[i]);
    }
    else{
    addUp += pow(base, power) * hexCharToInt(strNumber[i]) - minus;
    }

    power++;
  }
  return newString = to_string(addUp);
}

string hexToBinary(const string &strNumber){
  string change;

  change = hexToDecimal(strNumber);
  change = decimalToBinary(change);

  return change;
}

string binaryToHex(const string &strNumber){
  string change;

  change = binaryToDecimal(strNumber);
  change = decimalToHex(change);

  return change;
}
