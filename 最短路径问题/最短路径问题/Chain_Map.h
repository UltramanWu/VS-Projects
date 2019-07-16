#include<iostream>
using namespace std;

#include "Chain_Queue.h"

typedef int VertexNum;  /* �±� */
typedef int WeightType;  /* Ȩ�ر�ʾ */
typedef char DataType;  /* �������� */
#define MaxVertexNum  100 /* ��󶥵��� */
#define INFINITY 65535
bool visited[MaxVertexNum];

/* �ߵĶ��� */
struct ENode{
	VertexNum V1, V2;  /* �����±� */
	WeightType Weight;  /* ��Ȩ�� */
};
typedef struct ENode *Edge; 

/* �ڽӵ㶨�� */
struct AdjVNode{
	VertexNum AdjV;/* �ڽӵ��±� */
	WeightType Weight;/* Ȩ�� */
	struct AdjVNode *Next;/* ָ����һ�ڵ��ָ�� */
};
typedef struct AdjVNode *PtrToAdjVode;

/* �����ͷ��㶨�� */
typedef struct VNode{
	PtrToAdjVode FirstEdge;  /* �߱�ͷ��� */
	DataType Data;   /* ����ϴ洢������ */
	/*�ܶ�����£����������ݣ���ʱData���Բ����� */
}AdjList[MaxVertexNum];

/* ͼ���Ķ��� */
struct GNode{
	int Nv;  /* ������ */
	int Ne;  /* �߸��� */
	AdjList G;  /* �ڽӱ� */
};
typedef struct GNode *LGraph;

/* ������ */
LGraph CreateGraph(int VertexNum)
{/* ��ʼ��һ����Vertex����㵫��û�бߵ�ͼ */
	LGraph Graph = new struct  GNode;
	Graph->Ne = 0;
	Graph->Nv = VertexNum;
	
	for (int  i = 0; i <= Graph->Nv ; i++)
	{
		(Graph->G[i]).FirstEdge = NULL; /* �����бߵ�ͷ���ָ����г�ʼ�� */
	}
	
	return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVode NewNode = new struct AdjVNode;
	/*  ����<V1��V2> */
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;
	Graph->Ne++;

	//PtrToAdjVode NewNode1 = new struct AdjVNode;
	///* ��������ͼ��˵���������<V2,V1> */
	//NewNode1->AdjV = E->V1;
	//NewNode1->Weight = E->Weight;
	//NewNode1->Next = Graph->G[E->V2].FirstEdge;
	//Graph->G[E->V2].FirstEdge = NewNode1;
	//Graph->Ne++;
}

Edge InsertE(VertexNum V1, VertexNum V2, WeightType Weight)
{
	Edge E = new struct ENode;
	E->V1 = V1;
	E->V2 = V2;
	E->Weight = Weight;

	return E;
}

void Visit(VertexNum V)
{
	cout << "��ǰ���ʵĽ��Ϊ" << V << endl;
}

/* ����������� */
void BFS(LGraph Graph, VertexNum V)  /* ��Ҫ�õ����� */
{
	VertexNum U;
	PtrToAdjVode W;
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
				visited[W->AdjV] = true;  /* ������λ����λ */
			}
		}
	}
}

/* ����������� */
void DFS(LGraph G, VertexNum V)
{
	PtrToAdjVode W;
	visited[V] = true;
	Visit(V);
	for (W = G->G[V].FirstEdge; W; W = W->Next)
	{
		if (!visited[W->AdjV])  /* �����ǰ���δ�����ʣ��������еݹ����� */
		{
			DFS(G, W->AdjV);  /* ����ʽ�ṹ���еݹ���� */
			visited[W->AdjV] = true;  /* ������λ����λ */
		}	
	}
}