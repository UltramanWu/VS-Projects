//#include<iostream>
//using namespace std;
///* 此为多源加权最短路径和算法 */
//typedef int Vertex;
//typedef int WeightType;
//#define INFINITY 65535
//#define MaxVertexNum 100
//
//
//struct ENode{
//	Vertex V1, V2;  /* 结点位置 */
//	WeightType Weight; /* 权重 */
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
///* 创建邻接矩阵 */
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
///* 插入边 */
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
//	for (i = 0; i<MG->Nv; i++)  /* 对路径数组进行初始化 */
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
//					if (MG->G[i][j] < 0)  /* 存在负值圈，则无法进行处理 */
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
//		flag = 0;  /* 标志位复位 */
//		for (W = 0; W<MG->Nv; W++)
//		{
//			if (V == W) continue;
//			if ((!flag) && (MG->G[V][W] >= INFINITY))
//			{
//				flag = 1;  /* 标志位置位 */
//				ECount++;  /* 增加时间 */
//			}
//		}
//	}
//
//	if (ECount >= MG->Nv)  /* 如果每一起点都有不同的路，则不足以畅通 */
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
//		Sum = 0;  /* 标志位复位 */
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
//	int Path[MaxVertexNum][MaxVertexNum]; /* 路径数组 */
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
