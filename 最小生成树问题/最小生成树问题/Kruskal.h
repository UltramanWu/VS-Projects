#include"Chain_Map.h"

/* ---------------------���㲢�鼯����--------------------- */
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MaxVertexNum];

void InitializeVSet(SetType S, int N)
{/* ��ʼ�����鼯 */
	ElementType X;
	for (X = 0; X < N; X++)
		S[X] = -1;
}

/* �������� */
void Union(SetType S, SetName Root1, SetName Root2)
{/* ����Ĭ��Root1��Root2�ǲ�ͬ���ϵĸ���� */
	if (S[Root1] > S[Root2])  /* �������2�Ƚϴ� */
	{
		S[Root2] += S[Root1];  /* ����1���뼯��2�� */
		S[Root1] = Root2;
	}
	else{
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}

SetName Find(SetType S, ElementType X)
{/* Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1 */
	if (S[X] < 0)
		return X;
	else 
		return S[X] = Find(S, S[X]);  /* ·��ѹ�� */
}

bool CheckCycle(SetType VSet, VertexNum V1, VertexNum V2)
{/* �������V1��V2�ı��Ƿ������е���С�������Ӽ��й��ɻ�· */
	VertexNum Root1, Root2;
	Root1 = Find(VSet, V1);
	Root2 = Find(VSet, V2);

	if (Root1 == Root2)
		return false;
	else
	{
		Union(VSet, Root1, Root2);
		return true;
	}
}
/* ------------------���鼯�������--------------------- */



/* ------------------�ߵ���С�Ѷ���--------------------- */
void  PercDown(LEdge ESet, int p, int N)
{
	int Parents, Child;
	struct LENode X ;
	X = ESet[p];

	for ( Parents = p ; (Parents*2+1) < N; Parents = Child)
	{
		Child = Parents * 2 + 1;
		if ((Child != N - 1) && (ESet[Child].Weight>ESet[Child + 1].Weight))  
			Child++;  /* Child ָ�������ӽ��Ľ�С�� */
		if (X.Weight <= ESet[Child].Weight)  break;  /* �ҵ����ʵ�λ�� */
		else
			ESet[ Parents ] = ESet[ Child ];
	}
	ESet[Parents] = X;
}


void Swap(LEdge Source, LEdge Destination)
{
	LENode temp;
	temp = *Source;
	*Source = *Destination;
	*Destination = temp;
}

void InitializeESet(LGraph LG, LEdge ESet)
{/* ��ͼ�еıߴ�������Eset�����ҳ�ʼ��Ϊ��С�� */
	VertexNum V;
	PtrToAdjVNode W;  /* */
	int ECount;

	/* ��ͼ�еıߴ�������ESet�� */
	ECount = 0;
	for ( V = 0; V < LG->Nv; V++)
	{
		for ( W = LG->G[V].FirstEdge; W ; W = W->Next )
		{
			if (V < W->AdjV){  /* �����ظ�¼������ͼ�ıߣ�ֻ��¼V1<V2�ı� */
				(ESet)[ECount].V1 = V;
				(ESet)[ECount].V2 = W->AdjV;
				(ESet)[ECount++].Weight = W->Weight;
			}
				
		}
	}
	/* ��ʼ��Ϊ��С�� */
	for (ECount = LG->Ne/2; ECount >=0; ECount--)
		PercDown( ESet, ECount, LG->Ne );
}

int GetEdge(LEdge ESet, int CurrentSize)
{/* ������ǰ�ѵĴ�СCurrentSize������ǰ��С��λ�õ�����������*/

	/* ����С���뵱ǰ�ѵ����һ��λ�õı߽��� */
	Swap(&ESet[0], &ESet[CurrentSize-1]);

	/* ��ʣ��ı߼�������Ϊ��С�� */
	PercDown(ESet, 0, CurrentSize - 1);

	/* ������С�ѵĶѶ�Ԫ��*/
	return CurrentSize - 1;
}


/* ---------------��С�Ѷ������-----------------*/

void InsertEdge_Kruksal(LGraph LG, LEdge E)
{
	PtrToAdjVNode Kruskal_Node = new struct AdjVNode[2];

	/* ����<V1,V2> */
	Kruskal_Node->AdjV = E->V2;
	Kruskal_Node->Weight = E->Weight;
	Kruskal_Node->Next = LG->G[E->V1].FirstEdge;
	LG->G[E->V1].FirstEdge = Kruskal_Node;

	/* ����<V2,V1> */
	/*
	Kruskal_Node->AdjV = E->V1;
	Kruskal_Node->Weight = E->Weight;
	Kruskal_Node->Next = LG->G[E->V2].FirstEdge;
	LG->G[E->V2].FirstEdge = Kruskal_Node;
	*/

	LG->Ne++;
 }





/* �����㷨ʵ�� */

int Kruskal(LGraph LG, LGraph MST)
{/* ����С����������Ϊ�ڽӱ�洢��ͼMST��������СȨ�غ� */
	WeightType TotalWeight;
	int ECount, NextEdge;
	SetType VSet;
	LEdge ESet;

	/* ��ʼ�����㲢�鼯 */
	InitializeVSet(VSet, LG->Nv);
	
	ESet = new struct LENode;
	InitializeESet(LG, ESet);

	/* �����������ж��㵫û�бߵ�ͼ���ڽӱ���ʽ */
	//MST = CreateGraph(LG->Nv);
	TotalWeight = 0;
	ECount = 0;

	NextEdge = LG->Ne; /* ԭʼ�߼��Ĺ�ģ */
	while (ECount < LG->Nv - 1)
	{
		NextEdge = GetEdge(ESet, NextEdge);

		if (NextEdge < 0)
			break;
		if (CheckCycle(VSet,ESet[NextEdge].V1,ESet[NextEdge].V2))
		{
			/* ���ñ߲��뵽MST */
			InsertEdge_Kruksal(MST, ESet + NextEdge);
			TotalWeight += ESet[NextEdge].Weight;
			ECount++;
		}

	}
	if (ECount < LG->Nv - 1)
		TotalWeight = -1;

	delete(LG);
	return TotalWeight;
}
