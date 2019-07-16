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
{/* ���ˣ���H����H[p]Ϊ�����Ӷѵ���Ϊ��С�� */
	long long Parent, Child;
	ElementType X;
	X = H[p];  /*  ȡ��ָ�����ڵ��ŵ�ֵ */
	for (Parent = p; Parent * 2 + 1 <N; Parent = Child)
	{
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (H[Child] > H[Child + 1]))
			Child++;/* ѡȡ��������С�� */
		if (X <= H[Child])  break;  /* �ҵ����ʵ�λ�� */
		else  /* ����X */
			H[Parent] = H[Child];
	}
	H[Parent] = X;
}

void PercDown_Max(ElementType* H, long long p, long long N)
{/* ���ˣ���H����H[p]Ϊ�����Ӷѵ���Ϊ���� */
	long long Parent, Child;
	ElementType X;
	X = H[p];  /*  ȡ�����ڵ��ŵ�ֵ */
	for (Parent = p; Parent * 2 + 1 <N; Parent = Child)
	{
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (H[Child] < H[Child + 1]))
			Child++;/* ѡȡ���������� */
		if (X >= H[Child])  break;  /* �ҵ����ʵ�λ�� */
		else  /* ����X */
			H[Parent] = H[Child];
	}
	H[Parent] = X;
}


/* ������С�� */
void BuildHeap_Min(ElementType* H, long long N)
{ /* ����H->Data[]�е�Ԫ�أ�ʹ������С�ѵ�������  */
	/* �����������N��Ԫ���Ѿ�����H[]�� */
	long long i;

	/* �����һ�����ĸ��ڵ㿪ʼ���������0 */
	for (i = (N - 2) / 2; i >= 0; i--)
		PercDown_Min(H, i, N);
}

/*�������� */
void BulidHeap_Max(ElementType* H, long long N)
{
	/* ����H->Data[]�е�Ԫ�أ�ʹ������С�ѵ�������  */
	/* �����������N��Ԫ���Ѿ�����H[]�� */
	long long i;

	/* �����һ�����ĸ��ڵ㿪ʼ���������0 */
	for (i = (N - 2) / 2; i >= 0; i--)
		PercDown_Max(H, i, N);
}

ElementType DeleteMin(ElementType *H, long long N)
{
	Swap(&H[0], &H[N - 1]);
	/* ���¶ѵ���Ϊ��С�� */
	PercDown_Min(H, 0, N - 1);

	/* ����С�ѶѶ�Ԫ�ص��� */
	return H[N - 1];
}

ElementType DeleteMax(ElementType *H, long long N)
{
	Swap(&H[0], &H[N - 1]);
	/* ���¶ѵ���Ϊ��С�� */
	PercDown_Max(H, 0, N - 1);

	/* �����ѶѶ�Ԫ�ص��� */
	return H[N - 1];
}