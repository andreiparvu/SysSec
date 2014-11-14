#include <stdio.h>

int main(int argnr, char**argv) {
  int i = 0;

  printf("da\n");
//  printf("%256x%n", &i);

  chmod("./somefile.sh", atoi(argv[1]));

  printf("%d\n", i);
}

