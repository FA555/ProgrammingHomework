#include <stdio.h>

int main() {
  //  prework
  char s1[63], s2[63];
  for (int i = 1, a = 1, b = 1; i <= 60; ++i) {
    s1[i] = '0' + a - 1;
    s2[i] = 'A' + b - 1;
    a = a % 10 + 1;
    b = b % 12 + 1;
  }

  int T;
  scanf("%d", &T);
  for (int x; T; --T) {
    scanf("%d", &x);
    x = ((x - 1984) % 60 + 60) % 60 + 1;
    printf("%c%c\n", s1[x], s2[x]);
  }
  return 0;
}

