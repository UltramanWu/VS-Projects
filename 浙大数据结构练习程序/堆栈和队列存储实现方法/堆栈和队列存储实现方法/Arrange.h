#include<iostream>
using namespace std;

typedef  int   ElementType;
#define  MaxSize 10

//��ջʵ�ּ�
struct SNode{
	ElementType Data[ MaxSize ];
	int Top;  //ջ��
};

typedef  struct SNode *Stack;
//������
Stack CreatStack();  //������ջ

int IsEmptyS(Stack S);//����Ƿ�Ϊ��

int IsFullS(Stack S); //����Ƿ�Ϊ��

void Push(Stack S, ElementType item);//�Զ�ջ����ѹջ����

void Pop(Stack S); //�Զ�ջջ��Ԫ�ؽ��е�������


//����ʵ�ּ�
struct QNode{
	ElementType Data[ MaxSize ];
	int rear;
	int front;
};

typedef struct QNode *Queue;

//������

Queue CreatQueue(); //��������

int IsEmptyQ(Queue Q);//����Ƿ�Ϊ��

int IsFullQ(Queue Q); //����Ƿ�Ϊ��

void AddQ(Queue �� , ElementType item); //�Զ��н�����Ӳ���

void DeleteQ(Queue Q); //�Զ��н��г��Ӳ���
