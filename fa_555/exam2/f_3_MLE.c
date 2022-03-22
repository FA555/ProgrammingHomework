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

typedef struct {
  int id, N, *z;
} Node;

void swap_(Node *p, Node *q) {
  Node t = *p;
  *p = *q;
  *q = t;
}

void sort_(const Node *l, const Node *r) {
  for (Node *p = l; p < r - 1; ++p)
    for (Node *q = l; q - l < r - p - 1; ++q)
      if (q->id > q[1].id)
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

  Node *z = (Node *)malloc(N * sizeof (Node));
  for (int p = 0; p < size; ) {
    z[tot].id = data[p++];
    z[tot].N = data[p++];
    z[tot].z = (int *)malloc(z[tot].N * sizeof (int));
    for (int j = 0; j < z[tot].N; ++j)
      z[tot].z[j] = data[p++];
    ++tot;
  }

  // 原谅我 0~N-1 和 1~N 混用（
  sort_(z, z + N);

  for (int i = 0; i < N; ++i) {
    printf("%d %d ", z[i].id, z[i].N);
    for (int j = 0; j < z[i].N; ++j)
      printf("%d%c", z[i].z[j], " \n"[j == z[i].N - 1]);
  }

  for (int i = 0; i < N; ++i)
    free(z[i].z);
  free(z);
}

