#include<iostream>
#include<stack>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;


int M, N, K;

int Jungle(vector<int> &Vec)
{
	stack<int> sta;
	sta.push(0);
	int i = 0;
	int num = 1;
	int S = M + 1;
	while (i < N)
	{
		while (Vec[i] > sta.top() && sta.size() < S)
		{
			sta.push(num++);
		}

		if (Vec[i++] == sta.top())
			sta.pop();
		else
			return 0;
	}
	return 1;
}

int main()
{
	int temp;
	scanf("%d%d%d", &M, &N, &K);


	vector<int >Vec;
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &temp);
			Vec.push_back(temp);
		}
		if (Jungle(Vec))
			printf("Yes\n");
		else
			printf("No\n");
		Vec.clear();
	}
	return 0;
}