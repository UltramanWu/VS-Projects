#include<iostream>
using namespace std;

typedef int ElementType;
#define MaxSize  100
int  StackSize = 0;
int  QueueSize = 0;

/* 堆栈实现 */
typedef struct SNode *Stack;
struct SNode{
	ElementType Data;
	Stack next;  /* 指向下一位置的指针 */
};

/* 操作集 */
Stack CreateS()
{
	Stack S = new struct SNode;
	S->next = NULL;
	return S;
}

bool IsEmptyS(Stack S)
{
	if (S->next == NULL)
		return 1;
	return 0;
}

bool IsFullS(Stack S)
{
	if (StackSize == MaxSize)
		return 1;
	return 0;
}

void PushS(Stack S, ElementType Item)
{
	if (IsFullS(S))
	{
		cout << "当堆栈已满，无法进行压栈操作！" << endl;
		return;
	}
	Stack AddS = new struct SNode;
	AddS->Data = Item;
	AddS->next = NULL;

	AddS->next = S->next;
	S->next = AddS;
	StackSize ++;
}

ElementType PopS(Stack S)
{
	if (IsEmptyS(S))
	{
		cout << "当前堆栈已空，无法进行出栈操作！" << endl;
		return -1;
	}
	Stack PopS;
	ElementType PopItem;
	PopS = S->next;
	S->next = PopS->next;
	PopItem = PopS->Data;
	delete(PopS);  /* 释放弹出链表结点空间 */
	StackSize	--;
	return PopItem;
}


/* 队列实现 */
struct Node{
	ElementType Data;   /* 结点数据 */
	struct Node *Next;  /* 指向下一节点的指针 */
};

struct QNode{
	struct Node *rear;     /* 后向指针 */
	struct Node *front;   /* 前向指针 */
};
typedef struct QNode *Queue;

/* 操作集 */
Queue CreateQ()
{
	Queue Q = new struct QNode;
	Q->rear = new struct Node;
	Q->front = new struct Node;

	Q->rear->Next = NULL;  /* 对成员指针进行初始化 */
	Q->front->Next = NULL;

	return Q;
}

bool IsEmptyQ(Queue Q)
{
	if (Q->front->Next == NULL)
		return 1;
	return 0;
}

bool IsFullQ(Queue Q)
{
	if (QueueSize == MaxSize)
		return 1;
	return 0;
}

void EnQueue(Queue Q , ElementType Item)
{
	if (IsFullQ(Q))
	{
		cout << "当前队列元素已满，无法进行入队操作！" << endl;
		return;
	}
	try
	{ 
		Node* EnNode = new struct Node;
		EnNode->Data = Item;
		EnNode->Next = NULL;
		if (QueueSize == 0)
			Q->front->Next = EnNode;

		Q->rear->Next = EnNode;
		Q->rear = EnNode;  /* 指针后移 */
		QueueSize++;
	}
	catch (runtime_error err){ cout << err.what() << endl; }
	
	cout << Item << endl;
}

ElementType DeQueue(Queue Q)
{
	if (IsEmptyQ(Q)){
		cout << "当前队列为空，无法进行出队操作" << endl;
		return -1;
	}
	ElementType DeItem;
	Node* DeNode;
	DeNode = Q->front->Next;
	Q->front->Next = DeNode->Next;  /* 头部指针移至下一节点 */
	DeItem = DeNode->Data;
	delete(DeNode);  /* 释放结点 */
	QueueSize --;
	return DeItem;
}

