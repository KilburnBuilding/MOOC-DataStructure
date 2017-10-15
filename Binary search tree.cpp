#include<iostream>
using namespace std;

typedef struct TreeNode* Tree;
struct TreeNode
{
	int V;
	Tree Left;
	Tree Right;
	int flag;
};

Tree NewNode(int v) /*构造一个新的节点*/
{
	Tree T;
	T = (Tree)malloc(sizeof(struct TreeNode));
	T->V = v;
	T->flag = 0;
	T->Left = NULL;
	T->Right = NULL;
	return T;
}

Tree Insert(Tree T, int v)
{
	if (!T)
		T = NewNode(v);
	else
	{
		if (v > T->V)
			T->Right = Insert(T->Right, v);
		else
			T->Left = Insert(T->Left, v);
	}
	return T;
}

Tree BuildTree(int N) /*构造一个新的树*/
{
	Tree T;
	int v;
	cin >> v;
	T = NewNode(v);
	for (int i = 1; i < N; i++)
	{
		cin >> v;
		T = Insert(T, v);
	}

	return T;
}

int check(Tree T, int v)
{
	if (T->flag)
	{
		if (v < T->V)
			return check(T->Left, v);
		else if (v > T->V)
			return check(T->Right, v);
		else
			return 0;
	}
	else
	{
		if (v == T->V)
		{
			T->flag = 1;
			return 1;
		}
		else
			return 0;
	}
}

int Judge(Tree T, int N)
{
	int i, v, flag = 0;
	cin >> v;
	if (v != T->V)
		flag = 1;
	else
		T->flag = 1;
	for (int i = 1; i < N; i++)
	{
		cin >> v;
		if ((!flag) && (!check(T, v)))
			flag = 1;
	}
	if (flag)
		return 0;
	else
		return 1;
}

void ResetT(Tree T)
{
	if (T->Left)
		ResetT(T->Left);
	if (T->Right)
		ResetT(T->Right);
	T->flag = 0;
}

void FreeTree(Tree T)
{
	if (T->Left)
		FreeTree(T->Left);
	if (T->Right)
		FreeTree(T->Right);
	free(T);
}

int main()
{
	int N;
	int K;
	Tree T;
	cin >> N;
	while (N)
	{
		cin >> K;
		T = BuildTree(N);
		for (int i = 0; i < K; i++)
		{
			if (Judge(T, N))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
			ResetT(T);
		}
		FreeTree(T);
		cin >> N;

		
	}
	return 0;
}