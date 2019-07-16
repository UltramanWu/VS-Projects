#include<iostream>
using namespace std;

/* Ͱ���� */
const int MaxSubjectNum = 5;  /* ����Ŀ�� */
const int MaxUsersNum = 10000;  /* ���ѧ���� */

struct BucketNode{
	int UID;  /* ѧ����� */
	int Scope[MaxSubjectNum];  /* ��÷��� */
	int Total_Scope;  /* �ܷ� */
	int Perfect_Num;  /* ���������� */
	int Submission_Num;  /* �Ͻ������� */
};
typedef BucketNode *Bucket;

struct ScopeNode{
	int UID;  /* ѧ����� */
	int SID;  /* �γ̱�� */
	int SNum;  /* �γ̷��� */
};
typedef ScopeNode *Scope;

Bucket CreateBucket( int N)
{
	Bucket BT = new struct BucketNode[N];  /* ������Ӧ��С���ڴ� */
	for (int i = 0; i < N; i++)  /* �ṹ���ڲ�����ʼ�� */
	{
		BT[i].Perfect_Num = 0;
		BT[i].Submission_Num = 0;
		BT[i].Total_Scope = 0;
		BT[i].UID = i;
		for (int j = 0; j < MaxSubjectNum; j++)
			BT[i].Scope[j] = -1;
	}

	return BT;
}

void InsertS(Bucket BT, Scope S,int FullScope[])
{
	if (S->SNum == -1)  /* �����ǰ����ֵΪ-1����û�л�÷��� */
	{
		BT[S->UID].Scope[S->SID] = 0;  /* �ɼ�ֱ��¼�� */
	}
	else if (S->SNum > BT[S->UID].Scope[S->SID]){  /* ��ǰֵ���ڵ�ǰλ�ô����ֵ */
		if (BT[S->UID].Scope[S->SID] == 0)  /* ��ǰλ��û�б�¼��� */
			BT[S->UID].Submission_Num++;
		if (S->SNum == FullScope[S->SID])  /* ��ǰ¼��ĳɼ�Ϊ������ */
			BT[S->UID].Perfect_Num++;
		if (BT[S->UID].Scope[S->SID] == -1)  /* �����ǰλ��Ϊ��ʼֵ */
			BT[S->UID].Total_Scope += S->SNum - BT[S->UID].Scope[S->SID]-1;  /* �����ܷ��� */
		else  /* ������³���1��ʱ */
			BT[S->UID].Total_Scope += S->SNum - BT[S->UID].Scope[S->SID];

		BT[S->UID].Scope[S->SID] = S->SNum;  /* �ɼ�¼�� */
	}
}

#if 1
/* Ԫ�ؽ��� */
void Swap(int* a, int *b) 
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}



void PercDown_Min(Bucket BT,int Rank[], long long p, long long N)
{/* ���ˣ���H����H[p]Ϊ�����Ӷѵ���Ϊ���� */
	long long Parent, Child;
	int X;
	X = BT[Rank[p]].Total_Scope;  /*  ȡ�����ڵ��ŵ�ֵ */
	for (Parent = p; Parent * 2 + 1 < N; Parent = Child)
	{
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (BT[Rank[Child]].Total_Scope < BT[Rank[Child + 1]].Total_Scope))
			Child++;/* ѡȡ���������� */
		if (X <= Rank[Child])  break;  /* �ҵ����ʵ�λ�� */
		else  /* ����X */
			Rank[Parent] = Rank[Child];
	}
	Rank[Parent] = X;
}


/*�������� */
void BulidHeap_Min(Bucket BT, int Rank[], long long N)
{
	/* ����H->Data[]�е�Ԫ�أ�ʹ������С�ѵ�������  */
	/* �����������N��Ԫ���Ѿ�����H[]�� */
	long long i;

	/* �����һ�����ĸ��ڵ㿪ʼ���������0 */
	for (i = (N - 2) / 2; i >= 0; i--)
		PercDown_Min(BT, Rank, i, N);
}

/* ���͸��ӶȵĶ������㷨 */
void Heap_Sort_Max(Bucket BT, int Rank[], long long N)
{
	long long Count = N;
	for (; Count > 0; Count--)
	{
		if (Count == N)
			BulidHeap_Min(BT,Rank, Count); /* �������� */
		else
			PercDown_Min(BT ,Rank, 0, Count);  /* �������� */
		Swap(&Rank[0], &Rank[Count - 1]);  /* ��Ѷ���ĩβԪ�ؽ��н��� */
	}
}

#endif

/* ϣ������ */
void Shell_Sort(Bucket BT, int Rank[], long long N)
{ /* ԭʼϣ������������Ԫ�ز����ʣ����»�Ӱ�����Ԫ�ص�����˳�� */
	int TmpA;
	long long  i;
	int si;  /* �ֲ�����Ҫ���г�ʼ�� */
	int Sedgewick[] = { 929, 505, 209, 109, 41, 19, 5, 1, 0 };
	for (si = 0; Sedgewick[si] >= N; si++)  /* ��Sedgewick�������� */
		;
	for (long long D = Sedgewick[si]; D >0; D = Sedgewick[++si])  /* ԭʼϣ���������� */
	{
		for (long long P = D; P < N; P++)
		{
			TmpA = BT[Rank[P]].Total_Scope;
			for (i = P; i >D - 1 && BT[Rank[i - D]].Total_Scope<TmpA; i -= D)
				Rank[i] = Rank[i - D];  /* ��Ԫ�غ��� */

			Rank[i] = Rank[P];  /* ��Ԫ�طŵ�ָ��λ�� */
		}
	}
}

/* �������� */
void Insert_Sort(Bucket BT, int Rank[], long long N){
	int TmpA,Temp;
	long long  i;
	
	for (long long P = 1; P < N; P++)
	{		
			TmpA = BT[Rank[P]].Total_Scope;
			Temp = Rank[P];
			for (i = P; i >0 && BT[Rank[i - 1]].Total_Scope<TmpA; i --)
				Rank[i] = Rank[i - 1];  /* ��Ԫ�غ��� */

			Rank[i] = Temp;  /* ��Ԫ�طŵ�ָ��λ�� */
	}
}

void Rank(Bucket BT,int Rank[],int N)
{
	for (int i = 0; i < N; i++)  /* �б��ʼ�� */
		Rank[i] = i; 

	Insert_Sort(BT, Rank, N);  /* �ֹܷؼ������� */

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (BT[Rank[j]].Total_Scope == BT[Rank[j + 1]].Total_Scope)  /* �ܷ���ͬ */
			{
				if (BT[Rank[j]].Perfect_Num < BT[Rank[j + 1]].Perfect_Num)
					Swap(&Rank[j], &Rank[j + 1]);/* ���ֿ�Ŀ����ʱ������ */
				else if (BT[Rank[j]].Perfect_Num == BT[Rank[j + 1]].Perfect_Num)  /* ���ֿ�Ŀ����ͬ */
				{
					if (BT[Rank[j]].UID > BT[Rank[j + 1]].UID)
						Swap(&Rank[j], &Rank[j + 1]);/* ID���ϴ�ʱ������ */
				}
			}
		}
	}
	
}