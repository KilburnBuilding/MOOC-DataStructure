#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

#define MaxVertexNum 100
#define INFINITY 65535
#define Radius 7.5
#define MAXDISTANCE 42.5

struct Point 
{
	int x;
	int y;
	bool Visited;
};

int Num;
double Step;
vector<Point> P;

double Distance(Point X, Point Y)
{	
	return sqrt((X.x - Y.x)*(X.x - Y.x) + (X.y - Y.y)*(X.y - Y.y));
}

void Search(int K)
{
	P[K].Visited = 1;
	if (((50 - abs(P[K].x)) <= Step) || ((50 - abs(P[K].y)) <= Step))
	{
		cout << "Yes" << endl;
		exit(0);
	}
	else
	{
		for (int j = 0; j < Num; j++)
		{
			if ((!P[j].Visited) && (Distance(P[K], P[j]) <= Step))
			{
				Search(j);
			}
		}
	}
}



int main()
{
	int m, n;
	double distance = 0;
	cin >> Num >> Step;
	vector<int> First;

	Point Point_0;
	Point Zero;
	Zero.x = 0;
	Zero.y = 0;
	Zero.Visited = 1;
	for (int i = 0; i < Num; i++)
	{
		cin >> m >> n;
		Point_0.x = m;
		Point_0.y = n;
		Point_0.Visited = 0;
		P.push_back(Point_0);
 	}
	
	

	if (Step >= MAXDISTANCE)
	{
		cout << "Yes" << endl;
	}
	else
	{
		for (int i = 0; i < Num; i++)
		{
			if (Distance(P[i], Zero) <= (Step + 7.5))
			{
				First.push_back(i);
			}
		}

		if (First.empty())
		{
			cout << "No" << endl;
		}
		else
		{
			for (int i = 0; i < First.size(); i++)
			{
				Search(First[i]);
			}
			cout << "No" << endl;
		} 
	}
	return 0;
}
