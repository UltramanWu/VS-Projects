#include<iostream>
#include"Chain.h"
using namespace std;

#define MaxVertexNum 100  /* 最大顶点数设为100 */
#define INFINITY 65535  /* 正无穷设为双字节无符号整数的最大值65535 */
typedef int Vertex;  /* 用顶点下标表示顶点，为整型 */
typedef int WeightType;  /* 边的权值为整型 */
typedef char DataType;
bool Visited[MaxVertexNum]; /* 被访问标志位 */

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1, V2;  /* 有向边<V1,V2> */
	WeightType Weight;    /* 权重 */
};
typedef PtrToENode  Edge;


/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
	Vertex AdjV;     /* 邻接点下标 */
	WeightType Weight;  /* 边权重 */
	PtrToAdjVNode Next;  /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct VNode{
	PtrToAdjVNode FirstEdge;   /* 边表头指针 */
	DataType Data;    /* 存顶点的数据 */
	/* 在很多情况下，顶点无数据，此时Data可以不出现 */
}AdjList[MaxVertexNum];    /* 创建表头数组 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;         /* 顶点数*/
	int Ne;         /* 边数 */
	AdjList G;     /*邻接表*/
};
typedef PtrToGNode LGraph;  /* 以邻接表方式存储的图类型 */

LGraph CreateGraph(int VertexNum)
{ /* 初始化一个有VertexNum个顶点但没有边的图 */
	Vertex V;
	LGraph Graph;
	Graph = new struct GNode;
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* 初始化邻接表头指针 */
	for (V = 0; V < Graph->Nv; V++)
		(Graph->G[Graph->Nv]).FirstEdge = NULL;

	return Graph;
}

/* 插入结点 */
void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;

	/* 插入边 <V1,V2> */
	/* 为V2建立新的邻接点 */
	NewNode = new struct AdjVNode;
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	/* 将V2插入到V1的表头 */
	/* 向前插入*/
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;


	/* 若是无向图，还要插入边<V2,V1> */
	/* 为V1建立新的邻接点 */
	NewNode = new struct AdjVNode;
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	/* 将V1插入到V2的表头 */
	/* 向前插入 */
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;

}


void Visit(Vertex V)
{
	cout << "当前访问的结点为" << V << endl;
}

/* 广度优先搜索 */
void BFS(LGraph G,Vertex V)
{
	Vertex U;
	PtrToAdjVNode  W;
	Queue Q = Creat_Queue();
	Add_Q(Q, V);

	if (!IsEmpty_Q(Q))  /* 队列非空 */
	{
		U = Delete_Q(Q);  /* 元素出队*/
		Visit(U);  /* 访问该结点 */
		for (W = G->G[U].FirstEdge; W; W = W->Next)
		{
			if (!Visited[W->AdjV])   /* 如果当前结点没有被访问过 */
			{
				Add_Q(Q, W->AdjV);  /* 入队元素 */
				Visited[W->AdjV] = true;  /* 标记已经被访问 */
			}
		}
	}  /* 队列为空 */
}

/* 深度优先搜索 */
void DFS(LGraph G, Vertex V)
{
	PtrToAdjVNode W;
	Visit(V);
	Visited[V] = true;  /* 当前结点置为TRUE，标记为已被访问 */
	for (W = G->G[V].FirstEdge; W; W = W->Next)  /* 对V的每个邻接点W->AdjV 进行访问 */
	{
		if (!Visited[W->AdjV])  /* 如果当前结点没有被访问过 */
		{
			DFS(G, W->AdjV);  /* 对链式结构进行递归调用 */
		}
	}

}