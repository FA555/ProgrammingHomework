#include <stdio.h>

int main() {
    int n,a=0,b=0,c=0,num=0;
    scanf("%d",&n);
    do{
        if(n==0)break;
        num++;
        getchar();
        if(n%3==0&&n%5!=0&&n%7!=0){
            a++;
        }
        if(n%3!=0&&n%5==0&&n%7!=0){
            b++;
        }
        if(n%3!=0&&n%5!=0&&n%7==0){
            c++;
        }
    } while (scanf("%d",&n));
    printf("%.2f%%\n%.2f%%\n%.2f%%\n",100.0*a/num,100.0*b/num,100.0*c/num);
    return 0;
}
