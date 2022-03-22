#include <stdio.h>

#define MAXLEN 500000
void sortAndOutput(int *data, int size);

int main() {
  int data[MAXLEN];
  int n, i;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &data[i]);

  sortAndOutput(data, n);

  return 0;
}

/* 请在这里填写答案 */
// 应该让用 malloc 吧？
#include <stdlib.h>

void swap_(int *p, int *q) {
  int t = *p;
  *p = *q;
  *q = t;
}

void sort_(int *l, int *r, int **z) {
  for (int *p = l; p < r - 1; ++p)
    for (int *q = l; q - l < r - p - 1; ++q)
      if (*z[*q] > *z[*(q + 1)])
        swap_(q, q + 1);
}

void sortAndOutput(int *data, int size) {
  // 我知道变量重名很丑，但是没办法，题目没实际意义，算法竞赛命名习惯留下来了
  int tot = 0, N = 0;
  for (int p = 0, tmpN; p < size; ) {
    ++p;
    tmpN = data[p++];
    for (int j = 0; j < tmpN; ++j)
      ++p;
    ++N;
  }

  int **z = (int **)malloc(N * sizeof (int *));
  int *y = (int *)malloc(N * sizeof (int));
  for (int i = 0; i < N; ++i)
    y[i] = i;
  for (int p = 0, tmpN; p < size; ) {
    // z[tot].id = data[p++];
    z[tot++] = data + p;
    ++p;
    tmpN = data[p++];
    for (int j = 0; j < tmpN; ++j)
      ++p;
  }

  // 原谅我 0~N-1 和 1~N 混用（
  sort_(y, y + N, z);

  for (int i = 0, tmpN, *p; i < N; ++i) {
    p = z[y[i]];
    printf("%d ", *p++);
    printf("%d ", (tmpN = *p++));
    for (int j = 0; j < tmpN; ++j)
      printf("%d%c", *p++, " \n"[j == tmpN - 1]);
  }

  free(z);
  free(y);
}

