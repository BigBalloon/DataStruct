#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;//������
	struct node *lchild, *rchild;//����ָ��,�Һ���ָ��
}BinTree;

BinTree* CreateBinTree()//���������
{
	int data;
	BinTree* bt = NULL;
	scanf("%d", &data);
	if (data != 0){
	LOOP:bt = (BinTree*)malloc(sizeof(BinTree));
		if (bt == NULL){
			goto LOOP;
		}
		bt->val = data;
		bt->lchild = CreateBinTree();
		bt->rchild = CreateBinTree();
	}
	return bt;
}

void TraverseBinTree(BinTree* bt)//����������
{
	if (bt){
		printf("%d ", bt->val);
		TraverseBinTree(bt->lchild);
		TraverseBinTree(bt->rchild);
	}
}

void CountLeaf(BinTree* bt,int *count)//ͳ��Ҷ����
{
	if (bt){
		if ((!bt->lchild) && (!bt->rchild))//����ý�㲻�������Ӻ��Һ���
			(*count)++;
		CountLeaf(bt->lchild, count);
		CountLeaf(bt->rchild, count);
	}
}

int Depth_BinTree(BinTree* bt)
{
	int hlchild, hrchild;
	if (!bt)
		return 0;
	else{
		hlchild = Depth_BinTree(bt->lchild);
		hrchild = Depth_BinTree(bt->rchild);
		if (hlchild >= hrchild)//������������������������������������ȼ�1
			return hlchild + 1;
		else
			return hrchild;
	}
}

BinTree* LeftChild(BinTree* bt, int data)//����������Ϊdata������
{
	BinTree* T = NULL;
	if (bt){
		if (data == bt->val){
			LOOP:T = (BinTree*)malloc(sizeof(BinTree));
			if (T){
				T->lchild = T->rchild = NULL;
				T->val = bt->val;
				return T;
			}
			else
				goto LOOP;
		}
		LeftChild(bt->lchild, data);
		LeftChild(bt->rchild, data);
	}
	return T;
}

int main()
{
	int count = 0;
	printf("���������,������ԭʼ����:\n");
	BinTree* bt = CreateBinTree();
	printf("�ö������ĺ��ӽ��ĸ�����: ");
	CountLeaf(bt, &count);
	printf("%d", count);
	printf("\n�ö������������: ");
	printf("%d\n", Depth_BinTree(bt));
	printf("����������:\n");
	TraverseBinTree(bt);
	printf("\n");
	system("pause");
	return 0;
}