#include"Arrange.h"

Stack CreatStack()  //������ջ
{
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Top = -1;

	return S;
}

int IsEmptyS(Stack S)//����Ƿ�Ϊ��
{
	if (S->Top == -1)
		return 1;
	return 0;
}

int IsFullS(Stack S) //����Ƿ�Ϊ��
{
	if (S->Top == MaxSize - 1)
		return 1;
	return 0;

}

void Push(Stack S, ElementType item) //�Զ�ջ����ѹջ����
{
	if (IsFullS(S))
		cout << "��ǰ��ջ�������޷�����ѹջ������" << endl;
	else
	{
		S->Data[++S->Top] = item;  //�ȶ�ջ����¼���ݼ�1 ��Ԫ��ѹջ
		cout << "��ǰѹ���ջ�ڵ�Ԫ��Ϊ" << item << endl;
	}
}

void Pop(Stack S) //�Զ�ջջ��Ԫ�ؽ��е�������
{
	if (IsEmptyS(S))
		cout << "��ǰ��ջΪ�գ��޷����е���������" << endl;
	else
	{
		cout << "��ǰ������ջ��Ԫ��Ϊ" << S->Data[S->Top--] << endl;
	}
}