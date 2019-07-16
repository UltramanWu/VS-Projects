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
{/* ����С����������Ϊ�ڽӱ�洢��ͼMST,������СȨ�غ� */
	WeightType dist[MaxVertexNum], TotalWeight;
	VertexNum Parents[MaxVertexNum], V, W;
	int VCount;
	LEdge E;

	/* ��ʼ����Ĭ�ϳ�ʼ���±�Ϊ0 */
	for ( V = 0; V < MG->Nv; V++)
	{/* ���������V��Wû��ֱ�ӵıߣ���Graph->G[V][W]����ΪINFINITY*/
		dist[V] = MG->G[0][V];
		Parents[V] = 0;
	}
	TotalWeight = 0;  /* ��ʼ��Ȩ�غ� */
	VCount = 0;  /* ��ʼ����¼�Ķ����� */

	/* �����������ж��㵫��û�бߵ�ͼ��ʹ���ڽӱ���ʽ */
	*MST = CreateGraph(MG->Nv);
	E = new struct LENode;  /* �����յı߽�� */

	/* ����ʼ����¼��MST */
	dist[0] = 0;
	VCount++;
	Parents[0] = -1;  /* ��ǰ����Ϊ0 */

	while (1){
		V = FindMinDist(MG, dist);
		if (V == -1)   /* ��������V������ */
			break;
		
		E->V1 = Parents[V];
		E->V2 = V;
		E->Weight = dist[V];
		InsertEdge(*MST, E);  /* ��V��¼��MST */
		TotalWeight += dist[V];
		VCount++;
		dist[V] = 0; 

		for (W = 0; W < MG->Nv; W++)  /* ��ͼ�е�ÿһ������ */
		{
			if (MG->G[V][W] < dist[W])
			{
				dist[W] = MG->G[V][W];  /* ����dist[W] */
				Parents[W] = V;  /* ������ */
			}
		}
	}
	if (VCount < MG->Nv)  /* MST���յ��Ķ��㲻��|V|�� */
		TotalWeight = -1;
	return TotalWeight;  /* �㷨ִ����ϣ�������СȨ�غͻ������ */
}