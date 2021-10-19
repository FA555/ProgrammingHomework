#include <stdio.h>

int main() {
    char c;
    int a = 0, b = 0, e = 0, d = 0;
    while ((c = getchar()) != '\n') {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            a++;
        } else if (c >= '0' && c <= '9') {
            e++;
        } else if (c == ' ') {
            b++;
        } else {
            d++;
        }
    }
    printf("%d %d %d %d\n", a, b, e, d);
    return 0;
}
