#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
  srand((unsigned int)time(NULL));

  char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                      "abcdefghijklmnopqrstuvwxyz"
                      "0123456789"
                      "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

  unsigned long charactersLen = strlen(characters);
  for (int i = 0; i < 16; i++)
    putchar(characters[(unsigned long)rand() % charactersLen]);
  putchar('\n');

  return EXIT_SUCCESS;
}
