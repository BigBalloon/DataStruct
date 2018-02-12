#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 10 //���Ա��洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 2 //���Ա�洢�ռ�ķ�������
typedef struct
{
	int *elem; //�洢�ռ��ַ
	int length; //˳�����Ա�ǰ����
	int listsize; //˳�����Ա�ĳ���
}SqList;

void InitList(SqList* List)//��ʼ��˳���
{
	List->elem = (int*)malloc(sizeof(int)*LIST_INIT_SIZE);
	if (List->elem == NULL)
		return;
	List->listsize = LIST_INIT_SIZE;
	List->length = 0;
}

int ListEmpty(SqList* List)//�ж����Ա��Ƿ�Ϊ��
{
	if (!List->elem)
		return 1;
	return 0;
}

void DestroyList(SqList* List) //�������Ա�
{
	free(List->elem);
	List->elem = NULL;
}

int ListLength(SqList* List)//�������Ա�ĳ���
{
	if (List->elem)
		return List->length;
	return 0;
}

void GetElem(SqList* List, int i, int *data)//��ȡ���Ա��е�i���ڵ������
{
	if (i < 0 || i > List->length)
		return;
	*data = List->elem[i - 1];
}

int LocateElem(SqList List, int data) //�����Ա��в�����û�к�data��ͬ������
{
	int i;
	for (i = 0; i < List.length; i++)
		if (data == List.elem[i])
			return i;
	return -1;
}

void TraverseList(SqList List)//�������Ա�
{
	int i;
	printf("%d", List.elem[0]);
	for (i = 1; i < List.length; i++)
		printf(" %d", List.elem[i]);
}

void ListInsert(SqList* List, int i, int data)//��data������Ա�ĵ�i���ڵ�
{
	int *newbase;
	int j;
	if (i < 1 || i > List->length + 1)
		return;
	if (List->length >= List->listsize)
	{
		newbase = (int*)realloc(List->elem, sizeof(int)*(List->listsize + LISTINCREMENT));
		if (!newbase)
			return;
		List->elem = newbase;
		List->listsize = List->listsize + LISTINCREMENT;
	}
	for (j = List->length - 1; j >= i - 1; j--)//�±�Ϊi-1�����ݾ��ǵ�i��
		List->elem[j + 1] = List->elem[j];
	List->elem[i - 1] = data;
	++List->length;
}
void ListDelete(SqList* List, int i)
{
	int j, data;
	if (i < 1 || i > List->length)
		return;
	data = List->elem[i - 1];
	for (j = i; j < List->length; j++)
		List->elem[j - 1] = List->elem[j];
	List->length--;
	printf("%d\n", data);
}

int main()
{
	int i, data, j;
	SqList sqlist;
	InitList(&sqlist);
	for (i = 0; i < sqlist.listsize; i++){
		ListInsert(&sqlist, i + 1, i + 1);
	}
	printf("˳����ԭʼ������:\n");
	TraverseList(sqlist);
	printf("\n���������±�����\n");
	scanf("%d", &j);
	GetElem(&sqlist, j, &data);
	printf("��%d������������: %d", j, data);
	printf("\n�������ɾ���Ľ���±�:\n");
	scanf("%d", &j);
	printf("�±�Ϊ%d�Ľ���������: ");
	ListDelete(&sqlist, j);
	printf("˳����е�����������:\n");
	TraverseList(sqlist);
	printf("\n˳���ĳ���Ϊ: %d", ListLength(&sqlist));
	printf("\n�������Ա�,");
	DestroyList(&sqlist);
	printf("˳����Ƿ�Ϊ��: ");
	printf("%d\n", ListEmpty(&sqlist));
	system("pause");
	return 0;
}