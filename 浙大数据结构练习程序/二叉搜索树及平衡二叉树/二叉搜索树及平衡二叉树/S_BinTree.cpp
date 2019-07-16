#include"Search_BinTree.h"


/*�Ӷ���������BST�в���Ԫ��X�����������ڽ��ĵ�ַ*/
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

/*�Ӷ���������BST�в��Ҳ�������СԪ�����ڽ��ĵ�ַ*/
Position FindMin(BinTree BT)
{
	if (BT)
	{
		while (BT->Left)
			FindMin(BT->Left);  /*�����������еݹ����*/
		return BT;
	} 
	return NULL;
}

/*�Ӷ���������BST�в��Ҳ��������Ԫ�����ڽ��ĵ�ַ*/
Position FindMax(BinTree BT)
{
	if (BT)
	{
		while (BT->Right)
			FindMin(BT->Right);  /*�����������еݹ����*/
		return BT;
	}
	return NULL;
}
/*�����㲢���ض������ĸ��ڵ�*/
BinTree Insert(ElementType X, BinTree BST)
{
	BinTree BtTemp;
	if (!BST) /*���Ϊ��*/
	{
		/*�����½��*/
		BinTree BtTemp = new struct TreeNode;
		BtTemp->Data = X;
		BtTemp->Left = NULL;
		BtTemp->Right = NULL;
		BST = BtTemp;
	}
	else
	{
		if (X < BST->Data)
			BST->Left = Insert(X, BST->Left);  /*�����������еݹ�*/
		
		if (X > BST->Data)
			BST->Right = Insert(X, BST->Right);	/*�����������еݹ����*/
	}
	return BST;
}

void Insert_Pointer(ElementType X, BinTree *BST)
{
	if (!(*BST)) /*���Ϊ��*/
	{
		/*�����½��*/
		BinTree BT = new struct  TreeNode;
		(*BST) = BT;
		(*BST)->Data = X;
		(*BST)->Left = NULL;
		(*BST)->Right = NULL;
	}
	else
	{
		if (X < (*BST)->Data)
			Insert_Pointer(X, &((*BST)->Left));  /*�����������еݹ�*/

		if (X > (*BST)->Data)
			Insert_Pointer(X, &((*BST)->Right));	/*�����������еݹ����*/
	}
}


/*ɾ����������㣬�����ض������ĸ��ڵ�*/
BinTree Delete(ElementType X, BinTree BST)
{
	BinTree Temp;
	if (!BST)  return NULL;
	if (X < BST->Data)
		BST->Left = Delete(X, BST->Left);/*�������ݹ�ɾ��*/
	if (X > BST->Data)
		BST->Right = Delete(X, BST->Right);/*�������ݹ�ɾ��*/
	if (X == BST->Data)/*�ҵ�Ҫɾ���Ľ��*/
	{
		if (BST->Left && BST->Right)  /*��ɾ��������������������*/
		{
			Temp = FindMin(BST->Right);/*���������в�����С��Ԫ�����ɾ�����*/
			BST->Data = Temp->Data;

			BST->Right = Delete(Temp->Data, BST->Right);/*ɾ���������е���СԪ��*/
		}
		else/*��ɾ�������һ�����޽��*/
		{
			Temp = BST;
			if (!BST->Left)  /*�����������ڻ�����������*/
				BST = BST->Right;
			else if (!BST->Right)/*�����������ڻ���������*/
				BST = BST->Left;
			delete(Temp);
		}
	}
	return BST;
}

void Delete_Pointer(ElementType X, BinTree *BST)
{
	BinTree Temp;
	if (!*BST)   cout << "��ǰ������Ϊ�գ��޷�ִ��ɾ��ָ�";
	if (X < (*BST)->Data)
		Delete_Pointer(X, &((*BST)->Left));/*�������ݹ�ɾ��*/
	if (X > (*BST)->Data)
		Delete_Pointer(X, &((*BST)->Right));/*�������ݹ�ɾ��*/
	if(X == (*BST)->Data)/*�ҵ�Ҫɾ���Ľ��*/
	{
		if ((*BST)->Left && (*BST)->Right)  /*��ɾ��������������������*/
		{
			Temp = FindMin((*BST)->Right);/*���������в�����С��Ԫ�����ɾ�����*/
			(*BST)->Data = Temp->Data;

			Delete_Pointer(Temp->Data, &((*BST)->Right));/*ɾ���������е���СԪ��*/
		}
		else/*��ɾ�������һ�����޽��*/
		{
			Temp = (*BST);
			if (!(*BST)->Left)  /*�����������ڻ�����������*/
				(*BST) = (*BST)->Right;
			else if (!(*BST)->Right)/*�����������ڻ���������*/
				(*BST) = (*BST)->Left;
			delete(Temp);
		}
	}
}