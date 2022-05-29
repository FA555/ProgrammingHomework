#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 节点结构体
 * 
 */
struct node
{
    int num;
    struct node* next;
};

typedef struct node node_t;
typedef struct node *nodeptr_t;

/**
 * @brief 初始化一个链表
 * 
 * @param value 第一个节点的值
 * @return nodeptr_t 头节点的地址
 */
nodeptr_t newLinkedList(int value)
{
    nodeptr_t head = NULL;

    head = malloc(sizeof(node_t));

    head->next = NULL;
    head->num = value;

    return head;
}

/**
 * @brief 在pos节点的后面插入一个节点
 * 
 * @param pos 插入节点的位置
 * @param value 需要添加的值
 * @return nodeptr_t 添加的节点的地址
 */
nodeptr_t append(nodeptr_t pos, int value)
{
    nodeptr_t newNode = malloc(sizeof(node_t));

    newNode->num = value;
    newNode->next = pos->next;

    pos->next = newNode;

    return newNode;
}

/**
 * @brief 对一个单链表进行快速排序
 * 
 * @param start 开始排序的位置
 * @param end 结束排序的位置
 */
void quickSort(nodeptr_t start, nodeptr_t end)
{
    if(start == NULL || start == end)
    {
        return;
    }

    int temp;
    nodeptr_t pos = start->next;
    nodeptr_t center = start;

    while(pos != end)
    {
        if(pos->num <= start->num)
        {
            center = center->next;
            temp = center->num;
            center->num = pos->num;
            pos->num = temp;
        }
        pos = pos->next;
    }

    temp = start->num;
    start->num = center->num;
    center->num = temp;

    quickSort(start, center);
    quickSort(center->next, end);
}

/**
 * @brief 释放链表分配的内存空间
 * 
 * @param head 链表的头节点
 */
void freeLinkedList(nodeptr_t head)
{
    nodeptr_t pos = head;
    while (pos != NULL)
    {
        nodeptr_t temp = pos;
        pos = pos->next;
        free(temp);
    }
}

int main(void)
{
    int temp;
    nodeptr_t head, pos;

    scanf("%d", &temp);
    head = newLinkedList(temp);
    pos = head;

    for(;;)
    {
        scanf("%d", &temp);
        if(temp == -1)
        {
            break;
        }

        pos = append(pos, temp);
    }

    quickSort(head, NULL);
    pos = head;

    printf("The new list is:");

    while(pos->next != NULL)
    {
        printf("%d ", pos->num);
        pos = pos->next;
    }
    printf("%d\n", pos->num);

    freeLinkedList(head);
    return 0;
}