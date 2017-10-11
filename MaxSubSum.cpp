#include<iostream>
using namespace std;

int MaxSubSum(int num, int List[])
{
	int Max = 0;
	int Sum = 0;
	int First = 0;
	int Last = 0;
	int TagStart = 0;
	int Start = 0;
	int TagEnd = 0;
	int Flag = 0;


	for (int i = 0; i < num; i++)
	{
		if (List[i] >= 0)
			Flag = 1;
		Sum += List[i];
		if (Sum < 0)
		{
			Sum = 0;
			Start = i + 1;
		}
		else if (Sum > Max)
		{
			Max = Sum;
			TagEnd = i;
			TagStart = Start;
		}
	}
	if (Max == 0)
	{
		if (Flag == 0)
		{
			cout << Max << ' ' << List[0] << ' ' << List[num-1] << endl;
		}
		else
		{
			cout << 0 << ' ' << 0 << ' ' << 0 << endl;
		}
	}
	else
	{
		First = TagStart;
		Last = TagEnd;
		cout << Max << ' ' << List[First] << ' ' << List[Last] << endl;
	}

	


	
	return 0;
}


int main()
{
	int List[10000];
	int num = 0;

	for (int i = 0; i < 10000; i++)
	{
		List[i] = 0;
	}

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> List[i];
	}

	MaxSubSum(num, List);


}