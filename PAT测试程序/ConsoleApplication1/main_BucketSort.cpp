//#include"Bucket_Sort.h"
//
//int main()
//{
//	int N, K, M;
//	int FullScope[MaxSubjectNum];
//	int R[7];
//	//Bucket BT = new struct BucketNode;
//	Scope S = new struct ScopeNode;
//	cin >> N >> K >> M;
//	for (int i = 0; i < K; i++)  /* ¼���������� */
//		cin >> FullScope[i];
//	Bucket BT = CreateBucket(N);  /* �������� */
//	
//	//if (M == 1)  /* �ɼ�¼��ֻ��һ������ */
//	//{
//	//	cin >> S->UID >> S->SID >> S->SNum;  /* �����ϴ����� */
//	//	/* ֱ����ʾ */
//	//	cout << 1 << " ";  /* ��ʾ���� */
//	//	cout << "0000" << S->UID  << " ";  /* ��ʾѧ����� */
//	//	cout << S->SNum  << " ";  /* ��ʾ�ܷ� */
//	//	cout << S->SNum;  /* ��ʾ�ɼ� */
//	//	cout << endl;
//	//}
//	 if (N == 1)  /* ���ֻ��һ��ѧ��¼�� */
//	{
//		while (M--)  /* ��¼�� */
//		{
//			cin >> S->UID >> S->SID >> S->SNum;  /* �����ϴ����� */
//			S->UID--; S->SID--;
//			InsertS(BT, S, FullScope);
//		}
//		/* ֱ����� */
//		cout << 1 << " ";  /* ��ʾ���� */
//		cout << "0000" << S->UID+1 << " ";  /* ��ʾѧ����� */
//		cout << BT[S->UID].Total_Scope;  /* ��ʾ�ܷ� */
//		for (int j = 0; j < K; j++){
//			if (BT[S->UID].Scope[j] == -1)
//				cout << " " << "-";
//			else
//				cout << " " << BT[S->UID].Scope[j];
//		}
//	}
//
//	else{  /* ����һ��ѧ�� */
//		while (M--)
//		{
//			cin >> S->UID >> S->SID >> S->SNum;  /* �����ϴ����� */
//			S->UID--; S->SID--;
//			InsertS(BT, S, FullScope);
//		}
//
//		Rank(BT, R, N);
//		int rank = 1;
//		int rankCount = 0;
//		int TempCount = 1;
//		for (int i = 0; i < N; i++)
//		{
//			if (BT[R[i]].Total_Scope != 0)  /* ���ܳɼ���Ϊ��ʱ */
//			{
//				rank += rankCount;
//				cout << rank << " ";  /* ��ʾ���� */
//				cout << "0000" << R[i] + 1 << " ";  /* ��ʾѧ����� */
//				cout << BT[R[i]].Total_Scope ;  /* ��ʾ�ܷ� */
//
//				for (int j = 0; j < K; j++){
//					if (BT[R[i]].Scope[j] == -1)
//						cout << " " << "-";
//					else
//						cout << " " << BT[R[i]].Scope[j];
//				}
//				cout << endl;  /* ����س� */
//				if (i + 1 < N)  /* ��ǰλ�ÿ��Ա�����ʱ */
//				{
//					if (BT[R[i + 1]].Total_Scope == BT[R[i]].Total_Scope) /* �����һλ�ܷ���ͬʱ */
//					{
//						rankCount = 0;
//						TempCount++;
//					}
//					else{
//						rankCount = TempCount;
//						TempCount = 1;
//					}
//				}
//				else{  /* ��ǰλ�ò��ɱ����� */
//					rankCount = 0;   /* �ָ���ԭʼ״̬ */
//					TempCount = 1;
//				}
//			}
//		}
//	}
//	
//	system("pause");
//	return 0;
//}