#include"AVL.h"

/* 获取二叉树树高 */
/* 返回值：二叉树树高值 */
int GetTreeHeight(AVLTree A)
{
	int LH, RH, MaxH;
	if (A)
	{
		LH = GetTreeHeight(A->Left);  /* 对左子树递归调用 */
		RH = GetTreeHeight(A->Right);/* 对右子树递归调用 */
		MaxH = (LH > RH) ? LH : RH;
		return MaxH + 1;
	}
	return  NULL;
}

/* 输出最大值 */
int Max(int a, int b)
{
	return a > b ? a : b;
}

/*LL旋转（单左旋转）*/
/*返回值：旋转后的根节点*/
AVLTree SingleLeftRotation(AVLTree A)
{
	AVLTree B;
	B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetTreeHeight(A->Left), GetTreeHeight(A->Right)) + 1;  /* 更新各二叉树树高值 */
	B->Height = Max(GetTreeHeight(B->Left), A->Height ) + 1;
	return B;
}

/*RR旋转（单右旋转）*/
/*返回值：旋转后的根节点*/
AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B;
	B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetTreeHeight(A->Left), GetTreeHeight(A->Right)) + 1;  /* 更新各二叉树树高值 */
	B->Height = Max( A->Height , GetTreeHeight(B->Right) ) + 1;

	return B;  
}

/*LR旋转（左-右双旋）*/
/*返回值：旋转后的根节点*/
AVLTree DoubleLeftRightRotation(AVLTree A)
{
	AVLTree B, C;
	B = A->Left;
	C = B->Right;
	A->Left = C->Right;
	B->Right = C->Left;
	C->Left = B;
	C->Right = A;

	A->Height = Max(GetTreeHeight(A->Left), GetTreeHeight(A->Right)) + 1;  /* 更新各二叉树树高值 */
	B->Height = Max(GetTreeHeight(B->Left), GetTreeHeight(B->Right)) + 1;
	C->Height = Max( A->Height  , B->Height ) + 1;

	return C;
}

/*RR旋转（右-左双旋）*/
/*返回值：旋转后的根节点*/
AVLTree DoubleRightLeftRotation(AVLTree A)
{
	AVLTree B, C;
	B = A->Right;
	C = B->Left;
	A->Right = C->Left;
	B->Left = C->Right;
	C->Right = B;
	C->Left = A;

	A->Height = Max(GetTreeHeight(A->Left), GetTreeHeight(A->Right)) + 1;  /* 更新各二叉树树高值 */
	B->Height = Max(GetTreeHeight(B->Left), GetTreeHeight(B->Right)) + 1;
	C->Height = Max(A->Height, B->Height) + 1;

	return C;
}

/* 插入结点并根据当前结点情况形成平衡二叉树 */
/* 返回值：当前二叉树的根节点 */
AVLTree Insert(ElementType X, AVLTree T)
{
	AVLTree BtTemp;
	/* 将X插入AVL树T中，并且返回调整后的AVL树 */
	if (!T) /*结点为空*/
	{
		/*创建新结点*/
		AVLTree BtTemp = new struct AVLNode;
		BtTemp->Data = X;
		BtTemp->Height = 0;
		BtTemp->Left = NULL;
		BtTemp->Right = NULL;
		T = BtTemp;
	}/*空树情况下*/
	else
	{
		if (X < T->Data)  /* 数据插入左子树 */
		{
			T->Left = Insert(X, T->Left);  /*对左子树进行递归*/
			if (GetTreeHeight(T->Left) - GetTreeHeight(T->Right) == 2)
				if (GetTreeHeight(T->Left) - GetTreeHeight(T->Right) == 2) /* 树高相差效果超过1 */
			{
				if (X < T->Left->Data)
					T = SingleLeftRotation(T);  /*左单旋*/
				else
					T = DoubleLeftRightRotation(T);  /*左-右双旋*/
			}
		}

		if (X > T->Data) /* 数据插入右子树 */
		{
			T->Right = Insert(X, T->Right);	/*对右子树进行递归调用*/
			if (GetTreeHeight(T->Right) - GetTreeHeight(T->Left) == 2) /* 树高相差效果超过1 */
			{
				if (X > T->Right->Data)
					T = SingleRightRotation(T);   /* 右单旋 */
				else
					T = DoubleRightLeftRotation(T);  /* 右-左双旋 */
			}
		}
		T->Height = Max(GetTreeHeight(T->Left), GetTreeHeight(T->Right)) + 1;   /* 更新树高值 */
	}

	return T;  /* 返回二叉树根结点 */
}