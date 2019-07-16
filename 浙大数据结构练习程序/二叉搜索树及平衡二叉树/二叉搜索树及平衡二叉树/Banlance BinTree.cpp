#include"AVL.h"

/* ��ȡ���������� */
/* ����ֵ������������ֵ */
int GetTreeHeight(AVLTree A)
{
	int LH, RH, MaxH;
	if (A)
	{
		LH = GetTreeHeight(A->Left);  /* ���������ݹ���� */
		RH = GetTreeHeight(A->Right);/* ���������ݹ���� */
		MaxH = (LH > RH) ? LH : RH;
		return MaxH + 1;
	}
	return  NULL;
}

/* ������ֵ */
int Max(int a, int b)
{
	return a > b ? a : b;
}

/*LL��ת��������ת��*/
/*����ֵ����ת��ĸ��ڵ�*/
AVLTree SingleLeftRotation(AVLTree A)
{
	AVLTree B;
	B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetTreeHeight(A->Left), GetTreeHeight(A->Right)) + 1;  /* ���¸�����������ֵ */
	B->Height = Max(GetTreeHeight(B->Left), A->Height ) + 1;
	return B;
}

/*RR��ת��������ת��*/
/*����ֵ����ת��ĸ��ڵ�*/
AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B;
	B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetTreeHeight(A->Left), GetTreeHeight(A->Right)) + 1;  /* ���¸�����������ֵ */
	B->Height = Max( A->Height , GetTreeHeight(B->Right) ) + 1;

	return B;  
}

/*LR��ת����-��˫����*/
/*����ֵ����ת��ĸ��ڵ�*/
AVLTree DoubleLeftRightRotation(AVLTree A)
{
	AVLTree B, C;
	B = A->Left;
	C = B->Right;
	A->Left = C->Right;
	B->Right = C->Left;
	C->Left = B;
	C->Right = A;

	A->Height = Max(GetTreeHeight(A->Left), GetTreeHeight(A->Right)) + 1;  /* ���¸�����������ֵ */
	B->Height = Max(GetTreeHeight(B->Left), GetTreeHeight(B->Right)) + 1;
	C->Height = Max( A->Height  , B->Height ) + 1;

	return C;
}

/*RR��ת����-��˫����*/
/*����ֵ����ת��ĸ��ڵ�*/
AVLTree DoubleRightLeftRotation(AVLTree A)
{
	AVLTree B, C;
	B = A->Right;
	C = B->Left;
	A->Right = C->Left;
	B->Left = C->Right;
	C->Right = B;
	C->Left = A;

	A->Height = Max(GetTreeHeight(A->Left), GetTreeHeight(A->Right)) + 1;  /* ���¸�����������ֵ */
	B->Height = Max(GetTreeHeight(B->Left), GetTreeHeight(B->Right)) + 1;
	C->Height = Max(A->Height, B->Height) + 1;

	return C;
}

/* �����㲢���ݵ�ǰ�������γ�ƽ������� */
/* ����ֵ����ǰ�������ĸ��ڵ� */
AVLTree Insert(ElementType X, AVLTree T)
{
	AVLTree BtTemp;
	/* ��X����AVL��T�У����ҷ��ص������AVL�� */
	if (!T) /*���Ϊ��*/
	{
		/*�����½��*/
		AVLTree BtTemp = new struct AVLNode;
		BtTemp->Data = X;
		BtTemp->Height = 0;
		BtTemp->Left = NULL;
		BtTemp->Right = NULL;
		T = BtTemp;
	}/*���������*/
	else
	{
		if (X < T->Data)  /* ���ݲ��������� */
		{
			T->Left = Insert(X, T->Left);  /*�����������еݹ�*/
			if (GetTreeHeight(T->Left) - GetTreeHeight(T->Right) == 2)
				if (GetTreeHeight(T->Left) - GetTreeHeight(T->Right) == 2) /* �������Ч������1 */
			{
				if (X < T->Left->Data)
					T = SingleLeftRotation(T);  /*����*/
				else
					T = DoubleLeftRightRotation(T);  /*��-��˫��*/
			}
		}

		if (X > T->Data) /* ���ݲ��������� */
		{
			T->Right = Insert(X, T->Right);	/*�����������еݹ����*/
			if (GetTreeHeight(T->Right) - GetTreeHeight(T->Left) == 2) /* �������Ч������1 */
			{
				if (X > T->Right->Data)
					T = SingleRightRotation(T);   /* �ҵ��� */
				else
					T = DoubleRightLeftRotation(T);  /* ��-��˫�� */
			}
		}
		T->Height = Max(GetTreeHeight(T->Left), GetTreeHeight(T->Right)) + 1;   /* ��������ֵ */
	}

	return T;  /* ���ض���������� */
}