#include "stdio.h"
#include "stdlib.h"

void Delete(FILE *PtrBegin, FILE *PtrEnd) {
    int target = 1;
    char cur, pre;
    int End = ftell(PtrEnd);
    pre = fgetc(PtrBegin);
    while (ftell(PtrBegin) != End && !feof(PtrBegin)) {
        if (pre == '/') {
            cur = fgetc(PtrBegin);
            if (cur == '*' && ftell(PtrBegin) != End) {
                target = 1;
                while (target && ftell(PtrBegin) != End) {
                    pre = fgetc(PtrBegin);
                    while (pre == '*' && (ftell(PtrBegin) != End)) {
                        pre = fgetc(PtrBegin);
                        if (pre == '/' && ftell(PtrBegin) != End) {
                            target = 0;
                            pre = fgetc(PtrBegin);
                            break;
                        }
                    }
                }
            } else if (cur == '/' && ftell(PtrBegin) != End) {
                while (pre != '\n' && ftell(PtrBegin) != End) {
                    pre = fgetc(PtrBegin);
                }
                if (ftell(PtrBegin) != End) {
                    printf("%c", pre);
                    pre = fgetc(PtrBegin);
                }
            } else {
                printf("%c", pre);
                if (ftell(PtrBegin) != End) {
                    printf("%c", cur);
                    pre = fgetc(PtrBegin);
                }
            }
        } else {
            if (ftell(PtrBegin) != End) {
                printf("%c", pre);
                pre = fgetc(PtrBegin);
            }
        }
    }
}

void Find(FILE *Ptr, int num) {
    int i = 0, j = 0;
    char ch;
    while (!feof(Ptr) && num--) {
        ch = fgetc(Ptr);
        while (ch != '\n' && !feof(Ptr)) {
            ch = fgetc(Ptr);
        }
    }
}

int begin[6];
char s;

int main(int argc, char *argv[]) {
    int choice = 0;
    FILE *PtrBegin = fopen("dict.dic", "r");
    FILE *PtrEnd = fopen("dict.dic", "r");
    scanf("%d", &choice);
    begin[0] = 5;
    for (int i = 1; i < 6; i++) {
        fscanf(PtrBegin, "%d", &begin[i]);
    }
    rewind(PtrBegin);
    rewind(PtrEnd);
    Find(PtrBegin, begin[choice - 1]);
    Find(PtrEnd, begin[choice]);
    Delete(PtrBegin, PtrEnd);
    fclose(PtrBegin);
    return 0;
}
