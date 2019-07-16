#include"Search_BinTree.h"

/* ������ */
/* N : ��������ݸ��� */
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

/* �������ڵ� */
Tree Insert(Tree T, ElementType Data)
{
	Tree Temp;
	if (!T)
	{
		Temp = new struct TreeNode;  /* ������������� */
		Temp->Data = Data;
		Temp->Left = Temp->Right = NULL;
		Temp->Flag = 0;
		T = Temp;
	}
	else
	{
		if (Data < T->Data)
			T->Left = Insert(T->Left, Data);  /* �����������еݹ���� */
		if (Data > T->Data)
			T->Right = Insert(T->Right, Data);/* �����������еݹ���� */
	}
	return T;
}
/* �ж�����һ���� */
/* N : �Ƚϵ����ݸ��� */
int Judge(Tree T, int N)
{
	int flag = 0;
	ElementType Data;

	cin >> Data;
	if (Data != T->Data)  flag = 1;  /* ����ֱ��return ��ϳ�����Ϊ��ʱ��ϳ�������ڴ��������ֵ��û����ȫ�����꣬
													    �Ὣ��һ�ε�������Ϊһ���µıȽ����н��бȽϣ��⽫�����bug */
	else T->Flag = 1;

	for (int i = 0; i < N - 1; i++)
	{
		cin >> Data;
		if (!flag && !Check(T, Data))  flag = 1;  /* ����ֱ��return ��ϳ�����Ϊ��ʱ��ϳ�������ڴ��������ֵ��û����ȫ�����꣬
																	    �Ὣ��һ�ε�������Ϊһ���µıȽ����н��бȽϣ��⽫�����bug */
	}
	if (flag) return 0;  /* ���������ݴ���������������ȽϽ�� */
	return 1;
}

/* �ж��ڵ�һ���� */
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
			T->Flag = 1;  /* ���ȽϹ���������ı�־λ��1 */
			return 1;
		}
		else
			return 0;
	}
}

/* ��λ���� */
void Reset(Tree T)
{
	if (T->Left)  Reset(T->Left); /* �ݹ���������� */
	if (T->Right) Reset(T->Right); /* �ݹ���������� */
	T->Flag = 0;
}

/* �ͷŶ����� */
void DeleteT(Tree T)
{
	if (T->Left)  DeleteT(T->Left);  /* �ݹ���������� */
	if (T->Right) DeleteT(T->Right); /* �ݹ���������� */
	delete(T);
}