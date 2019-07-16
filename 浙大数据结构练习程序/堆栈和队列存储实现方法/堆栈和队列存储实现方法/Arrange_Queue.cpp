#include"Arrange.h"

Queue CreatQueue() //创建队列
{
	Queue Q;
	Q = new struct QNode();
	Q->front = Q->rear = 0;

	return Q;
}

int IsEmptyQ(Queue Q)  //检测是否为空
{
	if (Q->front == Q->rear)
		return 1;
	return 0;
}

int IsFullQ(Queue Q) //检测是否为满
{
	Q->front = Q->front % MaxSize;
	Q->rear = Q->rear % MaxSize;

	if ( Q->front == Q->rear + 1 || ( Q->front == 0 && Q->rear == MaxSize - 1 ))
		return 1;
	return 0;
}

void AddQ(Queue Q, ElementType item) //对队列进行入队操作
{
	if (IsFullQ(Q)) //对队列进行入队操作
		cout << "当前队列已满，无法进行入队操作！" << endl;
	else
	{
		Q->rear = Q->rear %MaxSize;
		Q->Data[++Q->rear] = item;  //先对栈顶记录数据加1 后将元素压栈
		cout << "当前入队的元素为" << item << endl;
	}
}

void DeleteQ(Queue Q) //对队列进行出队操作
{
	if (IsEmptyQ(Q)) //对队列进行入队操作
		cout << "当前队列已空，无法进行出队操作！" << endl;
	else
	{
		Q->front = Q->front %MaxSize;
		cout << "当前出队的元素为" << Q->Data[++Q->front] << endl;
	}
}