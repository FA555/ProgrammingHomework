#include <stdio.h>

int main() {
    int t, n, k;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d", &n);
        getchar();
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            scanf("%d", &k);
            sum += k;
        }
        if (sum >= 400) {
            sum -= 160;
        } else if (sum >= 300) {
            sum -= 110;
        } else if (sum >= 200) {
            sum -= 70;
        } else if (sum >= 100) {
            sum -= 30;
        }
        printf("%d\n", sum);
    }
    return 0;
}
