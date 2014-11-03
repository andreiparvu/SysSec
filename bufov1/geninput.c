#include <stdio.h>
#include <stdlib.h>

FILE *g;

void init_bytes(char s[], long int c, long d) {
  s[3] = (c >> 8) & 0xff;
  s[2] = c & 0xff;
  s[1] = (d >> 8) & 0xff;
  s[0] = d & 0xff;
}

int main(int argnr, char **args) {
  char s[100] = {0};
  int i = 0;

  g = fopen("ceva", "wt");

  for (i = 0; i < 28; i++) {
    s[i] = 'A';
  }

  for (i = 1; i < argnr; i += 2) {
    init_bytes(s + 28 + 2 * (i - 1), strtol(args[i], NULL, 16),
        strtol(args[i + 1], NULL, 16));
  }


  printf("%s\n", s);

  return 0;
}

