#include <stdio.h>

//很遗憾在这里使用了全局变量
//但是这样真的很方便
char a;
short b;
int c;
long d;
long long e;
float g;
double h;
char aa[5];
short bb[5];
int cc[5];
long dd[5];
long long ee[5];
float gg[5];
double hh[5];

/**
 * @brief 读取指定的二进制文件
 * 
 * @param fp 指向需要读取的二进制文件的指针
 */
void readBinFile(FILE *fp)
{
    fread(&a, sizeof(a), 1, fp);
    fread(&b, sizeof(b), 1, fp);
    fread(&c, sizeof(c), 1, fp);
    fread(&d, sizeof(d), 1, fp);
    fread(&e, sizeof(e), 1, fp);
    fread(&g, sizeof(g), 1, fp);
    fread(&h, sizeof(h), 1, fp);
    fread(aa, sizeof(a), 5, fp);
    fread(bb, sizeof(b), 5, fp);
    fread(cc, sizeof(c), 5, fp);
    fread(dd, sizeof(d), 5, fp);
    fread(ee, sizeof(e), 5, fp);
    fread(gg, sizeof(g), 5, fp);
    fread(hh, sizeof(h), 5, fp);
}

/**
 * @brief 打印相关的变量
 * 
 */
void print()
{
    printf("%c\n", a);
    printf("%hd\n", b);
    printf("%d\n", c);
    printf("%ld\n", d);
    printf("%lld\n", e);
    printf("%f\n", g);
    printf("%f\n", h);

    char *p = aa;
    while(*p != '\0')
    {
        printf("%c", *p);
        p++;
    }
    printf("\n");
    for(size_t i = 0; i < 5; i++)
    {
        if(i == 4)
        {
            printf("%hd\n", bb[i]);
            break;
        }
        printf("%hd ", bb[i]);
    }
    for(size_t i = 0; i < 5; i++)
    {
        if(i == 4)
        {
            printf("%d\n", cc[i]);
            break;
        }
        printf("%d ", cc[i]);
    }
    for(size_t i = 0; i < 5; i++)
    {
        if(i == 4)
        {
            printf("%ld\n", dd[i]);
            break;
        }
        printf("%ld ", dd[i]);
    }
    for(size_t i = 0; i < 5; i++)
    {
        if(i == 4)
        {
            printf("%lld\n", ee[i]);
            break;
        }
        printf("%lld ", ee[i]);
    }
    for(size_t i = 0; i < 5; i++)
    {
        if(i == 4)
        {
            printf("%f\n", gg[i]);
            break;
        }
        printf("%f ", gg[i]);
    }
    for(size_t i = 0; i < 5; i++)
    {
        if(i == 4)
        {
            printf("%f\n", hh[i]);
            break;
        }
        printf("%f ", hh[i]);
    }
}

int main()
{
    FILE *fp = fopen("dict.dic", "rb");
    int input;
    scanf("%d", &input);
    for(size_t i = 0; i < input; i++)
    {
        readBinFile(fp);
    }
    print();

    fclose(fp);
    return 0;
}