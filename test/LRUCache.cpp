#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string LRUCache(string strArr[], int arrLength) {
  // code goes here  
  string *str;
  vector<string> ret;
  int len = 0;

  for(int i=0; i<arrLength; i++){
    str = &(strArr[i]);

    vector<string>::iterator it = find(ret.begin(), ret.end(), *str);
    if(it != ret.end()){
      // erase previous appear one
      ret.erase(it);
      len--;
    }
    // add last appear to back
    ret.push_back(*str);
    len++;
  }

  strArr[0] = "";

  int index = 0;
  if(len > 5){
    index = len -5;
  }

  for(int i=index; i<len-1; i++){
    strArr[0] += ret[i] + "-";
  }
  strArr[0] += ret[len-1];

  return strArr[0];

}

int main(void) { 
   
  // keep this function call here
//  string A[] = coderbyteInternalStdinFunction(stdin);
  string A[] = {"A", "B", "A", "C", "A", "B"}; //  C-A-E-D-Z

  /*
   * Input: {"A", "B", "A", "C", "A", "B"}
     Output: C-A-B
     Input: {"A", "B", "C", "D", "E", "D", "Q", "Z", "C"}
     Output: E-D-Q-Z-C
   */

  int arrLength = sizeof(A) / sizeof(*A);
  cout << LRUCache(A, arrLength);
  cout << "\n";
  return 0;
    
}
