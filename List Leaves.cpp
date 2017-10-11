#include<iostream>
#include<queue>
using namespace std;


#define Null -1

struct TreeNode {
	int Left;
	int Right;
} T[10];

int BuildTree(struct TreeNode T[])
{
	int Num;
	int check[10];
	int j;
	int Root;
	char cl;
	char cr;

	cin >> Num;

	for (int i = 0; i < Num; i++)
	{
		check[i] = 0;
	}

	for (int i = 0; i < Num; i++)
	{
		cin >> cl >> cr;
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
	return Root;
}

void PrintLeaves(int K)
{
	int N;
	queue<int> Q;
	queue<int> P;
	Q.push(K);
	while (!Q.empty())
	{
		N = Q.front();
		if ((T[N].Left != Null) && (T[N].Right != Null))
		{
			Q.pop();
			Q.push(T[N].Left);
			Q.push(T[N].Right);
		}
		else if ((T[N].Left != Null) && (T[N].Right == Null))
		{
			Q.pop();
			Q.push(T[N].Left);
		}
		else if ((T[N].Left == Null) && (T[N].Right != Null))
		{
			Q.pop();
			Q.push(T[N].Right);
		}
		else
		{
			P.push(Q.front());
			Q.pop();
		}
	}
	
	int J = P.size();

	for(int i=0;i<J;i++)
	{
		if (i < (J-1))
		{
			cout << P.front() << " ";
			P.pop();
		}
		else 
		{
			cout << P.front();
			P.pop();
		}
	}
}


int main()
{
	int K;
	K=BuildTree(T);
	PrintLeaves(K);
	return 0;
}