#include<iostream>
#include<stdlib.h>
using namespace std;


int compare(const void *a, const void *b)
{
	
	return *(int *)a - *(int *)b;
}

int j = 0;
int b[1005];

void Quenue(int a[], int N,int root)
{
	if (root <= N)
	{
		Quenue(a, N, 2 * root);
		b[root] = a[j++];
		Quenue(a, N, 2 * root + 1);
	}

}

int main()
{
	int N;
	int X;
	int root = 1;
	int a[1000];
	for (int i = 0; i < 1000; i++)
	{
		a[i] = 0;

	}

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	qsort(a, N, sizeof(int), compare);
	Quenue(a, N, root);

	cout << b[1];
	for (int i = 2; i < N+1; i++)
	{
		cout << " " << b[i];
	}


}