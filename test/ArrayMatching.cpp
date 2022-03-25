#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ArrayMatching(string strArr[], int arrLength) {
  // code goes here

  string *str;

  for(int i=0; i<arrLength; i++){
    str = &(strArr[i]);
    str->replace(str->find('['), 1, "");
  }


  string pattern = ", ";
  string::size_type begin, end;

  int num = 0;
  int index = 0;
  int len = 0;
  vector<int> sum;

  for(int i=0; i<arrLength; i++){
    index = 0;

    str = &(strArr[i]);
    end = str->find(pattern);
    begin = 0;
    while(end != string::npos){
      if(end - begin != 0){
	// split string to int by ", "
        num = stoi(str->substr(begin, end-begin));

	// first string initial; string length larger than before initial
	if(i == 0 || index > len)
    	  sum.push_back(0);
	// get current position then add
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
    len = index;

  }


  strArr[0] = "[";
  for(int i=0; i<len; i++){
    strArr[0] += to_string(sum[i]) + ", ";
  }
  strArr[0] += to_string(sum[len]);
  strArr[0] += "]";

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
