#include"BinTree.h"

int Time;

int IsEmptyT(BinTree BT)//�ж��Ƿ�Ϊ��
{
	if (BT->Data == NULL)
		return 1;
	return 0;
}

/*�������Ĵ�����������ֵ���ͣ�*/
BinTree CreatBinTree()//�����������������
{
	BinTree CreatBT = new struct TreeNode;  //�������
	CreatBT->Left = NULL;
	CreatBT->Right = NULL;
	int  item;
	cin >> item;

	if ( item == -1)  //j��Ҫ��ӽ�������������������������޵��ã����stack overflow
		CreatBT = NULL;
	else
	{
		if (!CreatBT)  //����ռ�ʧ�ܴ�����
			exit(-1);
		CreatBT->Data = item;
		
		CreatBT->Left = CreatBinTree();  //�ݹ鴴��
		CreatBT->Right = CreatBinTree();
		Time++;
	}
	return CreatBT;
}
/*�������Ĵ�����ָ�����ͣ�*/
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
/*������������*/
void DestoryBinTree(BinTree BT)  
{
	if (BT != NULL)
	{
		if (BT->Left != NULL)
		{
			DestoryBinTree(BT->Left);  //����������
			BT->Left = NULL;
		}
		if (BT->Right != NULL)
		{
			DestoryBinTree(BT->Right);  //����������
			BT->Right = NULL;
		}
		DestoryBinTree(BT);  //���ٸ��ڵ�
		BT = NULL;
	}
}
/*�������*/
void PreOrderTraserval(BinTree BT) //�������:���ڵ㡢��������������
{
	if (BT)
	{
		cout << BT->Data << " ";
		PreOrderTraserval(BT->Left);  //�ݹ����
		PreOrderTraserval(BT->Right);  //�ݹ����
	}
}
/*�������*/
void InOrderTraserval(BinTree BT)   //��������������������ڵ㡢������
{
	if (BT)
	{
		PreOrderTraserval(BT->Left);  //�ݹ����
		cout << BT->Data << " ";
		PreOrderTraserval(BT->Right);  //�ݹ����
	}
}
/*�������*/
void PostOrderTraserval(BinTree BT) //����������������������������ڵ�
{
	if (BT)
	{
		PreOrderTraserval(BT->Left);  //�ݹ����
		PreOrderTraserval(BT->Right);  //�ݹ����
		cout << BT->Data << " ";
	}
}
/*�������*/
void LevelOrderTraserval(BinTree BT)//����������������£��������ҽ��б�����ʹ������ʽ���бȽϼ�
{
	Queue Q;
	BinTree T;
	if (!BT)		return;
	Q = Creat_Queue();
	Add_Q(Q, BT);
	while ( !IsEmpty_Q(Q))
	{
		T = Delete_Q(Q);  //�������е��ײ�Ԫ�ص���
		cout << T->Data<<" ";
		if (T->Left)   Add_Q(Q,T->Left);  //�����������뵽������
		if (T->Right) Add_Q(Q, T->Right);  //�����������뵽������	
	}
}
/*�����е�Ҷ�ڵ㲢��ӡ*/
void PreOrderPrintLeaves(BinTree BT) //ʹ����������ı��Σ�����ͺ������
{
	if (BT)
	{
		if (BT->Left == NULL && BT->Right == NULL)
			cout << BT->Data << " ";
		PreOrderPrintLeaves(BT->Left);
		PreOrderPrintLeaves(BT->Right);
	}
}
/*���������*/
int PostOrderGetHeight(BinTree BT) //ʹ�ú�������ı���
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