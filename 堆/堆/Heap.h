#include<iostream>
using namespace std;

#define Full 1000;

/* ���ݼ� */
typedef struct HeapStruct *MaxHeap;
typedef struct HeapStruct *MinHeap;
typedef int ElementType;

struct HeapStruct{
	ElementType (*Element);/* �洢Ԫ�ص����� */
	int Size; /* �ѵĵ�ǰԪ�ظ��� */
	int Capacity; /* �ѵ�������� */
};

/* ������ */

/* ����һ���յ����� */
MaxHeap Create(int MaxSize); 

/* �ж�����H�Ƿ����� */
bool IsFull(MaxHeap H);

/* ��Ԫ��item���뵽������ */
void Insert(MaxHeap H, ElementType item);

/* �ж�����H�Ƿ�Ϊ�� */
bool IsEmpty( MaxHeap H );

/* ɾ��������H�����Ԫ�� */
ElementType DeleteMax(MaxHeap H);


/* ����һ���յ���С�� */
MinHeap CreatMin(int MaxSize);

/* ��Ԫ�ز��뵽��С���� */
void InsertMin(MinHeap MH, ElementType item);

/* ɾ��������MH����С��Ԫ�� */
ElementType DeleteMin(MinHeap MH);


