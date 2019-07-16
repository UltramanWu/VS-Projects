#include<iostream>
using namespace std;

#define Full 1000;

/* 数据集 */
typedef struct HeapStruct *MaxHeap;
typedef struct HeapStruct *MinHeap;
typedef int ElementType;

struct HeapStruct{
	ElementType (*Element);/* 存储元素的数组 */
	int Size; /* 堆的当前元素个数 */
	int Capacity; /* 堆的最大容量 */
};

/* 操作集 */

/* 创建一个空的最大堆 */
MaxHeap Create(int MaxSize); 

/* 判断最大堆H是否已满 */
bool IsFull(MaxHeap H);

/* 将元素item插入到最大堆中 */
void Insert(MaxHeap H, ElementType item);

/* 判断最大堆H是否为空 */
bool IsEmpty( MaxHeap H );

/* 删除并返回H中最大元素 */
ElementType DeleteMax(MaxHeap H);


/* 创建一个空的最小堆 */
MinHeap CreatMin(int MaxSize);

/* 将元素插入到最小堆中 */
void InsertMin(MinHeap MH, ElementType item);

/* 删除并返回MH中最小的元素 */
ElementType DeleteMin(MinHeap MH);


