#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;//数据域
	struct node *lchild, *rchild;//左孩子指针,右孩子指针
}BinTree;

BinTree* CreateBinTree()//构造二叉树
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

void TraverseBinTree(BinTree* bt)//遍历二叉树
{
	if (bt){
		printf("%d ", bt->val);
		TraverseBinTree(bt->lchild);
		TraverseBinTree(bt->rchild);
	}
}

void CountLeaf(BinTree* bt,int *count)//统计叶子数
{
	if (bt){
		if ((!bt->lchild) && (!bt->rchild))//如果该结点不存在左孩子和右孩子
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
		if (hlchild >= hrchild)//二叉树的深度是左子树或者右子树的最大深度加1
			return hlchild + 1;
		else
			return hrchild;
	}
}

BinTree* LeftChild(BinTree* bt, int data)//返回数据域为data的左孩子
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
	printf("构造二叉树,请输入原始数据:\n");
	BinTree* bt = CreateBinTree();
	printf("该二叉树的孩子结点的个数是: ");
	CountLeaf(bt, &count);
	printf("%d", count);
	printf("\n该二叉树的深度是: ");
	printf("%d\n", Depth_BinTree(bt));
	printf("遍历二叉树:\n");
	TraverseBinTree(bt);
	printf("\n");
	system("pause");
	return 0;
}