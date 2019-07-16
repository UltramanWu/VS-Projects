#include"TopSort_foudation.h"

bool TopSort(LGraph LG, Vertex TopOrder[],int Count[],int Path[])
{/* 对LG进行拓扑排序，TopOrder[]顺序存储排序后的顶点下标 */
	int Indegree[MaxVertexNum], cnt;
	Vertex V;
	PtrToAdjVNode W;
	Queue Q = CreateQ();  /* 创建队列 */

	/* 初始化Indegree[]和Count[]、Path[] */
	for (V = 0; V < LG->Nv; V++)
	{
		Indegree[V] = 0;
		Count[V] = 0;
		Path[V] = -1;
	}
		
	/* 遍历LG，得到Indegree[] */
	for (V = 0; V < LG->Nv; V++)
		for (W = LG->G[V].FirstEdge; W; W = W->next)
			Indegree[W->AdjV] ++;  /* 入度大小需要根据连接点的数量设定 */

	/* 将所有入度为零的顶点入队 */
	for (V = 0; V < LG->Nv; V++)
		if (Indegree[V] == 0)
			EntryQ(Q, V);

	/* 下面进入拓扑排序 */
	cnt = 0;
	while (!IsEmpty(Q)){
		V = OutQ(Q);  /* 弹出一个入度为0的顶点 */
		TopOrder[cnt++] = V;  /* 将之存为结果序列的下一个元素 */
		/* 对V的每个邻接点W->AdjV */
		for (W = LG->G[V].FirstEdge; W; W = W->next)
		{
			if (--Indegree[W->AdjV] == 0)  /* 若删除V使得W->AdjV入度为0 */
				EntryQ(Q, W->AdjV);  /* 则将该顶点入队 */
			
			/* 更新所有结点的数据 */
			if (Count[V] + W->Weight > Count[W->AdjV])  /* 更新Count[]数据，更新权重最大位置 */
			{
				Count[W->AdjV] = Count[V] + W->Weight;
				Path[W->AdjV] = V;
			}
		}
			
	}/* while循环结束 */

	if (cnt != LG->Nv)
		return false;
	else
		return true;
}