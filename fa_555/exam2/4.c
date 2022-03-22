#include <stdio.h>

int main() {
  const int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
  const int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

  int N, M, C, ans = 0, z[13][13] = {};
  scanf("%d%d%d", &N, &M, &C);
  for (int x, y; C; --C) {
    scanf("%d%d", &x, &y);
    for (int k = 0; k < 9; ++k)
      z[x + dx[k]][y + dy[k]] = 1;
  }
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j)
      ans += z[i][j];
  printf("%d\n", ans);
  return 0;
}

