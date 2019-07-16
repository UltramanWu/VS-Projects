#include<iostream>
using namespace std;

typedef int ElementType;
#define MaxSize  100
int  StackSize = 0;
int  QueueSize = 0;

/* ��ջʵ�� */
typedef struct SNode *Stack;
struct SNode{
	ElementType Data;
	Stack next;  /* ָ����һλ�õ�ָ�� */
};

/* ������ */
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
		cout << "����ջ�������޷�����ѹջ������" << endl;
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
		cout << "��ǰ��ջ�ѿգ��޷����г�ջ������" << endl;
		return -1;
	}
	Stack PopS;
	ElementType PopItem;
	PopS = S->next;
	S->next = PopS->next;
	PopItem = PopS->Data;
	delete(PopS);  /* �ͷŵ���������ռ� */
	StackSize	--;
	return PopItem;
}


/* ����ʵ�� */
struct Node{
	ElementType Data;   /* ������� */
	struct Node *Next;  /* ָ����һ�ڵ��ָ�� */
};

struct QNode{
	struct Node *rear;     /* ����ָ�� */
	struct Node *front;   /* ǰ��ָ�� */
};
typedef struct QNode *Queue;

/* ������ */
Queue CreateQ()
{
	Queue Q = new struct QNode;
	Q->rear = new struct Node;
	Q->front = new struct Node;

	Q->rear->Next = NULL;  /* �Գ�Աָ����г�ʼ�� */
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
		cout << "��ǰ����Ԫ���������޷�������Ӳ�����" << endl;
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
		Q->rear = EnNode;  /* ָ����� */
		QueueSize++;
	}
	catch (runtime_error err){ cout << err.what() << endl; }
	
	cout << Item << endl;
}

ElementType DeQueue(Queue Q)
{
	if (IsEmptyQ(Q)){
		cout << "��ǰ����Ϊ�գ��޷����г��Ӳ���" << endl;
		return -1;
	}
	ElementType DeItem;
	Node* DeNode;
	DeNode = Q->front->Next;
	Q->front->Next = DeNode->Next;  /* ͷ��ָ��������һ�ڵ� */
	DeItem = DeNode->Data;
	delete(DeNode);  /* �ͷŽ�� */
	QueueSize --;
	return DeItem;
}

