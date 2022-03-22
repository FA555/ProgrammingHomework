#include <stdio.h>

int main() {
  int g;
  double a, b;

  scanf("%lf%lf%d", &a, &b, &g);
  if (g)
    printf("%.2f\n", (a + b) * 1.08 / 2);
  else
    printf("%.2f\n", (a * 0.923 + b) / 2);
  return 0;
}

