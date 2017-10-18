#include<iostream>
using namespace std;

#define MAXN 1001
#define MINH -10001

int H[MAXN];
int s;

void Create()
{
	s = 0;
	H[0] = MINH;
}

void Insert(int X)
{
	int i;

	for (i = ++s; H[i / 2] > X; i /= 2)
		H[i] = H[i / 2];
	H[i] = X;
}

int main()
{
	int n, m, x, i, j;

	cin >> n >> m;
	Create();
	for (i = 0; i < n; i++)
	{
		cin >> x;
		Insert(x);
	}
	for (i = 0; i < m; i++)
	{
		cin >> j;
		cout << H[j];
		while (j > 1)
		{
			j /= 2;
			cout << " " << H[j];
		}
		cout << endl;
	}
	return 0;
}