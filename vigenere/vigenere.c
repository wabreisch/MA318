// Wes Breisch
// This program will perform a Vigenere cipher on a supplied file and
// output the result to the desired file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char encrypt(char c1, char c2);
char decrypt(char c1, char c2);
void process(char* pw);
void checkArgs(int argc, char** argv);

int main(int argc, char** argv) {
	checkArgs(argc, argv);

	FILE* infile;
	FILE* outfile;

	char holder[1000];
	char* password = malloc(1001);
	printf("Password: ");
	fgets(holder, 1000, stdin);
	strcpy(password, holder);
	process(password);
	char* startpw = password;
	infile = fopen(argv[2], "r");
	outfile = fopen(argv[3], "w+");
	int curr = fgetc(infile);
	if (toupper(*argv[1]) == 'E') {
		while (curr != EOF) {
			if (*password == 0) { password = startpw; }
			if ( ((curr >= 'A' && curr <= 'Z') || (curr >= 'a' && curr <= 'z')) ) {
				char enc = encrypt(curr, *password);
				fputc(enc, outfile);
				password++;
			} else {
				fputc(curr, outfile);
			} 
			curr = fgetc(infile);
		}
	}
	if (toupper(*argv[1]) == 'D') {
		while (curr != EOF) {
			if (*password == 0) { password = startpw; }
			if ( ((curr >= 'A' && curr <= 'Z') || (curr >= 'a' && curr <= 'z')) ) {
				char dec = decrypt(curr, *password);
				fputc(dec, outfile);
				password++;
			} else {
				fputc(curr, outfile);
			} 
			curr = fgetc(infile);
		}
	}
	fclose(infile);
	fclose(outfile);
	return 0;
}

// c1 is the "original" character
// c2 is the character in the password
char encrypt(char c1, char c2) {
	if ((c1 >= 'A' && c1 <= 'Z') && (c2 >= 'A' && c2 <= 'Z')) {
		c1-=65;
		c2-=65;
		c1 = ((c1+c2)%26)+65;
	} else if ((c1 >= 'a' && c1 <= 'z') && (c2 >= 'A' && c2 <= 'Z')) {
		c1-=97;
		c2-=65;
		c1 = ((c1+c2)%26)+97;
	}
	return c1;
}

// c1 is the "original" character
// c2 is the character in the password
char decrypt(char c1, char c2) {
	if ((c1 >= 'A' && c1 <= 'Z') && (c2 >= 'A' && c2 <= 'Z')) {
		c1-=65;
		c2-=65;
		c1 = ((c1-c2+26)%26)+65;
	} else if ((c1 >= 'a' && c1 <= 'z') && (c2 >= 'A' && c2 <= 'Z')) {
		c1-=97;
		c2-=65;
		c1 = ((c1-c2+26)%26)+97;
	}
	return c1;
}

void process(char* pw) {
  int i, j;
  for (i = 0, j = 0; pw[i] != 0 ; i++, j++) {
    if ( isalpha(pw[i]) ) {
      pw[j] = pw[i];
      pw[j] = toupper(pw[j]);
	  } else {
      j--;                                     
   	}
  }
  pw[j] = 0;
}

void checkArgs(int argc, char** argv) {
  if (argc != 4) {
    printf("Error - you must supply exactly 4 command line arguments\n");
    printf("Form: ./a.out (e|d) INPUT OUTPUT\n");
    exit(1);
  } else if (strlen(argv[1]) != 1) {
    printf("Error - second argument must be ONLY 'e' or 'd'\n");
    exit(1);
  } else if (toupper(*argv[1]) != 'E' && toupper(*argv[1]) != 'D') {
    printf("Error - unrecognized option: %c\n", *argv[1]);
    exit(1);
  }
}