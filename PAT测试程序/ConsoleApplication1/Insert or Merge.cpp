//#include<iostream>
//using namespace std;
//
//typedef int ElementType;
//typedef int MaxHeap;
//const int MaxItemNum = 100;  /* ������const��enum��inline����#define */
//
///* �������� */
//void Insertion_Sort(ElementType A[], ElementType Compare[], int N)
//{
//	int flag = 1;
//	int flag1 = 1;
//	int Count = 0;
//	ElementType TmpA;  /* �Ե�ǰԪ�صı��� */
//	for (int P = 1; P<N && flag == 1; P++){
//		TmpA = A[P];
//		Count = 0;
//		int i;
//		for (i = P; i>0 && A[i - 1]>TmpA; i--)
//		{
//			A[i] = A[i - 1];
//		}
//		A[i] = TmpA;
//		if (flag1 == 0)
//			flag = 0;
//		/* �����������ж� */
//		for (int i = 0; i<N; i++)
//			if (A[i] == Compare[i])
//				Count++;
//		if (Count == N)  /* �������������ͬ�Ļ����ʾ */
//			flag1 = 0;
//	}
//	if (flag == 0)
//	{
//		cout << "Insertion Sort" << endl;
//		for (int i = 0; i<N; i++)
//		{
//			if (i > 0)
//				cout << " ";
//			cout << A[i];
//		}
//	}
//}
//
///* ���Ѳ����� */
///* Ԫ�ؽ��� */
//void Swap(ElementType *a, ElementType *b)
//{
//	ElementType temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
///* ���˲��� */
//void PercDown(MaxHeap *H, int P, int N)
//{
//	int Parent, Child;
//	ElementType Temp = H[P];  /* ���浱ǰֵ */
//	for (Parent = P; Parent * 2 + 1<N; Parent = Child)
//	{
//		Child = Parent * 2 + 1;
//		if ((Child != N - 1) && (H[Child] < H[Child + 1]))
//			Child++;  /* ѡ���ӽڵ�����ֵ�ϴ���Ǹ� */
//		if (Temp >= H[Child])  break;   /* �ҵ���Ӧ��λ�� */
//
//		H[Parent] = H[Child];
//	}
//	H[Parent] = Temp;
//}
///* �������� */
//void CreateHeap_Max(ElementType A[], int N)
//{
//	for (int i = (N - 1) / 2; i >= 0; i--)
//		PercDown(A, i, N-1);
//}
//
///* ������ */
//void Heap_Sort(ElementType A[], ElementType Compare[], int N)
//{
//	int flag, flag1, ACount;
//	flag = flag1 = 1;
//	CreateHeap_Max(A, N);  /* �������� */
//	for (int Count = N - 1; Count>0 && flag == 1; Count--)
//	{
//		ACount = 0;
//		Swap(&A[0], &A[Count]);  /* �Ƚ���Ԫ�ؽ�����Ȼ���Ԫ�ؽ������˲��� */
//		PercDown(A, 0, Count);
//		if (flag1 == 0)  flag = 0;  /* ��flag1��������һ�������� */
//		/* ���������������ж� */
//		for (int i = 0; i<N; i++)
//			if (A[i] == Compare[i])
//				ACount++;
//		if (ACount == N)
//			flag1 = 0;
//	}
//
//	if (flag == 0)  /* �������Ϊflag���㵼������ */
//	{
//		cout << "Heap Sort" << endl;
//		for (int i = 0; i<N; i++)
//		{
//			if (i>0)
//				cout << " ";
//			cout << A[i];
//		}
//	}
//}
//
//int main()
//{
//	int N;
//	ElementType A[MaxItemNum], Compare[MaxItemNum];
//	ElementType Temp[MaxItemNum];  /* ����A���ݣ���ֹ������������ʱ������ */
//	cin >> N;
//	for (int i = 0; i<N; i++)  /*�����ռ�*/
//	{
//		cin >> A[i];
//	}
//	for (int i = 0; i<N; i++)  /*�����ռ�*/
//	{
//		cin >> Compare[i];
//	}
//	for (int i = 0; i < N; i++)
//		Temp[i] = A[i];
//	Heap_Sort(A, Compare, N);
//	Insertion_Sort(Temp, Compare, N);
//	return 0;
//}
