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
//	for (i = 0; i < N; i++)  /* ��¼���� */
//		cin >> ID[i];
//
//	/* ȡģ���㲢����ǰ17λ�Ƿ�Ϊ���� */
//	for (i = 0; i < N; i++){
//		flag[i] = 0;  /* ��־��ʼ�� */
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
//		Sum %= 11;  /* ȡģ���� */
//		if (ID[i][17] != M[Sum])
//			flag[i] = 1;  /* ���У���벻���ϣ�����־λ��λ */
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