#include"Chain_Map.h"



/* 存储距离值和路径值的结构体 */
struct  VertexData
{
	int Path[MaxVertexNum];
	int dist[MaxVertexNum];
}Vertex;

/* 对结构体进行初始化 */
void Init(VertexData *Vertex)
{
	for (int i = 0; i < MaxVertexNum ; i++)
	{
		Vertex->Path[i] = -1;  /* 将所有结点都设置为源节点 Source*/
		Vertex->dist[i] = INFINITY;  /* 将距离值设置为最大值 */
	}
}

/* 求解从源结点开始的无权图最短路径，默认所有的路径权重为1 */
void UWeight(LGraph G, VertexNum Source, VertexData *Vertex)
{
	VertexNum U;
	PtrToAdjVode W;
	Queue Q = CreateQ();

	EnQueue(Q, Source); 
	while (!IsEmptyQ(Q))  /* 如果队列非空 */
	{
		U = DeQueue(Q);
		Vertex->dist[U] = 0;  /* 将源节点的距离设置为0 */
		for (W = G->G[U].FirstEdge; W != NULL; W = W->Next)  /* 对邻接表进行BFS遍历 */
		{
			if (Vertex->Path[W->AdjV] == -1 && W->AdjV != Source) /* 当结点不是源节点且不为独立结点 */
			{
				Vertex->dist[W->AdjV] = Vertex->dist[U] + 1;   /* 在其源节点的基础上加1 */
				Vertex->Path[W->AdjV] = U;  /* 将路径改为源节点路径 */
				EnQueue(Q, W->AdjV);
			}
		}
	}
}


/* 打印制定路径 */
void Print_Path(VertexData *VT , VertexNum Dest )
{
	int time = 0;  /* 局部变量需要进行初始化 */
	Stack S = CreateS();  /* 创建堆栈 */
	PushS(S, Dest);  /* 将目的结点序号压栈 */
	for (int i = Dest ; VT->Path[i] != -1; i = VT->Path[i])  /* 向路径中的无向图 */
	{/* 将对应的path数据存储到数据中 */
		PushS(S, VT->Path[i]);
	}

	while (!IsEmptyS(S))  /* 将堆栈内的结点数据弹出并输出 */
	{
		if (time > 0)
			cout << "->";
			cout << PopS(S);
			time++;
	}
	cout << endl;
	cout << "PathNum:" << VT->dist[Dest] << endl;  /* 打印路径长度，即dist数组中的数据 */
}