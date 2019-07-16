#include<iostream>
using namespace std;


typedef struct TreeNode *Tree;
typedef int ElementType;
struct TreeNode{
	ElementType Data;
	Tree Left, Right;
	int Flag;/*用于序列之间的判定，当对应序列被比较同一后置1，否则置0*/
};



/* 操作集 */

/* 创建树 */
Tree CreatTree(ElementType Data );

/* 插入树节点 */
Tree Insert(Tree T, ElementType Data);

/* 判断序列一致性 */

int Judge( Tree T, int N );

/* 判定节点一致性 */
int Check(Tree T, int N );

/* 复位操作 */
void Reset(Tree T);

/* 释放二叉树 */
void DeleteT(Tree T);