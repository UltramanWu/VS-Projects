#include"Search_BinTree.h"

int main()
{
	int N,L;
	Tree SBT;
	ElementType Data;
	cin >> N;
	while (N){
		cin >> L;
		SBT = CreatTree(N);  /* ���õ�һ������ֵ�������Ĺ��� */
		for (int  i = 0; i <L; i++)
		{
			if (Judge(SBT, N)) cout << "YES!" << endl;  /* */
			else cout << "NO!" << endl;
			Reset(SBT);  /* ��ʼ��������״̬ */
		}
		DeleteT(SBT);  /* �ͷŶ������ռ䣬�Է��������Խ�����һ�εıȽ� */
		cin >> N;  /* ������һ����Ҫ�Ƚϵ����и��� */
	}

	system("pause");
	return 0;
}