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
  int power = 0, addUp = 0, random, random2;

  printTitle(PROMPT);

  do{
     choice = getNumber(PROMPT_TWO);

     base = getBase(choice);

     if(base == 'D'){
      change = decimalToBinary(choice);

      cout << "The binary conversion is: " << change << endl;

      change = decimalToHex(choice);

      cout << "The hexadecimal conversion is: " << change << endl << endl;
     }
     else if(base == 'B'){
      change = binaryToDecimal(choice);

      cout << "The decimal conversion is: " << change << endl;

      change = binaryToHex(choice);

      cout << "The hexadecimal conversion is: " << change << endl << endl;
     }
     else if(base == 'H'){
      //change = hexToDecimal(choice);


     for(int i = choice.length() - 1; i >= 2; i--){
      if(choice[i] == 'A' || choice[i] == 'B' || choice[i] == 'C'
       || choice[i] == 'D' || choice[i] == 'E' || choice[i] == 'F'){
        addUp += pow(16, power) * hexCharToInt(choice[i]);

        random2 = choice[i];
     }
     else{
      random2 = choice[i];

      addUp += pow(16, power) * static_cast<int>(choice[i]);
     }

      power++;
     }

      cout << "The decimal conversion is: " << change << endl;

      //change = binaryToHex(choice);

      //cout << "The hexadecimal conversion is: " << change << endl << endl;
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
  int transition, temp;
  string newString;
  char base;

  transition = stoi(strNumber);

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

  return "0x" + newString;
}

string hexToDecimal(const string &strNumber){
 int addUp = 0, base = 16, power = 0;
  string newString;

  for(int i = strNumber.length() - 1; i >= 2; i--){
    if(strNumber[i] == 'A' || strNumber[i] == 'B' || strNumber[i] == 'C'
       || strNumber[i] == 'D' || strNumber[i] == 'E' || strNumber[i] == 'F'){
        addUp += pow(base, power) * hexCharToInt(strNumber[i]);
    }
    else{
    addUp += pow(base, power) * static_cast<int>(strNumber[i]);
    }

    power++;
  }
  return newString = to_string(addUp);
}

string hexToBinary(const string &strNumber){
  string change;
  change = hexToDecimal(strNumber);
  change = decimalToBinary(change);
}

string binaryToHex(const string &strNumber){
  string change;

  change = binaryToDecimal(strNumber);
  change = decimalToHex(change);

  return change;
}
