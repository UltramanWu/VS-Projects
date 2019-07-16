#include"Arrange.h"

Stack CreatStack()  //创建堆栈
{
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Top = -1;

	return S;
}

int IsEmptyS(Stack S)//检测是否为满
{
	if (S->Top == -1)
		return 1;
	return 0;
}

int IsFullS(Stack S) //检测是否为空
{
	if (S->Top == MaxSize - 1)
		return 1;
	return 0;

}

void Push(Stack S, ElementType item) //对堆栈进行压栈操作
{
	if (IsFullS(S))
		cout << "当前堆栈已满，无法进行压栈操作！" << endl;
	else
	{
		S->Data[++S->Top] = item;  //先对栈顶记录数据加1 后将元素压栈
		cout << "当前压入堆栈内的元素为" << item << endl;
	}
}

void Pop(Stack S) //对堆栈栈顶元素进行弹出操作
{
	if (IsEmptyS(S))
		cout << "当前堆栈为空，无法进行弹出操作！" << endl;
	else
	{
		cout << "当前弹出堆栈的元素为" << S->Data[S->Top--] << endl;
	}
}