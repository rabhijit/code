#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
   char x[] = "junglefruit";
   char y[12];
   for (int i = 0; i < 11; i++) {
       int z = x[i];
       z -= 32;
       char temp = z;
       y[i] = temp;
   }
   printf("%s\n", y);
}