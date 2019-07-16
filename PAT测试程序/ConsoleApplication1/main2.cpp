//#include<iostream>
//using namespace std;
//
//#define MaxVertexNum 500  /* ��������� */
//#define INFINITY 65535
//typedef int Vertex;
//typedef int LengthType;  /* ·������ */
//typedef int MoneyType;  /* �շ��ܶ� */
//
//struct ENode{
//	Vertex V1;
//	Vertex V2;
//	LengthType length;  /* ·������ */
//	MoneyType Money;  /* �շ��ܶ� */
//};
//typedef struct ENode* Edge;
//
//struct GNode{
//	int Nv;
//	int Ne;
//	int L[MaxVertexNum][MaxVertexNum];  /* ·�����Ⱦ��� */
//	int M[MaxVertexNum][MaxVertexNum];  /* �ķ�·�Ѿ��� */
//};
//typedef struct GNode* MGraph;
//
//MGraph CreateGraph(int N)
//{
//	MGraph MG = new struct GNode;
//	MG->Nv = N;
//	MG->Ne = 0;
//	for (int j = 0; j<N; j++)
//		for (int i = 0; i<N; i++)
//		{
//			MG->L[j][i] = INFINITY;
//			MG->M[j][i] = INFINITY;
//		}
//
//	return MG;
//}
//
//void InsertEdge(MGraph MG, Edge E)
//{
//	MG->L[E->V1][E->V2] = E->length;
//	//MG->L[E->V2][E->V1] = E->length;
//
//	MG->M[E->V1][E->V2] = E->Money;
//	//MG->M[E->V2][E->V1] = E->Money;
//}
//
//
//Vertex FindMin(MGraph MG, int dist[], bool collected[])
//{
//	Vertex V;
//	LengthType Mindist = INFINITY;
//	Vertex MinV = -1;
//	for (V = 0; V < MG->Nv; V++)
//		if (collected[V] == false && dist[V]<Mindist)
//		{
//			Mindist = dist[V];
//			MinV = V;
//		}
//	if (dist[MinV] < INFINITY){
//		if (dist[MinV] < 0)
//			return -1;
//		else
//			return MinV;
//	}
//	return -2;
//}
//
//
//bool Dijkstra(MGraph MG, int dist[], int path[],int Cost[], Vertex S)
//{
//	bool collected[MaxVertexNum];    /* ����ռ����� */
//	Vertex V, W;
//	for (V = 0; V < MG->Nv; V++){
//		dist[V] = MG->L[S][V];  /* ������ֵ���뵽���������� */
//		Cost[V] = MG->M[S][V]; /* ��·��ֵ���뵽���������� */
//		collected[V] = false;  /* �����е���������Ϊδ�ռ� */
//
//		if (dist[V] < INFINITY)
//			path[V] = S;   /* ��ֱ������Դ�ڵ�Ľ��ֱ�Ӹ�ֵ */
//		else
//			path[V] = -1;
//	}
//	/* ��Դ�ڵ���뵽·�����������ռ�����ĸ�λ��λ */
//	dist[S] = 0;
//	collected[S] = true;
//	while (1)
//	{
//		V = FindMin(MG, dist, collected);  /* ȡ�þ�����Сֵ�����±� */
//		if ((V == -1) || (V == -2))  /* ���õ㲻����ʱ��ֱ���˳� */
//			break;
//		collected[V] = true;  /* ��¼V */
//		for (W = 0; W < MG->Nv; W++)  /* ��ͼ�е�ÿһ������*/
//		{
//			if (collected[W] == false && MG->L[V][W] < INFINITY)
//			{
//				if (MG->L[V][W] < 0)  /* ���ܴ��ڸ��� */
//					return false;  /* ���ܹ���ȷ��������ش����� */
//				if (dist[V] + MG->L[V][W] < dist[W]){
//					dist[W] = dist[V] + MG->L[V][W];   /* ����dist[W]*/
//					path[W] = V;  /* ����S��W��·�� */
//					Cost[W] = Cost[V] + MG->M[V][W];
//				}
//				else if ((dist[V] + MG->L[V][W] == dist[W]) && (Cost[W] > Cost[V] + MG->M[V][W]))
//				{
//					Cost[W] = Cost[V] + MG->M[V][W];
//					path[W] = V;  /* ����S��W��·�� */
//				}
//			}
//		}
//	}  /* while ѭ������ */
//	return true; /* �㷨ִ����ϣ�������ȷ��� */
//}
//
//void Floyd(MGraph MG, int Path[][MaxVertexNum])
//{
//	Vertex i, j, k;
//	for (i = 0; i< MG->Nv; i++)  /* ��·��������г�ʼ�� */
//		for (j = 0; j<MG->Nv; j++)
//		{
//			if (MG->L[i][j]<INFINITY)
//				Path[i][j] = i;
//			else
//				Path[i][j] = -1;
//		}
//	for (i = 0; i< MG->Nv; i++)
//		for (j = 0; j<MG->Nv; j++)
//			for (k = 0; k<MG->Nv; k++)
//			{
//				if (i == j) continue;
//				if (MG->L[i][k] + MG->L[k][j] < MG->L[i][j])
//				{
//					MG->L[i][j] = MG->L[i][k] + MG->L[k][j];
//					MG->M[i][j] = MG->M[i][k] + MG->M[k][j];  /* ����·�Ѿ���Ԫ�ؽ��и��� */
//					Path[i][j] = k;
//				}
//				else if (MG->L[i][k] + MG->L[k][j] == MG->L[i][j])
//				{
//					if (MG->M[i][j] > MG->M[i][k] + MG->M[k][j])  /*���·��������ͬ����·�Ѳ�ͬ�Ļ�������С·�ѵ�����*/
//					{
//						MG->M[i][j] = MG->M[i][k] + MG->M[k][j];  /* ����·�Ѿ���Ԫ�ؽ��и��� */
//						Path[i][j] = k;
//					}
//				}
//			}
//}
//
//
//int main()
//{
//	int N, M, S, D;
//	int Path[MaxVertexNum];
//	int Cost[MaxVertexNum];
//	int Path1[MaxVertexNum][MaxVertexNum];
//	int dist[MaxVertexNum];
//	cin >> N >> M >> S >> D;
//	if (N == 2)
//	{
//		Edge E = new struct ENode;
//		cin >> E->V1 >> E->V2 >> E->length >> E->Money;
//		cout << E->length << E->Money;
//	}
//	if (N>2 && N <= 500)
//	{
//		MGraph MG = CreateGraph(N);
//		while (M--)
//		{
//			Edge E = new struct ENode;
//			cin >> E->V1 >> E->V2 >> E->length >> E->Money;
//			InsertEdge(MG, E);  /* ����� */
//		}  /* �����ڽӾ������ */
//
//		Dijkstra(MG, dist, Path, Cost,S);
//		//Floyd(MG,Path1);
//		//cout << MG->L[S][D] << " " << MG->M[S][D] << endl;
//		cout << dist[D] << " " << Cost[D] << endl;
//	}
//
//	return 0;
//}