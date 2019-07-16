#include"Chain.h"

int StackSize;  //

Stack Creat_Stack()  //������ջ
{
	Stack S;
	S = new struct SNode();
	S->next = NULL;
	return S;
}

int IsEmpty_S(Stack S)//����Ƿ�Ϊ��
{
	if (S->next == NULL)
		return 1;
	return 0;
}

int IsFull_S(Stack S) //����Ƿ�Ϊ��
{
	if (StackSize >= MaxSize)
		return 1;
	return 0;
}

void Push_S(Stack S, ElementType item)//�Զ�ջ����ѹջ����
{
	if (IsFull_S(S))
		cout << "��ǰ��ջ�������޷�����ѹջ������" << endl;
	else
	{
		Stack AddS;
		AddS = new struct SNode();
		AddS->Data = item;
		AddS  ->next= S->next;  //������ͷ�����в���
		S->next = AddS;
		StackSize++;	//��ջ��Ԫ�ظ�����1
		cout << "��ǰѹ���ջ��Ԫ��Ϊ" << item << endl;
	}
}

void Pop_S(Stack S) //�Զ�ջջ��Ԫ�ؽ��е�������
{
	if (IsEmpty_S(S))
		cout << "��ǰ��ջΪ�գ��޷����е���������" << endl;
	else
	{
		ElementType TopItem;
		Stack Temp;

		Temp = S->next;
		S->next = Temp->next;
		TopItem = Temp->Data;
		delete(Temp);
		StackSize--;			//��ջ��Ԫ�ظ�����1
		cout << "��ǰ��ջ������Ԫ��Ϊ" << TopItem << endl;
	}	
}