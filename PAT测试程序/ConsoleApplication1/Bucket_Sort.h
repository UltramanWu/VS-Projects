#include<iostream>
using namespace std;

/* 桶排序 */
const int MaxSubjectNum = 5;  /* 最大科目数 */
const int MaxUsersNum = 10000;  /* 最大学生数 */

struct BucketNode{
	int UID;  /* 学生序号 */
	int Scope[MaxSubjectNum];  /* 获得分数 */
	int Total_Scope;  /* 总分 */
	int Perfect_Num;  /* 满分试题数 */
	int Submission_Num;  /* 上交试题量 */
};
typedef BucketNode *Bucket;

struct ScopeNode{
	int UID;  /* 学生编号 */
	int SID;  /* 课程编号 */
	int SNum;  /* 课程分数 */
};
typedef ScopeNode *Scope;

Bucket CreateBucket( int N)
{
	Bucket BT = new struct BucketNode[N];  /* 申请响应大小的内存 */
	for (int i = 0; i < N; i++)  /* 结构体内参数初始化 */
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
	if (S->SNum == -1)  /* 如果当前输入值为-1，即没有获得分数 */
	{
		BT[S->UID].Scope[S->SID] = 0;  /* 成绩直接录入 */
	}
	else if (S->SNum > BT[S->UID].Scope[S->SID]){  /* 当前值大于当前位置储存的值 */
		if (BT[S->UID].Scope[S->SID] == 0)  /* 当前位置没有被录入过 */
			BT[S->UID].Submission_Num++;
		if (S->SNum == FullScope[S->SID])  /* 当前录入的成绩为满分数 */
			BT[S->UID].Perfect_Num++;
		if (BT[S->UID].Scope[S->SID] == -1)  /* 如果当前位置为初始值 */
			BT[S->UID].Total_Scope += S->SNum - BT[S->UID].Scope[S->SID]-1;  /* 更新总分数 */
		else  /* 如果更新超过1次时 */
			BT[S->UID].Total_Scope += S->SNum - BT[S->UID].Scope[S->SID];

		BT[S->UID].Scope[S->SID] = S->SNum;  /* 成绩录入 */
	}
}

#if 1
/* 元素交换 */
void Swap(int* a, int *b) 
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}



void PercDown_Min(Bucket BT,int Rank[], long long p, long long N)
{/* 下滤：将H中以H[p]为根的子堆调整为最大堆 */
	long long Parent, Child;
	int X;
	X = BT[Rank[p]].Total_Scope;  /*  取出根节点存放的值 */
	for (Parent = p; Parent * 2 + 1 < N; Parent = Child)
	{
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (BT[Rank[Child]].Total_Scope < BT[Rank[Child + 1]].Total_Scope))
			Child++;/* 选取二者中最大的 */
		if (X <= Rank[Child])  break;  /* 找到合适的位置 */
		else  /* 下滤X */
			Rank[Parent] = Rank[Child];
	}
	Rank[Parent] = X;
}


/*创建最大堆 */
void BulidHeap_Min(Bucket BT, int Rank[], long long N)
{
	/* 调整H->Data[]中的元素，使满足最小堆的有序性  */
	/* 这里假设所有N个元素已经存在H[]中 */
	long long i;

	/* 从最后一个结点的父节点开始，到根结点0 */
	for (i = (N - 2) / 2; i >= 0; i--)
		PercDown_Min(BT, Rank, i, N);
}

/* 降低复杂度的堆排序算法 */
void Heap_Sort_Max(Bucket BT, int Rank[], long long N)
{
	long long Count = N;
	for (; Count > 0; Count--)
	{
		if (Count == N)
			BulidHeap_Min(BT,Rank, Count); /* 建立最大堆 */
		else
			PercDown_Min(BT ,Rank, 0, Count);  /* 重新排列 */
		Swap(&Rank[0], &Rank[Count - 1]);  /* 令堆顶与末尾元素进行交换 */
	}
}

#endif

/* 希尔排序 */
void Shell_Sort(Bucket BT, int Rank[], long long N)
{ /* 原始希尔增量序列内元素不互质，导致会影响各个元素的排列顺序 */
	int TmpA;
	long long  i;
	int si;  /* 局部变量要进行初始化 */
	int Sedgewick[] = { 929, 505, 209, 109, 41, 19, 5, 1, 0 };
	for (si = 0; Sedgewick[si] >= N; si++)  /* 用Sedgewick增量序列 */
		;
	for (long long D = Sedgewick[si]; D >0; D = Sedgewick[++si])  /* 原始希尔增量序列 */
	{
		for (long long P = D; P < N; P++)
		{
			TmpA = BT[Rank[P]].Total_Scope;
			for (i = P; i >D - 1 && BT[Rank[i - D]].Total_Scope<TmpA; i -= D)
				Rank[i] = Rank[i - D];  /* 将元素后移 */

			Rank[i] = Rank[P];  /* 将元素放到指定位置 */
		}
	}
}

/* 插入排序 */
void Insert_Sort(Bucket BT, int Rank[], long long N){
	int TmpA,Temp;
	long long  i;
	
	for (long long P = 1; P < N; P++)
	{		
			TmpA = BT[Rank[P]].Total_Scope;
			Temp = Rank[P];
			for (i = P; i >0 && BT[Rank[i - 1]].Total_Scope<TmpA; i --)
				Rank[i] = Rank[i - 1];  /* 将元素后移 */

			Rank[i] = Temp;  /* 将元素放到指定位置 */
	}
}

void Rank(Bucket BT,int Rank[],int N)
{
	for (int i = 0; i < N; i++)  /* 列表初始化 */
		Rank[i] = i; 

	Insert_Sort(BT, Rank, N);  /* 总分关键字排序 */

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (BT[Rank[j]].Total_Scope == BT[Rank[j + 1]].Total_Scope)  /* 总分相同 */
			{
				if (BT[Rank[j]].Perfect_Num < BT[Rank[j + 1]].Perfect_Num)
					Swap(&Rank[j], &Rank[j + 1]);/* 满分科目较少时，交换 */
				else if (BT[Rank[j]].Perfect_Num == BT[Rank[j + 1]].Perfect_Num)  /* 满分科目数相同 */
				{
					if (BT[Rank[j]].UID > BT[Rank[j + 1]].UID)
						Swap(&Rank[j], &Rank[j + 1]);/* ID数较大时，交换 */
				}
			}
		}
	}
	
}