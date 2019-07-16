#include"TopSort_foudation.h"

bool TopSort(LGraph LG, Vertex TopOrder[],int Count[],int Path[])
{/* ��LG������������TopOrder[]˳��洢�����Ķ����±� */
	int Indegree[MaxVertexNum], cnt;
	Vertex V;
	PtrToAdjVNode W;
	Queue Q = CreateQ();  /* �������� */

	/* ��ʼ��Indegree[]��Count[]��Path[] */
	for (V = 0; V < LG->Nv; V++)
	{
		Indegree[V] = 0;
		Count[V] = 0;
		Path[V] = -1;
	}
		
	/* ����LG���õ�Indegree[] */
	for (V = 0; V < LG->Nv; V++)
		for (W = LG->G[V].FirstEdge; W; W = W->next)
			Indegree[W->AdjV] ++;  /* ��ȴ�С��Ҫ�������ӵ�������趨 */

	/* ���������Ϊ��Ķ������ */
	for (V = 0; V < LG->Nv; V++)
		if (Indegree[V] == 0)
			EntryQ(Q, V);

	/* ��������������� */
	cnt = 0;
	while (!IsEmpty(Q)){
		V = OutQ(Q);  /* ����һ�����Ϊ0�Ķ��� */
		TopOrder[cnt++] = V;  /* ��֮��Ϊ������е���һ��Ԫ�� */
		/* ��V��ÿ���ڽӵ�W->AdjV */
		for (W = LG->G[V].FirstEdge; W; W = W->next)
		{
			if (--Indegree[W->AdjV] == 0)  /* ��ɾ��Vʹ��W->AdjV���Ϊ0 */
				EntryQ(Q, W->AdjV);  /* �򽫸ö������ */
			
			/* �������н������� */
			if (Count[V] + W->Weight > Count[W->AdjV])  /* ����Count[]���ݣ�����Ȩ�����λ�� */
			{
				Count[W->AdjV] = Count[V] + W->Weight;
				Path[W->AdjV] = V;
			}
		}
			
	}/* whileѭ������ */

	if (cnt != LG->Nv)
		return false;
	else
		return true;
}