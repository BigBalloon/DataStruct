#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
	int val;
	struct ListNode* next;
}ListNode;

ListNode* CreateListNode()//����������
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
	//tail->next = head;ѭ������
	return head;
}

void TravelListNode(ListNode* head)//����������
{
	ListNode* L = head->next;
	while (L)
	{
		printf("%d ", L->val);
		L = L->next;
	}
}

void DeleteNode(ListNode* head, unsigned Number)//ɾ����Number���ڵ�
{
	unsigned i = 0;
	ListNode* tail = head, *L;
	if (Number <= 0)
		return;//�����ɾ��ͷ�ڵ�Ļ�,�����κβ���
	while (tail && i < Number - 1)//����Ѱ�ҵ�Number - 1���ڵ�
	{
		tail = tail->next;
		i++;
	}
	if (!tail->next)
		return;
	L = tail->next;//Lָ���Number���ڵ�,tailָ���Number - 1���ڵ�
	tail->next = L->next;
	free(L);
}

void InserNode(ListNode* head, unsigned Number, int data)//�������еĵ�Numberλ����һ���ڵ�.
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

unsigned ListLength(ListNode* head)//������ĳ���.
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

void FreeListNode(ListNode* head)//��������
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

unsigned ListEmpty(ListNode* head)//����Ϊ�շ�����
{
	unsigned True = 1, error = 0;
	if (head->next == NULL)
		return True;
	else
		return error;
}

unsigned LocateList(ListNode* head, int data)//������������û�к�data��ͬ��Ԫ��,����еĻ�������Ӧ��λ��,���򷵻�-1
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

void GetDataInList(ListNode* head, unsigned Number, int* data)//���ص�Number���ڵ������
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
	ListNode* head = CreateListNode();//��������
	printf("ԭʼ����Ϊ: \n");
	TravelListNode(head);//����������
	listlength = ListLength(head);
	printf("\n����ĳ���Ϊ: %d", listlength);
	printf("\n������׼��ɾ���Ľ����±�:\n");
	scanf("%d", &Number);
	DeleteNode(head, Number);
	printf("�������ڵĽ��Ϊ:\n");
	TravelListNode(head);
	printf("\n����������������е�%d������Ϊ:\n", Number);
	scanf("%d", &data);
	InserNode(head, Number, data);
	printf("�������ڵĽ��Ϊ:\n");
	TravelListNode(head);
	printf("\n�����е�%d����������Ϊ:\n", Number);
	GetDataInList(head, Number, &data);
	printf("%d", data);
	printf("\n��������,�����Ƿ�Ϊ�� :");
	FreeListNode(head);
	printf("%d\n", ListEmpty(head));
	system("pause");
	return 0;
}