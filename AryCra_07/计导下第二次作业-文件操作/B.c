#include "stdio.h"
#include "string.h"

short b, nb[5];
int choice, c, nc[5];
long d, nd[5];
long long e, ne[5];
float g, ng[5];
double h, nh[5];
char a, na[5];

int main() {
    scanf("%d", &choice);
    memset(nb, 0, sizeof nb);
    memset(nc, 0, sizeof nc);
    memset(nd, 0, sizeof nd);
    memset(ne, 0, sizeof ne);
    memset(ng, 0, sizeof ng);
    memset(nh, 0, sizeof nh);
    FILE *fop = NULL;
    if ((fop = fopen("dict.dic", "rb")) != NULL) {
        while (choice--) {
            fread(&a, sizeof(a), 1, fop);
            fread(&b, sizeof(b), 1, fop);
            fread(&c, sizeof(c), 1, fop);
            fread(&d, sizeof(d), 1, fop);
            fread(&e, sizeof(e), 1, fop);
            fread(&g, sizeof(g), 1, fop);
            fread(&h, sizeof(h), 1, fop);
            fread(na, sizeof(a), 5, fop);
            fread(nb, sizeof(b), 5, fop);
            fread(nc, sizeof(c), 5, fop);
            fread(nd, sizeof(d), 5, fop);
            fread(ne, sizeof(e), 5, fop);
            fread(ng, sizeof(g), 5, fop);
            fread(nh, sizeof(h), 5, fop);
        }
        printf("%c\n%d\n%d\n%ld\n%lld\n%f\n%lf\n", a, b, c, d, e, g, h);
        printf("%s\n", na);
        for (int i = 0; i < 4; i++) {
            printf("%d ", nb[i]);
        }
        printf("%d\n", nb[4]);
        for (int i = 0; i < 4; i++) {
            printf("%d ", nc[i]);
        }
        printf("%d\n", nc[4]);
        for (int i = 0; i < 4; i++) {
            printf("%ld ", nd[i]);
        }
        printf("%ld\n", nd[4]);
        for (int i = 0; i < 4; i++) {
            printf("%lld ", ne[i]);
        }
        printf("%lld\n", ne[4]);
        for (int i = 0; i < 4; i++) {
            printf("%f ", ng[i]);
        }
        printf("%f\n", ng[4]);
        for (int i = 0; i < 4; i++) {
            printf("%lf ", nh[i]);
        }
        printf("%lf\n", nh[4]);
    }
    fclose(fop);
    return 0;
}
