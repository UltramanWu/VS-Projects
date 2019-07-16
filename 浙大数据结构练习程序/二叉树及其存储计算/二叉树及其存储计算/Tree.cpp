#include"BinTree.h"

int Time;

int IsEmptyT(BinTree BT)//判断是否为空
{
	if (BT->Data == NULL)
		return 1;
	return 0;
}

/*二叉树的创建（带返回值类型）*/
BinTree CreatBinTree()//先序遍历创建二叉树
{
	BinTree CreatBT = new struct TreeNode;  //创建结点
	CreatBT->Left = NULL;
	CreatBT->Right = NULL;
	int  item;
	cin >> item;

	if ( item == -1)  //j需要添加结束符的限制条件，否则会无限调用，造成stack overflow
		CreatBT = NULL;
	else
	{
		if (!CreatBT)  //申请空间失败处理方法
			exit(-1);
		CreatBT->Data = item;
		
		CreatBT->Left = CreatBinTree();  //递归创建
		CreatBT->Right = CreatBinTree();
		Time++;
	}
	return CreatBT;
}
/*二叉树的创建（指针类型）*/
void CreatBinTree_Pointer(BinTree *BT)
{
	int item;
	cin >> item;
	if (item == -1)
		*BT = NULL;
	else
	{
		*BT = new struct TreeNode;
		if (!*BT)
			exit(-1);
		(*BT)->Data = item;
		CreatBinTree_Pointer(&((*BT)->Left));
		CreatBinTree_Pointer(&((*BT)->Right));
	}
}
/*二叉树的销毁*/
void DestoryBinTree(BinTree BT)  
{
	if (BT != NULL)
	{
		if (BT->Left != NULL)
		{
			DestoryBinTree(BT->Left);  //销毁左子树
			BT->Left = NULL;
		}
		if (BT->Right != NULL)
		{
			DestoryBinTree(BT->Right);  //销毁右子树
			BT->Right = NULL;
		}
		DestoryBinTree(BT);  //销毁根节点
		BT = NULL;
	}
}
/*先序遍历*/
void PreOrderTraserval(BinTree BT) //先序遍历:根节点、左子树、右子树
{
	if (BT)
	{
		cout << BT->Data << " ";
		PreOrderTraserval(BT->Left);  //递归调用
		PreOrderTraserval(BT->Right);  //递归调用
	}
}
/*中序遍历*/
void InOrderTraserval(BinTree BT)   //中序遍历：左子树、根节点、右子树
{
	if (BT)
	{
		PreOrderTraserval(BT->Left);  //递归调用
		cout << BT->Data << " ";
		PreOrderTraserval(BT->Right);  //递归调用
	}
}
/*后序遍历*/
void PostOrderTraserval(BinTree BT) //后序遍历：左子树、右子树、根节点
{
	if (BT)
	{
		PreOrderTraserval(BT->Left);  //递归调用
		PreOrderTraserval(BT->Right);  //递归调用
		cout << BT->Data << " ";
	}
}
/*层序遍历*/
void LevelOrderTraserval(BinTree BT)//层序遍历：从上至下，从左至右进行遍历，使用链表式队列比较简单
{
	Queue Q;
	BinTree T;
	if (!BT)		return;
	Q = Creat_Queue();
	Add_Q(Q, BT);
	while ( !IsEmpty_Q(Q))
	{
		T = Delete_Q(Q);  //将队列中的首部元素弹出
		cout << T->Data<<" ";
		if (T->Left)   Add_Q(Q,T->Left);  //将左子树加入到队列中
		if (T->Right) Add_Q(Q, T->Right);  //将右子树加入到队列中	
	}
}
/*求树中的叶节点并打印*/
void PreOrderPrintLeaves(BinTree BT) //使用先序遍历的变形，中序和后序亦可
{
	if (BT)
	{
		if (BT->Left == NULL && BT->Right == NULL)
			cout << BT->Data << " ";
		PreOrderPrintLeaves(BT->Left);
		PreOrderPrintLeaves(BT->Right);
	}
}
/*求树的深度*/
int PostOrderGetHeight(BinTree BT) //使用后序遍历的变形
{
	int LH, RH, MaxH = 0;
	if (BT)
	{
		LH = PostOrderGetHeight(BT->Left);
		RH = PostOrderGetHeight(BT->Right);
		MaxH = (LH >= RH) ? LH : RH;
		return (MaxH + 1);
	}
	return NULL;
}