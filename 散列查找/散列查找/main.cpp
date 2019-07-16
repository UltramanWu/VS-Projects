// 散列查找.cpp : 定义控制台应用程序的入口点。
//
#include"HashTable.h"

int main()
{
	int N, i;
	HashTable H;
	ElementType E;
	cin >> N;
	H = CreateTable(N);
	/* 插入操作 */
	for (i = 0; i < N; i++){
		cin >> E; Insert(H, E);
		cin >> E; Insert(H, E);
	}
	/* 扫描并输出最大值 */
	ScanAndOutput(H);
	/* 销毁散列表 */
	DestroyTable(H);

	system("pause");
	return 0;
}