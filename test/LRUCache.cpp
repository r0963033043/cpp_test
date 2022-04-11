#include <iostream>
#include <string>
#include <vector>
#include <algorithm>   // std::find
using namespace std;

string LRUCache(string strArr[], int arrLength) {
  // code goes here  

  string *str;
  vector<string> ret;
  int len = 0;

  for(int i=0; i<arrLength; i++){
    str = &(strArr[i]);
    if(find(ret.begin(), ret.end(), *str) != ret.end()){
      // move previous one to back
      // erase finding one, than add to the back
      ret.erase(find(ret.begin(), ret.end(), *str));
      ret.push_back(*str);
    } else{
      // add first appear char
      ret.push_back(*str);
      len++;
    }
  }

  strArr[0] = "";
  for(int i=len-5; i<len-1; i++){
    if(ret[i] != "")
      strArr[0] += ret[i] + ", ";
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
