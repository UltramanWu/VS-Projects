#include<iostream>
using namespace std;

#include"Sort.h"

/* 快速排序  */

/* 选取左、中、右三者的中位数 */
ElementType Median3(ElementType A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Right]);
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if (A[Center]>A[Right])
		Swap(&A[Center], &A[Right]);
	/* 以上操作使得左、中、右三个元素按照从小到大的顺序进行排列 */
	Swap(&A[Center], &A[Right - 1]);  /* 将基准Pivot藏到右边 */
	/* 只需要考虑A[Left+1]~A[Right-2]  */
	return A[Right - 1];  /* 返回基准Pivot */
}

/* 快速排序-递归调用 */
void QSort(ElementType A[], int Left, int Right)
{/* 核心递归函数 */
	int Pivot, Cutoff, Low, High;
	Cutoff = 0;
	if (Cutoff <= Right - Left)  /* 如果元素个数较多时 */
	{
		Pivot = Median3(A, Left, Right);  /* 选基准 */
		Low = Left;  High = Right - 1;
		while (1)
		{
			while (A[++Low] < Pivot){}
			while (A[--High] > Pivot){}
			if (High - Low > 0)  /* 如果两者之间还有元素  */
				Swap(&A[Low], &A[High]);  /* 元素进行互换 */
			else break;
		}
		Swap(&A[Low], &A[Right - 1]);  /* 令基准换到正确的位置 */

		/* 当左右序列的元素个数只有一个时，将不再对其进行递归调用 */
		if (Left < Low-1)
			QSort(A, Left, Low - 1);  /* 对基准两侧序列进行递归调用 */
		if (Right>Low+1)
			QSort(A, Low + 1, Right);
	}
	else  /* 当元素较少时，使用快速排序的效率不高，考虑使用简单排序的一种 */
		Insert_Sort(A + Left, Right - Left + 1);
}

/* 统一函数接口 */
void Q_Sort(ElementType A[], int N)
{/* 统一接口 */
	QSort(A, 0, N - 1);
}