#include"Chain_Map.h"

/* ---------------------顶点并查集定义--------------------- */
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MaxVertexNum];

void InitializeVSet(SetType S, int N)
{/* 初始化并查集 */
	ElementType X;
	for (X = 0; X < N; X++)
		S[X] = -1;
}

/* 并集操作 */
void Union(SetType S, SetName Root1, SetName Root2)
{/* 这里默认Root1和Root2是不同集合的根结点 */
	if (S[Root1] > S[Root2])  /* 如果集合2比较大 */
	{
		S[Root2] += S[Root1];  /* 集合1并入集合2中 */
		S[Root1] = Root2;
	}
	else{
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}

SetName Find(SetType S, ElementType X)
{/* 默认集合元素全部初始化为-1 */
	if (S[X] < 0)
		return X;
	else 
		return S[X] = Find(S, S[X]);  /* 路径压缩 */
}

bool CheckCycle(SetType VSet, VertexNum V1, VertexNum V2)
{/* 检查连接V1和V2的边是否在现有的最小生成树子集中构成回路 */
	VertexNum Root1, Root2;
	Root1 = Find(VSet, V1);
	Root2 = Find(VSet, V2);

	if (Root1 == Root2)
		return false;
	else
	{
		Union(VSet, Root1, Root2);
		return true;
	}
}
/* ------------------并查集定义结束--------------------- */



/* ------------------边的最小堆定义--------------------- */
void  PercDown(LEdge ESet, int p, int N)
{
	int Parents, Child;
	struct LENode X ;
	X = ESet[p];

	for ( Parents = p ; (Parents*2+1) < N; Parents = Child)
	{
		Child = Parents * 2 + 1;
		if ((Child != N - 1) && (ESet[Child].Weight>ESet[Child + 1].Weight))  
			Child++;  /* Child 指向左右子结点的较小者 */
		if (X.Weight <= ESet[Child].Weight)  break;  /* 找到合适的位置 */
		else
			ESet[ Parents ] = ESet[ Child ];
	}
	ESet[Parents] = X;
}


void Swap(LEdge Source, LEdge Destination)
{
	LENode temp;
	temp = *Source;
	*Source = *Destination;
	*Destination = temp;
}

void InitializeESet(LGraph LG, LEdge ESet)
{/* 将图中的边存入数组Eset，并且初始化为最小堆 */
	VertexNum V;
	PtrToAdjVNode W;  /* */
	int ECount;

	/* 将图中的边存入数组ESet中 */
	ECount = 0;
	for ( V = 0; V < LG->Nv; V++)
	{
		for ( W = LG->G[V].FirstEdge; W ; W = W->Next )
		{
			if (V < W->AdjV){  /* 避免重复录入无向图的边，只收录V1<V2的边 */
				(ESet)[ECount].V1 = V;
				(ESet)[ECount].V2 = W->AdjV;
				(ESet)[ECount++].Weight = W->Weight;
			}
				
		}
	}
	/* 初始化为最小堆 */
	for (ECount = LG->Ne/2; ECount >=0; ECount--)
		PercDown( ESet, ECount, LG->Ne );
}

int GetEdge(LEdge ESet, int CurrentSize)
{/* 给定当前堆的大小CurrentSize，将当前最小边位置弹出并调整堆*/

	/* 将最小边与当前堆的最后一个位置的边交换 */
	Swap(&ESet[0], &ESet[CurrentSize-1]);

	/* 将剩余的边继续调整为最小堆 */
	PercDown(ESet, 0, CurrentSize - 1);

	/* 返回最小堆的堆顶元素*/
	return CurrentSize - 1;
}


/* ---------------最小堆定义结束-----------------*/

void InsertEdge_Kruksal(LGraph LG, LEdge E)
{
	PtrToAdjVNode Kruskal_Node = new struct AdjVNode[2];

	/* 插入<V1,V2> */
	Kruskal_Node->AdjV = E->V2;
	Kruskal_Node->Weight = E->Weight;
	Kruskal_Node->Next = LG->G[E->V1].FirstEdge;
	LG->G[E->V1].FirstEdge = Kruskal_Node;

	/* 插入<V2,V1> */
	/*
	Kruskal_Node->AdjV = E->V1;
	Kruskal_Node->Weight = E->Weight;
	Kruskal_Node->Next = LG->G[E->V2].FirstEdge;
	LG->G[E->V2].FirstEdge = Kruskal_Node;
	*/

	LG->Ne++;
 }





/* 具体算法实现 */

int Kruskal(LGraph LG, LGraph MST)
{/* 将最小生成树保存为邻接表存储的图MST，返回最小权重和 */
	WeightType TotalWeight;
	int ECount, NextEdge;
	SetType VSet;
	LEdge ESet;

	/* 初始化顶点并查集 */
	InitializeVSet(VSet, LG->Nv);
	
	ESet = new struct LENode;
	InitializeESet(LG, ESet);

	/* 创建包含所有顶点但没有边的图，邻接表形式 */
	//MST = CreateGraph(LG->Nv);
	TotalWeight = 0;
	ECount = 0;

	NextEdge = LG->Ne; /* 原始边集的规模 */
	while (ECount < LG->Nv - 1)
	{
		NextEdge = GetEdge(ESet, NextEdge);

		if (NextEdge < 0)
			break;
		if (CheckCycle(VSet,ESet[NextEdge].V1,ESet[NextEdge].V2))
		{
			/* 将该边插入到MST */
			InsertEdge_Kruksal(MST, ESet + NextEdge);
			TotalWeight += ESet[NextEdge].Weight;
			ECount++;
		}

	}
	if (ECount < LG->Nv - 1)
		TotalWeight = -1;

	delete(LG);
	return TotalWeight;
}
