#include<iostream>
using namespace std;

#define MAXN 1000
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MAXN];

//typedef struct{
//	ElementType Data;
//	int Parents;
//} SetType;

/* ������ */

/* �������� */
void Union(SetType S, SetName Root1, SetName Root2);

/* ����Ԫ�� */
SetName Find(SetType S, ElementType X);