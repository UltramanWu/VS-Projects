#include<iostream>
using namespace std;

typedef int ElementType;
#define MaxVertexNum 100000

void Swap(ElementType* a, ElementType *b)
{
	ElementType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void PercDown_Min(ElementType* H, long long p, long long N)
{/* 下滤：将H中以H[p]为根的子堆调整为最小堆 */
	long long Parent, Child;
	ElementType X;
	X = H[p];  /*  取出指定父节点存放的值 */
	for (Parent = p; Parent * 2 + 1 <N; Parent = Child)
	{
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (H[Child] > H[Child + 1]))
			Child++;/* 选取二者中最小的 */
		if (X <= H[Child])  break;  /* 找到合适的位置 */
		else  /* 下滤X */
			H[Parent] = H[Child];
	}
	H[Parent] = X;
}

void PercDown_Max(ElementType* H, long long p, long long N)
{/* 下滤：将H中以H[p]为根的子堆调整为最大堆 */
	long long Parent, Child;
	ElementType X;
	X = H[p];  /*  取出根节点存放的值 */
	for (Parent = p; Parent * 2 + 1 <N; Parent = Child)
	{
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (H[Child] < H[Child + 1]))
			Child++;/* 选取二者中最大的 */
		if (X >= H[Child])  break;  /* 找到合适的位置 */
		else  /* 下滤X */
			H[Parent] = H[Child];
	}
	H[Parent] = X;
}


/* 创建最小堆 */
void BuildHeap_Min(ElementType* H, long long N)
{ /* 调整H->Data[]中的元素，使满足最小堆的有序性  */
	/* 这里假设所有N个元素已经存在H[]中 */
	long long i;

	/* 从最后一个结点的父节点开始，到根结点0 */
	for (i = (N - 2) / 2; i >= 0; i--)
		PercDown_Min(H, i, N);
}

/*创建最大堆 */
void BulidHeap_Max(ElementType* H, long long N)
{
	/* 调整H->Data[]中的元素，使满足最小堆的有序性  */
	/* 这里假设所有N个元素已经存在H[]中 */
	long long i;

	/* 从最后一个结点的父节点开始，到根结点0 */
	for (i = (N - 2) / 2; i >= 0; i--)
		PercDown_Max(H, i, N);
}

ElementType DeleteMin(ElementType *H, long long N)
{
	Swap(&H[0], &H[N - 1]);
	/* 将新堆调整为最小堆 */
	PercDown_Min(H, 0, N - 1);

	/* 将最小堆堆顶元素弹出 */
	return H[N - 1];
}

ElementType DeleteMax(ElementType *H, long long N)
{
	Swap(&H[0], &H[N - 1]);
	/* 将新堆调整为最小堆 */
	PercDown_Max(H, 0, N - 1);

	/* 将最大堆堆顶元素弹出 */
	return H[N - 1];
}