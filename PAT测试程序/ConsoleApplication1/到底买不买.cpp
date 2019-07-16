//#include<iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string A;
//	string B;
//	int Acount[1000];
//	int Bcount[1000];
//	int Count = 0;
//	int i,j;
//	cin >> A;
//	cin >> B;
//	/* 标志位进行初始化 */
//	for (i = 0; i < A.length(); i++)
//		Acount[i] = 0;
//	for (i = 0; i < B.length(); i++)
//		Bcount[i] = 0;
//	for (i = 0; i < B.length(); i++)
//		for (j = 0; j < A.length();j++)
//		{
//			if (A[j] == B[i] && Acount[j] != 1 && Bcount[i] != 1){ /* 当两个元素相同时，且当前位置没有被标记过 */
//				Acount[j] = 1;  
//				Bcount[i] = 1;
//				break;  /* 如果已经找到对应的位置，结束内循环，开始新的一轮循环 */
//			}
//		}
//	for (j = 0; j < B.length();j++)
//	{
//		if (Bcount[j] == 0)
//			Count++;
//	}
//	if (Count == 0)
//		cout << "Yes" << " " << A.length() - B.length() << endl;
//	else
//		cout << "No" << " " << Count;
//
//	system("pause");
//	return 0;
//}