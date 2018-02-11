#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
	int val;
	struct ListNode* next;
}ListNode;

ListNode* CreateListNode()//创建单链表
{
	int length, i;
	ListNode* head, *tail, *L;
	head = (ListNode*)malloc(sizeof(ListNode));
	head->next = NULL;
	tail = head;
	scanf("%d", &length);
	for (i = 0; i < length; i++)
	{
		L = (ListNode*)malloc(sizeof(ListNode));
		L->next = NULL;
		scanf("%d", &L->val);
		tail->next = L;
		tail = L;
	}
	//tail->next = head;循环链表
	return head;
}

void TravelListNode(ListNode* head)//遍历单链表
{
	ListNode* L = head->next;
	while (L)
	{
		printf("%d ", L->val);
		L = L->next;
	}
}

void DeleteNode(ListNode* head, unsigned Number)//删除第Number个节点
{
	unsigned i = 0;
	ListNode* tail = head, *L;
	if (Number <= 0)
		return;//如果是删除头节点的话,不做任何操作
	while (tail && i < Number - 1)//遍历寻找第Number - 1个节点
	{
		tail = tail->next;
		i++;
	}
	if (!tail->next)
		return;
	L = tail->next;//L指向第Number个节点,tail指向第Number - 1个节点
	tail->next = L->next;
	free(L);
}

void InserNode(ListNode* head, unsigned Number, int data)//往链表中的第Number位增加一个节点.
{
	unsigned i = 0;
	ListNode* tail = head, *L;
	if (Number <= 0)
		return;
	while (tail && i < Number - 1)
	{
		tail = tail->next;
		i++;
	}
	if (!tail)
		return;
	L = (ListNode*)malloc(sizeof(ListNode));
	L->val = data;
	L->next = tail->next;
	tail->next = L;
}

unsigned ListLength(ListNode* head)//求链表的长度.
{
	ListNode* tail = head->next;
	unsigned length = 0;
	while (tail)
	{
		tail = tail->next;
		length++;
	}
	return length;
}

void FreeListNode(ListNode* head)//销毁链表
{
	ListNode *p, *q;
	p = head->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	head->next = NULL;
}

unsigned ListEmpty(ListNode* head)//链表为空返回真
{
	unsigned True = 1, error = 0;
	if (head->next == NULL)
		return True;
	else
		return error;
}

unsigned LocateList(ListNode* head, int data)//查找链表中有没有和data相同的元素,如果有的话返回相应的位置,否则返回-1
{
	unsigned i = 1;
	ListNode* tail = head->next;
	while (tail)
	{
		if (data == tail->val)
			return i;
		tail = tail->next;
		i++;
	}
	return -1;
}

void GetDataInList(ListNode* head, unsigned Number, int* data)//返回第Number个节点的数据
{
	unsigned i = 0;
	ListNode* tail = head;
	if (Number <= 0)
		return;
	while (tail && i < Number)
	{
		tail = tail->next;
		i++;
	}
	if (!tail)
		return;
	*data = tail->val;
}

int main()
{
	int data;
	unsigned listlength, Number;
	ListNode* head = CreateListNode();//创建链表
	printf("原始链表为: \n");
	TravelListNode(head);//遍历单链表
	listlength = ListLength(head);
	printf("\n链表的长度为: %d", listlength);
	printf("\n请输入准备删除的结点的下标:\n");
	scanf("%d", &Number);
	DeleteNode(head, Number);
	printf("链表现在的结果为:\n");
	TravelListNode(head);
	printf("\n请输入待插入链表中第%d的数据为:\n", Number);
	scanf("%d", &data);
	InserNode(head, Number, data);
	printf("链表现在的结果为:\n");
	TravelListNode(head);
	printf("\n链表中第%d个结点的数据为:\n", Number);
	GetDataInList(head, Number, &data);
	printf("%d", data);
	printf("\n销毁链表,链表是否为空 :");
	FreeListNode(head);
	printf("%d\n", ListEmpty(head));
	system("pause");
	return 0;
}