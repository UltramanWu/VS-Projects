#include<iostream>
using namespace std;

#include"Sort.h"

/* ��������  */

/* ѡȡ���С������ߵ���λ�� */
ElementType Median3(ElementType A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Right]);
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if (A[Center]>A[Right])
		Swap(&A[Center], &A[Right]);
	/* ���ϲ���ʹ�����С�������Ԫ�ذ��մ�С�����˳��������� */
	Swap(&A[Center], &A[Right - 1]);  /* ����׼Pivot�ص��ұ� */
	/* ֻ��Ҫ����A[Left+1]~A[Right-2]  */
	return A[Right - 1];  /* ���ػ�׼Pivot */
}

/* ��������-�ݹ���� */
void QSort(ElementType A[], int Left, int Right)
{/* ���ĵݹ麯�� */
	int Pivot, Cutoff, Low, High;
	Cutoff = 0;
	if (Cutoff <= Right - Left)  /* ���Ԫ�ظ����϶�ʱ */
	{
		Pivot = Median3(A, Left, Right);  /* ѡ��׼ */
		Low = Left;  High = Right - 1;
		while (1)
		{
			while (A[++Low] < Pivot){}
			while (A[--High] > Pivot){}
			if (High - Low > 0)  /* �������֮�仹��Ԫ��  */
				Swap(&A[Low], &A[High]);  /* Ԫ�ؽ��л��� */
			else break;
		}
		Swap(&A[Low], &A[Right - 1]);  /* ���׼������ȷ��λ�� */

		/* ���������е�Ԫ�ظ���ֻ��һ��ʱ�������ٶ�����еݹ���� */
		if (Left < Low-1)
			QSort(A, Left, Low - 1);  /* �Ի�׼�������н��еݹ���� */
		if (Right>Low+1)
			QSort(A, Low + 1, Right);
	}
	else  /* ��Ԫ�ؽ���ʱ��ʹ�ÿ��������Ч�ʲ��ߣ�����ʹ�ü������һ�� */
		Insert_Sort(A + Left, Right - Left + 1);
}

/* ͳһ�����ӿ� */
void Q_Sort(ElementType A[], int N)
{/* ͳһ�ӿ� */
	QSort(A, 0, N - 1);
}