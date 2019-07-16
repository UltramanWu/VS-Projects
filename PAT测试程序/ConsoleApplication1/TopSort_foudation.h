#include<iostream>
using namespace std;


typedef int Vertex;
typedef int WeightType;
const int MaxVertexNum = 100;
const int Infinity = 65535;

typedef struct ENode *Edge;
struct ENode{
	Vertex V1, V2;  /* 结点 */
	WeightType Weight;  /* 权重 */
};

typedef struct AdjVNode  *PtrToAdjVNode;
struct AdjVNode{
	Vertex AdjV;  /* 邻接点下标 */
	WeightType Weight;  /* 权重  */
	PtrToAdjVNode next;  /* 指向下一点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct VNode{
	PtrToAdjVNode FirstEdge;
}AdjList[MaxVertexNum];

typedef struct GNode *LGraph;
struct GNode{
	int Ne;  /* 边总数 */
	int Nv;  /* 顶点总数 */
	AdjList G;  /* 邻接表 */
};

/* 创建以邻接表表示的单向图 */
LGraph CreateLGraph(int Vertex)
{
	LGraph LG = new struct GNode;
	LG->Ne = 0;
	LG->Nv = Vertex;
	for (int i = 0; i < Vertex; i++)  /* 邻接表初始化 */
	{
		LG->G[i].FirstEdge = NULL;
	}
	return LG;
}

/* 插入结点 */
void InsertEdge(LGraph LG, Edge E)
{
	PtrToAdjVNode NewNode = new struct AdjVNode;  /* 创建新的结点 */
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	NewNode->next = LG->G[E->V1].FirstEdge;
	LG->G[E->V1].FirstEdge = NewNode;
}



/* 队列相关操作 */
int QueueSize = 0;
int QCount = 0;
struct Node{
	int Data;
	struct Node *next;
};

struct QNode{
	Node *front;  /* 头结点 */
	Node *rear;   /* 尾节点 */
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
		Q->rear->next = NewNode;  /* 尾结点后移 */
		Q->rear = NewNode;
	}

	
	QueueSize++;  /* 队列规模加1 */
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
	delete(DelNode);  /* 释放空间 */
	QueueSize--;
	return DelItem;
}