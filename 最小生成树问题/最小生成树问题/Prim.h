#include"Array_Map.h"


VertexNum FindMinDist(MGraph MG, WeightType dist[])
{
	VertexNum MinV, V;
	WeightType MinDist = INFINITY;
	for (V = 0;  V < MG->Nv; V++)
	{
		if (dist[V] != 0 && dist[V] < MinDist){
			MinDist = dist[V];
			MinV = V;
		}
	}
	if (MinDist < INFINITY)
		return MinV;
	return -1;
}

int Prim(MGraph MG, LGraph *MST)
{/* 将最小生成树保存为邻接表存储的图MST,返回最小权重和 */
	WeightType dist[MaxVertexNum], TotalWeight;
	VertexNum Parents[MaxVertexNum], V, W;
	int VCount;
	LEdge E;

	/* 初始化，默认初始点下标为0 */
	for ( V = 0; V < MG->Nv; V++)
	{/* 这里假设若V到W没有直接的边，则Graph->G[V][W]定义为INFINITY*/
		dist[V] = MG->G[0][V];
		Parents[V] = 0;
	}
	TotalWeight = 0;  /* 初始化权重和 */
	VCount = 0;  /* 初始化收录的顶点数 */

	/* 创建包含所有顶点但是没有边的图，使用邻接表形式 */
	*MST = CreateGraph(MG->Nv);
	E = new struct LENode;  /* 建立空的边结点 */

	/* 将初始点收录进MST */
	dist[0] = 0;
	VCount++;
	Parents[0] = -1;  /* 当前树根为0 */

	while (1){
		V = FindMinDist(MG, dist);
		if (V == -1)   /* 若这样的V不存在 */
			break;
		
		E->V1 = Parents[V];
		E->V2 = V;
		E->Weight = dist[V];
		InsertEdge(*MST, E);  /* 将V收录进MST */
		TotalWeight += dist[V];
		VCount++;
		dist[V] = 0; 

		for (W = 0; W < MG->Nv; W++)  /* 对图中的每一个顶点 */
		{
			if (MG->G[V][W] < dist[W])
			{
				dist[W] = MG->G[V][W];  /* 更新dist[W] */
				Parents[W] = V;  /* 更新树 */
			}
		}
	}
	if (VCount < MG->Nv)  /* MST中收到的顶点不到|V|个 */
		TotalWeight = -1;
	return TotalWeight;  /* 算法执行完毕，返回最小权重和或错误标记 */
}