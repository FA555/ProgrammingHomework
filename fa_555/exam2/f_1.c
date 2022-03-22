#include <math.h>
#include <stdio.h>

double fun(int n, double x);

int main() {
  int n;
  double x;

  scanf("%d%lf", &n, &x);
  printf("%.3f\n", fun(n, x));

  return 0;
}

/* 请在这里填写答案 */
double fun(int n, double x) {
  if (!n)
    return x;
  return sqrt(n + fun(n - 1, x));
}

