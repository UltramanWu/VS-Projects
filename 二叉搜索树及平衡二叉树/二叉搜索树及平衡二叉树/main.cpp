//#include"Search_BinTree.h"
#include "AVL.h"

int main()
{
	int arr[] = { 9, 21, 6 ,15, 18, 24 };/*插入的数组，形成平衡二叉树*/
	//BinTree BST = new struct TreeNode;
	AVLTree BST = new struct AVLNode;
	BST->Data = 15;
	BST->Height = 0;
	BST->Left = NULL;
	BST->Right = NULL;
	/*创建二叉树并插入二叉树结点*/
	//BinTree BT = new struct TreeNode;  /*创建根节点*/
	//BT->Data = 4;
	//BT->Left = NULL;
	//BT->Right = NULL;
	for (int i = 0; i <4; i++)
	{
		//Insert_Pointer(arr[i], &BT);/*使用传地址的方法对实参进行赋值*/
		BST = Insert(arr[i], BST);
	}

	/* 右单旋 */
	BST = Insert( 25 , BST);
	BST = Insert( 27, BST);

	/*左单旋*/
	BST = Insert( 4, BST);
	BST = Insert( 2, BST);

	/*左-右双旋*/
	BST = Insert(13, BST);

	/*右-左双旋*/
	BST = Insert(20, BST);
	/*删除数据结点*/
	//BST = Delete(1, BST);
	/*Delete_Pointer(1, &BT);
	Delete_Pointer(3, &BT);
	Delete_Pointer(5, &BT);
	Delete_Pointer(7, &BT);*/

	system("pause");
	return 0;
}