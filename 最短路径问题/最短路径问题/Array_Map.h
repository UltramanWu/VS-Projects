#include<iostream>
using namespace std;
#include"Chain_Queue.h"

#define MaxVertexNum 100
#define INFINITY 65535
typedef int VertexNum;
typedef int WeightType;
typedef int DataType;

struct ENode{
	VertexNum V1, V2;     /* 矩阵结点 */
	WeightType Weight;   /* 权重 */
};

typedef struct ENode *Edge;

struct GNode{
	int Ne;  /* 边个数 */
	int Nv;  /* 结点个数 */
	WeightType G[MaxVertexNum][MaxVertexNum];  /* 权重邻接矩阵 */
	DataType Data[MaxVertexNum];  /* 结点数据 */
};

/* 创建邻接矩阵，并对矩阵内元素进行初始化 */
typedef  struct GNode *MGraph;
MGraph CreatMGraph(int VertexNum)
{
	MGraph MG = new struct GNode;  
	MG->Nv = VertexNum;
	MG->Ne = 0;
	for (int i = 0; i < MG->Nv+1; i++)  /* 对邻接矩阵进行初始化 ,INFINITY表示两个结点之间没有连接 */
		for (int j = 0; j < MG->Nv + 1; j++)
				MG->G[i][j] = INFINITY;

	return MG;
}

/* 对创建好的邻接矩阵权重进行设置 */
void ChangeWeight(MGraph *G,VertexNum V, VertexNum W, WeightType Weight)
{
	if (Weight > 0 && Weight < INFINITY)
	{
		(*G)->G[V][W] = Weight;   /* 只有单向的结点连接 */
		(*G)->G[W][V] = Weight;   /* 增加另一方向的结点连接 */
	}
	else  /* 如果权重为负数或者赋值溢出，直接返回 */
		return;
}

/* 查找出当前权重数组中最小权重对应的元素 */
VertexNum FindMin(MGraph G, int dist[], bool collected[])
{
	VertexNum V;
	WeightType Mindist = INFINITY;
	VertexNum MinV = 0;
	for (V = 0; V < G->Nv+1;V++)
	if (collected[V] == false && dist[V]<Mindist)
	{
		Mindist = dist[V];
		MinV = V;
	}
	if (dist[MinV] < INFINITY){
		if (dist[MinV] < 0)
			return -1;
		else
			return MinV;
	}
	return -2;
}

/* 有权单源最短路径算法 */
bool Dijkstra(MGraph Graph, int dist[], int path[], VertexNum S)
{
	bool collected[MaxVertexNum];    /* 标记收集数组 */
	VertexNum V,W;
	for (V = 1; V < Graph->Nv+1; V++){
		dist[V] = Graph->G[S][V];  /* 将权重值加入到距离数组中 */
		collected[V] = false;  /* 将所有的数据设置为未收集 */
		if (V == S)  /* 对角线的元素特殊处理 */
		{
			path[V] = -1;
			continue;
		}
		if (dist[V] < INFINITY)
			path[V] = S;   /* 对直接连接源节点的结点直接赋值 */ 
		else
			path[V] = -1;
	}
	/* 将源节点存入到路径数组中且收集数组的该位置位 */
	dist[S] = 0;
	collected[S] = true;  
	while (1){
		V = FindMin(Graph, dist, collected);  /* 取得距离最小值所在下标 */
		if ((V == -1) || (V == -2))  /* 当该点不存在时，直接退出 */
			break; 
		collected[V] = true;  /* 收录V */
		for (W = 0; W < Graph->Nv+1; W++)  /* 对图中的每一个顶点*/
		{
			if (collected[W] == false && Graph->G[V][W] < INFINITY){
				if (Graph->G[V][W] < 0)  /* 不能存在负边 */
					return false;  /* 不能够正确解决，返回错误标记 */

				if (dist[V] + Graph->G[V][W] < dist[W]){
					dist[W] = dist[V] + Graph->G[V][W];   /* 更新dist[W]*/
					path[W] = V;  /* 更新S到W的路径 */
				}
			}	
		}
	}  /* while 循环结束 */
	return true; /* 算法执行完毕，返回正确标记 */
}

/* 打印路径值 */
void Print_Path(MGraph G ,int path[],VertexNum V)
{
	int PathNum = 0;  /* 局部变量需要进行初始化*/
	int time = 0;
	Stack S = CreateS();  /* 创建堆栈 */
	VertexNum W;
	PushS(S, V);  /* 先将目的节点序号压栈 */
	for (W = V; path[W] != -1; W = path[W])
	{
		PushS(S, path[W]);  /* 将当前值压栈 */
		PathNum += G->G[path[W]][W];
	}
	while (!IsEmptyS(S))  /* 将压入栈内的元素倒序弹出 */
	{
		if (time > 0)
			cout << "->";
			cout << PopS(S);
			time++;
	}
	cout << endl;
	cout << "PathNum: " << PathNum << endl;  /* 打印路径长度 */
}


/* 针对有权多源最短路径的Floyd算法 */
bool floyd(MGraph G , WeightType D[][MaxVertexNum],int Path[][MaxVertexNum])
{
	VertexNum i, j, k;

	/* 初始化 */
	for ( i = 0; i <= G->Nv; i++)
		for ( j = 0; j <= G->Nv; j++)
		{
			D[i][j] = G->G[i][j];
			if (i == j){  /* 不对在对角线上的权重和路径值做处理 */
				Path[i][j] = -1;
				continue;
			}
			if (D[i][j] < INFINITY)  /* 如果两点之间存在路径 */
				Path[i][j] = i;
			else
				Path[i][j] = -1;
		}
	
	/* 算法实现 */
	for ( k = 0; k <= G->Nv; k++)
		for ( i = 0; i <= G->Nv; i++)
			for ( j = 0; j <= G->Nv; j++)
			{
				if (i == j)
				{
					D[i][j] = INFINITY;
					continue;
				}

				if (D[i][k]+D[k][j]<D[i][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					if (D[i][j] < 0)  /* 若发现负值圈 */
						return false;
					Path[i][j] = k;  /* 除去i后，和有权单源最短路径一致 */
				}
			}
	return true;
}

/* 打印源节点与目的节点的路径并输出路径长度 */
void Print_Multi_Path(WeightType D[][MaxVertexNum], int Path[][MaxVertexNum],VertexNum Source, VertexNum Destinate)
{
	VertexNum V;
	int time = 0;
	int PathNum = 0;
	if (Path[Source][Destinate] == -1){
		cout << "两点之间没有路径！" << endl;
		return;
	}
	Stack S = CreateS();  /*  创建堆栈 */
	PushS(S, Destinate);  /* 将目的点压栈 */
	for (V = Destinate; Path[Source][V] != -1; V = Path[Source][V])
	{
		PushS(S, Path[Source][V]);  /* 将路径点压栈 */
		PathNum += D[Path[Source][V]][V];  /* 将权重值相加 */
	}

	while (!IsEmptyS(S))
	{
		if (time > 0)
			cout << "->";
		cout << PopS(S);
		time++;
	}
	cout << endl;
	cout << "PathNum:" << PathNum;  /* 打印路径长度 */

}