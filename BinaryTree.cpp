#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void PreorderTraversal(BinTree BT)
{
	if (BT)
	{
		printf("%d", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}

}/* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal(BinTree BT)
{
	if (BT)
	{
		InorderTraversal(BT->Left);
		printf("%d", BT->Data);
		InorderTraversal(BT->Right);
	}
}/* 中序遍历，由裁判实现，细节不表 */

BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

int main()
{
	BinTree BST, MinP, MaxP, Tmp;
	ElementType X;
	int N, i;

	BST = NULL;
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		BST = Insert(BST, X);
	}
	printf("Preorder:"); PreorderTraversal(BST); printf("\n");
	MinP = FindMin(BST);
	MaxP = FindMax(BST);
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		Tmp = Find(BST, X);
		if (Tmp == NULL) printf("%d is not found\n", X);
		else {
			printf("%d is found\n", Tmp->Data);
			if (Tmp == MinP) printf("%d is the smallest key\n", Tmp->Data);
			if (Tmp == MaxP) printf("%d is the largest key\n", Tmp->Data);
		}
	}
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		BST = Delete(BST, X);
	}
	printf("Inorder:"); InorderTraversal(BST); printf("\n");

	return 0;
}
BinTree Insert(BinTree BST, ElementType X)
{
	BinTree p;
	p = (BinTree)malloc(sizeof(struct TNode));
	if (!p) printf("Error");
	p->Data = X;
	p->Left = NULL;
	p->Right = NULL;

	if (BST == NULL)
		BST = p;
	else
	{
		if (X < BST->Data)
		{
			BST->Left = Insert(BST->Left, X);
		}
		else
			BST->Right = Insert(BST->Right, X);
	}
	return BST;
}
BinTree Delete(BinTree BST, ElementType X)
{
	BinTree Temp;
	if (!BST)
		printf("Not Found\n");
	else if (X > BST->Data)
	{
		BST->Right = Delete(BST->Right, X);
	}
	else if (X < BST->Data)
	{
		BST->Left = Delete(BST->Left, X);
	}
	else
	{
		if (BST->Left && BST->Right)
		{
			Temp = FindMin(BST->Right);
			BST->Data = Temp->Data;
			BST->Right = Delete(BST->Right, BST->Data);
		}
		else
		{
			Temp = BST;
			if (!BST->Left)
			{
				BST = BST->Right;
			}
			else if (!BST->Right)
			{
				BST = BST->Left;
			}
			free(Temp);

		}
	}

	return BST;
}
Position Find(BinTree BST, ElementType X)
{
	BinTree Temp;
	Temp = BST;

	int Flag = 1;

	while (Temp && Flag)
	{
		if (Temp->Data == X)
			Flag = 0;
		else if (Temp->Data > X)
		{
			Temp = Temp->Left;
		}
		else
		{
			Temp = Temp->Right;
		}
	}
	return Temp;
}

Position FindMin(BinTree BST)
{
	BinTree Temp;
	Temp = BST;

	if (Temp)
	{
		while (Temp->Left)
		{
			Temp = Temp->Left;
		}
	}
	return Temp;

}
Position FindMax(BinTree BST)
{
	BinTree Temp;
	Temp = BST;
	if (Temp)
	{
		while (Temp->Right)
		{
			Temp = Temp->Right;
		}
	}
	return Temp;
}
