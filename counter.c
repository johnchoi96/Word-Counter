/**
  * @file counter.c
  * @author John Choi
  *
  * Simple word or character counter in a file.
  * Usage: ./counter word or ./counter char
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  * Prints the error message and exits program.
  *
  * @param msg error message
  */
void fail(const char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(EXIT_FAILURE);
}

/**
  * Prints the usage and terminates program.
  */
void usage() {
  fprintf(stderr, "usage: \n./counter word\n./counter char\n");
  exit(EXIT_FAILURE);
}

/**
  * Counts the number of words in the input file.
  *
  * @param fp file pointer
  * @return number of words
  */
int countWords(FILE *fp) {
  int counter = 0;
  while (fscanf(fp, "%*s") != EOF) {
    counter++;
  }
  return counter;
}

/**
  * Counts the number of characters in the input file.
  *
  * @param fp file pointer
  * @return number of characters
  */
int countChar(FILE *fp) {
  int counter = 0;
  int ch = fgetc(fp);
  while (ch != EOF) {
    if (ch == 0x0A) {
      ch = fgetc(fp);
      continue;
    }
    counter++;
    ch = fgetc(fp);
  }
  return counter;
}

/**
  * Driver function for this program.
  *
  * @param argc nubmer of arguments passed
  * @param argv array of arguments
  * @return EXIT_SUCCESS if exits correctly
  */
int main(int argc, char **argv) {
  if (argc != 2) {
    usage();
  }
  int counter = 0;
  FILE *file = fopen("input.txt", "r");
  if (!file) {
    fail("Can't open input file");
  }
  if (strcmp(argv[1], "word") == 0) {
    counter = countWords(file);
    fprintf(stdout, "Number of words in input file is: %d\n", counter);
  } else if (strcmp(argv[1], "char") == 0) {
    counter = countChar(file);
    fprintf(stdout, "Number of characters in input file is: %d\n", counter);
  } else {
    fclose(file);
    usage();
  }
  fclose(file);
  return EXIT_SUCCESS;
}
