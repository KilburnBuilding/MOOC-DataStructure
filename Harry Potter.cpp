#include<iostream>
using namespace std;

#define MaxVertexNum 100	/* ������󶥵���Ϊ100 */
#define INFINITY 65535		/* ������Ϊ˫�ֽ��޷������������ֵ65535 */
typedef int Vertex;			/* �ö�����±������������Ϊ���� */
typedef int WeightType;		/* �ߵ�Ȩֵ��Ϊ���� */


/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;			/* �����<V1,V2> */
	WeightType Weight;		/* Ȩ�� */
};
typedef PtrToENode Edge;


/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;					/* ������ */
	int Ne;					/* ���� */
	WeightType G[MaxVertexNum][MaxVertexNum];	/* �ڽӾ��� */
};
typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */


MGraph CreateGraph(int VertexNum)
{/* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode));  /* ����ͼ */
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* ��ʼ���ڽӾ��� */
	/* ע�⣺����Ĭ�϶����Ŵ�0��ʼ������Graph->Nv - 1) */
	for (V = 0; V < Graph->Nv; V++)
	{
		for (W = 0; W < Graph->Nv; W++)
		{
			Graph->G[V][W] = INFINITY;
 		}
	}
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	/* �����<V1, V2> */
	Graph->G[E->V1][E->V2] = E->Weight;
	/*  */
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	int Nv, i;

	cin >> Nv;				/* ���붥��ĸ��� */
	Graph = CreateGraph(Nv);

	cin>>Graph->Ne;		/* ������� */
	if (Graph->Ne != 0)
	{
		E = (Edge)malloc(sizeof(struct ENode));
		for (i = 0; i < Graph->Ne; i++)
		{
			cin >> E->V1 >> E->V2 >> E->Weight;
			E->V1--;
			E->V2--;
			InsertEdge(Graph, E);
		}
	}
	return Graph;
}

void Floyd(MGraph Graph, WeightType D[][MaxVertexNum])
{
	for (int i = 0; i < Graph->Nv; i++)
	{
		for (int j = 0; j < Graph->Nv; j++)
		{
			D[i][j] = Graph->G[i][j];
		}
	}

	for (int k = 0; k < Graph->Nv; k++)
	{
		for (int i = 0; i < Graph->Nv; i++)
		{
			for (int j = 0; j < Graph->Nv; j++)
			{
				if (D[i][k] + D[k][j] < D[i][j])
				{
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
}


WeightType FindMaxDist(WeightType D[][MaxVertexNum], Vertex i, int N)
{
	WeightType MaxDist;
	Vertex j;

	MaxDist = 0;
	for (j = 0; j < N; j++)			/* �ҳ�i����������j������� */
	{
		if (i != j && D[i][j] > MaxDist)
		{
			MaxDist = D[i][j];
		}
	}
	return MaxDist;
}

void FindAnimal(MGraph Graph)
{
	WeightType D[MaxVertexNum][MaxVertexNum], MaxDist, MinDist;
	Vertex Animal, i;

	Floyd(Graph, D);

	MinDist = INFINITY;
	
	for (i = 0; i < Graph->Nv; i++)
	{
		MaxDist = FindMaxDist(D, i, Graph->Nv);
		if (MaxDist == INFINITY)  
		{/* ˵���д�i�޷�����Ķ��� */
			cout << "0" << endl;
			return;
		}
		if (MinDist > MaxDist)
		{/* �ҵ�������С�Ķ��� */
			MinDist = MaxDist;
			Animal = i + 1;			/* ���¾��룬��¼��� */
		}
	}
	cout << Animal <<' '<<MinDist << endl;
}



int main()
{
	MGraph G = BuildGraph();
	FindAnimal(G);
	return 0;
}



