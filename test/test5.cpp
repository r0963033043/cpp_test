#include <stdio.h>
#include <iostream>

int main(){
  printf("Test 5\n");

  int i1 = 4;
  long l1 = 4;

  printf("i1 = %d\n", i1);
  printf("l1 = %ld\n", l1);
  printf("\n");

  i1 = i1 << 1;
  l1 = l1 << 1;
  printf("i1 << 1 = %d\n", i1);
  printf("l1 << 1 = %ld\n", l1);
  printf("\n");

  i1 = i1 << 1;
  l1 = l1 << 1;
  printf("i1 << 1 = %d\n", i1);
  printf("l1 << 1 = %ld\n", l1);
  printf("\n");

  return 0;
}
