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

/* 操作集 */

/* 并集操作 */
void Union(SetType S, SetName Root1, SetName Root2);

/* 查找元素 */
SetName Find(SetType S, ElementType X);