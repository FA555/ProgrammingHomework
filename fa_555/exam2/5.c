// O(n * max(c)) 应该能过吧（心虚

#include <stdio.h>

int check(int *z, int N, int k) {
  int v[3003] = {};
  for (int i = 1; i <= N; ++i) {
    if (v[z[i] % k]) return 0;
    v[z[i] % k] = 1;
  }
  return 1;
}

int main() {
  int N, z[103];

  scanf("%d", &N);
  for (int i = 1; i <= N; ++i)
    scanf("%d", z + i);

  for (int k = 1; ; ++k)
    if (check(z, N, k)) {
      printf("%d\n", k);
      break;
    }
  return 0;
}

