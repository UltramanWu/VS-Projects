#include<iostream>
using namespace std;

typedef struct TreeNode* BinTree;
typedef  BinTree  ElementType;
#define MaxSize 100
#if 0
//堆栈实现集
typedef struct SNode *Stack;

struct SNode{
	ElementType Data;
	Stack next; //链表指针
};

//操作集
Stack Creat_Stack();  //创建堆栈

int IsEmpty_S(Stack S);//检测是否为满

int IsFull_S(Stack S); //检测是否为空

void Push_S(Stack S, ElementType item);//对堆栈进行压栈操作

void Pop_S(Stack S); //对堆栈栈顶元素进行弹出操作
#endif

//队列实现
typedef struct QNode *Queue;


/*二叉树结构体 */
struct TreeNode{
	int  Data;
	BinTree Left;
	BinTree Right;
};

/*链表队列结构体*/
struct Node{
	ElementType Data;
	struct Node *next;
};
struct QNode{
	struct Node *rear;   //指向队列尾部
	struct Node *front;  //指向队列头部
};



//操作集

Queue Creat_Queue(); //创建队列

int IsEmpty_Q(Queue Q);//检测是否为空

int IsFull_Q(Queue Q); //检测是否为满

void Add_Q(Queue Ｑ, BinTree BT); //对队列进行入队操作

BinTree Delete_Q(Queue Q); //对队列进行出队操作
