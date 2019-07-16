#include"Chain_Map.h"



/* �洢����ֵ��·��ֵ�Ľṹ�� */
struct  VertexData
{
	int Path[MaxVertexNum];
	int dist[MaxVertexNum];
}Vertex;

/* �Խṹ����г�ʼ�� */
void Init(VertexData *Vertex)
{
	for (int i = 0; i < MaxVertexNum ; i++)
	{
		Vertex->Path[i] = -1;  /* �����н�㶼����ΪԴ�ڵ� Source*/
		Vertex->dist[i] = INFINITY;  /* ������ֵ����Ϊ���ֵ */
	}
}

/* ����Դ��㿪ʼ����Ȩͼ���·����Ĭ�����е�·��Ȩ��Ϊ1 */
void UWeight(LGraph G, VertexNum Source, VertexData *Vertex)
{
	VertexNum U;
	PtrToAdjVode W;
	Queue Q = CreateQ();

	EnQueue(Q, Source); 
	while (!IsEmptyQ(Q))  /* ������зǿ� */
	{
		U = DeQueue(Q);
		Vertex->dist[U] = 0;  /* ��Դ�ڵ�ľ�������Ϊ0 */
		for (W = G->G[U].FirstEdge; W != NULL; W = W->Next)  /* ���ڽӱ����BFS���� */
		{
			if (Vertex->Path[W->AdjV] == -1 && W->AdjV != Source) /* ����㲻��Դ�ڵ��Ҳ�Ϊ������� */
			{
				Vertex->dist[W->AdjV] = Vertex->dist[U] + 1;   /* ����Դ�ڵ�Ļ����ϼ�1 */
				Vertex->Path[W->AdjV] = U;  /* ��·����ΪԴ�ڵ�·�� */
				EnQueue(Q, W->AdjV);
			}
		}
	}
}


/* ��ӡ�ƶ�·�� */
void Print_Path(VertexData *VT , VertexNum Dest )
{
	int time = 0;  /* �ֲ�������Ҫ���г�ʼ�� */
	Stack S = CreateS();  /* ������ջ */
	PushS(S, Dest);  /* ��Ŀ�Ľ�����ѹջ */
	for (int i = Dest ; VT->Path[i] != -1; i = VT->Path[i])  /* ��·���е�����ͼ */
	{/* ����Ӧ��path���ݴ洢�������� */
		PushS(S, VT->Path[i]);
	}

	while (!IsEmptyS(S))  /* ����ջ�ڵĽ�����ݵ�������� */
	{
		if (time > 0)
			cout << "->";
			cout << PopS(S);
			time++;
	}
	cout << endl;
	cout << "PathNum:" << VT->dist[Dest] << endl;  /* ��ӡ·�����ȣ���dist�����е����� */
}