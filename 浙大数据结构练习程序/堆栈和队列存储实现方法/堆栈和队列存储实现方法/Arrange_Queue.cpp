#include"Arrange.h"

Queue CreatQueue() //��������
{
	Queue Q;
	Q = new struct QNode();
	Q->front = Q->rear = 0;

	return Q;
}

int IsEmptyQ(Queue Q)  //����Ƿ�Ϊ��
{
	if (Q->front == Q->rear)
		return 1;
	return 0;
}

int IsFullQ(Queue Q) //����Ƿ�Ϊ��
{
	Q->front = Q->front % MaxSize;
	Q->rear = Q->rear % MaxSize;

	if ( Q->front == Q->rear + 1 || ( Q->front == 0 && Q->rear == MaxSize - 1 ))
		return 1;
	return 0;
}

void AddQ(Queue Q, ElementType item) //�Զ��н�����Ӳ���
{
	if (IsFullQ(Q)) //�Զ��н�����Ӳ���
		cout << "��ǰ�����������޷�������Ӳ�����" << endl;
	else
	{
		Q->rear = Q->rear %MaxSize;
		Q->Data[++Q->rear] = item;  //�ȶ�ջ����¼���ݼ�1 ��Ԫ��ѹջ
		cout << "��ǰ��ӵ�Ԫ��Ϊ" << item << endl;
	}
}

void DeleteQ(Queue Q) //�Զ��н��г��Ӳ���
{
	if (IsEmptyQ(Q)) //�Զ��н�����Ӳ���
		cout << "��ǰ�����ѿգ��޷����г��Ӳ�����" << endl;
	else
	{
		Q->front = Q->front %MaxSize;
		cout << "��ǰ���ӵ�Ԫ��Ϊ" << Q->Data[++Q->front] << endl;
	}
}