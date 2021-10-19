#include <stdio.h>

int main() {
    long long t;
    scanf("%lld",&t);
    if(t==1||t==2){
        printf("0");
        return 0;
    }
    long long m = t-2;

    long long ans = 0;
    for(long long n=1;n<=m;n++) {
        ans += n * n * (n + 1) * (n + 1) / 4 + n * (n + 1) * (2 * n + 1) / 2 + (n + 1) * n;
    }
    printf("%lld\n",ans);
    return 0;
}
