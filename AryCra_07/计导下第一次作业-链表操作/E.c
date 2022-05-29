#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"


typedef struct node { //链表结点
    int data;
    struct node *next;
    int cnt;
} Node;

Node *create() {
    int x = 0;
    Node *p, *pre, *head; //pre保存当前结点的前驱结点，head是头结点
    head = (Node *) malloc(sizeof(Node)); //创建头结点
    head->next = NULL; //头结点不需要数据域，指针域初始为NULL
    head->cnt = 0;
    pre = head; //记录pre为head
    while (1) {
        scanf("%d", &x);
        if (x == -1) break;
        p = (Node *) malloc(sizeof(Node));; //新建结点
        //将Array[i]赋给新建的结点作为数据域，也可以scanf输入
        p->data = x;
        p->next = NULL; //新结点的指针域设为NULL
        pre->next = p; //前驱结点的指针域设为当前结点的地址
        pre = p; //把当前结点赋值给pre，作为下一个结点的前驱结点
    }
    return head; //返回头结点指针
}



void sort(Node *headA, Node *headB) {
    Node *temp = headB, *temp2 = headB, *first1 = headA->next, *first2 = headB->next, *pre1 = headA;
    while (first1 != NULL && first2 != NULL) {
        if (first2->data < first1->data) {
            temp2 = first2->next;
            pre1->next = first2;
            pre1 = first2;
            first2->next = first1;
            first2 = temp2;
        } else if (first1->data == first2->data) {
            temp->next = first2;
            temp = first2;
            first2=first2->next;
            pre1 = first1;
            first1 = first1->next;
        } else {
            pre1 = first1;
            first1 = first1->next;
        }
    }
    if (first2 != NULL) {
        pre1->next = first2;
    }
    //headB->next = NULL;
    temp->next = NULL;

}


void print(Node *A, Node *B) {
    if (A->next == NULL) {
        printf("There is no item in A list.\n");
    } else {
        printf("The new list A:");
        A = A->next;
        while (A != NULL) {
            if (A->next != NULL)
                printf("%d ", A->data);
            else
                printf("%d\n", A->data);
            A = A->next;
        }
    }

    if (B->next == NULL) {
        printf("There is no item in B list.\n");
    } else {
        printf("The new list B:");
        B = B->next;
        while (B != NULL) {
            if (B->next != NULL)
                printf("%d ", B->data);
            else
                printf("%d\n", B->data);
            B = B->next;
        }
    }
}

int main() {
    Node *A = create();
    Node *B = create();
    sort(A, B);
    print(A, B);
    return 0;
}
