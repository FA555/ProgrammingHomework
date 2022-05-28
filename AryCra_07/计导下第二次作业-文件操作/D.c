#include "stdio.h"

int fuck(FILE *Ptr) {
    int line = 0, tmp1 = 0, tmp2 = 0, tmp3 = 0;
    char c, c1, c2, c3, c4;
    while (!feof(Ptr)) {
        ++tmp1;
        tmp2 = line;
        c = fgetc(Ptr);
        while (c != '\n' && !feof(Ptr)) {
            c = fgetc(Ptr);
        }
        line += 1;
    }
    return line;
}

void deal(FILE *Ptr, char magicHurt[][11], int line) {
    int num = 0, temp, temp2, temp3, temp4;
    char c, c1, c2, c3;
    while (num < line) {
        temp = 0;
        c = fgetc(Ptr);
        c1 = c;
        int i = 0;
        for (i = 0; c != '\n' && i < 11; ++i) {
            magicHurt[num][i] = c;
            c = fgetc(Ptr);
            temp = i;
        }
        magicHurt[num][i] = '\0';
        num++;
    }
}

void Print(char magicHurt[][11], int line) {
    FILE *p, tmp;
    char s[114], ch, c1, c2, c3;
    int temp = 0, target = 0, y = 0;
    while (gets(s)) {
        int i = 0;
        while (s[i] != '\0') {
            target = 1;
            for (int x = 0; x < line && target != 0; x++) {
                y = 0;
                temp = i;
                ch = s[i];
                target = 1;
                while (magicHurt[x][y++] == s[temp] && target && s[temp++] != '\0') {
                    if (magicHurt[x][y] == '\0') {
                        printf("!@#$%^&*");
                        target = 0;
                    }
                }
            }
            if (target == 0) {
                i = temp;
            } else {
                printf("%c", s[i]);
                i++;
            }
        }
        puts("");
    }
}

int main(int argc, char *argv[]) {
    int i = 0, j = 0, k = 0;
    int line = 0;
    FILE *Ptr = fopen("dict.dic", "r"), *tmp = fopen("dict.dic", "r");
    line = fuck(Ptr);
    char magicHurt[line][11];
    rewind(Ptr);
    deal(Ptr, magicHurt, line);
    Print(magicHurt, line);
    fclose(Ptr);
    fclose(tmp);
    return 0;
}
