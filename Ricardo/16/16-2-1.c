/**
 * @file 16-2-1.c
 * @author rrricardi
 * @brief 生成一个供16-2.c读取的二进制文件
 * @version 0.1
 * @date 2022-04-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

char a = 'x';
short b = 100;
int c = 100;
long d = 100000;
long long e = 1000000;
float g = 100.0;
double h = 200.0;
char aa[5] = {'x', 'x', 'x', 'x'};
short bb[5] = {100, 100, 100, 100 ,100};
int cc[5] = {100, 100, 100, 100 ,100};
long dd[5] = {100000, 100000, 100000, 100000, 100000};
long long ee[5] = {1000000, 1000000, 1000000, 1000000, 1000000};
float gg[5] = {100.0, 100.0, 100.0, 100.0, 100.0};
double hh[5] = {200.0, 200.0, 200.0, 200.0, 200.0};

int main()
{
    FILE *fp = fopen("dict.dic", "wb");
    for(size_t i = 0; i < 5; i++)
    {
        fwrite(&a,sizeof(a),1,fp);
        fwrite(&b,sizeof(b),1,fp);
        fwrite(&c,sizeof(c),1,fp);
        fwrite(&d,sizeof(d),1,fp);
        fwrite(&e,sizeof(e),1,fp);
        fwrite(&g,sizeof(g),1,fp);
        fwrite(&h,sizeof(h),1,fp);
        fwrite(aa,sizeof(a),5,fp);
        fwrite(bb,sizeof(b),5,fp);
        fwrite(cc,sizeof(c),5,fp);
        fwrite(dd,sizeof(d),5,fp);
        fwrite(ee,sizeof(e),5,fp);
        fwrite(gg,sizeof(g),5,fp);
        fwrite(hh,sizeof(h),5,fp);
    }
    fclose(fp);
    return 0;
}