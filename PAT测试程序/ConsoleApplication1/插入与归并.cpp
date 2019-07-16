//#include <iostream>
//using namespace std;
//
///* 插入排序 */
//void Insert_Sort(int A[],int Compare[],int N)
//{
//	int P, i, j;
//	int flag, flag_pre;
//	flag = flag_pre = 0;
//	int Tmp;
//	for (P = 1; P < N&&!flag;P++)
//	{
//		Tmp = A[P];
//		for (i = P; i > 0 && A[i - 1] > Tmp; i--)
//			A[i] = A[i - 1];
//		A[i] = Tmp;
//		/* 进行序列对比验证 */
//		if (flag_pre == 1)
//			flag = 1;
//		j = 0;
//		while (j < N)
//		{
//			if(A[j] != Compare[j])
//				break;
//			j++;
//		}
//		if (j == N)
//			flag_pre = 1;
//	}
//	/* 如果因标志位置位而结束循环 */
//	if (flag == 1){
//		cout << "Insertion Sort" << endl;
//		for (i = 0; i < N; i++){
//			if (i > 0)
//				cout << " ";
//			cout << A[i];
//		}
//	}
//		
//}
//
//
///* 归并排序-非递归实现 */
//void Merge(int A[],int TmpA[],int L,int R,int RightEnd)
//{
//	int Left, Right,Tmp,ItemNum;
//	int LeftEnd;
//	Left = L;
//	Right = R;
//	LeftEnd = R - 1;
//	Tmp = L;
//	ItemNum = RightEnd - L + 1;  /* 元素总个数 */
//
//	while (L<=LeftEnd&&R<=RightEnd)
//	{
//		if (A[L] < A[R])
//			TmpA[Tmp++] = A[L++];
//		else
//			TmpA[Tmp++] = A[R++];
//	}
//	while (L<=LeftEnd)
//		TmpA[Tmp++] = A[L++];
//
//	while (R<=RightEnd)
//		TmpA[Tmp++] = A[R++];	
//}
//
//void Merge_Sort(int A[], int TmpA[],int length, int N)
//{
//	int i;
//	for (i = 0; i + 2 * length < N; i += 2 * length)
//		Merge(A, TmpA, i, i+length,i + 2 * length - 1);
//	if (i + length < N)  /* 存在两个子列 */
//		Merge(A, TmpA, i, i + length, N - 1);
//	else  /* 只存在一个子列 */
//		for (; i < N; i++)
//			TmpA[i] = A[i];
//
//	for ( i = 0; i < N; i++)
//	{
//		A[i] = TmpA[i];  /* 复制到原序列 */
//	}
//}
//
//void M_Sort(int A[],int Compare[],int N)
//{
//	int length = 1;
//	int i;
//	int flag, flag_pre;
//	int *TmpA = new int[N];
//	flag = flag_pre = 0;
//	while (length < N && !flag)
//	{
//		Merge_Sort(A, TmpA, length, N);  /* 非递归归并排序 */
//		length *= 2;  /* 步长翻倍 */
//		if (flag_pre == 1)  /* 如果预先标志位被置位 */
//			flag = 1;  /* 标志位被置位 */
//
//		/* 序列相似性验证 */
//		for (i = 0; i < N;i++)
//		{
//			if (A[i] != Compare[i])  /* 当两序列对应元素不一致时，直接退出 */
//				break;
//		}
//		if (i == N)
//			flag_pre = 1;
//	}
//	delete[] TmpA;
//	/* 如果当前flag被置位 */
//	if (flag == 1)
//	{
//		cout << "Merge Sort" <<  endl;
//		for (i = 0; i < N; i++){
//			if (i > 0)
//				cout << " ";
//			cout << A[i];
//		}
//	}
//}
//
//int main()
//{
//	int N;
//	int i;
//	int A[100];
//	int Compare[100];
//	int TmpA[100];
//
//	cin >> N;   /* 录入元素个数 */
//	for (i = 0; i < N; i++){  /* 录入原始序列 */
//		cin >> A[i];
//		TmpA[i] = A[i];
//	}
//
//	for (i = 0; i < N; i++)  /* 录入对比序列 */
//		cin >> Compare[i];
//
//	Insert_Sort(A, Compare, N);
//	M_Sort(TmpA, Compare, N);
//
//	system("pause");
//	return 0;
//}