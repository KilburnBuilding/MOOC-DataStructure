#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

void AcquireNodes(int Num, vector<int>&PUSH, vector<int>&POP)
{
	int K;;
	string P;

	stack<int>STACK;


	for (int i = 0; i < 2 * Num; i++)
	{
		cin >> P;

		if (P == "Push")
		{
			cin >> K;
			STACK.push(K);
			PUSH.push_back(K);
		}
		if (P == "Pop")
		{
			POP.push_back(STACK.top());
			STACK.pop();
		}

	}

}

void PrintPostorder(int Num, vector<int>PUSH, int Pre, vector<int>POP, int In, vector<int>&POST, int Post)
{
	if (Num == 0) return;
	if (Num == 1) POST[Post] = PUSH[Pre];
	int i=0;

	auto root = PUSH[Pre];
	POST[Post+Num-1] = root;

	while (i < Num)
	{
		if (POP[In+i] == root) break;
		++i;
	}

	int L = i;
	int R = Num - i - 1;
	
	PrintPostorder(L, PUSH, Pre + 1, POP, In, POST, Post);
	PrintPostorder(R, PUSH, Pre + L + 1, POP, In + L + 1,POST, Post + L);
}




int main()
{
	
	int Num = 0;
	int t = 10;
	cin >> Num;

	vector<int>PUSH;
	vector<int>POP;
	vector<int>POST(Num, 0);

	AcquireNodes(Num, PUSH, POP);

	PrintPostorder(Num, PUSH, 0, POP, 0, POST, 0);
	for (int i = 0; i < Num - 1; i++)
	{
		cout << POST[i] << " ";
	}
	cout << POST[Num-1];
	return 0;
}