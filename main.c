#include "utility.h"
#include <stdio.h>
#include <string.h>


int main() {

  char test[] = "Dette er en test: &  <  > ";
  printf("%s\n", test);

  printf("%s\n", formatString(test));
}
