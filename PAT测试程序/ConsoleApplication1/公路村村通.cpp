//#include<iostream>
//using namespace std;
//
//#define MaxVertexNum 100  /* 规定好最大的变量数 */
//#define INFINITY 65535
//typedef int Vertex;  /* 顶点元素类型 */
//typedef int WeightType;  /* 权重类型 */
//
//struct ENode{
//	Vertex V1;  /* 边两侧对应顶点 */
//	Vertex V2;
//	WeightType Weight;  /* 边权重*/
//};
//typedef struct ENode *Edge;
//
//struct GNode{
//	int Nv;  /* 顶点总数 */
//	int Ne;  /* 边总数 */
//	int G[MaxVertexNum][MaxVertexNum];  /* 权重矩阵 */
//};
//typedef struct GNode *MGraph;
//
//
///* 创建邻接矩阵 */
//MGraph CreateGraph(int Vertex)
//{
//	MGraph MG = new struct GNode;
//	MG->Nv = Vertex;
//	MG->Ne = 0;
//	for (int i = 0; i< Vertex; i++)
//		for (int j = 0; j<Vertex; j++)
//			MG->G[i][j] = INFINITY;  /* 对矩阵相关位置进行初始化 */
//	return MG;
//}
//
///* 插入边 */
//void InsertEdge(MGraph MG, Edge E)
//{
//	/* 插入<V1,V2> */
//	MG->G[E->V1][E->V2] = E->Weight;
//	/* 插入<V2,V1> */
//	MG->G[E->V2][E->V1] = E->Weight;
//	MG->Ne++;
//}
//
//
///* Floyd算法 */
//void Floyd(MGraph MG, int Path[][MaxVertexNum])
//{
//	Vertex i, j, k;
//	for (i = 0; i<MG->Nv; i++)  /* 对Path数组进行初始化 */
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
//				if (i == j) continue;  /* 矩阵对角线上的元素不做处理 */
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
//	int Max = 0;  /* 初始化最大值和最小值 */
//	int Min = INFINITY;
//	int MinV = -1;  /* 初始化最小值与最大值指向 */
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
//		flag = 0;  /* 每一组数据对标志位进行初始化 */
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
//	if (Count >= MG->Nv)  /* 对通断路径进行判断 */
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
////	cin >> N >> M; /*输入动物总数N与直接变形的魔咒条数M*/
////	MGraph MG = CreateGraph(N);  /* 创建邻接矩阵 */
////	while (M--)
////	{
////		cin >> E->V1 >> E->V2 >> E->Weight;
////		E->V1--; E->V2--;
////		InsertEdge(MG, E);  /* 插入边 */
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