#include<iostream>
using namespace std;
#include"Chain_Queue.h"

#define MaxVertexNum 100
#define INFINITY 65535
typedef int VertexNum;
typedef int WeightType;
typedef int DataType;

struct ENode{
	VertexNum V1, V2;     /* ������ */
	WeightType Weight;   /* Ȩ�� */
};

typedef struct ENode *Edge;

struct GNode{
	int Ne;  /* �߸��� */
	int Nv;  /* ������ */
	WeightType G[MaxVertexNum][MaxVertexNum];  /* Ȩ���ڽӾ��� */
	DataType Data[MaxVertexNum];  /* ������� */
};

/* �����ڽӾ��󣬲��Ծ�����Ԫ�ؽ��г�ʼ�� */
typedef  struct GNode *MGraph;
MGraph CreatMGraph(int VertexNum)
{
	MGraph MG = new struct GNode;  
	MG->Nv = VertexNum;
	MG->Ne = 0;
	for (int i = 0; i < MG->Nv+1; i++)  /* ���ڽӾ�����г�ʼ�� ,INFINITY��ʾ�������֮��û������ */
		for (int j = 0; j < MG->Nv + 1; j++)
				MG->G[i][j] = INFINITY;

	return MG;
}

/* �Դ����õ��ڽӾ���Ȩ�ؽ������� */
void ChangeWeight(MGraph *G,VertexNum V, VertexNum W, WeightType Weight)
{
	if (Weight > 0 && Weight < INFINITY)
	{
		(*G)->G[V][W] = Weight;   /* ֻ�е���Ľ������ */
		(*G)->G[W][V] = Weight;   /* ������һ����Ľ������ */
	}
	else  /* ���Ȩ��Ϊ�������߸�ֵ�����ֱ�ӷ��� */
		return;
}

/* ���ҳ���ǰȨ����������СȨ�ض�Ӧ��Ԫ�� */
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

/* ��Ȩ��Դ���·���㷨 */
bool Dijkstra(MGraph Graph, int dist[], int path[], VertexNum S)
{
	bool collected[MaxVertexNum];    /* ����ռ����� */
	VertexNum V,W;
	for (V = 1; V < Graph->Nv+1; V++){
		dist[V] = Graph->G[S][V];  /* ��Ȩ��ֵ���뵽���������� */
		collected[V] = false;  /* �����е���������Ϊδ�ռ� */
		if (V == S)  /* �Խ��ߵ�Ԫ�����⴦�� */
		{
			path[V] = -1;
			continue;
		}
		if (dist[V] < INFINITY)
			path[V] = S;   /* ��ֱ������Դ�ڵ�Ľ��ֱ�Ӹ�ֵ */ 
		else
			path[V] = -1;
	}
	/* ��Դ�ڵ���뵽·�����������ռ�����ĸ�λ��λ */
	dist[S] = 0;
	collected[S] = true;  
	while (1){
		V = FindMin(Graph, dist, collected);  /* ȡ�þ�����Сֵ�����±� */
		if ((V == -1) || (V == -2))  /* ���õ㲻����ʱ��ֱ���˳� */
			break; 
		collected[V] = true;  /* ��¼V */
		for (W = 0; W < Graph->Nv+1; W++)  /* ��ͼ�е�ÿһ������*/
		{
			if (collected[W] == false && Graph->G[V][W] < INFINITY){
				if (Graph->G[V][W] < 0)  /* ���ܴ��ڸ��� */
					return false;  /* ���ܹ���ȷ��������ش����� */

				if (dist[V] + Graph->G[V][W] < dist[W]){
					dist[W] = dist[V] + Graph->G[V][W];   /* ����dist[W]*/
					path[W] = V;  /* ����S��W��·�� */
				}
			}	
		}
	}  /* while ѭ������ */
	return true; /* �㷨ִ����ϣ�������ȷ��� */
}

/* ��ӡ·��ֵ */
void Print_Path(MGraph G ,int path[],VertexNum V)
{
	int PathNum = 0;  /* �ֲ�������Ҫ���г�ʼ��*/
	int time = 0;
	Stack S = CreateS();  /* ������ջ */
	VertexNum W;
	PushS(S, V);  /* �Ƚ�Ŀ�Ľڵ����ѹջ */
	for (W = V; path[W] != -1; W = path[W])
	{
		PushS(S, path[W]);  /* ����ǰֵѹջ */
		PathNum += G->G[path[W]][W];
	}
	while (!IsEmptyS(S))  /* ��ѹ��ջ�ڵ�Ԫ�ص��򵯳� */
	{
		if (time > 0)
			cout << "->";
			cout << PopS(S);
			time++;
	}
	cout << endl;
	cout << "PathNum: " << PathNum << endl;  /* ��ӡ·������ */
}


/* �����Ȩ��Դ���·����Floyd�㷨 */
bool floyd(MGraph G , WeightType D[][MaxVertexNum],int Path[][MaxVertexNum])
{
	VertexNum i, j, k;

	/* ��ʼ�� */
	for ( i = 0; i <= G->Nv; i++)
		for ( j = 0; j <= G->Nv; j++)
		{
			D[i][j] = G->G[i][j];
			if (i == j){  /* �����ڶԽ����ϵ�Ȩ�غ�·��ֵ������ */
				Path[i][j] = -1;
				continue;
			}
			if (D[i][j] < INFINITY)  /* �������֮�����·�� */
				Path[i][j] = i;
			else
				Path[i][j] = -1;
		}
	
	/* �㷨ʵ�� */
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
					if (D[i][j] < 0)  /* �����ָ�ֵȦ */
						return false;
					Path[i][j] = k;  /* ��ȥi�󣬺���Ȩ��Դ���·��һ�� */
				}
			}
	return true;
}

/* ��ӡԴ�ڵ���Ŀ�Ľڵ��·�������·������ */
void Print_Multi_Path(WeightType D[][MaxVertexNum], int Path[][MaxVertexNum],VertexNum Source, VertexNum Destinate)
{
	VertexNum V;
	int time = 0;
	int PathNum = 0;
	if (Path[Source][Destinate] == -1){
		cout << "����֮��û��·����" << endl;
		return;
	}
	Stack S = CreateS();  /*  ������ջ */
	PushS(S, Destinate);  /* ��Ŀ�ĵ�ѹջ */
	for (V = Destinate; Path[Source][V] != -1; V = Path[Source][V])
	{
		PushS(S, Path[Source][V]);  /* ��·����ѹջ */
		PathNum += D[Path[Source][V]][V];  /* ��Ȩ��ֵ��� */
	}

	while (!IsEmptyS(S))
	{
		if (time > 0)
			cout << "->";
		cout << PopS(S);
		time++;
	}
	cout << endl;
	cout << "PathNum:" << PathNum;  /* ��ӡ·������ */

}