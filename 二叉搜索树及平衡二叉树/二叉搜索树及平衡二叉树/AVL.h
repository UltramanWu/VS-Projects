#include<iostream>
using namespace std;

typedef struct AVLNode *Position;
typedef Position AVLTree;	/*AVL树类型*/
typedef int ElementType;
struct AVLNode{
	ElementType Data;  /* 结点数据 */
	AVLTree Left;		  /* 指向左子树 */
	AVLTree Right;		  /* 指向右子树 */
	int Height;			  /* 树高 */
};

/* 获取当前二叉树的树高 */
int GetTreeHeight(AVLTree A);

/* 输出最大值 */
int Max(int a, int b);

/*LL旋转（单左旋转）*/
AVLTree SingleLeftRotation(AVLTree A);

/*RR旋转（单右旋转）*/
AVLTree SingleRightRotation(AVLTree A);

/*LR旋转（左-右双旋）*/
AVLTree DoubleLeftRightRotation(AVLTree A);

/*RR旋转（右-左双旋）*/
AVLTree DoubleRightLeftRotation(AVLTree A);

/* 对当前二叉树插入结点并通过旋转等操作满足平衡二叉树 */
/* 返回值：当前二叉树的结点 */
AVLTree Insert(ElementType X, AVLTree T);

