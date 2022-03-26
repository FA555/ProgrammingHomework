#include <stdio.h>
#include <stdlib.h>
//#define scanf_s scanf
struct link
{
	int data;
	struct link* nextPTR;
};
struct link* createHead(struct link* headPTR)//创建头节点
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
void delLink(struct link* headPTR)//释放链表内存空间
{
	struct link* movePTR = headPTR;
	while (movePTR != NULL)
	{
		headPTR = movePTR->nextPTR;
		free(movePTR);
		movePTR = headPTR;
	}
}
void printLink(struct link* headPTR)//遍历打印链表
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
void endInsertLink(struct link* headPTR, int data)//尾插节点
{
	struct link* nowPTR = headPTR, * newPTR = NULL;
	while (nowPTR->nextPTR != NULL)//将当前指针移动到链表尾部
	{
		nowPTR = nowPTR->nextPTR;
	}
	newPTR = (struct link*)malloc(sizeof(struct link));
	newPTR->data = data;
	newPTR->nextPTR = NULL;
	nowPTR->nextPTR = newPTR;
}
void exchangePart(struct link* headPTR, int s1, int t1, int s2, int t2)
{
	int counter = 1;
	struct link* S1, * T1, * S2, * T2;
	struct link* pS1, * aT1, * pS2, * aT2;
	pS1 = pS2 = headPTR;
	T1 = T2 = headPTR->nextPTR;
	while (counter < s1)
	{
		pS1 = pS1->nextPTR;
		counter++;
	}
	S1 = pS1->nextPTR;
	counter = 1;
	while (counter < t1)
	{
		T1 = T1->nextPTR;
		counter++;
	}
	aT1 = T1->nextPTR;
	counter = 1;
	while (counter < s2)
	{
		pS2 = pS2->nextPTR;
		counter++;
	}
	S2 = pS2->nextPTR;
	counter = 1;
	while (counter < t2)
	{
		T2 = T2->nextPTR;
		counter++;
	}
	aT2 = T2->nextPTR;
	counter = 1;
	if (t1 + 1 == s2)
	{
		pS1->nextPTR = S2;
		T2->nextPTR = S1;
		T1->nextPTR = aT2;
	}
	else 
	{
		pS1->nextPTR = S2;
		T2->nextPTR = aT1;
		pS2->nextPTR = S1;
		T1->nextPTR = aT2;
	}
}
int main()
{
	int data = 0, total1 = 0, total2 = 0, judge = 0;
	int s1 = 0, t1 = 0, s2 = 0, t2 = 0;
	struct link* head1 = NULL;
	head1 = createHead(head1);
	scanf_s("%d", &data);
	while (data != -1)
	{
		total1++;
		endInsertLink(head1, data);
		scanf_s("%d", &data);
	}
	scanf_s("%d %d %d %d", &s1, &t1, &s2, &t2);
	exchangePart(head1, s1, t1, s2, t2);
	printf("The new list is:");
	printLink(head1);
	delLink(head1);
	return 0;
}