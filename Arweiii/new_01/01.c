#include <stdio.h>
#include <stdlib.h>
struct link
{
	int data;
	struct link* nextPTR;
};
struct link* createHead(struct link *headPTR)//创建头节点
{
	headPTR = (struct link*)malloc(sizeof(struct link));
	if (headPTR != NULL)
	{
		headPTR->nextPTR = NULL;
	}
	return headPTR;
}
struct link* addNode(int data)//添加节点并写入数据
{
	struct link* newNode = (struct link*)malloc(sizeof(struct link));
	newNode->data = data;
	newNode->nextPTR = NULL;
	return newNode;
}
void printLink(struct link *headPTR)//遍历打印链表
{
	struct link* movePTR = headPTR->nextPTR;
	while (movePTR) 
	{
		printf("%d", movePTR->data);
		if (movePTR->nextPTR != NULL)
		{
			printf(" ");
		}
		movePTR = movePTR->nextPTR;
	}
}
void endInsertLink(struct link *headPTR, int data)//尾插节点
{
	struct link *nowPTR = headPTR, *newPTR = NULL;
	while (nowPTR->nextPTR != NULL)//将当前指针移动到链表尾部
	{
		nowPTR = nowPTR->nextPTR;
	}
	newPTR = (struct link*)malloc(sizeof(struct link));
	newPTR->data = data;
	newPTR->nextPTR = NULL;
	nowPTR->nextPTR = newPTR;
}
int findMax(struct link* headPTR)//寻找链表中的最大值
{
	struct link* nowPTR = headPTR->nextPTR;
	int max = nowPTR->data;
	while (nowPTR->nextPTR != NULL)
	{
		if (nowPTR->data > max)
		{
			max = nowPTR->data;
		}
		nowPTR = nowPTR->nextPTR;
	}
	if (nowPTR->data > max)
	{
		max = nowPTR->data;
	}
	return max;
}
int findMin(struct link* headPTR)//寻找链表中的最大值
{
	struct link* nowPTR = headPTR->nextPTR;
	int min = nowPTR->data;
	while (nowPTR->nextPTR != NULL)
	{
		if (nowPTR->data < min)
		{
			min = nowPTR->data;
		}
		nowPTR = nowPTR->nextPTR;
	}
	if (nowPTR->data < min)
	{
		min = nowPTR->data;
	}
	return min;
}
int main()
{
	int data = 0, sum = 0, max = 0, min = 0;
	struct link *headPTR = NULL, *nowPTR = NULL;
	headPTR = createHead(headPTR);
	scanf_s("%d", &data);
	while (data != -1)
	{
		sum += data;
		endInsertLink(headPTR, data);
		scanf_s("%d", &data);
	}
	max = findMax(headPTR);
	min = findMin(headPTR);
	printf("The maximum,minmum and the total are:%d %d %d",max,min,sum);
	//printLink(headPTR);
	return 0;
}

