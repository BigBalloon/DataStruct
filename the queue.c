#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef struct
{
	int *buf;	//队列元素空间
	int length; //长度
	int front; //头指针
	int rear; //尾指针
}queue;

void InitQueue(queue* Q)//初始化队列
{
	LOOP:Q->buf = (int*)malloc(sizeof(int)*MAXSIZE);
	if (!Q->buf){
		goto LOOP;//如果申请内存失败,跳到LOOP处继续申请.
	}
	Q->front = Q->rear = 0;
	Q->length = 0;
}

void FreeQueue(queue* Q)//销毁队列
{
	free(Q->buf);
	Q->buf = NULL;
}

int IsEmpty(queue Q)//判断队列是否为空
{
	queue* P = &Q;
	if (!P->length)
		return 1;
	return 0;
}

int IsFull(queue Q)
{
	queue* P = &Q;
	if (P->length == MAXSIZE)
		return 1;
	return 0;
}

void Push_Queue(queue* Q, int data)
{
	if (MAXSIZE == Q->length)
		return;	//队列已满
	Q->buf[Q->rear] = data;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	Q->length++;
}

void Pop_Queue(queue* Q, int *data)
{
	if (!Q->length)
		return;
	*data = Q->buf[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	Q->length--;
}

void TraverseQueue(queue Q)
{
	queue* P = &Q;
	int i;
	if (!P->length)
		return;
	for (i = P->front; i < P->length + P->rear; i++){
		printf("%d ", P->buf[i % MAXSIZE]);
	}
}

void ClearQueue(queue* Q)
{
	Q->length = 0;
	Q->front = 0;
	Q->rear = 0;
}

int main()
{
	int i, data;
	queue Q;
	InitQueue(&Q);
	for (i = 0; i < MAXSIZE; i++){
		Push_Queue(&Q, i + 1);
	}
	printf("队列中的原始数据为: ");
	TraverseQueue(Q);
	printf("\n队列是否已经满了: %d", IsFull(Q));
	printf("\n出队列:\n");
	for (i = 0; i < MAXSIZE; i++){
		Pop_Queue(&Q, &data);
		printf("%d ", data);
	}
	printf("\n队列是否已经空了: %d", IsEmpty(Q));
	ClearQueue(&Q);
	printf("\n清空队列,队列是否已经空了: %d\n", IsEmpty(Q));
	FreeQueue(&Q);
	system("pause");
	return 0;
}