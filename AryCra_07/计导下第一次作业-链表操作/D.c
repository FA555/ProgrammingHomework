#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int n, Array[10100];

typedef struct node { //链表结点
    int data;
    struct node *next;
    int min, max, total;
} Node;

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

void jg(Node *first, Node *second) {
    Node *nowA = first->next, *nowB = second->next, *hereA = first->next;
    while (hereA != NULL && nowB != NULL) {
        if (hereA->data == nowB->data) {
            hereA = hereA->next;
            nowB = nowB->next;
        } else {
            nowA = nowA->next;
            hereA = nowA;
            nowB = second->next;
        }
    }
    if (nowB == NULL) {
        printf("ListB is the sub sequence of ListA.");
    } else {
        printf("ListB is not the sub sequence of ListA.");
    }
}

void Del(Node *A) {
    Node *start = NULL, *end = A;
    while (end->next != NULL) {
        start = end;
        end = end->next;
        free(start);
    }
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i)  //遍历n-1次
        for (int j = 0; j < n - i - 1; ++j)  //j小于的就是越来越小的递归边界，不过为什么是n-i-1而不是n-i呢
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;  //如果你熟悉c++，可以调用swap函数来交换数字。
            }
}

void swapList(Node *A, int l1, int r1, int l2, int r2) {
    Node *fL = A, *fR = A, *sL = A, *sR = A;
    while (--l1)
        fL = fL->next;
    while (r1--)
        fR = fR->next;
    while (--l2)
        sL = sL->next;
    while (r2--)
        sR = sR->next;
    Node *tmp = fL->next;
    fL->next = sL->next;
    sL->next = tmp;
    Node *tmp1 = fR->next;
    fR->next = sR->next;
    sR->next = tmp1;
}

void swap(Node *A, Node *B) {
    Node *tmp;
    tmp = A;
    A = B;
    B = tmp;
}

int main() {
    int x = 0, i = 0;
    int l1, r1, l2, r2;
    while (1) {
        scanf("%d", &x);
        if (x == -1)
            break;
        Array[i++] = x;
    }
    scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    struct node *A = create(Array, i); //L是头结点
    swapList(A, l1, r1, l2, r2);
    printf("The new list is:");
    A = A->next; //从第一个结点开始才有数据域
    while (A != NULL) {
        if (A->next != NULL)
            printf("%d ", A->data);
        else
            printf("%d\n", A->data);
        A = A->next;
    }
    return 0;
}
