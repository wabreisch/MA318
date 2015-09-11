#include <stdio.h>

int euclid(int a, int b);

int main() {
  int a=28;
  int b=392;
  printf("gcd of %d and %d: %d\n", a, b, euclid(a,b));
	return 0;
}

// gcd(a,b) = gcd(a, b % a) where a < b
int euclid(int a, int b) {
  if (a > b) { b = a }
  if (a != 0 && b!= 0) {

  }
  return 4;
}