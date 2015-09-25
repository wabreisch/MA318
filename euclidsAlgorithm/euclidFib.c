#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);
unsigned int fibIterative(unsigned int n);
void help();

int main(int argc, char** argv) {
  if (argc != 2) {
    help();
    return 1; // return error
  }

  int a=atoi(argv[1]);
  fibIterative(a);
  return 0;
}

void help() {
  printf("Error: please provide one command line argument.\n");
}

// gcd(a,b) = gcd(a, b % a)
int gcd(int a, int b) {
  if (b == 0) { return a; }
  else {
    return gcd(b, a%b);
  }
}

// iterative: prints the nth Fibonacci number using an iterative algorithm
unsigned int fibIterative(unsigned int n) {
  if (n == 0) { return 0; }
  int n1 = 1; // represents n-1 in the recursive version of fib(int n) -- base case
  int n2 = 1; // represents n-2 in the recursive version of fib(int n) -- base case
  int sum = 1; // this will be the nth Fib. num. at the end of the computation
  int i;
  for (i = 2 ; i < n ; i++) {
    sum = n2 + n1;
    n2 = n1;
    n1 = sum;
    printf("fib at %d: %d\n", i+1, sum);
  }
  printf("gcd of %d and %d: %d\n", n2, sum, gcd(sum, n2));
  return sum;
}
