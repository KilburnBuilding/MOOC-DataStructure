#include<iostream>
using namespace std;

typedef struct AVLNode *Position;
typedef Position AVLTree;

struct AVLNode 
{
	int Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
};

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int height(AVLTree root)
{
	if (root == NULL)
	{
		return -1;
	}
	else
		return root->Height;
}

AVLTree RightRight(AVLTree k1)
{
	AVLTree k2;
	k2 = k1->Right;
	k1->Right = k2->Left;
	k2->Left = k1;
	
	k1->Height = max(height(k1->Left), height(k1->Right)) + 1;
	k2->Height = max(height(k2->Left), height(k2->Right)) + 1;
	return k2;
}

AVLTree LeftLeft(AVLTree k1)
{
	AVLTree k2;
	k2 = k1->Left;
	k1->Left = k2->Right;
	k2->Right = k1;

	k1->Height = max(height(k1->Left), height(k1->Right)) + 1;
	k2->Height = max(height(k2->Left), height(k2->Right)) + 1;
	return k2;
}

AVLTree RightLeft(AVLTree k1)
{
	k1->Right = LeftLeft(k1->Right);
	return RightRight(k1);
}

AVLTree LeftRight(AVLTree k1)
{
	k1->Left = RightRight(k1->Left);
	return LeftLeft(k1);
}

AVLTree Insert(AVLTree T, int X)
{
	if (T == NULL)
	{
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->Data = X;
		T->Left = NULL;
		T->Right = NULL;
		T->Height = 0;
	}
	else if (X < T->Data)
	{
		T->Left = Insert(T->Left, X);
		if (height(T->Left) - height(T->Right) == 2)
		{
			if (X < T->Left->Data)
				T = LeftLeft(T);
			else
				T = LeftRight(T);
		}
	}
	else if (X > T->Data)
	{
		T->Right = Insert(T->Right, X);
		if (height(T->Right) - height(T->Left) == 2)
		{
			if (X > T->Right->Data)
				T = RightRight(T);
			else
				T = RightLeft(T);
		}
	}
	T->Height = max(height(T->Left), height(T->Right)) + 1;
	return T;

}
int main()
	{
		int N;
		int X;
		AVLTree T = NULL;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> X;
			T = Insert(T, X);
		}
		cout << T->Data;
		return 0;
	}