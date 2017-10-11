#include<iostream>
using namespace std;

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree], T2[MaxTree];


Tree BuildTree(struct TreeNode T[])
{
	ElementType cl, cr;
	int Root;
	int j;
	int Num;
	int check[10];
	cin >> Num;
	if (Num)
	{
		for (int i = 0; i < Num; i++)
		{
			check[i] = 0;
		}
		for (int i = 0; i < Num; i++)
		{
			cin >> T[i].Element >> cl >> cr;
			if (cl != '-')
			{
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else
				T[i].Left = Null;
			if (cr != '-')
			{
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else
				T[i].Right = Null;
		}
		for (j = 0; j < Num; j++)
		{
			if (!check[j])
				break;
		}
		Root = j;
	}
	else Root = Null;
	return Root;
}

int Isomorphic(Tree R1, Tree R2)
{
	if ((R1 == Null) && (R2 == Null))
		return 1;
	if (((R1 == Null) && (R1 != Null)) || ((R1 != Null) && (R2 == Null)))
		return 0;
	if (T1[R1].Element != T2[R2].Element)
		return 0;
	if ((T1[R1].Left == Null) && (T2[R2].Left == Null))
		return Isomorphic(T1[R1].Right, T2[R2].Right);
	if (((T1[R1].Left != Null) && (T2[R2].Left != Null)) && ((T1[T1[R1].Left].Element == T2[T2[R2].Left].Element)))
		return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
	else
		return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));
}

int main()
{
	Tree R1, R2;

	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	
	if (Isomorphic(R1, R2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}