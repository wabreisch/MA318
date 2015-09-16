#include <stdio.h>
#include <ctype.h>

void printString(char* str);
char* strToUpper(char* str);
char* encrypt(char* str, int alpha, int beta);
char* decrypt(char* str, int alpha, int beta);

int main(int argc, char** argv) {
  printString(argv[1]);
}

char* strToUpper(char* str) {
  int counter = 0;
  while (*str != '\0') {
    *str = toUpper(*str);
    counter++;
  }
  for (counter ; counter >= 0 ; counter--) {

  }
}

void printString(char* str) {
  while (*str != '\0') {
    printf("%c", *str);
    str++;
  }
  printf("\n");
}