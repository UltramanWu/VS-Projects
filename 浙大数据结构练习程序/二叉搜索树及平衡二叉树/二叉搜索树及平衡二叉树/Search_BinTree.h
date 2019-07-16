#include<iostream>
using namespace std;

typedef  char ElementType;
typedef struct TreeNode *BinTree;
/*�������ṹ��*/
struct TreeNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

typedef BinTree Position;


/*�Ӷ���������BST�в���Ԫ��X�����������ڽ��ĵ�ַ*/
Position Find(ElementType X, BinTree BST);

/*�Ӷ���������BST�в��Ҳ�������СԪ�����ڽ��ĵ�ַ*/
Position FindMin(BinTree BT);

/*�Ӷ���������BST�в��Ҳ��������Ԫ�����ڽ��ĵ�ַ*/
Position FindMax(BinTree BT);

/*ʹ�÷���ֵ������*/
BinTree Insert(ElementType X, BinTree BST);

/*ʹ��ָ�������*/
void Insert_Pointer(ElementType X, BinTree *BST);

/*ʹ�÷���ֵɾ�����*/
BinTree Delete(ElementType X, BinTree BST);

/*ʹ��ָ��ɾ�����*/
void Delete_Pointer(ElementType X, BinTree *BST);