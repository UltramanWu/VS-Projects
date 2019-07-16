#include<iostream>
using namespace std;

typedef  int  ElementType;
#define MaxSize 10

//��ջʵ�ּ�
typedef struct SNode *Stack;

struct SNode{
	ElementType Data;
	Stack next; //����ָ��
};

//������
Stack Creat_Stack();  //������ջ

int IsEmpty_S(Stack S);//����Ƿ�Ϊ��

int IsFull_S(Stack S); //����Ƿ�Ϊ��

void Push_S(Stack S, ElementType item);//�Զ�ջ����ѹջ����

void Pop_S(Stack S); //�Զ�ջջ��Ԫ�ؽ��е�������


//����ʵ��
typedef struct QNode *Queue;

struct Node{
	ElementType Data;
	struct Node *next;
};

struct QNode{
	struct Node *rear;   //ָ�����β��
	struct Node *front;  //ָ�����ͷ��
};

//������

Queue Creat_Queue(); //��������

int IsEmpty_Q(Queue Q);//����Ƿ�Ϊ��

int IsFull_Q(Queue Q); //����Ƿ�Ϊ��

void Add_Q(Queue ��, ElementType item); //�Զ��н�����Ӳ���

void Delete_Q(Queue Q); //�Զ��н��г��Ӳ���
