#include <stdio.h>

int main(){
  printf("Test 4\n");

  // overflow
  //int = 1024 * 1024 * 1024 * 1024
  //int = 1024ll * 1024 * 1024 * 1024
  //long = 1024 * 1024 * 1024 * 1024

  int i1 = 1024ll;
  long l1 = 1024ll;
  long long ll1 = 1024ll;

  int i2 = 1024ll * 1024 * 1024;
  long l2 = 1024ll * 1024 * 1024;
  long long ll2 = 1024ll * 1024 * 1024;

  int i3 = 1024ll * 1024 * 1024 * 1024;     // warning
  long l3 = 1024ll * 1024 * 1024 * 1024;
  long long ll3 = 1024ll * 1024 * 1024 * 1024;

  long l4 = 1024 * 1024 * 1024 * 1024;      // warning

  printf("i1 = %d\n", i1);
  printf("l1 = %ld\n", l1);
  //printf("l1 = %lld\n", l1);      // warning
  printf("ll1 = %lld\n", ll1);
  printf("\n");

  printf("i2 = %d\n", i2);
  printf("l2 = %ld\n", l2);
  printf("ll2 = %lld\n", ll2);
  printf("\n");

  printf("i3 = %d\n", i3);
  printf("l3 = %ld\n", l3);
  printf("ll3 = %lld\n", ll3);
  printf("\n");

  printf("l4 = %ld\n", l4);
  printf("\n");


  return 0;
}
