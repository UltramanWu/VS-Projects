//#include"Prim.h"
#include"Kruskal.h"
int main()
{
	int TotalWeight;
	//LGraph MST ;
#if 0
	MGraph G = CreatMGraph(7);
	ChangeWeight(&G, 1, 4, 1);
	ChangeWeight(&G, 1, 2, 2);
	ChangeWeight(&G, 2, 4, 3);
	ChangeWeight(&G, 2, 5, 10);
	ChangeWeight(&G, 4, 3, 2);
	ChangeWeight(&G, 4, 6, 8);
	ChangeWeight(&G, 4, 7, 4);
	ChangeWeight(&G, 4, 5, 7);
	ChangeWeight(&G, 5, 7, 6);
	ChangeWeight(&G, 7, 6, 1);
	ChangeWeight(&G, 3, 6, 5);
	ChangeWeight(&G, 3, 1, 4);
	TotalWeight = Prim(G, &MST);
#endif

	LGraph G = CreateGraph(7);
	LEdge E;
	LGraph MST = CreateGraph(7);
	/* 构建7个结点的图*/
	E = InsertE(1, 4, 1);
	InsertEdge(G, E);
	E = InsertE(1, 2, 2);
	InsertEdge(G, E);
	E = InsertE(1, 3, 4);
	InsertEdge(G, E);
	E = InsertE(2, 4, 3);
	InsertEdge(G, E);
	E = InsertE(2, 5, 10);
	InsertEdge(G, E);
	E = InsertE(3, 4, 2);
	InsertEdge(G, E);
	E = InsertE(3, 5, 6);
	InsertEdge(G, E);
	E = InsertE(4, 5, 7);
	InsertEdge(G, E);
	E = InsertE(4, 6, 8);
	InsertEdge(G, E);
	E = InsertE(4, 7, 4);
	InsertEdge(G, E);
	E = InsertE(5, 7, 6);
	InsertEdge(G, E);
	E = InsertE(6, 7, 1);
	InsertEdge(G, E);

	TotalWeight = Kruskal(G, MST);
	system("pause");
	return 0;
}