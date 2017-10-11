#include<iostream>
using namespace std;


int RetureMax(int a, int b, int c)
{
	if (a < b)
		a = b;
	if(a < c)
		a = c;
	return a;
}
int MaxSum(int Left, int Right, int List[])
{
	int LeftMax = 0;
	int LeftSum = 0;

	int RightMax = 0;
	int RightSum = 0;

	int MiddleSum = 0;
	int SumMax = 0;

	int LeftSub = 0;
	int RightSub = 0;

	if (Left == Right)
		return List[Left];

	int n = (Right + Left) / 2;

	LeftSub = MaxSum(Left, n, List);
	RightSub = MaxSum(n + 1, Right, List);


	for (int k = n; k >= Left; k--)
	{
		LeftSum += List[k];
		if (LeftSum > LeftMax)
			LeftMax = LeftSum;
	}

	for (int k = n + 1; k < Right; k++)
	{
		RightSum += List[k];
		if (RightSum > RightMax)
			RightMax = RightSum;
	}

	MiddleSum = LeftMax + RightMax;

	return RetureMax(MiddleSum, LeftSub, RightSub);
}


int main()
{
	int num = 0;
	int list[100000];
	int count = 0;

	for (int i = 0; i < 100000; i++)
	{
		list[i] = 0;
	}

	cin >> num;
	
	for (int i = 0; i < num; i++)
	{
		cin >> list[i];
		if (list[i] < 0)
		{
			count += 1;
		}
	}

	if (count == num)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << MaxSum(0, num, list)<<endl;
	}
	return 0;
}