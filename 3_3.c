#include <stdlib.h>
#include <string.h>

int some_function(const char *string) {
  int loop;
  int numA = 0;
  for (loop = 0; loop < strlen(string); loop++) {
    if (string[loop] ==  'A') numA++;
  }
  return numA;
}
