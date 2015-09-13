#include <stdio.h>
#include <stdlib.h>

int euclid(int a, int b);
void findLinearComb(int a, int b);
void help();

int main(int argc, char** argv) {
  if (argc != 3) {
    help();
    return 1; // return error
  }

  int a=atoi(argv[1]);
  int b=atoi(argv[2]);
  printf("gcd of %d and %d: %d\n", a, b, euclid(a,b));
	return 0;
}

void help() {
  printf("Error: please provide two command line arguments.\n");
  printf("Example: a.out 123 832\n");
}

// gcd(a,b) = gcd(a, b % a)
// TODO: implement as + bt = d where s and t are integers -- will be most efficient to implement this using a 2D array as demonstrated in class
// in other words: express d as a linear combination of a and b (times some integers s and t, respectively)
// gcd(a, b) = as + bt = d
int euclid(int a, int b) {
  findLinearComb(a, b);
  if (b == 0) { return a; }
  else {
    return euclid(b, a%b);
  }
}

// arguments: int a, int b
// data structure: 2D array (matrix), setup as below
// [1 0 | a] because 1*a + 0*b = a
// [0 1 | b] because 0*a + 1*b = b
void findLinearComb(int a, int b) {
  int matrix[3][2]; // init array

  matrix[0][0] = 1; // set up the array as described above in comments
  matrix[1][0] = 0;
  matrix[2][0] = a;
  matrix[0][1] = 0;
  matrix[1][1] = 1;
  matrix[2][1] = b;

  int i, j;
  for (i = 0 ; i < 2 ; i++) {
    for (j = 0 ; j < 3 ; j++) {
      printf("%d ", matrix[j][i]);
    }
    printf("\n");
  }
  printf("- - - - -\n");
}
