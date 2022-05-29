#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 链表结构体
 * 
 */
struct node
{
    char data;
    struct node* next;
};

typedef struct node node_t;
typedef struct node* nodeptr_t;

/**
 * @brief 初始化一个链表
 * 
 * @param value 第一个节点的值
 * @return nodeptr_t 头节点的地址
 */
nodeptr_t newLinkedList(char value)
{
    nodeptr_t head = NULL;

    head = malloc(sizeof(node_t));

    head->next = NULL;
    head->data = value;

    return head;
}

/**
 * @brief 在pos节点的后面插入一个节点
 * 
 * @param pos 插入节点的位置
 * @param value 需要添加的值
 * @return nodeptr_t 添加的节点的地址
 */
nodeptr_t append(nodeptr_t pos, char value)
{
    nodeptr_t newNode = malloc(sizeof(node_t));

    newNode->data = value;
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
            printf("%c\n", pos->data);
            break;
        }
        printf("%c ", pos->data);
        pos = pos->next;
    }
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
        if(pos->data <= start->data)
        {
            center = center->next;
            temp = center->data;
            center->data = pos->data;
            pos->data = temp;
        }
        pos = pos->next;
    }

    temp = start->data;
    start->data = center->data;
    center->data = temp;

    quickSort(start, center);
    quickSort(center->next, end);
}

int main(void)
{
    nodeptr_t charList = NULL;
    nodeptr_t numberList = NULL;
    nodeptr_t signalList = NULL;
    nodeptr_t charListPos = NULL;
    nodeptr_t numberListPos = NULL;
    nodeptr_t signalListPos = NULL;

    char temp[2];
    char input;

    for(;;)
    {
        scanf("%s", temp);
        if(temp[0] == '-' && temp[1] == '1')
        {
            break;
        }

        input = temp[0];
        if((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
        {
            if(charList == NULL)
            {
                charListPos = newLinkedList(input);
                charList = charListPos;
            }
            else
            {
                charListPos = append(charListPos, input);
            }
        }
        else if(input >= '0' && input <= '9')
        {
            if(numberList == NULL)
            {
                numberListPos = newLinkedList(input);
                numberList = numberListPos;
            }
            else
            {
                numberListPos = append(numberListPos, input);
            }
        }
        else
        {
            if(signalList == NULL)
            {
                signalListPos = newLinkedList(input);
                signalList = signalListPos;
            }
            else
            {
                signalListPos = append(signalListPos, input);
            }
        }
    }

    quickSort(charList, NULL);
    quickSort(numberList, NULL);
    quickSort(signalList, NULL);

    if(charList == NULL)
    {
        printf("There is no item in A list.\n");
    }
    else
    {
        printf("The list A is: ");
        printLinkedList(charList);
    }

    if(numberList == NULL)
    {
        printf("There is no item in B list.\n");
    }
    else
    {
        printf("The list B is: ");
        printLinkedList(numberList);
    }

    if(signalList == NULL)
    {
        printf("There is no item in C list.\n");
    }
    else
    {
        printf("The list C is: ");
        printLinkedList(signalList);
    }

    freeLinkedList(charList);
    freeLinkedList(numberList);
    freeLinkedList(signalList);

    return 0;
}