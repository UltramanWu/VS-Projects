#include<iostream>
using namespace std;
#include"Chain.h"


#define MaxVertexNum 100  /* ��󶥵�����Ϊ100 */
#define INFINITY 65535  /* ��������Ϊ˫�ֽ��޷������������ֵ65535 */
typedef int Vertex;  /* �ö����±��ʾ���㣬Ϊ���� */
typedef int WeightType;  /* �ߵ�ȨֵΪ���� */
typedef char DataType;

bool Visited[MaxVertexNum];  /* ��ʼ��ΪFALSE */
/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1, V2;   /* �����<V1��V2> */
	WeightType Weight;  /* Ȩ�� */
};
typedef PtrToENode  Edge;  

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;  /* ������ */
	int Ne;  /* ���� */
	WeightType G[MaxVertexNum][MaxVertexNum];  /* �ڽӾ��� */
	DataType Data[MaxVertexNum];  /* �涥������� */
	/* �ںܶ�����£����������ݣ���ʱData[ ] ���Բ��ó��� */
};
typedef PtrToGNode  MGraph;  /* ���ڽӾ���洢��ͼ���� */



MGraph CreateGraph(int VertexNum)
{
	/* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
	Vertex V, W;
	MGraph Graph;
	Graph = new struct GNode;
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* ��ʼ���ڽӾ��� */
	/* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv-1) */
	for (V = 0; V < Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;
	
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	/* �����<V1,V2> */
	Graph->G[E->V1][E->V2] = E->Weight;

	/* �����<V2,V1> */
	Graph->G[E->V2][E->V1] = E->Weight;
}


/* ���<V,W>�Ƿ�ΪGraph�е�һ���ߣ���W�Ƿ�V���ڽӵ� */
/* �˺�������ͼ�Ĳ�ͬ����Ҫ����ͬ��ʵ�֣��ؼ�ȡ���ڶԲ����ڱߵı�ʾ���� */
/* ������Ȩͼ����������ڵı߱���ʼ��INFINITY������ʵ�����£�*/
bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W] < INFINITY ? true : false;
}

void Visit(MGraph G, Vertex V)
{
	cout << G->Data[V];
}


/* Deepth_First_Search ���������������*/
void DFS(MGraph Graph,Vertex V)
{
	Vertex W;
	Visited[V] = true;

	for (W = 0; W < Graph->Nv ; W++)
	{
		if (!Visited[W] && IsEdge(Graph, V, W))  /* �����ǰ��û�б����ʹ����Ҹõ�����ʼ���б߽������� */
		{
			Visit(Graph, W);
			DFS(Graph, W);  /* �ݹ���������ӽڵ� */
			Visited[W] = true;
		}
	}
}

/* Breadth_First_Search��������������� */

void BFS(MGraph G, Vertex V)
{
	Vertex W,U;
	Visited[V] = true;
	Queue Q = Creat_Queue();  /* �������� */
	Add_Q(Q, V);  /* ���������Ԫ����� */
	while (!IsEmpty_Q(Q))
	{
		U = Delete_Q(Q);  /* ����Ԫ��*/
		for (W = 0; W < G->Nv; W++)
		{
			if (!Visited[W] && IsEdge(G, U, W))
			{
				Visit(G, W);  /* ���ʸ�Ԫ�� */
				Visited[W] = true;  /* ����λ����λ*/
				Add_Q(Q, W);  /* ����Ԫ����� */
			}
		}
	}  /* ѭ������ */
}