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
//	int Path[MaxVertexNum];  /* ·������ */
//	int important[MaxVertexNum]; /* �ؼ���������� */
//	Edge E = new struct ENode;
//
//	cin >> N >> M;  /* NΪ��������MΪ���� */
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
//		if (TopSort(LG, Order, Count, Path))  /* �������Ϊ�� */
//		{
//			for (int i = 0; i < LG->Nv; i++)
//			{  /* �ȵõ����ֵ */
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
//				if (MaxV[k] > -1)  /* �����Ԫ�ر��Ķ�������˵����������һ�����·�� */
//				{
//					VCount = 0;  /* ��VCount���г�ʼ�� */
//					important[VCount++] = MaxV[k];  /* ��β����д�� */
//					for (int l = MaxV[k]; Path[l] != -1;) {
//						important[VCount++] = Path[l];/* ��¼������ */
//						l = Path[l]; /* ���ݺ��� */
//					}
//
//					for (int m = VCount - 1; m >0; --m) {
//						cout << important[m] + 1 << "->" << important[m - 1] + 1 << endl;
//					}
//				}
//			}
//
//		}
//		else /* ����Ϊ�� */
//			cout << 0 << endl;
//	}
//	
//	system("pause");
//	return 0;
//}