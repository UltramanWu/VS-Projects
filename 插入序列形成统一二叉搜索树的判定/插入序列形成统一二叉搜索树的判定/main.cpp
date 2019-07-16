#include"Search_BinTree.h"

int main()
{
	int N,L;
	Tree SBT;
	ElementType Data;
	cin >> N;
	while (N){
		cin >> L;
		SBT = CreatTree(N);  /* 利用第一组序列值进行树的构建 */
		for (int  i = 0; i <L; i++)
		{
			if (Judge(SBT, N)) cout << "YES!" << endl;  /* */
			else cout << "NO!" << endl;
			Reset(SBT);  /* 初始化二叉树状态 */
		}
		DeleteT(SBT);  /* 释放二叉树空间，以方便程序可以进行下一次的比较 */
		cin >> N;  /* 输入下一次需要比较的数列个数 */
	}

	system("pause");
	return 0;
}