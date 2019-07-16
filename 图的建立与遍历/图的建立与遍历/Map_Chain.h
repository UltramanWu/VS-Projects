#include<iostream>
#include"Chain.h"
using namespace std;

#define MaxVertexNum 100  /* ��󶥵�����Ϊ100 */
#define INFINITY 65535  /* ��������Ϊ˫�ֽ��޷������������ֵ65535 */
typedef int Vertex;  /* �ö����±��ʾ���㣬Ϊ���� */
typedef int WeightType;  /* �ߵ�ȨֵΪ���� */
typedef char DataType;
bool Visited[MaxVertexNum]; /* �����ʱ�־λ */

/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1, V2;  /* �����<V1,V2> */
	WeightType Weight;    /* Ȩ�� */
};
typedef PtrToENode  Edge;


/* �ڽӵ�Ķ��� */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
	Vertex AdjV;     /* �ڽӵ��±� */
	WeightType Weight;  /* ��Ȩ�� */
	PtrToAdjVNode Next;  /* ָ����һ���ڽӵ��ָ�� */
};

/* �����ͷ���Ķ��� */
typedef struct VNode{
	PtrToAdjVNode FirstEdge;   /* �߱�ͷָ�� */
	DataType Data;    /* �涥������� */
	/* �ںܶ�����£����������ݣ���ʱData���Բ����� */
}AdjList[MaxVertexNum];    /* ������ͷ���� */

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;         /* ������*/
	int Ne;         /* ���� */
	AdjList G;     /*�ڽӱ�*/
};
typedef PtrToGNode LGraph;  /* ���ڽӱ�ʽ�洢��ͼ���� */

LGraph CreateGraph(int VertexNum)
{ /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
	Vertex V;
	LGraph Graph;
	Graph = new struct GNode;
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* ��ʼ���ڽӱ�ͷָ�� */
	for (V = 0; V < Graph->Nv; V++)
		(Graph->G[Graph->Nv]).FirstEdge = NULL;

	return Graph;
}

/* ������ */
void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;

	/* ����� <V1,V2> */
	/* ΪV2�����µ��ڽӵ� */
	NewNode = new struct AdjVNode;
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	/* ��V2���뵽V1�ı�ͷ */
	/* ��ǰ����*/
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;


	/* ��������ͼ����Ҫ�����<V2,V1> */
	/* ΪV1�����µ��ڽӵ� */
	NewNode = new struct AdjVNode;
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	/* ��V1���뵽V2�ı�ͷ */
	/* ��ǰ���� */
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;

}


void Visit(Vertex V)
{
	cout << "��ǰ���ʵĽ��Ϊ" << V << endl;
}

/* ����������� */
void BFS(LGraph G,Vertex V)
{
	Vertex U;
	PtrToAdjVNode  W;
	Queue Q = Creat_Queue();
	Add_Q(Q, V);

	if (!IsEmpty_Q(Q))  /* ���зǿ� */
	{
		U = Delete_Q(Q);  /* Ԫ�س���*/
		Visit(U);  /* ���ʸý�� */
		for (W = G->G[U].FirstEdge; W; W = W->Next)
		{
			if (!Visited[W->AdjV])   /* �����ǰ���û�б����ʹ� */
			{
				Add_Q(Q, W->AdjV);  /* ���Ԫ�� */
				Visited[W->AdjV] = true;  /* ����Ѿ������� */
			}
		}
	}  /* ����Ϊ�� */
}

/* ����������� */
void DFS(LGraph G, Vertex V)
{
	PtrToAdjVNode W;
	Visit(V);
	Visited[V] = true;  /* ��ǰ�����ΪTRUE�����Ϊ�ѱ����� */
	for (W = G->G[V].FirstEdge; W; W = W->Next)  /* ��V��ÿ���ڽӵ�W->AdjV ���з��� */
	{
		if (!Visited[W->AdjV])  /* �����ǰ���û�б����ʹ� */
		{
			DFS(G, W->AdjV);  /* ����ʽ�ṹ���еݹ���� */
		}
	}

}