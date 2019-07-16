#include"Heap.h"


#define MaxVertexNum 100000


/* ð������ */
void Bubble_Sort(ElementType A[], long long N)
{
	int flag = 0;
	for (long long P = N - 1; P >= 0; P--)
	{
		flag = 0;
		for (long long i = 0; i < P; i++)
		{
			if (A[i] > A[i + 1]){
				Swap(&A[i], &A[i + 1]); /* ���߽��н��� */
				flag = 1;
			}
		}
		if (flag == 0) break;  /* ��ʱ�����ٽ������� */
	}
}


/* �������� */
void Insert_Sort(ElementType A[], long long N)
{
	/* ��Ϊ���е���Ϊ0 */

	ElementType TmpA;
	long long  i;
	for (long long P = 1; P < N; P++)
	{
		TmpA = A[P];
		for (i = P; i >0 && A[i - 1]>TmpA; i--)
		{
			A[i] = A[i - 1];  /* ��Ԫ�غ��� */
		}
		A[i] = TmpA;  /* ��Ԫ�طŵ�ָ��λ�� */
	}
}

/* ϣ������ */
void Shell_Sort(ElementType A[], long long N)
{ /* ԭʼϣ������������Ԫ�ز����ʣ����»�Ӱ�����Ԫ�ص�����˳�� */
	ElementType TmpA;
	long long  i;
	int si;  /* �ֲ�����Ҫ���г�ʼ�� */
	int Sedgewick[] = { 929, 505, 209, 109, 41, 19, 5, 1, 0 };
	for (si = 0; Sedgewick[si] >= N; si++)  /* ��Sedgewick�������� */
		;
	for (long long D = Sedgewick[si]; D >0; D = Sedgewick[++si])  /* ԭʼϣ���������� */
	{
		for (long long P = D; P < N; P++)
		{
			TmpA = A[P];
			for (i = P; i >D-1 && A[i - D]>TmpA; i -= D)
				A[i] = A[i - D];  /* ��Ԫ�غ��� */

			A[i] = TmpA;  /* ��Ԫ�طŵ�ָ��λ�� */
		}	
	}
}

/* ������СԪ�� */
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

/* ѡ������ */
void Select_Sort(ElementType A[], long long N)
{
	long long MinPosition = 0;
	for (int i = 0; i < N; i++){
		MinPosition = ScanForMin(A, i, N);
		/* ���ѡ���Ԫ��λ����������ʼλ�Ͳ����н��� */
		if (MinPosition == i) continue;
		/* ��δ����Ĳ��ֵ���СԪ�������򲿷ֵ����λ�� */
		Swap(&A[i], &A[MinPosition]);
	}
}
/* ������ */
void Heap_Sort(ElementType A[], long long N)
{
	/* ÿһ�δ���С���л����Сֵ����뵽���������� */
	ElementType TmpA[MaxVertexNum];
	/* ������ */
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

/* ���͸��ӶȵĶ������㷨 */
void Heap_Sort_Max(ElementType A[], long long N)
{
	long long Count = N;
	for (; Count > 0; Count--)
	{
		if (Count == N)
			BulidHeap_Max(A, Count); /* �������� */
		else
			PercDown_Max(A, 0, Count);  /* �������� */
		Swap(&A[0], &A[Count-1]);  /* ��Ѷ���ĩβԪ�ؽ��н��� */
		//Count--;  /* �ų���ĩβԪ�� */
	}
}
/* �鲢���� -�ݹ�ʵ��*/

/* �鲢�㷨�ĺ��� */
/* L =  �����ʼλ�ã�R = �ұ���ʼλ�ã�RightEnd = �ұ��յ�λ�� */
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{/* �������A[L]~A[R-1]��A[R]~A[RightEnd]�鲢��һ������ */
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
		TmpA[Tmp++] = A[L++];  /* ֱ�Ӹ������ʣ�µ� */
	while (R<=RightEnd)
		TmpA[Tmp++] = A[R++];  /* ֱ�Ӹ����ұ�ʣ�µ� */

	for (int i = 0; i < NumElement; i++,RightEnd--)  /* ���ź�������и��Ƶ�ԭ������ */
		A[RightEnd] = TmpA[RightEnd];
}
/* �ݹ鷽��ʵ�� */
void MSort(ElementType A[], ElementType TmpA[], int L, int RightEnd)
{
	int Center;
	if (L < RightEnd)
	{
		Center = (L + RightEnd) / 2;
		MSort(A, TmpA, L, Center);  /* �ݹ����벿�ֽ��й鲢 */
		MSort(A, TmpA, Center + 1, RightEnd);  /* �ݹ���Ұ벿�ֽ��й鲢 */
		Merge(A, TmpA, L, Center + 1, RightEnd);  /* ���������е������ֽ��й鲢 */
	}
}

/* ͳһ�����ӿ� */
void MergeSort(ElementType A[], int N)
{
	/* �鲢���� */
	ElementType *TmpA;
	TmpA = new ElementType[N];
	if (TmpA != NULL)  /* ����ڴ�����ɹ� */
	{
		MSort(A, TmpA, 0, N-1);
		delete(TmpA);
	}
	else 
		cout << "�ռ䲻��" << endl;
}

/* �ǵݹ�ʵ�ֹ鲢�㷨�ĺ��� */
void Merge1(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{/* �������A[L]~A[R-1]��A[R]~A[RightEnd]�鲢��һ������ */
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
		TmpA[Tmp++] = A[L++];  /* ֱ�Ӹ������ʣ�µ� */
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++];  /* ֱ�Ӹ����ұ�ʣ�µ� */
}

/* �鲢����-�ǵݹ�ʵ�� */
void Merge_Pass(ElementType A[], ElementType TmpA[], int N, int length)
{
	int i;
	for ( i = 0; i <= N - 2 * length; i += 2 * length)
		Merge1(A, TmpA, i, i + length, i + 2 * length - 1);
	if (i + length < N)  /* �鲢����������У����������еĳ��Ȳ�ͬ */
		Merge1(A, TmpA, i, i + length, N-1);
	else
		for (int j = i; j < N; j++)  /* ���ʣ��һ������ */
			TmpA[j] = A[j];
}

/* ͳһ�����ӿ� */
void Merge_Sort(ElementType A[], int N)
{
	/* �鲢���� */
	ElementType *TmpA;
	TmpA = new ElementType[N];
	int length = 1;
	if (TmpA != NULL)  /* ����ڴ�����ɹ� */
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
		cout << "�ռ䲻��" << endl;
}