#include <stdio.h>
#include <stdlib.h>
struct link
{
	int data;
	struct link* nextPTR;
};
struct note //检查者
{
	struct link* prePTR;
	struct link* midPTR;
	struct link* aftPTR;
};
void delLink(struct link* headPTR)//释放链表内存空间
{
	struct link* movePTR = headPTR;
	while (movePTR)
	{
		headPTR = movePTR->nextPTR;
		free(movePTR);
		movePTR = movePTR->nextPTR;
	}
}
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
void exchangeNode(struct note finder)//根据note交换相邻的节点
{
	finder.prePTR->nextPTR = finder.aftPTR;
	finder.midPTR->nextPTR = finder.aftPTR->nextPTR;
	finder.aftPTR->nextPTR = finder.midPTR;
}
void moveNode(struct note finder)//向后移动一位note
{
	finder.prePTR = finder.prePTR->nextPTR;
	finder.midPTR = finder.midPTR->nextPTR;
	if (finder.aftPTR->nextPTR != NULL) {
		finder.aftPTR = finder.aftPTR->nextPTR;
	}
}
void sortLink(struct link* headPTR, int total)//链表排序，headPTR为表头，total为需要排序的总数
{
	int counter = 0, mid = 0;
	struct note finder = { headPTR,headPTR->nextPTR,headPTR->nextPTR->nextPTR };
	for (int mid0 = 1; mid0 < total; mid0++)//进行冒泡排序
	{
		counter = 0;
		for (int mid1 = 1; mid1 < total; mid1++)
		{
			if (finder.midPTR->data > finder.aftPTR->data)
			{
				exchangeNode(finder);
				counter++;
			}
			moveNode(finder);
			printf("%d\n", finder.midPTR->data);
		}
		/*if (counter == 0)
		{
			break;
		}*/
		finder.prePTR = headPTR;
		finder.midPTR = headPTR->nextPTR;
		finder.aftPTR = headPTR->nextPTR->nextPTR;
	}
}
void BubbleSort(struct link*headPTR)//冒泡排序算法修改版（原算法存在问题）
{
	struct link* pPTR, * qPTR, * endPTR;
	endPTR = NULL;
	while ((headPTR->nextPTR->nextPTR) != endPTR)
	{
		pPTR = headPTR;
		qPTR = headPTR->nextPTR;
		while (qPTR->nextPTR != endPTR)
		{
			if ((qPTR->data) > (qPTR->nextPTR->data))
			{
				pPTR->nextPTR = qPTR->nextPTR;
				qPTR->nextPTR = qPTR->nextPTR->nextPTR;
				pPTR->nextPTR->nextPTR = qPTR;
				qPTR = pPTR->nextPTR;
			}
			qPTR = qPTR->nextPTR;
			pPTR = pPTR->nextPTR;
		}
		endPTR = qPTR;
	}
}
int main()
{
	int data = 0, total = 0;
	struct link* headPTR = NULL, * nowPTR = NULL;
	headPTR = createHead(headPTR);
	scanf_s("%d", &data);
	while (data != -1)
	{
		total++;
		endInsertLink(headPTR, data);
		scanf_s("%d", &data);
	}
	printf("The new list is:");
	BubbleSort(headPTR);
	printLink(headPTR);
	delLink(headPTR);
	return 0;
}

