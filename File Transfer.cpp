#include<iostream>
using namespace std;

#define MaxSize 10000

typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MaxSize];

void Initialization(SetType S, int N)
{
	for (int i = 0; i < N; i++)
	{
		S[i] = -1;
	}
}

ElementType Find(SetType S, ElementType u)
{
	if (S[u] < 0)
		return u;
	else
		return S[u] = Find(S, S[u]);
}
void Union(SetType S, SetName Root1, SetName Root2)
{
	if (S[Root2] < S[Root1])
	{
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
	else
	{
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}

void Check_connection(SetType S)
{
	ElementType u, v;
	SetName Root1, Root2;
	cin >> u >> v;
	Root1 = Find(S, u - 1);
	Root2 = Find(S, v - 1);
	if (Root1 == Root2)
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}
}

void Check_network(SetType S, ElementType n)
{
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		if (S[i] < 0)
		{
			counter++;
		}
	}
	if (counter == 1)
	{
		cout << "The network is connected." << endl;
	}
	else
	{
		cout << "There are " << counter << " components." << endl;
	}

}

void Input_connection(SetType S)
{
	ElementType u, v;
	SetName Root1, Root2;
	cin >> u >> v;
	Root1 = Find(S, u - 1);
	Root2 = Find(S, v - 1);
	if (Root1 != Root2)
	{
		Union(S, Root1, Root2);
	}
}
int main()
{
	SetType S;
	int N;
	char T;
	cin >> N;
	Initialization(S, N);
	do {
		cin >> T;
		switch (T)
		{
		case 'C': Check_connection(S); break;
		case 'I':Input_connection(S); break;
		case 'S':Check_network(S, N); break;
		}
	} while (T != 'S');
	return 0;
}