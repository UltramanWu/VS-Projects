// ɢ�в���.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include"HashTable.h"

int main()
{
	int N, i;
	HashTable H;
	ElementType E;
	cin >> N;
	H = CreateTable(N);
	/* ������� */
	for (i = 0; i < N; i++){
		cin >> E; Insert(H, E);
		cin >> E; Insert(H, E);
	}
	/* ɨ�貢������ֵ */
	ScanAndOutput(H);
	/* ����ɢ�б� */
	DestroyTable(H);

	system("pause");
	return 0;
}