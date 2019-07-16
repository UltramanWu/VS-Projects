#include<iostream>
using namespace std;

typedef struct AVLNode *Position;
typedef Position AVLTree;	/*AVL������*/
typedef int ElementType;
struct AVLNode{
	ElementType Data;  /* ������� */
	AVLTree Left;		  /* ָ�������� */
	AVLTree Right;		  /* ָ�������� */
	int Height;			  /* ���� */
};

/* ��ȡ��ǰ������������ */
int GetTreeHeight(AVLTree A);

/* ������ֵ */
int Max(int a, int b);

/*LL��ת��������ת��*/
AVLTree SingleLeftRotation(AVLTree A);

/*RR��ת��������ת��*/
AVLTree SingleRightRotation(AVLTree A);

/*LR��ת����-��˫����*/
AVLTree DoubleLeftRightRotation(AVLTree A);

/*RR��ת����-��˫����*/
AVLTree DoubleRightLeftRotation(AVLTree A);

/* �Ե�ǰ�����������㲢ͨ����ת�Ȳ�������ƽ������� */
/* ����ֵ����ǰ�������Ľ�� */
AVLTree Insert(ElementType X, AVLTree T);

