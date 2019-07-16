//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int N; /* 参赛人数 */
//	int MaxI;
//	int i;
//	long long int MaxS = 0;  /* 最大值 */
//	long long int Scope;  /* 最大值 */
//	long long int Score[100001];  /* 学校总分 */
//
//	cin >> N;
//
//	for (i = 1; i < 100001; i++)  /* 对当前的分数数组进行初始化 */
//		Score[i] = 0;
//
//	while (N--)  /* 收录数据 */
//	{
//		cin >> i >> Scope;
//		Score[i] += Scope;
//		if (MaxS < Score[i])  /* 如有最大值进行更换 */
//		{
//			MaxS = Score[i];
//			MaxI = i;
//		}
//	}
//
//	cout << MaxI << " " << MaxS;  /* 输出学校编号与总分值 */
//
//	system("pause");
//	return 0;
//}