#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef struct
{
	int *buf;	//����Ԫ�ؿռ�
	int length; //����
	int front; //ͷָ��
	int rear; //βָ��
}queue;

void InitQueue(queue* Q)//��ʼ������
{
	LOOP:Q->buf = (int*)malloc(sizeof(int)*MAXSIZE);
	if (!Q->buf){
		goto LOOP;//��������ڴ�ʧ��,����LOOP����������.
	}
	Q->front = Q->rear = 0;
	Q->length = 0;
}

void FreeQueue(queue* Q)//���ٶ���
{
	free(Q->buf);
	Q->buf = NULL;
}

int IsEmpty(queue Q)//�ж϶����Ƿ�Ϊ��
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
		return;	//��������
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
	printf("�����е�ԭʼ����Ϊ: ");
	TraverseQueue(Q);
	printf("\n�����Ƿ��Ѿ�����: %d", IsFull(Q));
	printf("\n������:\n");
	for (i = 0; i < MAXSIZE; i++){
		Pop_Queue(&Q, &data);
		printf("%d ", data);
	}
	printf("\n�����Ƿ��Ѿ�����: %d", IsEmpty(Q));
	ClearQueue(&Q);
	printf("\n��ն���,�����Ƿ��Ѿ�����: %d\n", IsEmpty(Q));
	FreeQueue(&Q);
	system("pause");
	return 0;
}