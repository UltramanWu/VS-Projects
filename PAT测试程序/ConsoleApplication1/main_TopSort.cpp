//#include"TopSort.h"
//
//int main()
//{
//	int N, M;
//	int MaxV[MaxVertexNum];
//	int Max = 0;
//	int VCount = 0;
//	int MaxCount = 0;
//	Vertex Order[MaxVertexNum];
//	int Count[MaxVertexNum];
//	int Path[MaxVertexNum];  /* 路径数组 */
//	int important[MaxVertexNum]; /* 关键活动储存数组 */
//	Edge E = new struct ENode;
//
//	cin >> N >> M;  /* N为顶点数，M为边数 */
//
//	for (int i = 0; i < N; i++)
//		MaxV[i] = -1;
//
//	if (M == 0)
//		cout << 0 << endl;
//	else
//	{
//		LGraph LG = CreateLGraph(N);
//		while (M--)
//		{
//			cin >> E->V1 >> E->V2 >> E->Weight;
//			E->V1--; E->V2--;  
//			InsertEdge(LG, E);
//		}
//		if (TopSort(LG, Order, Count, Path))  /* 如果返回为真 */
//		{
//			for (int i = 0; i < LG->Nv; i++)
//			{  /* 先得到最大值 */
//				if (Max < Count[i]){
//					Max = Count[i];
//					MaxV[MaxCount] = i;
//				}
//			}
//				cout << Max << endl;
//
//				for (int j = MaxV[MaxCount]+1; j < LG->Nv; j++){
//					if (Max == Count[j]){
//						MaxV[++MaxCount] = j;
//					}	
//				}
//
//			for (int k = 0; k < LG->Nv; k++)
//			{
//				if (MaxV[k] > -1)  /* 如果该元素被改动过，则说明存在至少一组最大路径 */
//				{
//					VCount = 0;  /* 对VCount进行初始化 */
//					important[VCount++] = MaxV[k];  /* 将尾数据写入 */
//					for (int l = MaxV[k]; Path[l] != -1;) {
//						important[VCount++] = Path[l];/* 记录数据量 */
//						l = Path[l]; /* 数据后移 */
//					}
//
//					for (int m = VCount - 1; m >0; --m) {
//						cout << important[m] + 1 << "->" << important[m - 1] + 1 << endl;
//					}
//				}
//			}
//
//		}
//		else /* 返回为假 */
//			cout << 0 << endl;
//	}
//	
//	system("pause");
//	return 0;
//}