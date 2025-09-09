#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
  unsigned long length = 16;
  bool majusculesEnabled = true, minusculesEnabled = true,
       numeralsEnabled = true, symbolsEnabled = true;

  struct option long_options[] = {
      {"help", no_argument, 0, 'h'},
      {"length", required_argument, 0, 'l'},
      {"no-majuscules", no_argument, 0, 'M'},
      {"no-minuscules", no_argument, 0, 'm'},
      {"no-numerals", no_argument, 0, 'n'},
      {"no-symbols", no_argument, 0, 's'},
      {0, 0, 0, 0}, // needed to mark the end of the array
  };

  int opt;
  while ((opt = getopt_long(argc, argv, "hl:Mmns", long_options, NULL)) != -1) {
    switch (opt) {
    case 'h':
      printf(
          "Usage: %s [OPTION]...\n"
          "A simple command-line password generator.\n"
          "By default, it prints to standard output a random 16 character\n"
          "password, which may include majuscules, minuscules, numerals and\n"
          "symbols.\n"
          "Options:\n"
          "  -h, --help           display this help and exit\n"
          "  -l, --length=LENGTH  set the LENGTH of the password\n"
          "  -M, --no-majuscules  disable majuscules\n"
          "  -m, --no-minuscules  disable minuscules\n"
          "  -n, --no-numerals    disable numerals\n"
          "  -s, --no-symbols     disable symbols\n",
          argv[0]);
      return EXIT_SUCCESS;
    case 'l': {
      int providedLength = atoi(optarg);
      if (providedLength <= 0) {
        fprintf(stderr,
                "%s: can't create a password with the provided length\n",
                argv[0]);
        return EXIT_FAILURE;
      }
      length = (unsigned long)providedLength;
    } break;
    case 'M':
      majusculesEnabled = false;
      break;
    case 'm':
      minusculesEnabled = false;
      break;
    case 'n':
      numeralsEnabled = false;
      break;
    case 's':
      symbolsEnabled = false;
      break;
    case '?':
      fprintf(stderr, "See \"%s --help\" for valid options\n", argv[0]);
      return EXIT_FAILURE;
    }
  }

  if (!majusculesEnabled && !minusculesEnabled && !numeralsEnabled &&
      !symbolsEnabled) {
    fprintf(stderr, "%s: at least one character set needs to stay enabled\n",
            argv[0]);
    return EXIT_FAILURE;
  }

  srand((unsigned int)time(NULL));

  char majuscules[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
       minuscules[] = "abcdefghijklmnopqrstuvwxyz", numerals[] = "0123456789",
       symbols[] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

  unsigned long charactersLen = strlen(majuscules) * majusculesEnabled +
                                strlen(minuscules) * minusculesEnabled +
                                strlen(numerals) * numeralsEnabled +
                                strlen(symbols) * symbolsEnabled;

  char characters[charactersLen + 1];
  characters[0] = '\0';

  if (majusculesEnabled)
    strcat(characters, majuscules);
  if (minusculesEnabled)
    strcat(characters, minuscules);
  if (numeralsEnabled)
    strcat(characters, numerals);
  if (symbolsEnabled)
    strcat(characters, symbols);

  for (unsigned long i = 0; i < length; i++)
    putchar(characters[(unsigned long)rand() % charactersLen]);
  putchar('\n');

  return EXIT_SUCCESS;
}
