//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int N; /* �������� */
//	int MaxI;
//	int i;
//	long long int MaxS = 0;  /* ���ֵ */
//	long long int Scope;  /* ���ֵ */
//	long long int Score[100001];  /* ѧУ�ܷ� */
//
//	cin >> N;
//
//	for (i = 1; i < 100001; i++)  /* �Ե�ǰ�ķ���������г�ʼ�� */
//		Score[i] = 0;
//
//	while (N--)  /* ��¼���� */
//	{
//		cin >> i >> Scope;
//		Score[i] += Scope;
//		if (MaxS < Score[i])  /* �������ֵ���и��� */
//		{
//			MaxS = Score[i];
//			MaxI = i;
//		}
//	}
//
//	cout << MaxI << " " << MaxS;  /* ���ѧУ������ܷ�ֵ */
//
//	system("pause");
//	return 0;
//}