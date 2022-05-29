#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    int cnt;
} Node;

Node *create() {
    Node *head, *cur, *last, *emptyHead = NULL;
    int x = 0, y = 0;
    emptyHead = (Node *) malloc(sizeof(Node));
    head = (Node *) malloc(sizeof(Node));
    emptyHead->data = 0;
    emptyHead->cnt = 0;
    emptyHead->next = head;
    scanf("%d", &x);
    head->data = x;
    last = head;
    while (~scanf("%d", &x)) {
        if (x == -1) {
            break;
        }
        cur = (Node *) malloc(sizeof(Node));
        cur->data = x;
        cur->next = NULL;
        cur->cnt = last->cnt + 1;
        last->next = cur;
        last = cur;
    }
    last->next = NULL;
    emptyHead->cnt = last->cnt;

    return emptyHead;
}

void print(Node *head) {
    int i = 0, j = 0, k = 0;
    Node *p = head;
    printf("The new list is:");
    while (p->next != NULL) {
        printf("%d ", p->next->data);
        p = p->next;
    }
}

void sort(Node *head) {
    Node *cur = NULL, *pre = NULL, *last = NULL, *temp = NULL;
    while (last != head->next) {
        temp = head;
        cur = head->next->next;
        pre = head->next;
        while (pre->next != last) {
            if (pre->data > cur->data) {
                pre->next = cur->next;
                temp->next = cur;
                cur->next = pre;
            } else {
                pre = pre->next;
            }
            cur = pre->next;
            temp = temp->next;
        }
        last = pre;
    }
}

int main() {
    Node *head = create();
    sort(head);
    print(head);
    return 0;
}
