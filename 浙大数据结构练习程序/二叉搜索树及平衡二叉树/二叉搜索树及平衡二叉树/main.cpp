//#include"Search_BinTree.h"
#include "AVL.h"

int main()
{
	int arr[] = { 9, 21, 6 ,15, 18, 24 };/*��������飬�γ�ƽ�������*/
	//BinTree BST = new struct TreeNode;
	AVLTree BST = new struct AVLNode;
	BST->Data = 15;
	BST->Height = 0;
	BST->Left = NULL;
	BST->Right = NULL;
	/*������������������������*/
	//BinTree BT = new struct TreeNode;  /*�������ڵ�*/
	//BT->Data = 4;
	//BT->Left = NULL;
	//BT->Right = NULL;
	for (int i = 0; i <4; i++)
	{
		//Insert_Pointer(arr[i], &BT);/*ʹ�ô���ַ�ķ�����ʵ�ν��и�ֵ*/
		BST = Insert(arr[i], BST);
	}

	/* �ҵ��� */
	BST = Insert( 25 , BST);
	BST = Insert( 27, BST);

	/*����*/
	BST = Insert( 4, BST);
	BST = Insert( 2, BST);

	/*��-��˫��*/
	BST = Insert(13, BST);

	/*��-��˫��*/
	BST = Insert(20, BST);
	/*ɾ�����ݽ��*/
	//BST = Delete(1, BST);
	/*Delete_Pointer(1, &BT);
	Delete_Pointer(3, &BT);
	Delete_Pointer(5, &BT);
	Delete_Pointer(7, &BT);*/

	system("pause");
	return 0;
}