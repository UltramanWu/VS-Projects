//#include"UWeight_UDirect.h"
//#include"Array_Map.h"
#include"Harry Potter.h"

/* 主函数实现 */
int main()
{
#if 0
	/* 主函数实现 */
	LGraph G = CreateGraph(7);
	Edge E;
	//VertexData *VT = new struct VertexData[100];
	//VertexData *VT = new Vertex;  /* 保存路径的结构体数组 */
	/* 构建7个结点的图*/
	E = InsertE(3, 1, 1);
	InsertEdge(G, E);
	E = InsertE(3, 6, 1);
	InsertEdge(G, E);
	E = InsertE(1, 4, 1);
	InsertEdge(G, E);
	E = InsertE(1, 2, 1);
	InsertEdge(G, E);
	E = InsertE(2, 4, 1);
	InsertEdge(G, E);
	E = InsertE(2, 5, 1);
	InsertEdge(G, E);
	E = InsertE(4, 3, 1);
	InsertEdge(G, E);
	E = InsertE(4, 5, 1);
	InsertEdge(G, E);
	E = InsertE(4, 6, 1);
	InsertEdge(G, E);
	E = InsertE(4, 7, 1);
	InsertEdge(G, E);
	E = InsertE(5, 7, 1);
	InsertEdge(G, E);
	E = InsertE(7, 6, 1);
	InsertEdge(G, E);
	Init(&Vertex);
	UWeight(G, 3, &Vertex);

	Print_Path(&Vertex, 7);
	Print_Path(&Vertex, 6);
	Print_Path(&Vertex, 5);
#endif

#if 0
	int Path[MaxVertexNum];  /* 路径数组 */ 
	int dist[MaxVertexNum];  /* 距离数组 */
	/*int Path[MaxVertexNum][MaxVertexNum];  /* 路径数组*/
	/*int D[MaxVertexNum][MaxVertexNum];  /* 权重矩阵*/
	MGraph G = CreatMGraph(7);

	ChangeWeight(&G, 1, 4, 1);
	ChangeWeight(&G, 1, 2, 2);
	ChangeWeight(&G, 2, 4, 3);
	ChangeWeight(&G, 2, 5, 10);
	ChangeWeight(&G, 4, 3, 2);
	ChangeWeight(&G, 4, 6, 8);
	ChangeWeight(&G, 4, 7, 4);
	ChangeWeight(&G, 4, 5, 2);
	ChangeWeight(&G, 5, 7, 6);
	ChangeWeight(&G, 7, 6, 1);
	ChangeWeight(&G, 3, 6, 5);
	ChangeWeight(&G, 3, 1, 4);

	if (Dijkstra(G, dist, Path, 1))
		Print_Path(G,Path, 5);
	else
		cout << "error!" << endl;

	/*if (floyd(G, D, Path))
		Print_Multi_Path(D, Path, 7, 1);
	else
		cout << "ERROR!" << endl;
	*/	

#endif

	MGraph MG = BuildGraph();

	VertexNum V = FindAnimal(MG);

	cout << V << endl;

	system("pause"); /* 令命令窗口暂停运行 */
	return 0;
}