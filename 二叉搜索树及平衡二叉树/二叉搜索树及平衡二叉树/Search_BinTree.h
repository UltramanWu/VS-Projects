#include<iostream>
using namespace std;

typedef  char ElementType;
typedef struct TreeNode *BinTree;
/*二叉树结构体*/
struct TreeNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

typedef BinTree Position;


/*从二叉搜索树BST中查找元素X，返回其所在结点的地址*/
Position Find(ElementType X, BinTree BST);

/*从二叉搜索树BST中查找并返回最小元素所在结点的地址*/
Position FindMin(BinTree BT);

/*从二叉搜索树BST中查找并返回最大元素所在结点的地址*/
Position FindMax(BinTree BT);

/*使用返回值插入结点*/
BinTree Insert(ElementType X, BinTree BST);

/*使用指针插入结点*/
void Insert_Pointer(ElementType X, BinTree *BST);

/*使用返回值删除结点*/
BinTree Delete(ElementType X, BinTree BST);

/*使用指针删除结点*/
void Delete_Pointer(ElementType X, BinTree *BST);