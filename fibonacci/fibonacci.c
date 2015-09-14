#include <stdio.h>
#include <stdlib.h>

int fib(int n);
int fibIterative(int n);

int main(int argc, char** argv) {
  char* opt = argv[1];
  int n = atoi(argv[2]);
  if (*opt == 'i') { // quick and dirty option checking
    printf("ITERATIVE: Fibonacci number for n = %d: %d\n", n, fibIterative(n));
  } else if (*opt == 'r') {
    printf("RECURSIVE: Fibonacci number for n = %d: %d\n", n, fib(n));
  } else {
    printf("ERROR: Unrecognized option: %c\n", *opt);
  }
  return 0;
}

// recursive: prints the nth Fibonacci number
int fib(int n) {
  if (n <= 1) {
    return n;
  }
  return fib(n-1)+fib(n-2);
}

int fibIterative(int n) {
  if (n == 0) { return 0; }
  if (n == 1 || n == 2) { return 1; } // if n <=2, we will never run the for loop, so we check here
  int n1 = 1; // represents n-1 in the recursive version of fib(int n) -- this is a base case
  int n2 = 1; // represents n-2 in the recursive version of fib(int n) -- this is a base case
  int sum = 0; // keeps track of the current sum; this will be the nth Fib. num. at the end of the computation
  int i;
  for (i = 2 ; i < n ; i++) {
    sum = n2 + n1;
    n2 = n1;
    n1 = sum; 
  }
  return sum;
}
