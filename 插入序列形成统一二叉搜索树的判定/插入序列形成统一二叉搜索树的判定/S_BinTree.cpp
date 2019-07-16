#include"Search_BinTree.h"

/* 创建树 */
/* N : 插入的数据个数 */
Tree CreatTree(int  N)
{
	ElementType Data;
	Tree T = new struct TreeNode;
	cin >> Data;
	T->Data = Data;
	T->Flag = 0;
	T->Left = T->Right = NULL;

	for (int  i = 0; i < N-1; i++)
	{
		cin >> Data;
		Insert(T, Data);
	}
	return T;
}

/* 插入树节点 */
Tree Insert(Tree T, ElementType Data)
{
	Tree Temp;
	if (!T)
	{
		Temp = new struct TreeNode;  /* 创建空子树结点 */
		Temp->Data = Data;
		Temp->Left = Temp->Right = NULL;
		Temp->Flag = 0;
		T = Temp;
	}
	else
	{
		if (Data < T->Data)
			T->Left = Insert(T->Left, Data);  /* 对左子树进行递归调用 */
		if (Data > T->Data)
			T->Right = Insert(T->Right, Data);/* 对右子树进行递归调用 */
	}
	return T;
}
/* 判断序列一致性 */
/* N : 比较的数据个数 */
int Judge(Tree T, int N)
{
	int flag = 0;
	ElementType Data;

	cin >> Data;
	if (Data != T->Data)  flag = 1;  /* 不能直接return 打断程序，因为此时打断程序后，正在处理的序列值还没有完全处理完，
													    会将下一次的输入作为一个新的比较序列进行比较，这将会出现bug */
	else T->Flag = 1;

	for (int i = 0; i < N - 1; i++)
	{
		cin >> Data;
		if (!flag && !Check(T, Data))  flag = 1;  /* 不能直接return 打断程序，因为此时打断程序后，正在处理的序列值还没有完全处理完，
																	    会将下一次的输入作为一个新的比较序列进行比较，这将会出现bug */
	}
	if (flag) return 0;  /* 待该组数据处理结束后，最后输出比较结果 */
	return 1;
}

/* 判定节点一致性 */
int Check(Tree T, ElementType Data)
{
	if (T->Flag){
		if (Data > T->Data)  return Check(T->Right, Data);
		if (Data < T->Data)  return Check(T->Left, Data);
		else return 0;
	}
	else
	{
		if (Data == T->Data)
		{
			T->Flag = 1;  /* 被比较过，其结点出的标志位置1 */
			return 1;
		}
		else
			return 0;
	}
}

/* 复位操作 */
void Reset(Tree T)
{
	if (T->Left)  Reset(T->Left); /* 递归调用左子树 */
	if (T->Right) Reset(T->Right); /* 递归调用右子树 */
	T->Flag = 0;
}

/* 释放二叉树 */
void DeleteT(Tree T)
{
	if (T->Left)  DeleteT(T->Left);  /* 递归调用左子树 */
	if (T->Right) DeleteT(T->Right); /* 递归调用右子树 */
	delete(T);
}