#include"Chain.h"

int StackSize;  //

Stack Creat_Stack()  //创建堆栈
{
	Stack S;
	S = new struct SNode();
	S->next = NULL;
	return S;
}

int IsEmpty_S(Stack S)//检测是否为满
{
	if (S->next == NULL)
		return 1;
	return 0;
}

int IsFull_S(Stack S) //检测是否为空
{
	if (StackSize >= MaxSize)
		return 1;
	return 0;
}

void Push_S(Stack S, ElementType item)//对堆栈进行压栈操作
{
	if (IsFull_S(S))
		cout << "当前堆栈已满，无法进行压栈操作！" << endl;
	else
	{
		Stack AddS;
		AddS = new struct SNode();
		AddS->Data = item;
		AddS  ->next= S->next;  //在链表头部进行插入
		S->next = AddS;
		StackSize++;	//堆栈中元素个数加1
		cout << "当前压入堆栈的元素为" << item << endl;
	}
}

void Pop_S(Stack S) //对堆栈栈顶元素进行弹出操作
{
	if (IsEmpty_S(S))
		cout << "当前堆栈为空，无法进行弹出操作！" << endl;
	else
	{
		ElementType TopItem;
		Stack Temp;

		Temp = S->next;
		S->next = Temp->next;
		TopItem = Temp->Data;
		delete(Temp);
		StackSize--;			//堆栈中元素个数减1
		cout << "当前堆栈弹出的元素为" << TopItem << endl;
	}	
}