//#include"BinTree.h"
#include"Arrange.h"
#if 0
int main()
{
	//char *Arr = "124###35###";
	/*BinTree BT = new struct TreeNode;
	BT= CreatBinTree();*/
	
	BinTree BT;
	CreatBinTree_Pointer(&BT);
	PreOrderTraserval(BT);
	cout << endl;
	InOrderTraserval(BT);
	cout << endl;
	PostOrderTraserval(BT);
	cout << endl;
	LevelOrderTraserval(BT);
	cout << endl;

	PreOrderPrintLeaves(BT);
	cout << endl;
	cout << PostOrderGetHeight(BT);
	cout << endl;


	system("pause");
	return 0;
}
#endif

int main()
{
	int R1,R2;
	R1 = BulidTree(T1);
	R2 = BulidTree(T2);
	if (Isomorphic(R1, R2)) cout << "Yes" << endl;
	else cout << "No" << endl;
	system("pause");
	return 0;
}