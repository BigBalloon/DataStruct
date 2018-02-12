#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 10 //线性表表存储空间的初始分配量
#define LISTINCREMENT 2 //线性表存储空间的分配增量
typedef struct
{
	int *elem; //存储空间基址
	int length; //顺序线性表当前长度
	int listsize; //顺序线性表的长度
}SqList;

void InitList(SqList* List)//初始化顺序表
{
	List->elem = (int*)malloc(sizeof(int)*LIST_INIT_SIZE);
	if (List->elem == NULL)
		return;
	List->listsize = LIST_INIT_SIZE;
	List->length = 0;
}

int ListEmpty(SqList* List)//判断线性表是否为空
{
	if (!List->elem)
		return 1;
	return 0;
}

void DestroyList(SqList* List) //销毁线性表
{
	free(List->elem);
	List->elem = NULL;
}

int ListLength(SqList* List)//返回线性表的长度
{
	if (List->elem)
		return List->length;
	return 0;
}

void GetElem(SqList* List, int i, int *data)//获取线性表中第i个节点的数据
{
	if (i < 0 || i > List->length)
		return;
	*data = List->elem[i - 1];
}

int LocateElem(SqList List, int data) //在线性表中查找有没有和data相同的数据
{
	int i;
	for (i = 0; i < List.length; i++)
		if (data == List.elem[i])
			return i;
	return -1;
}

void TraverseList(SqList List)//遍历线性表
{
	int i;
	printf("%d", List.elem[0]);
	for (i = 1; i < List.length; i++)
		printf(" %d", List.elem[i]);
}

void ListInsert(SqList* List, int i, int data)//将data插进线性表的第i个节点
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
	for (j = List->length - 1; j >= i - 1; j--)//下标为i-1的数据就是第i项
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
	printf("顺序表的原始数据是:\n");
	TraverseList(sqlist);
	printf("\n请输入结点下标数；\n");
	scanf("%d", &j);
	GetElem(&sqlist, j, &data);
	printf("第%d个结点的数据是: %d", j, data);
	printf("\n请输入待删除的结点下标:\n");
	scanf("%d", &j);
	printf("下标为%d的结点的数据是: ");
	ListDelete(&sqlist, j);
	printf("顺序表中的所有数据是:\n");
	TraverseList(sqlist);
	printf("\n顺序表的长度为: %d", ListLength(&sqlist));
	printf("\n销毁线性表,");
	DestroyList(&sqlist);
	printf("顺序表是否为空: ");
	printf("%d\n", ListEmpty(&sqlist));
	system("pause");
	return 0;
}