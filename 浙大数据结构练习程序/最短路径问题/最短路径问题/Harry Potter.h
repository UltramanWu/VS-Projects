#include"Array_Map.h"



/* �����ڽӾ���ͼ */
MGraph BuildGraph()
{
	int NV,NE;
	Edge E = new struct ENode;
	MGraph G;
	cin >> NV >> NE;
	if (NV > 0)
		 G = CreatMGraph(NV);
	else
		return NULL;
	for (int i = 0; i < NE; i++)
	{
		cin >> E->V1 >> E->V2 >> E->Weight;  /* �������� */
		E->V1--; E->V2--;
		ChangeWeight(&G, E->V1, E->V2, E->Weight);  /* ��������λ */
	}

	return G;
}

/* ����ͬһ���ڵ�������Ԫ�� */
int FindMaxDist(MGraph MG,int  D[][MaxVertexNum], VertexNum V)
{
	int MaxDist = 0;
	for (int i = 0; i < MG->Nv; i++)
	{
		if (D[V][i] < INFINITY && D[V][i] >0)
		{
			if (D[V][i] >MaxDist)
				MaxDist = D[V][i];
		}
	}
	return MaxDist;
}

/* ���Ҷ�Ӧͼ�е��ʺ�Ԫ�� */
int FindAnimal(MGraph G)
{
	int Path[MaxVertexNum][MaxVertexNum];  /* ·������*/
	int D[MaxVertexNum][MaxVertexNum];  /* Ȩ�ؾ���*/
	
	int MaxDist = 0;
	int MinDist = INFINITY;
	VertexNum V = 0;
	floyd(G, D, Path);
	for (int i = 0; i < G->Nv; i++)
	{
		 MaxDist = FindMaxDist(G,D, i);

		if (MaxDist<0 || MaxDist >= INFINITY)
			return NULL;

		if (MinDist > MaxDist)
		{
			MinDist = MaxDist;
			V = i;
		}
	}
	return V + 1;
}

