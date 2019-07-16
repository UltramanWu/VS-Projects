#include<iostream>
using namespace std;

#include "Chain_Queue.h"

typedef int VertexNum;  /* 下标 */
typedef int WeightType;  /* 权重表示 */
typedef char DataType;  /* 数据类型 */
#define MaxVertexNum  100 /* 最大顶点数 */
#define INFINITY 65535
bool visited[MaxVertexNum];

/* 边的定义 */
struct LENode{
	VertexNum V1, V2;  /* 顶点下标 */
	WeightType Weight;  /* 边权重 */
};
typedef struct LENode *LEdge; 

/* 邻接点定义 */
struct AdjVNode{
	VertexNum AdjV;/* 邻接点下标 */
	WeightType Weight;/* 权重 */
	struct AdjVNode *Next;/* 指向下一节点的指针 */
};
typedef struct AdjVNode *PtrToAdjVNode;

/* 顶点表头结点定义 */
typedef struct VNode{
	PtrToAdjVNode FirstEdge;  /* 边表头结点 */
	DataType Data;   /* 结点上存储的数据 */
	/*很多情况下，顶点无数据，此时Data可以不出现 */
}AdjList[MaxVertexNum];

/* 图结点的定义 */
struct LGNode{
	int Nv;  /* 结点个数 */
	int Ne;  /* 边个数 */
	AdjList G;  /* 邻接表 */
};
typedef struct LGNode *LGraph;

/* 操作集 */
LGraph CreateGraph(int VertexNum)
{/* 初始化一个有Vertex个结点但是没有边的图 */
	LGraph Graph = new struct  LGNode;
	Graph->Ne = 0;
	Graph->Nv = VertexNum;
	
	for (int  i = 0; i <= Graph->Nv ; i++)
	{
		(Graph->G[i]).FirstEdge = NULL; /* 将所有边的头结点指向进行初始化 */
	}
	
	return Graph;
}

void InsertEdge(LGraph Graph, LEdge E)
{
	PtrToAdjVNode NewNode = new struct AdjVNode[1];
	/*  插入<V1，V2> */
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	PtrToAdjVNode NewNode1 = new struct AdjVNode[1];
	/* 对于无向图来说，还需插入<V2,V1> */
	NewNode1->AdjV = E->V1;
	NewNode1->Weight = E->Weight;
	NewNode1->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode1;
	
	Graph->Ne++;
}

LEdge InsertE(VertexNum V1, VertexNum V2, WeightType Weight)
{
	LEdge E = new struct LENode;
	E->V1 = V1-1;
	E->V2 = V2-1;
	E->Weight = Weight;

	return E;
}

void Visit(VertexNum V)
{
	cout << "当前访问的结点为" << V << endl;
}

/* 广度优先搜索 */
void BFS(LGraph Graph, VertexNum V)  /* 需要用到队列 */
{
	VertexNum U;
	PtrToAdjVNode W;
	visited[V] = true;
	Queue Q = CreateQ();
	EnQueue(Q, V);
	while (IsEmptyQ(Q))
	{
		U = DeQueue(Q);
		for (W = Graph->G[U].FirstEdge; W; W = W->Next)
		{
			if (!visited[W->AdjV])
			{
				EnQueue(Q, W->AdjV);
				visited[W->AdjV] = true;  /* 将访问位置置位 */
			}
		}
	}
}

/* 深度优先搜索 */
void DFS(LGraph G, VertexNum V)
{
	PtrToAdjVNode W;
	visited[V] = true;
	Visit(V);
	for (W = G->G[V].FirstEdge; W; W = W->Next)
	{
		if (!visited[W->AdjV])  /* 如果当前结点未被访问，则对其进行递归运算 */
		{
			DFS(G, W->AdjV);  /* 对链式结构进行递归调用 */
			visited[W->AdjV] = true;  /* 将访问位置置位 */
		}	
	}
}