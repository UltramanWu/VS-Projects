#include<iostream>
#include"Chain.h"
using namespace std;

//操作集
int IsEmptyT(BinTree BT);//判断是否为空

BinTree CreatBinTree(); //创建二叉树
void CreatBinTree_Pointer(BinTree *BT); //不需要返回值的二叉树创建

void DestoryBinTree(BinTree BT);  //销毁二叉树

void InsertBinTree(BinTree(*BT), int Direction, int item); //插入二叉树结点

void PreOrderTraserval(BinTree BT); //先序遍历

void InOrderTraserval(BinTree BT);   //中序遍历

void PostOrderTraserval(BinTree BT); //后序遍历

void LevelOrderTraserval(BinTree BT);//层序遍历

void PreOrderPrintLeaves(BinTree BT); //求叶节点

int PostOrderGetHeight(BinTree BT); //求二叉树的深度
