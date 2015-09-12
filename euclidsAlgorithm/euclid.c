#include <stdio.h>
#include <stdlib.h>

int euclid(int a, int b);

int main(int argc, char** argv) {
  if (argc != 3) { 
    printf("Error: please provide two command line arguments.\n");
    printf("Example: a.out 123 832\n");
    return 1; // return error
  }
  int a=atoi(argv[1]);
  int b=atoi(argv[2]);
  printf("gcd of %d and %d: %d\n", a, b, euclid(a,b));
	return 0;
}

// gcd(a,b) = gcd(a, b % a) b
int euclid(int a, int b) {
  if (b == 0) { return a; }
  else { return euclid(b, a%b); }
}