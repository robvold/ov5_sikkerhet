#include "../utility.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  // Create a c string from fuzzer data (with an additional byte set to '\0')
  char *str = (char *)malloc(sizeof(char) * size + 1); // Create a c-string of length size + 1
  memcpy(str, data, size);                             // Copy fuzzer data to string
  str[size] = '\0';                                    // Set last byte of allocated string to '\0'

  formatString(str);

  free(str);

  return 0;
}
