#include<iostream>
#include<queue>
using namespace std;

/*���еĽ���*/
/*
typedef struct QNode	 ���еĴ��� 
{
	int data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct			/* ���е�����ṹ 
{
	QueuePtr front, rear; /* ��ͷ����βָ�� 
}LinkQueue;

void InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	Q->front->next = NULL;
	return;
}

int QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}


void EnQueue(LinkQueue *Q, int e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;	/* ��ӵ��Ԫ��e���½��s��ֵ��ԭ��β���ĺ��  
	Q->rear = s;		/* �ѵ�ǰ��s����Ϊ��β��㣬rearָ��s 
	return;
}

int DeQueue(LinkQueue *Q)
{
	QueuePtr p;
	int DelteElemennt;
	p = Q->front->next;		/* ����ɾ���Ķ�ͷ����ݴ��p����ͼ�Т� 
	DelteElemennt = p->data;				/* ����ɾ���Ķ�ͷ����ֵ��ֵ��e 
	Q->front->next = p->next;/* ��ԭ��ͷ���ĺ��p->next��ֵ��ͷ����̣���ͼ�Т� 
	if (Q->rear == p)		/* ����ͷ���Ƕ�β����ɾ����rearָ��ͷ��㣬��ͼ�Т� 
		Q->rear = Q->front;
	free(p);
	return DelteElemennt;
}

*/








/*ͼ���ڽӾ����ʾ��*/

#define MaxVertexNum 100	/*��󶥵�����Ϊ100*/
#define INFINITY 65535		/*����ֵ��Ϊ˫�ַ��޷������������ֵΪ65535*/

typedef int Vertex;			/*�ö����±��ʾ���㣬Ϊ����*/
typedef int WeightType;		/*�ߵ�Ȩֵ��Ϊ����*/
typedef char DataType;		/*����洢������������Ϊ�ַ���*/

typedef struct ENode *PtrToENode;
struct ENode
{
	Vertex v1, v2;			/*�����<v1,v2>*/
	/*WeightType Weight;*/		/*Ȩ��*/
};
typedef PtrToENode Edge;

typedef struct GNode *PtrToGNode;
struct GNode
{
	int Nv;					/*������*/
	int Ne;					/*����*/
	WeightType G[MaxVertexNum][MaxVertexNum];	/*�ڽӾ���*/
	/*DataType Data[MaxVertexNum];*/				/*�涥�������*/
};
typedef PtrToGNode MGraph;						/*���ڽӾ���洢��ͼ����*/


MGraph CreateGraph(int VertexNum)
{	/*��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ*/
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for(V=0;V<Graph->Nv;V++)
		for (W = 0; W < Graph->Nv; W++)
		{
			Graph->G[V][W] = INFINITY;
		}
	return Graph;
}


void InsertEdge(MGraph Graph, Edge E)
{
	Graph->G[E->v1][E->v2] = 1;			/*E->Weight*/
	Graph->G[E->v2][E->v1] = 1;			/*E->Weight*/
}


MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	/*Vertex V;*/
	int Nv, i;

	cin >> Nv;						/*���붥��ĸ���*/
	Graph = CreateGraph(Nv);		/*����һ������Nv������Ŀ�ͼ*/

	cin >> Graph->Ne;				/*�������*/
	if (Graph->Ne != 0)				/*����бߵĻ�*/
	{
		E = (Edge)malloc(sizeof(struct ENode));		/*�����߽ڵ�*/
		for (i = 0; i < Graph->Ne; i++)					/*����ߣ������ʽΪ����㡱�����յ㡱����Ȩ�ء��������ڽӾ���*/
		{
			cin >> E->v1;
			cin >> E->v2;
			/*cin >> E->Weight;*/
			InsertEdge(Graph, E);
		}
	}
	/*for (V = 0; V < Graph->Nv; V++)					/*������������ݵĻ������������*/
	/*{
		cin >> Graph->Data[V];
	}*/
	return Graph;
}

int Visit[MaxVertexNum];


void DFS(MGraph Graph, Vertex V)
{
	int i;
	Visit[V] = 1;
	cout << V <<' ';
	for (i = 0; i < Graph->Nv; i++)
	{
		if ((!Visit[i]) && (Graph->G[V][i] == 1))
		{
			DFS(Graph, i);
		}
	}

}


void DFS_MG(MGraph Graph)
{
	int i;
	for (i = 0; i < Graph->Nv; i++)
	{
		Visit[i] = 0;
	}
	for (i = 0; i < Graph->Nv; i++)
	{
		if (!Visit[i])
		{
			cout << '{' << ' ';
			DFS(Graph, i);
			cout << '}' << endl;
		}
	}
}

void BFS(MGraph Graph, Vertex V)
{
	queue<int> Q;
	int i, j;
	Q.push(V);
	Visit[V] = 1;
	while (!Q.empty())
	{
		j = Q.front();
		Q.pop();
		cout << j<<' ';
		for (i = 0; i <Graph->Nv; i++)
		{
			if ((!Visit[i]) && (Graph->G[j][i] == 1))
			{
				Q.push(i);
				Visit[i] = 1;
			}
		}
	}
}

void BFS_MG(MGraph Graph)
{
	int i;
	for (i = 0; i < Graph->Nv; i++)
	{
		Visit[i] = 0;
	}
	for (i = 0; i < Graph->Nv; i++)
	{
		if (!Visit[i])
		{
			cout << '{'<<' ';
			BFS(Graph,i);
			cout << '}' << endl;
		}
	}
}




int main()
{
	MGraph Graph;
	Graph = BuildGraph();
	DFS_MG(Graph);
	BFS_MG(Graph);
	

	return 0;
}
