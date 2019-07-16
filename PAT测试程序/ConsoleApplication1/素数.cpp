//
//#if 1
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int main()
//{
//	int M, N;
//	int i, j;
//	int Count = 0;
//	cin >> M >> N;
//	/*求素数 */
//	for( i = 2;; i++)
//	{
//		for (j = 2; j<sqrt(i); j++)
//			if (i%j == 0)  break;  /* 如果当前值不是素数，直接跳出 */
//			
//		if (j>sqrt(i))  /* 如果当前值是素数 */
//		{
//				Count++;
//				if (Count >N)  break;
//				if (Count >= M && Count <= N)
//				{
//					cout << i;
//					if ((Count - M + 1) % 10 == 0)  /* 当个数达到10个时 */
//						cout << endl;
//					else if (Count <N)
//						cout << " ";
//				}
//				
//		}
//	}
//	system("pause");
//	return 0;
//}
//
//#endif
//
//
//#if 0
//#include<stdio.h>
//#include<math.h>
//int Prime(int a)
//{
//	for (int i = 2; i<=a / i; i++)
//		if (a%i == 0)
//			return 0;
//	return 1;
//}
//
//int main()
//{
//	int M, N;
//	int Count = 0;
//	scanf_s("%d %d", &M, &N);
//
//	for (int i = 2;; i++)
//	{
//		if (Prime(i))
//		{
//			Count++;
//			if (Count >N) break;
//			if (Count >= M && Count <= N){
//				if ((Count - M + 1) % 10 == 0)
//					printf("%d\n", i);
//				else if (Count < N)
//					printf("%d ", i);
//				else
//					printf("%d", i);
//			}
//		}
//	}
//	getchar();
//	getchar();
//	return 0;
//}
//#endif