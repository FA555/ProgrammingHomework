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

int main(void)
{
    int temp;
    int maxNum;
    int minNum;
    int sumNum = 0;
    nodeptr_t head = NULL;
    nodeptr_t pos = NULL;

    scanf("%d", &temp);
    head = newLinkedList(temp);
    pos = head;
    maxNum = temp;
    minNum = temp;
    sumNum  = sumNum + temp;

    for(;;)
    {
        scanf("%d", &temp);
        if(temp == -1)
        {
            break;
        }
        pos = append(pos, temp);
        sumNum = sumNum + temp;
        if(temp > maxNum)
        {
            maxNum = temp;
        }
        if(temp < minNum)
        {
            minNum = temp;
        }
    }

    printf("The maximum,minmum and the total are:%d %d %d\n", maxNum, minNum, sumNum);

    return 0;
}