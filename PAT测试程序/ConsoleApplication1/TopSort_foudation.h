#include<iostream>
using namespace std;


typedef int Vertex;
typedef int WeightType;
const int MaxVertexNum = 100;
const int Infinity = 65535;

typedef struct ENode *Edge;
struct ENode{
	Vertex V1, V2;  /* ��� */
	WeightType Weight;  /* Ȩ�� */
};

typedef struct AdjVNode  *PtrToAdjVNode;
struct AdjVNode{
	Vertex AdjV;  /* �ڽӵ��±� */
	WeightType Weight;  /* Ȩ��  */
	PtrToAdjVNode next;  /* ָ����һ���ָ�� */
};

/* �����ͷ���Ķ��� */
typedef struct VNode{
	PtrToAdjVNode FirstEdge;
}AdjList[MaxVertexNum];

typedef struct GNode *LGraph;
struct GNode{
	int Ne;  /* ������ */
	int Nv;  /* �������� */
	AdjList G;  /* �ڽӱ� */
};

/* �������ڽӱ��ʾ�ĵ���ͼ */
LGraph CreateLGraph(int Vertex)
{
	LGraph LG = new struct GNode;
	LG->Ne = 0;
	LG->Nv = Vertex;
	for (int i = 0; i < Vertex; i++)  /* �ڽӱ��ʼ�� */
	{
		LG->G[i].FirstEdge = NULL;
	}
	return LG;
}

/* ������ */
void InsertEdge(LGraph LG, Edge E)
{
	PtrToAdjVNode NewNode = new struct AdjVNode;  /* �����µĽ�� */
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	NewNode->next = LG->G[E->V1].FirstEdge;
	LG->G[E->V1].FirstEdge = NewNode;
}



/* ������ز��� */
int QueueSize = 0;
int QCount = 0;
struct Node{
	int Data;
	struct Node *next;
};

struct QNode{
	Node *front;  /* ͷ��� */
	Node *rear;   /* β�ڵ� */
};

typedef struct QNode *Queue;

Queue CreateQ( )
{
	Queue Q = new struct QNode;
	Q->front = new struct Node;
	Q->rear = new struct Node;
	Q->front->next = NULL;
	Q->rear->next = NULL;

	return Q;
}

bool IsEmpty(Queue Q)
{
	if (Q->front == NULL)
		return 1;
	return 0;
}

void EntryQ(Queue Q,int Item)
{
	Node* NewNode = new struct Node;
	NewNode->Data = Item;
	NewNode->next = NULL;
	
	if (QueueSize == 0)
	{
		Q->front = NewNode;
		Q->rear = NewNode;
	}
	else{
		Q->rear->next = NewNode;  /* β������ */
		Q->rear = NewNode;
	}

	
	QueueSize++;  /* ���й�ģ��1 */
}

int OutQ(Queue Q)
{
	Node *DelNode;
	int DelItem;
	
	DelNode = Q->front;
	if (Q->front == Q->rear)
		Q->front = Q->rear = NULL;
	else
		Q->front = DelNode->next;
	DelItem = DelNode->Data;
	delete(DelNode);  /* �ͷſռ� */
	QueueSize--;
	return DelItem;
}