#include"Chain.h"

int QueueSize;
//操作集

Queue Creat_Queue() //创建队列
{
	Queue Q;
	Q = new struct QNode;
	Q->front = new struct Node();
	Q->rear = new struct Node();
	
	Q->front->next = NULL;
	Q->rear->next = NULL;

	return Q;
}

int IsEmpty_Q(Queue Q)//检测是否为空
{
	if (Q->front->next== NULL)
		return 1;
	return 0;
}

int IsFull_Q(Queue Q) //检测是否为满
{
	if (QueueSize == MaxSize)
		return 1;
	return 0;
}

void Add_Q(Queue Q, ElementType item) //对队列进行入队操作
{
	if (IsFull_Q(Q))
		cout << "当前队列已满，无法进行入队操作！" << endl;
	else
	{
		Node* AddQ = new struct Node();
		AddQ->Data = item;
		AddQ->next = NULL;
		if (QueueSize == 0)
			Q->front->next = AddQ;  //插入链表节点

		Q->rear->next = AddQ;  //插入链表节点
		Q->rear = AddQ;   //节点后移
		QueueSize++;
		cout << "当前入队的元素是" << item << endl;
	}
}

void Delete_Q(Queue Q) //对队列进行出队操作
{
	if (IsEmpty_Q(Q))
		cout << "当前队列已空，无法进行入队操作！" << endl;
	else
	{
		ElementType  FrontItem;
		Node* DeleteQ;
		DeleteQ = Q->front->next;
		Q->front->next = DeleteQ->next;
		FrontItem = DeleteQ->Data;
		delete(DeleteQ);
		QueueSize--;
		cout << "当前出队的元素是" << FrontItem << endl;
	}
}

