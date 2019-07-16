//#include<iostream>
//using namespace std;
//
//#define MaxVertexNum 100  /* �涨�����ı����� */
//#define INFINITY 65535
//typedef int Vertex;  /* ����Ԫ������ */
//typedef int WeightType;  /* Ȩ������ */
//
//struct ENode{
//	Vertex V1;  /* �������Ӧ���� */
//	Vertex V2;
//	WeightType Weight;  /* ��Ȩ��*/
//};
//typedef struct ENode *Edge;
//
//struct GNode{
//	int Nv;  /* �������� */
//	int Ne;  /* ������ */
//	int G[MaxVertexNum][MaxVertexNum];  /* Ȩ�ؾ��� */
//};
//typedef struct GNode *MGraph;
//
//
///* �����ڽӾ��� */
//MGraph CreateGraph(int Vertex)
//{
//	MGraph MG = new struct GNode;
//	MG->Nv = Vertex;
//	MG->Ne = 0;
//	for (int i = 0; i< Vertex; i++)
//		for (int j = 0; j<Vertex; j++)
//			MG->G[i][j] = INFINITY;  /* �Ծ������λ�ý��г�ʼ�� */
//	return MG;
//}
//
///* ����� */
//void InsertEdge(MGraph MG, Edge E)
//{
//	/* ����<V1,V2> */
//	MG->G[E->V1][E->V2] = E->Weight;
//	/* ����<V2,V1> */
//	MG->G[E->V2][E->V1] = E->Weight;
//	MG->Ne++;
//}
//
//
///* Floyd�㷨 */
//void Floyd(MGraph MG, int Path[][MaxVertexNum])
//{
//	Vertex i, j, k;
//	for (i = 0; i<MG->Nv; i++)  /* ��Path������г�ʼ�� */
//		for (j = 0; j<MG->Nv; j++)
//		{
//			if (MG->G[i][j]<INFINITY)
//				Path[i][j] = i;
//			else
//				Path[i][j] = -1;
//		}
//
//
//	for (i = 0; i<MG->Nv; i++)
//		for (j = 0; j<MG->Nv; j++)
//			for (k = 0; k<MG->Nv; k++)
//			{
//				if (i == j) continue;  /* ����Խ����ϵ�Ԫ�ز������� */
//				if (MG->G[i][k] + MG->G[k][j]<MG->G[i][j]){
//					MG->G[i][j] = MG->G[i][k] + MG->G[k][j];
//					Path[i][j] = k;
//				}
//
//			}
//}
//
//int GetMinOfMax(MGraph MG)
//{
//	int Max = 0;  /* ��ʼ�����ֵ����Сֵ */
//	int Min = INFINITY;
//	int MinV = -1;  /* ��ʼ����Сֵ�����ֵָ�� */
//	for (int j = 0; j<MG->Nv; j++)
//	{
//		Max = 0;
//		for (int i = 0; i<MG->Nv; i++)
//		{
//			if (i == j) continue;
//			if (MG->G[j][i] > Max)
//			{
//				Max = MG->G[j][i];
//			}
//		}
//
//		if (Max < Min)
//		{
//			Min = Max;
//			MinV = j;
//		}
//	}
//
//	return MinV;
//}
//
//int Check(MGraph MG)
//{
//	int flag = 0;
//	int Count = 0;
//
//	for (int i = 0; i < MG->Nv; i++)
//	{
//		flag = 0;  /* ÿһ�����ݶԱ�־λ���г�ʼ�� */
//		for (int j = 0; j < MG->Nv; j++)
//		{
//			if (i == j) continue;
//			if ((!flag) && (MG->G[i][j] == INFINITY))
//			{
//				flag = 1;
//				Count++;
//			}
//		}
//	}
//
//	if (Count >= MG->Nv)  /* ��ͨ��·�������ж� */
//		return 0;
//	return 1;
//}
//
//
////int main()
////{
////	int N, M;
////	Edge E = new struct ENode;
////	int Max = 0;
////	int MinV;
////	int Path[MaxVertexNum][MaxVertexNum];
////	cin >> N >> M; /*���붯������N��ֱ�ӱ��ε�ħ������M*/
////	MGraph MG = CreateGraph(N);  /* �����ڽӾ��� */
////	while (M--)
////	{
////		cin >> E->V1 >> E->V2 >> E->Weight;
////		E->V1--; E->V2--;
////		InsertEdge(MG, E);  /* ����� */
////	}
////
////	Floyd(MG, Path);
////	if (Check(MG))
////	{
////		MinV = GetMinOfMax(MG);
////		for (int i = 0; i<MG->Nv; i++)
////		{
////			if (MG->G[MinV][i] > Max)
////			{
////				if (i == MinV) continue;
////				Max = MG->G[MinV][i];
////			}
////		}
////		cout << MinV+1 << " " << Max;
////	}
////	else
////		cout << 0;
////
////	return 0;
////}