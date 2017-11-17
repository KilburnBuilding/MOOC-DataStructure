#include<iostream>
#include<queue>
using namespace std;

/*队列的建立*/
/*
typedef struct QNode	 队列的创建 
{
	int data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct			/* 队列的链表结构 
{
	QueuePtr front, rear; /* 队头、队尾指针 
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
	Q->rear->next = s;	/* 把拥有元素e的新结点s赋值给原队尾结点的后继  
	Q->rear = s;		/* 把当前的s设置为队尾结点，rear指向s 
	return;
}

int DeQueue(LinkQueue *Q)
{
	QueuePtr p;
	int DelteElemennt;
	p = Q->front->next;		/* 将欲删除的队头结点暂存给p，见图中① 
	DelteElemennt = p->data;				/* 将欲删除的队头结点的值赋值给e 
	Q->front->next = p->next;/* 将原队头结点的后继p->next赋值给头结点后继，见图中② 
	if (Q->rear == p)		/* 若队头就是队尾，则删除后将rear指向头结点，见图中③ 
		Q->rear = Q->front;
	free(p);
	return DelteElemennt;
}

*/








/*图的邻接矩阵表示法*/

#define MaxVertexNum 100	/*最大顶点数设为100*/
#define INFINITY 65535		/*无穷值设为双字符无符号整数的最大值为65535*/

typedef int Vertex;			/*用顶点下标表示顶点，为整型*/
typedef int WeightType;		/*边的权值设为整型*/
typedef char DataType;		/*顶点存储的数据类型设为字符型*/

typedef struct ENode *PtrToENode;
struct ENode
{
	Vertex v1, v2;			/*有向边<v1,v2>*/
	/*WeightType Weight;*/		/*权重*/
};
typedef PtrToENode Edge;

typedef struct GNode *PtrToGNode;
struct GNode
{
	int Nv;					/*顶点数*/
	int Ne;					/*边数*/
	WeightType G[MaxVertexNum][MaxVertexNum];	/*邻接矩阵*/
	/*DataType Data[MaxVertexNum];*/				/*存顶点的数据*/
};
typedef PtrToGNode MGraph;						/*以邻接矩阵存储的图类型*/


MGraph CreateGraph(int VertexNum)
{	/*初始化一个有VertexNum个顶点但没有边的图*/
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

	cin >> Nv;						/*读入顶点的个数*/
	Graph = CreateGraph(Nv);		/*创建一个包含Nv个顶点的空图*/

	cin >> Graph->Ne;				/*读入边数*/
	if (Graph->Ne != 0)				/*如果有边的话*/
	{
		E = (Edge)malloc(sizeof(struct ENode));		/*建立边节点*/
		for (i = 0; i < Graph->Ne; i++)					/*读入边，读入格式为“起点”，“终点”，“权重”，插入邻接矩阵*/
		{
			cin >> E->v1;
			cin >> E->v2;
			/*cin >> E->Weight;*/
			InsertEdge(Graph, E);
		}
	}
	/*for (V = 0; V < Graph->Nv; V++)					/*如果顶点有数据的话，则读入数据*/
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
