#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"


typedef struct node { //链表结点
    char data;
    struct node *next;
    int cnt;
} Node;

//创建链表（关键函数）
struct node *create() {
    struct node *p, *pre, *head; //pre保存当前结点的前驱结点，head是头结点
    head = (struct node *) malloc(sizeof(struct node)); //创建头结点
    head->next = NULL; //头结点不需要数据域，指针域初始为NULL
    head->cnt = 0;
    pre = head; //记录pre为head
    while (1) {
        char x[5];
        scanf(" %s", x);
        if (x[0] == '-' && x[1] == '1') {
            break;
        }
//        printf("%s I fuck you\n",x);
        p = (Node *) malloc(sizeof(Node));
        p->cnt = pre->cnt + 1;
        p->data = x[0];
        p->next = NULL;
//        printf("%c I fuck you\n",p->data);
        pre->next = p;
        pre = p;
    }
    head->cnt = p->cnt;
    return head; //返回头结点指针
}

void SortYourMother(Node *head) {
    Node *current = NULL, *previous = NULL, *last = NULL, *temp = NULL;
    if (head->next == NULL) {
        return;
    }
    while (last != head->next)//保证能正确退出循环，并且每一次都从head开始排序同时避免了成员<2的情况
    {
        temp = head;
        current = head->next->next;
        previous = head->next;
        while (previous->next != last)//这里避免了成员<3的情况
        {
            if (previous->data > current->data) {
                temp->next = current;//这一步相当于把成员一的next指向了成员三的地址
                previous->next = current->next;//这一步可以看做把成员二的next指向了三成员的next所指向的地址（成员四所在的地址）
                current->next = previous;//这把成员三的next指向了成员二所在的地址
            } else {
                previous = previous->next;//这一步没写在下面和上面是为了保证在碰到更大的数之后让pre-next连接着目前最小的数字
            }
            current = previous->next;
            temp = temp->next;
        }
        last = previous;
    }
}

void fuckYouCProgram(Node *L) {
    if (L->cnt == 0) {
        printf("There is no item in A list.");
        printf("There is no item in B list.");
        printf("There is no item in C list.");
        return;
    } else {
        Node *A, *B, *C, *preA, *pA, *preB, *pB, *preC, *pC;
        int cntA, cntB, cntC;
        A = (Node *) malloc(sizeof(Node));
        B = (Node *) malloc(sizeof(Node));
        C = (Node *) malloc(sizeof(Node));
        A->next = NULL;
        B->next = NULL;
        C->next = NULL;
        A->cnt = B->cnt = C->cnt = 0;
        preA = A;
        preB = B;
        preC = C;
        while (L->next != NULL) {
            L = L->next;
            char c = L->data;
            if (isalpha(c)) {
                pA = (Node *) malloc(sizeof(Node));
                pA->data = L->data;
                pA->cnt = preA->cnt + 1;
                pA->next = NULL;
                preA->next = pA;
                preA = pA;
            } else if (isdigit(c)) {
                pB = (Node *) malloc(sizeof(Node));
                pB->data = L->data;
                pB->cnt = preB->cnt + 1;
                pB->next = NULL;
                preB->next = pB;
                preB = pB;
            } else {
                pC = (Node *) malloc(sizeof(Node));
                pC->data = L->data;
                pC->cnt = preC->cnt + 1;
                pC->next = NULL;
                preC->next = pC;
                preC = pC;
            }
        }
        int sbA = preA->cnt;
        int sbB = preB->cnt;
        int sbC = preC->cnt;
        SortYourMother(A);
        SortYourMother(B);
        SortYourMother(C);
        if (sbA) {
            printf("The list A is: ");
            A = A->next;
            while (A != NULL) {
                if (A->next != NULL)
                    printf("%c ", A->data);
                else
                    printf("%c\n", A->data);
                A = A->next;
            }
        } else {
            printf("There is no item in A list.\n");
        }
        if (sbB) {
            printf("The list B is: ");
            B = B->next;
            while (B != NULL) {
                if (B->next != NULL)
                    printf("%c ", B->data);
                else
                    printf("%c\n", B->data);
                B = B->next;
            }
        } else {
            printf("There is no item in B list.\n");
        }
        if (sbC) {
            printf("The list C is: ");
            C = C->next;
            while (C != NULL) {
                if (C->next != NULL)
                    printf("%c ", C->data);
                else
                    printf("%c\n", C->data);
                C = C->next;
            }
        } else {
            printf("There is no item in C list.\n");
        }
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


int main() {
    Node *L = create();
    fuckYouCProgram(L);
    return 0;
}
