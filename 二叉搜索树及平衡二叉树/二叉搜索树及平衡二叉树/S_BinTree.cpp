#include"Search_BinTree.h"


/*从二叉搜索树BST中查找元素X，返回其所在结点的地址*/
Position Find(ElementType X, BinTree BST)
{
	while (BST)
	{
		if (X < BST->Data)
			BST = BST->Left;
		else if (X > BST->Data)
		{
			BST = BST->Right;
		}
		else if (X == BST->Data)
			return BST;
	} 
	return NULL;
}

/*从二叉搜索树BST中查找并返回最小元素所在结点的地址*/
Position FindMin(BinTree BT)
{
	if (BT)
	{
		while (BT->Left)
			FindMin(BT->Left);  /*对左子树进行递归调用*/
		return BT;
	} 
	return NULL;
}

/*从二叉搜索树BST中查找并返回最大元素所在结点的地址*/
Position FindMax(BinTree BT)
{
	if (BT)
	{
		while (BT->Right)
			FindMin(BT->Right);  /*对右子树进行递归调用*/
		return BT;
	}
	return NULL;
}
/*插入结点并返回二叉树的根节点*/
BinTree Insert(ElementType X, BinTree BST)
{
	BinTree BtTemp;
	if (!BST) /*结点为空*/
	{
		/*创建新结点*/
		BinTree BtTemp = new struct TreeNode;
		BtTemp->Data = X;
		BtTemp->Left = NULL;
		BtTemp->Right = NULL;
		BST = BtTemp;
	}
	else
	{
		if (X < BST->Data)
			BST->Left = Insert(X, BST->Left);  /*对左子树进行递归*/
		
		if (X > BST->Data)
			BST->Right = Insert(X, BST->Right);	/*对右子树进行递归调用*/
	}
	return BST;
}

void Insert_Pointer(ElementType X, BinTree *BST)
{
	if (!(*BST)) /*结点为空*/
	{
		/*创建新结点*/
		BinTree BT = new struct  TreeNode;
		(*BST) = BT;
		(*BST)->Data = X;
		(*BST)->Left = NULL;
		(*BST)->Right = NULL;
	}
	else
	{
		if (X < (*BST)->Data)
			Insert_Pointer(X, &((*BST)->Left));  /*对左子树进行递归*/

		if (X > (*BST)->Data)
			Insert_Pointer(X, &((*BST)->Right));	/*对右子树进行递归调用*/
	}
}


/*删除二叉树结点，并返回二叉树的根节点*/
BinTree Delete(ElementType X, BinTree BST)
{
	BinTree Temp;
	if (!BST)  return NULL;
	if (X < BST->Data)
		BST->Left = Delete(X, BST->Left);/*左子树递归删除*/
	if (X > BST->Data)
		BST->Right = Delete(X, BST->Right);/*右子树递归删除*/
	if (X == BST->Data)/*找到要删除的结点*/
	{
		if (BST->Left && BST->Right)  /*被删除结点的左右子树均存在*/
		{
			Temp = FindMin(BST->Right);/*从右子树中查找最小的元素填充删除结点*/
			BST->Data = Temp->Data;

			BST->Right = Delete(Temp->Data, BST->Right);/*删除右子树中的最小元素*/
		}
		else/*被删除结点由一个或无结点*/
		{
			Temp = BST;
			if (!BST->Left)  /*左子树不存在或无子树存在*/
				BST = BST->Right;
			else if (!BST->Right)/*右子树不存在或子树存在*/
				BST = BST->Left;
			delete(Temp);
		}
	}
	return BST;
}

void Delete_Pointer(ElementType X, BinTree *BST)
{
	BinTree Temp;
	if (!*BST)   cout << "当前二叉树为空，无法执行删除指令！";
	if (X < (*BST)->Data)
		Delete_Pointer(X, &((*BST)->Left));/*左子树递归删除*/
	if (X > (*BST)->Data)
		Delete_Pointer(X, &((*BST)->Right));/*右子树递归删除*/
	if(X == (*BST)->Data)/*找到要删除的结点*/
	{
		if ((*BST)->Left && (*BST)->Right)  /*被删除结点的左右子树均存在*/
		{
			Temp = FindMin((*BST)->Right);/*从右子树中查找最小的元素填充删除结点*/
			(*BST)->Data = Temp->Data;

			Delete_Pointer(Temp->Data, &((*BST)->Right));/*删除右子树中的最小元素*/
		}
		else/*被删除结点由一个或无结点*/
		{
			Temp = (*BST);
			if (!(*BST)->Left)  /*左子树不存在或无子树存在*/
				(*BST) = (*BST)->Right;
			else if (!(*BST)->Right)/*右子树不存在或子树存在*/
				(*BST) = (*BST)->Left;
			delete(Temp);
		}
	}
}