//#include<iostream>
//using namespace std;
//
//#define MaxVertexNum 500  /* 结点最大个数 */
//#define INFINITY 65535
//typedef int Vertex;
//typedef int LengthType;  /* 路径长度 */
//typedef int MoneyType;  /* 收费总额 */
//
//struct ENode{
//	Vertex V1;
//	Vertex V2;
//	LengthType length;  /* 路径长度 */
//	MoneyType Money;  /* 收费总额 */
//};
//typedef struct ENode* Edge;
//
//struct GNode{
//	int Nv;
//	int Ne;
//	int L[MaxVertexNum][MaxVertexNum];  /* 路径长度矩阵 */
//	int M[MaxVertexNum][MaxVertexNum];  /* 耗费路费矩阵 */
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
//	bool collected[MaxVertexNum];    /* 标记收集数组 */
//	Vertex V, W;
//	for (V = 0; V < MG->Nv; V++){
//		dist[V] = MG->L[S][V];  /* 将距离值加入到距离数组中 */
//		Cost[V] = MG->M[S][V]; /* 将路费值加入到消费数组中 */
//		collected[V] = false;  /* 将所有的数据设置为未收集 */
//
//		if (dist[V] < INFINITY)
//			path[V] = S;   /* 对直接连接源节点的结点直接赋值 */
//		else
//			path[V] = -1;
//	}
//	/* 将源节点存入到路径数组中且收集数组的该位置位 */
//	dist[S] = 0;
//	collected[S] = true;
//	while (1)
//	{
//		V = FindMin(MG, dist, collected);  /* 取得距离最小值所在下标 */
//		if ((V == -1) || (V == -2))  /* 当该点不存在时，直接退出 */
//			break;
//		collected[V] = true;  /* 收录V */
//		for (W = 0; W < MG->Nv; W++)  /* 对图中的每一个顶点*/
//		{
//			if (collected[W] == false && MG->L[V][W] < INFINITY)
//			{
//				if (MG->L[V][W] < 0)  /* 不能存在负边 */
//					return false;  /* 不能够正确解决，返回错误标记 */
//				if (dist[V] + MG->L[V][W] < dist[W]){
//					dist[W] = dist[V] + MG->L[V][W];   /* 更新dist[W]*/
//					path[W] = V;  /* 更新S到W的路径 */
//					Cost[W] = Cost[V] + MG->M[V][W];
//				}
//				else if ((dist[V] + MG->L[V][W] == dist[W]) && (Cost[W] > Cost[V] + MG->M[V][W]))
//				{
//					Cost[W] = Cost[V] + MG->M[V][W];
//					path[W] = V;  /* 更新S到W的路径 */
//				}
//			}
//		}
//	}  /* while 循环结束 */
//	return true; /* 算法执行完毕，返回正确标记 */
//}
//
//void Floyd(MGraph MG, int Path[][MaxVertexNum])
//{
//	Vertex i, j, k;
//	for (i = 0; i< MG->Nv; i++)  /* 对路径数组进行初始化 */
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
//					MG->M[i][j] = MG->M[i][k] + MG->M[k][j];  /* 将其路费矩阵元素进行更换 */
//					Path[i][j] = k;
//				}
//				else if (MG->L[i][k] + MG->L[k][j] == MG->L[i][j])
//				{
//					if (MG->M[i][j] > MG->M[i][k] + MG->M[k][j])  /*如果路径长度相同，但路费不同的话，将最小路费的填入*/
//					{
//						MG->M[i][j] = MG->M[i][k] + MG->M[k][j];  /* 将其路费矩阵元素进行更换 */
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
//			InsertEdge(MG, E);  /* 插入边 */
//		}  /* 创建邻接矩阵完成 */
//
//		Dijkstra(MG, dist, Path, Cost,S);
//		//Floyd(MG,Path1);
//		//cout << MG->L[S][D] << " " << MG->M[S][D] << endl;
//		cout << dist[D] << " " << Cost[D] << endl;
//	}
//
//	return 0;
//}