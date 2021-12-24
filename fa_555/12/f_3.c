#include <stdio.h>
#include <stdio.h>

//将只包含小写字母的字符串str中的元音字母复制到字符数组vowel,并返回元音字符的个数。
int getVowel(char str[], char vowel[]);

int main() {
  char vowel[101], str[101]; //每个数组都至少要101个字节
  int len;

  scanf("%s", str);           //读入字符串
  len = getVowel(str, vowel); //复制
  if (len > 0)
    printf("%d %s\n", len, vowel); //输出复制后结果
  else
    printf("%d\n", len); //仅输出长度

  return 0;
}

/* 请在这里填写答案 */
int getVowel(char str[], char vowel[]) {
  int l = 0;
  for (char *p = str; *p; ++p)
    switch (*p) {
      case 'a': case 'e': case 'i': case 'o': case 'u':
        vowel[l++] = *p;
    }
  vowel[l] = 0;
  return l;
}