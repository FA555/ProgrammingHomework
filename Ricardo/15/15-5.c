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
 * @brief 寻找给出节点的前一个节点
 * 
 * @param head 该链表的头节点
 * @param pos 需要寻找的节点的后一个节点
 * @return nodeptr_t 寻找到的节点的地址，若为了NULL则为头节点
 */
nodeptr_t findLastNode(nodeptr_t head, nodeptr_t pos)
{
    nodeptr_t last = NULL;
    nodeptr_t temp = head;

    while(temp != pos)
    {
        last = temp;
        temp = temp->next;
    }

    return last;
}

/**
 * @brief 打印给出的链表
 * 
 * @param head 需要打印的链表的头节点
 */
void printLinkedList(nodeptr_t head)
{
    nodeptr_t pos = head;
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
}

int main(void)
{
    int temp;
    nodeptr_t listA, listB, pos, posA, posB;

    scanf("%d", &temp);
    if(temp == -1)
    {
        listA = NULL;
    }
    else
    {
        listA = newLinkedList(temp);
        pos = listA;

        for(;;)
        {
            scanf("%d", &temp);

            if(temp == -1)
            {
                break;
            }

            pos = append(pos, temp);
        }
    }

    scanf("%d", &temp);
    if(temp == -1)
    {
        listB = NULL;
    }
    else
    {
        listB = newLinkedList(temp);
        pos = listB;

        for(;;)
        {
            scanf("%d", &temp);

            if(temp == -1)
            {
                break;
            }
            
            pos = append(pos, temp);
        }
    }

    posB = listB;
    while(posB != NULL)
    {
        posA = listA;
        nodeptr_t nextPosB = posB->next;
        for(;;)
        {
            if(posA != NULL)
            {
                if(posB->num < posA->num)
                {
                    if(posA == listA)
                    {
                        if(posB == listB)
                        {
                            listB = listB->next;
                            posB->next = posA;
                            listA = posB;
                        }
                        else
                        {
                            nodeptr_t lastPosB = findLastNode(listB, posB);

                            lastPosB->next = posB->next;
                            listA = posB;
                            posB->next = posA;
                        }
                    }
                    else
                    {
                        if(posB == listB)
                        {
                            nodeptr_t lastPosA = findLastNode(listA, posA);

                            listB = listB->next;
                            posB->next = posA;
                            lastPosA->next = posB;
                        }
                        else
                        {
                            nodeptr_t lastPosA = findLastNode(listA, posA);
                            nodeptr_t lastPosB = findLastNode(listB, posB);

                            lastPosB->next = posB->next;
                            posB->next = posA;
                            lastPosA->next = posB;
                        }
                    }
                    break;
                }
                else if(posA->num == posB->num)
                {
                    break;
                }
                else
                {
                    posA = posA->next;
                }
            }
            else
            {
                nodeptr_t lastPosA = findLastNode(listA, posA);
                nodeptr_t lastPosB = findLastNode(listB, posB);
                if(lastPosA != NULL)//考虑直接放在A的开头情况
                {
                    lastPosA->next = posB;
                }
                else
                {
                    listA = posB;
                }
                if(lastPosB != NULL)//考虑直接从B的开头开始的情况
                {
                    lastPosB->next = NULL;
                }
                else
                {
                    listB = NULL;
                }
                nextPosB = NULL;
                break;
            }
        }
        posB = nextPosB;
    }

    if(listA == NULL)
    {
        printf("There is no item in A list.\n");
    }
    else
    {
        printf("The new list A:");
        printLinkedList(listA);
    }
    if(listB == NULL)
    {
        printf("There is no item in B list.\n");
    }
    else
    {
        printf("The new list B:");
        printLinkedList(listB);
    }

    if(listA != NULL)
    {
        freeLinkedList(listA);
    }
    if(listB != NULL)
    {
        freeLinkedList(listB);
    }
    return 0;
}