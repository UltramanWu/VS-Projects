#include<iostream>
using namespace std;

typedef  int   ElementType;
#define  MaxSize 10

//堆栈实现集
struct SNode{
	ElementType Data[ MaxSize ];
	int Top;  //栈顶
};

typedef  struct SNode *Stack;
//操作集
Stack CreatStack();  //创建堆栈

int IsEmptyS(Stack S);//检测是否为满

int IsFullS(Stack S); //检测是否为空

void Push(Stack S, ElementType item);//对堆栈进行压栈操作

void Pop(Stack S); //对堆栈栈顶元素进行弹出操作


//队列实现集
struct QNode{
	ElementType Data[ MaxSize ];
	int rear;
	int front;
};

typedef struct QNode *Queue;

//操作集

Queue CreatQueue(); //创建队列

int IsEmptyQ(Queue Q);//检测是否为空

int IsFullQ(Queue Q); //检测是否为满

void AddQ(Queue Ｑ , ElementType item); //对队列进行入队操作

void DeleteQ(Queue Q); //对队列进行出队操作
