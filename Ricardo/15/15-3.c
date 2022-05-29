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
 * @brief 验证B是否是A的子列
 * 
 * @param listA 链表A
 * @param listB 链表B
 * @return int 如果1则匹配成功，如果0则匹配失败
 */
int match(nodeptr_t listA, nodeptr_t listB)
{
    /**
     * @brief 是否开始匹配的标志量，若为0则未开始匹配，若为1则已开始匹配
     * 
     */
    int flag = 0;

    nodeptr_t posA = listA;
    nodeptr_t posB = listB;
    /**
     * @brief 子路上次开始匹配的下一个位置，考虑A:12223, B:2233;
     * 
     */
    nodeptr_t last_search_pos = NULL;

    for(;;)
    {
        if(posA == NULL && posB != NULL)
        {
            flag = 0;
            break;
        }
        if(posA == NULL || posB == NULL)
        {
            break;
        }
        if(posA->num == posB->num)
        {
            if(flag == 0)
            {
                last_search_pos = posA->next;
            }
            flag = 1;
            posA = posA->next;
            posB = posB->next;
        }
        else
        {
            if(flag == 1)
            {
                posA = last_search_pos;
            }
            else
            {
                posA = posA->next;
            }
            posB = listB;

            flag = 0;
        }
    }

    return flag;
}

int main(void)
{
    int temp, result;
    nodeptr_t listA, listB, pos;

    scanf("%d", &temp);
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

    scanf("%d", &temp);
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

    result = match(listA, listB);
    if(result == 0)
    {
        printf("ListB is not the sub sequence of ListA.\n");
    }
    else
    {
        printf("ListB is the sub sequence of ListA.\n");
    }

    freeLinkedList(listA);
    freeLinkedList(listB);
    return 0;
}