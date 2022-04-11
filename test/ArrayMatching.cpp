#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string ArrayMatching(string strArr[], int arrLength) {
  // code goes here
  string *str;

  // remove header "["
  for(int i=0; i<arrLength; i++){
    str = &(strArr[i]);
    str->replace(str->find('['), 1, "");
  }

  string pattern = ", ";
  string::size_type begin, end;

  vector<int> sum;
  int num = 0;
  int index = 0;
  int len=0;

  for(int i=0; i<arrLength; i++){
    index = 0;

    str = &(strArr[i]);
    begin = 0;
    end = str->find(pattern);
    while(end != string::npos){
      if(end - begin != 0){
        // vector item that need to be initialized: 
        // 1. first line(A[0])
        // 2. or string larger than before
        if(i == 0 || index > len)
          sum.push_back(0);
        
        // split string by ", ", than change type to int
        num = stoi(str->substr(begin, end-begin));
        sum.at(index) += num;
        index++;
      }
      begin = end + pattern.size();
      end = str->find(pattern, begin);
    }

    // last num
    if(begin != str->length()){
      num = stoi(str->substr(begin, end-begin));
      sum.push_back(0);
      sum.at(index) += num;
    }

    if(len < index)
      len = index;
  }

  strArr[0] = "";
  for(int i=0; i<len; i++){
    strArr[0] += to_string(sum[i]) + "-";
  }
  strArr[0] += to_string(sum[len]);


  return strArr[0];
}

int main(void) { 
   
  // keep this function call here
  //string A[] = coderbyteInternalStdinFunction(stdin);

  string A[] = {"[5, 2, 3]", "[2, 2, 3, 10, 6]"};  // 6-4-13-17
  /*
   * Input: {"[5, 2, 3]", "[2, 2, 3, 10, 6]"}
     Output: 7-4-6-10-6
     Input: {"[1, 2, 1]", "[2, 1, 5, 2]"}
     Output: 3-3-6-2
   */

  int arrLength = sizeof(A) / sizeof(*A);
  cout << ArrayMatching(A, arrLength) << "\n";
  return 0;
    
}
