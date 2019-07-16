//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	int N;
//	string ID[100];
//	int flag[100];
//	int Z[100];
//	const int Weight[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
//	char M[] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
//	int i, j;
//	long long int Sum;
//	cin >> N;
//	for (i = 0; i < N; i++)  /* 收录数据 */
//		cin >> ID[i];
//
//	/* 取模运算并检验前17位是否为数字 */
//	for (i = 0; i < N; i++){
//		flag[i] = 0;  /* 标志初始化 */
//		Sum = 0;
//		for (j = 0; j < 17; j++)
//		{
//			if (ID[i][j] >= '0' && ID[i][j] <= '9')
//				Sum += (ID[i][j] - '0')*Weight[j];
//			else{
//				flag[i] = 1;
//				break;
//			}
//		}
//		Sum %= 11;  /* 取模运算 */
//		if (ID[i][17] != M[Sum])
//			flag[i] = 1;  /* 如果校验码不符合，将标志位置位 */
//	}
//	int count = 0;
//	for (i = 0; i < N; i++){
//		if (flag[i] == 1){
//			cout << ID[i] << endl;
//			count++;
//		}
//	}
//	if (count == 0)
//		cout << "All passed" << endl;
//
//
//	system("pause");
//	return 0;
//}