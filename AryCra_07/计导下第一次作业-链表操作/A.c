#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, Array[10100];

struct node{ //链表结点
    int data;
    struct node *next;
    int min , max , total;
};

//创建链表（关键函数）
struct node *create(int Array[], int n) {
    struct node *p, *pre, *head; //pre保存当前结点的前驱结点，head是头结点
    head = (struct node *) malloc(sizeof(struct node)); //创建头结点
    head->next = NULL; //头结点不需要数据域，指针域初始为NULL
    head->min = 0x3f3f3f3f;
    head->max = -1;
    head->total = 0;
    pre = head; //记录pre为head
    for (int i = 0; i < n; ++i) {
        p = (struct node *) malloc(sizeof(struct node)); //新建结点
        //将Array[i]赋给新建的结点作为数据域，也可以scanf输入
        p->data = Array[i];
        p->next = NULL; //新结点的指针域设为NULL
        p->max = p->data > pre->max ? p->data : pre->max;
        p->min = p->data < pre->min ? p->data : pre->min;
        p->total = p->data + pre->total;
        pre->next = p; //前驱结点的指针域设为当前结点的地址
        pre = p; //把当前结点赋值给pre，作为下一个结点的前驱结点
    }
    head->max = pre->max;
    head->min = pre->min;
    head->total = pre->total;
    return head; //返回头结点指针
}

int main() {
    int x = 0, i = 0;
    while (1) {
        scanf("%d", &x);
        if (x == -1)
            break;
        Array[i++] = x;
    }
    struct node *L = create(Array, i); //L是头结点

    printf("The maximum,minmum and the total are:%d %d %d ", L->max, L->min, L->total);


    return 0;
}
