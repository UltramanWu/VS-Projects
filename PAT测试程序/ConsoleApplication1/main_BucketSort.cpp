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
//	for (int i = 0; i < K; i++)  /* 录入满分数组 */
//		cin >> FullScope[i];
//	Bucket BT = CreateBucket(N);  /* 创建数组 */
//	
//	//if (M == 1)  /* 成绩录入只有一组数据 */
//	//{
//	//	cin >> S->UID >> S->SID >> S->SNum;  /* 输入上传数据 */
//	//	/* 直接显示 */
//	//	cout << 1 << " ";  /* 显示排名 */
//	//	cout << "0000" << S->UID  << " ";  /* 显示学生序号 */
//	//	cout << S->SNum  << " ";  /* 显示总分 */
//	//	cout << S->SNum;  /* 显示成绩 */
//	//	cout << endl;
//	//}
//	 if (N == 1)  /* 如果只有一名学生录入 */
//	{
//		while (M--)  /* 收录进 */
//		{
//			cin >> S->UID >> S->SID >> S->SNum;  /* 输入上传数据 */
//			S->UID--; S->SID--;
//			InsertS(BT, S, FullScope);
//		}
//		/* 直接输出 */
//		cout << 1 << " ";  /* 显示排名 */
//		cout << "0000" << S->UID+1 << " ";  /* 显示学生序号 */
//		cout << BT[S->UID].Total_Scope;  /* 显示总分 */
//		for (int j = 0; j < K; j++){
//			if (BT[S->UID].Scope[j] == -1)
//				cout << " " << "-";
//			else
//				cout << " " << BT[S->UID].Scope[j];
//		}
//	}
//
//	else{  /* 超过一名学生 */
//		while (M--)
//		{
//			cin >> S->UID >> S->SID >> S->SNum;  /* 输入上传数据 */
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
//			if (BT[R[i]].Total_Scope != 0)  /* 当总成绩不为零时 */
//			{
//				rank += rankCount;
//				cout << rank << " ";  /* 显示排名 */
//				cout << "0000" << R[i] + 1 << " ";  /* 显示学生序号 */
//				cout << BT[R[i]].Total_Scope ;  /* 显示总分 */
//
//				for (int j = 0; j < K; j++){
//					if (BT[R[i]].Scope[j] == -1)
//						cout << " " << "-";
//					else
//						cout << " " << BT[R[i]].Scope[j];
//				}
//				cout << endl;  /* 输出回车 */
//				if (i + 1 < N)  /* 当前位置可以被访问时 */
//				{
//					if (BT[R[i + 1]].Total_Scope == BT[R[i]].Total_Scope) /* 如果下一位总分相同时 */
//					{
//						rankCount = 0;
//						TempCount++;
//					}
//					else{
//						rankCount = TempCount;
//						TempCount = 1;
//					}
//				}
//				else{  /* 当前位置不可被访问 */
//					rankCount = 0;   /* 恢复到原始状态 */
//					TempCount = 1;
//				}
//			}
//		}
//	}
//	
//	system("pause");
//	return 0;
//}