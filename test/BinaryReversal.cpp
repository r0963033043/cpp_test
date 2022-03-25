#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string BinaryReversal(string str) {
  // code goes here  

  long int num = stoi(str);
  long int binNum = 0;
  int i = 0;

  while(num > 0){
    binNum += (num % 2) * pow(10, i);
    num/=2;
    i++;
  }

  i = 7 + 8 * ( (i-1)/8 );

  while(binNum > 0){
    num += binNum % 2 * pow(2, i);
    binNum/=10;
    i--;
  }
  
  return std::to_string(num);

}

int main(void) { 
   
  // keep this function call here
  cout << BinaryReversal(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}
