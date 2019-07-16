//#include<iostream>
//using namespace std;
//
//typedef int ElementType;
//typedef int MaxHeap;
//const int MaxItemNum = 100;  /* 尽量以const、enum与inline代替#define */
//
///* 插入排序 */
//void Insertion_Sort(ElementType A[], ElementType Compare[], int N)
//{
//	int flag = 1;
//	int flag1 = 1;
//	int Count = 0;
//	ElementType TmpA;  /* 对当前元素的备份 */
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
//		/* 序列相似性判断 */
//		for (int i = 0; i<N; i++)
//			if (A[i] == Compare[i])
//				Count++;
//		if (Count == N)  /* 如果序列排列相同的话则表示 */
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
///* 最大堆操作集 */
///* 元素交换 */
//void Swap(ElementType *a, ElementType *b)
//{
//	ElementType temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
///* 下滤操作 */
//void PercDown(MaxHeap *H, int P, int N)
//{
//	int Parent, Child;
//	ElementType Temp = H[P];  /* 保存当前值 */
//	for (Parent = P; Parent * 2 + 1<N; Parent = Child)
//	{
//		Child = Parent * 2 + 1;
//		if ((Child != N - 1) && (H[Child] < H[Child + 1]))
//			Child++;  /* 选择子节点中数值较大的那个 */
//		if (Temp >= H[Child])  break;   /* 找到相应的位置 */
//
//		H[Parent] = H[Child];
//	}
//	H[Parent] = Temp;
//}
///* 创建最大堆 */
//void CreateHeap_Max(ElementType A[], int N)
//{
//	for (int i = (N - 1) / 2; i >= 0; i--)
//		PercDown(A, i, N-1);
//}
//
///* 堆排序 */
//void Heap_Sort(ElementType A[], ElementType Compare[], int N)
//{
//	int flag, flag1, ACount;
//	flag = flag1 = 1;
//	CreateHeap_Max(A, N);  /* 创建最大堆 */
//	for (int Count = N - 1; Count>0 && flag == 1; Count--)
//	{
//		ACount = 0;
//		Swap(&A[0], &A[Count]);  /* 先进行元素交换，然后对元素进行下滤操作 */
//		PercDown(A, 0, Count);
//		if (flag1 == 0)  flag = 0;  /* 在flag1置零后的下一周期跳出 */
//		/* 增加序列相似性判断 */
//		for (int i = 0; i<N; i++)
//			if (A[i] == Compare[i])
//				ACount++;
//		if (ACount == N)
//			flag1 = 0;
//	}
//
//	if (flag == 0)  /* 如果是因为flag置零导致跳出 */
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
//	ElementType Temp[MaxItemNum];  /* 备份A数据，防止其在两次排序时被更改 */
//	cin >> N;
//	for (int i = 0; i<N; i++)  /*数据收集*/
//	{
//		cin >> A[i];
//	}
//	for (int i = 0; i<N; i++)  /*数据收集*/
//	{
//		cin >> Compare[i];
//	}
//	for (int i = 0; i < N; i++)
//		Temp[i] = A[i];
//	Heap_Sort(A, Compare, N);
//	Insertion_Sort(Temp, Compare, N);
//	return 0;
//}
