#include<iostream>
using namespace std;


typedef struct TreeNode *Tree;
typedef int ElementType;
struct TreeNode{
	ElementType Data;
	Tree Left, Right;
	int Flag;/*��������֮����ж�������Ӧ���б��Ƚ�ͬһ����1��������0*/
};



/* ������ */

/* ������ */
Tree CreatTree(ElementType Data );

/* �������ڵ� */
Tree Insert(Tree T, ElementType Data);

/* �ж�����һ���� */

int Judge( Tree T, int N );

/* �ж��ڵ�һ���� */
int Check(Tree T, int N );

/* ��λ���� */
void Reset(Tree T);

/* �ͷŶ����� */
void DeleteT(Tree T);