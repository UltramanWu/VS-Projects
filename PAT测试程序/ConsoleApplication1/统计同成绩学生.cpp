//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int N, S, Scope[101];
//	int K,TmpK, i,*SearchS;
//	for (int i = 0; i < 101; i++)  /* ��������г�ʼ�� */
//		Scope[i] = 0;
//	cin >> N;
//	while (N--){
//		cin >> S;
//		Scope[S]++;  /* ��Ӧ������Ԫ�ؼ�1 */
//	}
//	cin >> K;
//	TmpK = K;
//	i = 0;
//	SearchS = new int[K];
//	while (TmpK--)
//		cin >> SearchS[i++];
//	for (i = 0; i < K; i++){
//		if (i > 0)
//			cout << " ";
//		cout << Scope[SearchS[i]];
//	}
//		
//	cout << endl;
//	system("pause");
//	return 0;
//}