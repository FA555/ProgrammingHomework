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

/**
 * @brief 在链表中找到指定的节点
 * 
 * @param head 链表的头节点
 * @param pos 要寻找元素的位置
 * @return nodeptr_t 循找到的节点位置
 */
nodeptr_t find(nodeptr_t head, int pos)
{
    nodeptr_t temp = head;

    for(int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }

    return temp;
}

/**
 * @brief 链表的交换函数
 * 
 * @param head 链表的头节点
 * @param firstStart 第一组起始位置
 * @param firstEnd 第一组结束位置
 * @param secondStart 第二组起始位置
 * @param secondEnd 第二组结束位置
 * @return nodeptr_t 新的链表头节点地址
 */
nodeptr_t swap(nodeptr_t head, int firstStart, int firstEnd, int secondStart, int secondEnd)
{
    if(firstStart == 1)
    {
        if(firstEnd + 1 == secondStart)
        {
            nodeptr_t firstStartPos = head;
            nodeptr_t firstEndPos = find(head, firstEnd);
            nodeptr_t secondStartPos = firstEndPos->next;
            nodeptr_t secondEndPos = find(head, secondEnd);

            firstEndPos->next = secondEndPos->next;
            secondEndPos->next = firstStartPos;
            head = secondStartPos;
        }
        else
        {
            nodeptr_t firstStartPos = head;
            nodeptr_t firstEndPos = find(head, firstEnd);
            nodeptr_t firstEndPosNext = firstEndPos->next;
            nodeptr_t secondStartPosPre = find(head, secondStart - 1);
            nodeptr_t secondStartPos = secondStartPosPre->next;
            nodeptr_t secondEndPos = find(head, secondEnd);

            firstEndPos->next = secondEndPos->next;
            secondEndPos->next = firstEndPosNext;
            secondStartPosPre->next = firstStartPos;
            head = secondStartPos;
        }
    }
    else
    {
        if(firstEnd + 1 == secondStart)
        {
            nodeptr_t firstStartPosPre = find(head, firstStart - 1);
            nodeptr_t firstEndPos = find(head, firstEnd);
            nodeptr_t secondStartPos = firstEndPos->next;
            nodeptr_t secondEndPos = find(head, secondEnd);

            firstEndPos->next = secondEndPos->next;
            secondEndPos->next = firstStartPosPre->next;
            firstStartPosPre->next = secondStartPos;
        }
        else
        {
            nodeptr_t firstStartPosPre = find(head, firstStart - 1);
            nodeptr_t firstEndPos = find(head, firstEnd);
            nodeptr_t firstEndPosNext = firstEndPos->next;
            nodeptr_t secondStartPosPre = find(head, secondStart - 1);
            nodeptr_t secondStartPos = secondStartPosPre->next;
            nodeptr_t secondEndPos = find(head, secondEnd);

            firstEndPos->next = secondEndPos->next;
            secondEndPos->next = firstEndPosNext;
            secondStartPosPre->next = firstStartPosPre->next;
            firstStartPosPre->next = secondStartPos;
        }
    }

    return head;
}

int main(void)
{
    int temp, firstStart, firstEnd, secondStart, secondEnd;
    nodeptr_t head = NULL;
    nodeptr_t pos;

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
    getchar();
    scanf("%d %d %d %d", &firstStart, &firstEnd, &secondStart, &secondEnd);

    head = swap(head, firstStart, firstEnd, secondStart, secondEnd);

    printf("The new list is:");
    pos = head;
    for(;;)
    {
        if(pos->next == NULL)
        {
            printf("%d\n", pos->num);
            break;
        }
        printf("%d ", pos->num);
        pos = pos->next;
    }

    freeLinkedList(head);
    return 0;
}
