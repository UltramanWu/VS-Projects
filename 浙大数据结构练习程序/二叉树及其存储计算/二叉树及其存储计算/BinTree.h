#include<iostream>
#include"Chain.h"
using namespace std;

//������
int IsEmptyT(BinTree BT);//�ж��Ƿ�Ϊ��

BinTree CreatBinTree(); //����������
void CreatBinTree_Pointer(BinTree *BT); //����Ҫ����ֵ�Ķ���������

void DestoryBinTree(BinTree BT);  //���ٶ�����

void InsertBinTree(BinTree(*BT), int Direction, int item); //������������

void PreOrderTraserval(BinTree BT); //�������

void InOrderTraserval(BinTree BT);   //�������

void PostOrderTraserval(BinTree BT); //�������

void LevelOrderTraserval(BinTree BT);//�������

void PreOrderPrintLeaves(BinTree BT); //��Ҷ�ڵ�

int PostOrderGetHeight(BinTree BT); //������������
