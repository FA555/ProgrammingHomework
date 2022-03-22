#include <stdio.h>

int check(int x) {
  if (x % 7 == 0) return 0;

  do {
    if (x % 10 == 7) return 0;
  } while (x /= 10);

  return 1;
}

int main() {
  int a, b, ans = 0;

  scanf("%d%d", &a, &b);
  for (int i = a; i <= b; ++i)
    ans += !check(i);

  printf("%d\n", ans);
  return 0;
}

