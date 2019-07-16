//#include <iostream>
//using namespace std;
//
///* �������� */
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
//		/* �������жԱ���֤ */
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
//	/* ������־λ��λ������ѭ�� */
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
///* �鲢����-�ǵݹ�ʵ�� */
//void Merge(int A[],int TmpA[],int L,int R,int RightEnd)
//{
//	int Left, Right,Tmp,ItemNum;
//	int LeftEnd;
//	Left = L;
//	Right = R;
//	LeftEnd = R - 1;
//	Tmp = L;
//	ItemNum = RightEnd - L + 1;  /* Ԫ���ܸ��� */
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
//	if (i + length < N)  /* ������������ */
//		Merge(A, TmpA, i, i + length, N - 1);
//	else  /* ֻ����һ������ */
//		for (; i < N; i++)
//			TmpA[i] = A[i];
//
//	for ( i = 0; i < N; i++)
//	{
//		A[i] = TmpA[i];  /* ���Ƶ�ԭ���� */
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
//		Merge_Sort(A, TmpA, length, N);  /* �ǵݹ�鲢���� */
//		length *= 2;  /* �������� */
//		if (flag_pre == 1)  /* ���Ԥ�ȱ�־λ����λ */
//			flag = 1;  /* ��־λ����λ */
//
//		/* ������������֤ */
//		for (i = 0; i < N;i++)
//		{
//			if (A[i] != Compare[i])  /* �������ж�ӦԪ�ز�һ��ʱ��ֱ���˳� */
//				break;
//		}
//		if (i == N)
//			flag_pre = 1;
//	}
//	delete[] TmpA;
//	/* �����ǰflag����λ */
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
//	cin >> N;   /* ¼��Ԫ�ظ��� */
//	for (i = 0; i < N; i++){  /* ¼��ԭʼ���� */
//		cin >> A[i];
//		TmpA[i] = A[i];
//	}
//
//	for (i = 0; i < N; i++)  /* ¼��Ա����� */
//		cin >> Compare[i];
//
//	Insert_Sort(A, Compare, N);
//	M_Sort(TmpA, Compare, N);
//
//	system("pause");
//	return 0;
//}