//#include<iostream>
//using namespace std;
///* ��Ϊ��Դ��Ȩ���·�����㷨 */
//typedef int Vertex;
//typedef int WeightType;
//#define INFINITY 65535
//#define MaxVertexNum 100
//
//
//struct ENode{
//	Vertex V1, V2;  /* ���λ�� */
//	WeightType Weight; /* Ȩ�� */
//};
//typedef struct ENode *Edge;
//
//struct GNode{
//	int Nv;
//	int Ne;
//	WeightType G[MaxVertexNum][MaxVertexNum];
//};
//typedef struct GNode *MGraph;
//
///* �����ڽӾ��� */
//MGraph CreateGraph(int VertexNum)
//{
//	MGraph MG = new struct GNode;
//	MG->Ne = 0;
//	MG->Nv = VertexNum;
//	for (int i = 0; i<VertexNum; i++)
//		for (int j = 0; j<VertexNum; j++)
//			MG->G[i][j] = INFINITY;
//
//	return MG;
//}
//
///* ����� */
//void InsertEdge(MGraph MG, Edge E)
//{
//	MG->G[E->V1][E->V2] = E->Weight;
//	MG->G[E->V2][E->V1] = E->Weight;
//	MG->Ne++;
//}
//
//int Floyd(MGraph MG, int Path[][MaxVertexNum])
//{
//	Vertex i, j, k;
//	for (i = 0; i<MG->Nv; i++)  /* ��·��������г�ʼ�� */
//		for (j = 0; j < MG->Nv; j++)
//		{
//			if (MG->G[i][j] < INFINITY)
//				Path[i][j] = i;
//			else
//				Path[i][j] = -1;
//		}
//
//	for (i = 0; i<MG->Nv; i++)
//		for (j = 0; j<MG->Nv; j++)
//			for (k = 0; k<MG->Nv; k++)
//			{
//				if (i == j)  continue;
//				if (MG->G[i][k] + MG->G[k][j] < MG->G[i][j])
//				{
//					MG->G[i][j] = MG->G[i][k] + MG->G[k][j];
//					if (MG->G[i][j] < 0)  /* ���ڸ�ֵȦ�����޷����д��� */
//						return false;
//					Path[i][j] = k;
//				}
//			}
//	return true;
//}
//
//int Check(MGraph MG)
//{
//	int flag = 0;
//	int ECount = 0;
//	Vertex V, W;
//	for (V = 0; V<MG->Nv; V++)
//	{
//		flag = 0;  /* ��־λ��λ */
//		for (W = 0; W<MG->Nv; W++)
//		{
//			if (V == W) continue;
//			if ((!flag) && (MG->G[V][W] >= INFINITY))
//			{
//				flag = 1;  /* ��־λ��λ */
//				ECount++;  /* ����ʱ�� */
//			}
//		}
//	}
//
//	if (ECount >= MG->Nv)  /* ���ÿһ��㶼�в�ͬ��·�������Գ�ͨ */
//		return 0;
//	return 1;
//
//}
//
//int GetMinOfSum(MGraph MG)
//{
//	int Sum = 0;
//	int MinSum = INFINITY;
//	int MinV = -1;
//	Vertex V, W;
//	for (V = 0; V<MG->Nv; V++)
//	{
//		Sum = 0;  /* ��־λ��λ */
//		for (W = 0; W<MG->Nv; W++)
//		{
//			if (V == W) continue;
//			Sum += MG->G[V][W];
//		}
//		if (Sum < MinSum)
//		{
//			MinSum = Sum;
//			MinV = V;
//		}
//	}
//	//*MinS = MinSum;
//	return MinSum;
//}
//
//int main()
//{
//	int N, M;
//	int Path[MaxVertexNum][MaxVertexNum]; /* ·������ */
//	int MinSum;
//	Edge E = new struct ENode;
//	cin >> N >> M;
//	if (N <= MaxVertexNum)
//	{
//		MGraph MG = CreateGraph(N);
//		while (M--)
//		{
//			cin >> E->V1 >> E->V2 >> E->Weight;
//			E->V1--; E->V2--;
//			InsertEdge(MG, E);
//		}
//
//		Floyd(MG, Path);
//		if (Check(MG))
//		{
//			MinSum = GetMinOfSum(MG);
//			cout << MinSum << endl;
//		}
//
//		else
//			cout << -1 << endl;
//	}
//	return 0;
//}
