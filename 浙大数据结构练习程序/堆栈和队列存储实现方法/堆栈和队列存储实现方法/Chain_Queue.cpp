#include"Chain.h"

int QueueSize;
//������

Queue Creat_Queue() //��������
{
	Queue Q;
	Q = new struct QNode;
	Q->front = new struct Node();
	Q->rear = new struct Node();
	
	Q->front->next = NULL;
	Q->rear->next = NULL;

	return Q;
}

int IsEmpty_Q(Queue Q)//����Ƿ�Ϊ��
{
	if (Q->front->next== NULL)
		return 1;
	return 0;
}

int IsFull_Q(Queue Q) //����Ƿ�Ϊ��
{
	if (QueueSize == MaxSize)
		return 1;
	return 0;
}

void Add_Q(Queue Q, ElementType item) //�Զ��н�����Ӳ���
{
	if (IsFull_Q(Q))
		cout << "��ǰ�����������޷�������Ӳ�����" << endl;
	else
	{
		Node* AddQ = new struct Node();
		AddQ->Data = item;
		AddQ->next = NULL;
		if (QueueSize == 0)
			Q->front->next = AddQ;  //��������ڵ�

		Q->rear->next = AddQ;  //��������ڵ�
		Q->rear = AddQ;   //�ڵ����
		QueueSize++;
		cout << "��ǰ��ӵ�Ԫ����" << item << endl;
	}
}

void Delete_Q(Queue Q) //�Զ��н��г��Ӳ���
{
	if (IsEmpty_Q(Q))
		cout << "��ǰ�����ѿգ��޷�������Ӳ�����" << endl;
	else
	{
		ElementType  FrontItem;
		Node* DeleteQ;
		DeleteQ = Q->front->next;
		Q->front->next = DeleteQ->next;
		FrontItem = DeleteQ->Data;
		delete(DeleteQ);
		QueueSize--;
		cout << "��ǰ���ӵ�Ԫ����" << FrontItem << endl;
	}
}

