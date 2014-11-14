#include <stdio.h>
#include <stdlib.h>

FILE *g;

void init_bytes(char s[], unsigned long int c) {
  s[3] = (c >> 24) & 0xff;
  s[2] = (c >> 16) & 0xff;
  s[1] = (c >> 8) & 0xff;
  s[0] = c & 0xff;
}

int main(int argnr, char **args) {
  char s[10000] = {0};
  int i = 0;

  g = fopen("ceva", "wt");

  for (i = 0; i < 24; i++) {
    s[i] = 'A';
  }

  for (i = 1; i < argnr; i++) {
    init_bytes(s + 24 + 4 * (i - 1), strtoul(args[i], NULL, 16));
  }


  printf("%s\n", s);

  return 0;
}

