////
//// Created by Win_Lin on 2019/5/16.
////
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	char A[1000];  /* 被除数 */
//	int B;   /* 除数 */
//	char Q[1000];   /* 商 */
//	int R;  /* 余数 */
//	int flag = 0;
//	int i;
//	for (i = 0; i < 1000; i++)
//		Q[i] = '\0';
//
//	cin >> A >> B;
//
//	for (i = 0; A[i] != '\0'; i++){
//		if (i == 0)/* 当取第一位进行计算时，*/
//		{
//			Q[i] = (A[i] - '0') / B + '0';
//			R = (A[i] - '0') % B;
//		}
//		else
//		{
//			Q[i] = (R * 10 + A[i] - '0') / B + '0';
//			R = (R * 10 + A[i] - '0') % B;
//		}
//	}
//	for (int j = 0; Q[j] != '\0'; ++j) {
//		if( (Q[j] == '0')&& !flag) 
//
//			continue;
//		else
//		{
//			flag = 1;  /* 置位 */
//			cout << Q[j];
//		}
//		
//	}
//	cout << " " << R;
//
//	system("pause");
//	return 0;
//}