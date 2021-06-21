#include "foo1.h"
#include <stdio.h>
#include <iostream>

int main(){
  printf("Test 3\n");
  foo1();

  // size
  // int = 4
  // unsigned int = 4

  // long = 8
  // long int = 8
  // long unsigned int = 8
  // long long = 8
  // long long int = 8

  // int * = 8
  // long * = 8

  // %d = int = 4
  // %u = unsigned int = 4
  // %ld = long int = 4
  // %lu = long unsigned int = 4
  // %lld = long long int = 8
  // %l, %ll not exit
  // sizeof() = long unsigned int = 4


  long long data_size = 4;
  int *data = new int [data_size];

  int data_size2 = 4;
  int *data2 = new int [data_size2];


  printf("\n");
  printf("size\n");

  //printf("int = %d\n", sizeof(int));
  //printf("int = %u\n", sizeof(int));
  printf("int = %ld\n", sizeof(int));
  printf("int = %lu\n", sizeof(int));
  printf("long = %ld", sizeof(long));  std::cout << " (" << sizeof(long) << ")\n";
  printf("long int = %ld\n", sizeof(long int));
  printf("long unsigned int = %ld\n", sizeof(long unsigned int));
  printf("long long = %ld\n", sizeof(long long));
  printf("long long int = %ld\n", sizeof(long long int));

  printf("int * = %ld\n", sizeof(int*));
  printf("long * = %ld\n", sizeof(long*));
  printf("\n");

  printf("long long data_size = %ld\n", sizeof(data_size));
  printf("int *data = %ld\n", sizeof(data));
  printf("data[0] = %ld\n", sizeof(data[0]));
  printf("data[1] = %ld\n", sizeof(data[1]));
  printf("data[2] = %ld\n", sizeof(data[2]));
  printf("data[3] = %ld\n", sizeof(data[3]));
  printf("data[4] = %ld\n", sizeof(data[4]));
  printf("data[999] = %ld\n", sizeof(data[999]));
  printf("\n");

  printf("int data_size2 = %ld\n", sizeof(data_size2));
  printf("int *data2 = %ld\n", sizeof(data2));
  printf("\n");


  return 0;
}
