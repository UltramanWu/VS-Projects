#include<iostream>
using namespace std;
#include"Chain.h"


#define MaxVertexNum 100  /* 最大顶点数设为100 */
#define INFINITY 65535  /* 正无穷设为双字节无符号整数的最大值65535 */
typedef int Vertex;  /* 用顶点下标表示顶点，为整型 */
typedef int WeightType;  /* 边的权值为整型 */
typedef char DataType;

bool Visited[MaxVertexNum];  /* 初始化为FALSE */
/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1, V2;   /* 有向边<V1，V2> */
	WeightType Weight;  /* 权重 */
};
typedef PtrToENode  Edge;  

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;  /* 顶点数 */
	int Ne;  /* 边数 */
	WeightType G[MaxVertexNum][MaxVertexNum];  /* 邻接矩阵 */
	DataType Data[MaxVertexNum];  /* 存顶点的数据 */
	/* 在很多情况下，顶点无数据，此时Data[ ] 可以不用出现 */
};
typedef PtrToGNode  MGraph;  /* 以邻接矩阵存储的图类型 */



MGraph CreateGraph(int VertexNum)
{
	/* 初始化一个有VertexNum个顶点但没有边的图 */
	Vertex V, W;
	MGraph Graph;
	Graph = new struct GNode;
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* 初始化邻接矩阵 */
	/* 注意：这里默认顶点编号从0开始，到(Graph->Nv-1) */
	for (V = 0; V < Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;
	
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	/* 插入边<V1,V2> */
	Graph->G[E->V1][E->V2] = E->Weight;

	/* 插入边<V2,V1> */
	Graph->G[E->V2][E->V1] = E->Weight;
}


/* 检查<V,W>是否为Graph中的一条边，即W是否V的邻接点 */
/* 此函数根据图的不同类型要做不同的实现，关键取决于对不存在边的表示方法 */
/* 例如有权图，如果不存在的边被初始化INFINITY，则函数实现如下：*/
bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W] < INFINITY ? true : false;
}

void Visit(MGraph G, Vertex V)
{
	cout << G->Data[V];
}


/* Deepth_First_Search （深度优先搜索）*/
void DFS(MGraph Graph,Vertex V)
{
	Vertex W;
	Visited[V] = true;

	for (W = 0; W < Graph->Nv ; W++)
	{
		if (!Visited[W] && IsEdge(Graph, V, W))  /* 如果当前点没有被访问过而且该点与起始点有边进行连接 */
		{
			Visit(Graph, W);
			DFS(Graph, W);  /* 递归调用其连接节点 */
			Visited[W] = true;
		}
	}
}

/* Breadth_First_Search（广度优先搜索） */

void BFS(MGraph G, Vertex V)
{
	Vertex W,U;
	Visited[V] = true;
	Queue Q = Creat_Queue();  /* 创建队列 */
	Add_Q(Q, V);  /* 将搜索点的元素入队 */
	while (!IsEmpty_Q(Q))
	{
		U = Delete_Q(Q);  /* 出队元素*/
		for (W = 0; W < G->Nv; W++)
		{
			if (!Visited[W] && IsEdge(G, U, W))
			{
				Visit(G, W);  /* 访问该元素 */
				Visited[W] = true;  /* 将该位置置位*/
				Add_Q(Q, W);  /* 将该元素入队 */
			}
		}
	}  /* 循环结束 */
}