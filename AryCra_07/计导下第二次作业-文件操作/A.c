#include "stdio.h"
#include "string.h"
#include "ctype.h"

void Task1(FILE *Ptr) {
    int capital = 0, low = 0, digit = 0, others = 0;
    int tmp1 = 0, tmp2 = 0;
    rewind(Ptr);
    char ch;
    ch = fgetc(Ptr);
    while (!feof(Ptr)) {
        if (isdigit(ch)) {
            digit++;
        } else if (isalpha(ch)) {
            capital++;
            if (ch >= 'a' && ch <= 'z') {
                low++;
            }
        } else {
            others++;
        }
        ch = fgetc(Ptr);
    }
    puts("Task1:");
    printf("capital: %d\n", capital - low);
    printf("lowercase: %d\n", low);
    printf("digit: %d\n", digit);
    printf("others: %d\n", others);
}

void Task2(FILE *Ptr) {
    int line = 0, temp = 0, max = 0, min = 0x3f3f3f3f, dig = 0;
    char ch;
    rewind(Ptr);
    ch = fgetc(Ptr);
    while (!feof(Ptr)) {
        if (ch != 10) {
            temp++;
        } else {
            if (temp > max) {
                max = temp;
            }
            if (temp < min) {
                min = temp;
            }
            temp = 0;
            line++;
        }
        ch = fgetc(Ptr);
    }
    puts("Task2:");
    printf("line: %d\n", line);
    printf("%d characters in max line.\n", max);
    printf("%d characters in min line.\n", min);
}

void Task3(FILE *Ptr) {
    int capital[33], low[33], digits[33];
    int tmp1 = 0, tmp2 = 0;
    memset(digits, 0, sizeof (digits));
    memset(capital, 0, sizeof(capital));
    memset(low, 0, sizeof(low));
    rewind(Ptr);
    char ch;
    ch = fgetc(Ptr);
    while (!feof(Ptr)) {
        if (ch >= 'a' && ch <= 'z') {
            low[ch - 'a']++;
        } else if (ch >= 'A' && ch <= 'Z') {
            capital[ch - 'A']++;
        }
        ch = fgetc(Ptr);
    }
    puts("Task3:");
    puts("CAPITAL:");
    for (int i = 0; i < 26; i++) {
        printf("%c:%d\n", (char) (i + 65), capital[i]);
    }
    printf("LOWERCASE:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c:%d\n", (char) (i + 97), low[i]);
    }
}

int channel;

int main() {
    FILE *Ptr = NULL, *tmp = NULL;
    scanf("%d", &channel);
    if ((Ptr = fopen("dict.dic", "r")) != NULL) {
        if (channel == 1) {
            Task1(Ptr);
        } else if (channel == 2) {
            Task2(Ptr);
        } else if (channel == 3) {
            Task3(Ptr);
        } else return 0;
    }
    fclose(Ptr);
    return 0;
}
