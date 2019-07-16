#include"Heap.h"


#define MaxVertexNum 100000


/* 冒泡排序 */
void Bubble_Sort(ElementType A[], long long N)
{
	int flag = 0;
	for (long long P = N - 1; P >= 0; P--)
	{
		flag = 0;
		for (long long i = 0; i < P; i++)
		{
			if (A[i] > A[i + 1]){
				Swap(&A[i], &A[i + 1]); /* 两者进行交换 */
				flag = 1;
			}
		}
		if (flag == 0) break;  /* 此时无需再进行排序 */
	}
}


/* 插入排序 */
void Insert_Sort(ElementType A[], long long N)
{
	/* 认为手中的牌为0 */

	ElementType TmpA;
	long long  i;
	for (long long P = 1; P < N; P++)
	{
		TmpA = A[P];
		for (i = P; i >0 && A[i - 1]>TmpA; i--)
		{
			A[i] = A[i - 1];  /* 将元素后移 */
		}
		A[i] = TmpA;  /* 将元素放到指定位置 */
	}
}

/* 希尔排序 */
void Shell_Sort(ElementType A[], long long N)
{ /* 原始希尔增量序列内元素不互质，导致会影响各个元素的排列顺序 */
	ElementType TmpA;
	long long  i;
	int si;  /* 局部变量要进行初始化 */
	int Sedgewick[] = { 929, 505, 209, 109, 41, 19, 5, 1, 0 };
	for (si = 0; Sedgewick[si] >= N; si++)  /* 用Sedgewick增量序列 */
		;
	for (long long D = Sedgewick[si]; D >0; D = Sedgewick[++si])  /* 原始希尔增量序列 */
	{
		for (long long P = D; P < N; P++)
		{
			TmpA = A[P];
			for (i = P; i >D-1 && A[i - D]>TmpA; i -= D)
				A[i] = A[i - D];  /* 将元素后移 */

			A[i] = TmpA;  /* 将元素放到指定位置 */
		}	
	}
}

/* 查找最小元素 */
long long ScanForMin(ElementType A[], long long i, long long N)
{
	long long MinP = i;
	ElementType Min = A[i];
	for (long long j = i; j < N; j++){
		if (Min >= A[j])
		{
			Min = A[j];
			MinP = j;
		}
	}
	return MinP;
}

/* 选择排序 */
void Select_Sort(ElementType A[], long long N)
{
	long long MinPosition = 0;
	for (int i = 0; i < N; i++){
		MinPosition = ScanForMin(A, i, N);
		/* 如果选择的元素位置正好是起始位就不进行交换 */
		if (MinPosition == i) continue;
		/* 将未排序的部分的最小元换到有序部分的最后位置 */
		Swap(&A[i], &A[MinPosition]);
	}
}
/* 堆排序 */
void Heap_Sort(ElementType A[], long long N)
{
	/* 每一次从最小堆中获得最小值后放入到备份数组中 */
	ElementType TmpA[MaxVertexNum];
	/* 创建树 */
	long long Count = N;
	BuildHeap_Min(A, N);
	for (int i = 0; i < N; i++)
	{
		TmpA[i] = DeleteMin(A, Count);
		Count--;
	}
	for (int i = 0; i < N; i++)
	{
		A[i] = TmpA[i];
	}
}

/* 降低复杂度的堆排序算法 */
void Heap_Sort_Max(ElementType A[], long long N)
{
	long long Count = N;
	for (; Count > 0; Count--)
	{
		if (Count == N)
			BulidHeap_Max(A, Count); /* 建立最大堆 */
		else
			PercDown_Max(A, 0, Count);  /* 重新排列 */
		Swap(&A[0], &A[Count-1]);  /* 令堆顶与末尾元素进行交换 */
		//Count--;  /* 排除掉末尾元素 */
	}
}
/* 归并排序 -递归实现*/

/* 归并算法的核心 */
/* L =  左边起始位置，R = 右边起始位置，RightEnd = 右边终点位置 */
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{/* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个序列 */
	int LeftEnd,Tmp,NumElement;
	
	LeftEnd = R - 1;
	Tmp = L;
	NumElement = RightEnd - L + 1;

	while (L <= LeftEnd && R <= RightEnd)
	{
		if (A[L] < A[R])
			TmpA[Tmp++] = A[L++];
		else
			TmpA[Tmp++] = A[R++];
	}
	while (L<=LeftEnd)
		TmpA[Tmp++] = A[L++];  /* 直接复制左边剩下的 */
	while (R<=RightEnd)
		TmpA[Tmp++] = A[R++];  /* 直接复制右边剩下的 */

	for (int i = 0; i < NumElement; i++,RightEnd--)  /* 将排好序的序列复制到原数组中 */
		A[RightEnd] = TmpA[RightEnd];
}
/* 递归方法实现 */
void MSort(ElementType A[], ElementType TmpA[], int L, int RightEnd)
{
	int Center;
	if (L < RightEnd)
	{
		Center = (L + RightEnd) / 2;
		MSort(A, TmpA, L, Center);  /* 递归对左半部分进行归并 */
		MSort(A, TmpA, Center + 1, RightEnd);  /* 递归对右半部分进行归并 */
		Merge(A, TmpA, L, Center + 1, RightEnd);  /* 将整个序列的两部分进行归并 */
	}
}

/* 统一函数接口 */
void MergeSort(ElementType A[], int N)
{
	/* 归并排序 */
	ElementType *TmpA;
	TmpA = new ElementType[N];
	if (TmpA != NULL)  /* 如果内存申请成功 */
	{
		MSort(A, TmpA, 0, N-1);
		delete(TmpA);
	}
	else 
		cout << "空间不足" << endl;
}

/* 非递归实现归并算法的核心 */
void Merge1(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{/* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个序列 */
	int LeftEnd, Tmp, NumElement;

	LeftEnd = R - 1;
	Tmp = L;
	NumElement = RightEnd - L + 1;

	while (L <= LeftEnd && R <= RightEnd)
	{
		if (A[L] < A[R])
			TmpA[Tmp++] = A[L++];
		else
			TmpA[Tmp++] = A[R++];
	}
	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++];  /* 直接复制左边剩下的 */
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++];  /* 直接复制右边剩下的 */
}

/* 归并排序-非递归实现 */
void Merge_Pass(ElementType A[], ElementType TmpA[], int N, int length)
{
	int i;
	for ( i = 0; i <= N - 2 * length; i += 2 * length)
		Merge1(A, TmpA, i, i + length, i + 2 * length - 1);
	if (i + length < N)  /* 归并最后两个子列，可能两子列的长度不同 */
		Merge1(A, TmpA, i, i + length, N-1);
	else
		for (int j = i; j < N; j++)  /* 最后剩下一个子列 */
			TmpA[j] = A[j];
}

/* 统一函数接口 */
void Merge_Sort(ElementType A[], int N)
{
	/* 归并排序 */
	ElementType *TmpA;
	TmpA = new ElementType[N];
	int length = 1;
	if (TmpA != NULL)  /* 如果内存申请成功 */
	{
		while (length<N)
		{
			Merge_Pass(A, TmpA, N,length);
			length *= 2;
			Merge_Pass(TmpA, A, N, length);
			length *= 2;
		}
		delete(TmpA);
	}
	else
		cout << "空间不足" << endl;
}