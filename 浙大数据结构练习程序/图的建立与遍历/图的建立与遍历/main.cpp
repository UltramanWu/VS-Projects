//#include"Map_Array.h"
#include"Map_Chain.h"
int main()
{
	int N;
	Edge E = new struct ENode;
	//MGraph Graph;   /* 使用数组进行创建及插入 */
	//cin >> N;
	//Graph = CreateGraph(N); 
	//while (N--)
	//{
	//	cin >> E->V1 >> E->V2 >> E->Weight;
	//	InsertEdge(Graph, E);
	//}
	LGraph Graph;
	cin >> N;
	Graph = CreateGraph(N);
	while (N--)
	{
		cin >> E->V1 >> E->V2 >> E->Weight;
		InsertEdge(Graph, E);
	}

	system("pause");
	return 0;
}