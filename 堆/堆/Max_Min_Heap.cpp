#include"Heap.h"

/* 创建一个空的最大堆 */
MaxHeap Create(int MaxSize)
{
	MaxHeap H = new struct HeapStruct;
	H->Element = new ElementType[MaxSize + 1];  /* 申请多一个空间，用于在起初位置放置哨兵 */
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Element[0] = 1000;  
		/* 定义“哨兵”为大于堆中所有可能元素的值，便于以后更快操作 */
	return H;
}

/* 判断最大堆H是否已满 */
bool IsFull(MaxHeap H)
{
	if (H->Size == H->Capacity)
		return 1;
	return 0;
}

/* 将元素item插入到最大堆中 */
void Insert(MaxHeap H, ElementType item)
{

	if (IsFull(H))
	{
		cout << "当前堆已满，无法插入！" << endl;
		return;
	}
		
	int i = ++H->Size;  /* i指向插入后堆中的最后一个元素的位置 */
	for (  ; H->Element[i / 2]  < item ; i /= 2)
	{
		H->Element[i]= H->Element[i / 2];  /* 将其父节点的数据下移到子节点上 */
	}
	H->Element[i] = item;  /* 将item插入 */
}

/* 判断最大堆H是否为空 */
bool IsEmpty(MaxHeap H)
{
	if (H->Size == 0)
		return 1;
	return 0;
}

/* 删除并返回H中最大元素 */
ElementType DeleteMax(MaxHeap H)
{
	ElementType DeleteItem,Temp;
	int  Parents, Child;
	if (IsEmpty(H))
	{
		cout << "当前堆已空，无法删除！" << endl;
		return Full;
	}
		
	DeleteItem = H->Element[1];  /* 将最大值存储 */

	Temp = H->Element[H->Size --];  /* 取出最后一个结点值 */

	for (Parents = 1; Parents * 2 <= H->Size; Parents = Child)
	{
		Child = Parents * 2;  /* 其左子树结点位置 */
		if ((Child != H->Size) && (H->Element[Child] < H->Element[Child + 1]))
			Child++;  /* Child指向左右子节点的较大者 */
		if (Temp > H->Element[Child])  break;  /* 跳出整个for循环 */
		else  /* 移动temp元素到下一层 */
			H->Element[Parents] = H->Element[Child];
	}
	H->Element[Parents] = Temp;

	return DeleteItem;
}

/* 创建一个空的最小堆 */
MinHeap CreatMin(int MaxSize)
{
	MinHeap MH = new struct HeapStruct;
	MH->Element = new ElementType[MaxSize + 1];
	MH->Size = 0;
	MH->Capacity = MaxSize;
	MH->Element[0] = 0;

	return MH;
}

/* 将元素插入到最小堆中 */
void InsertMin(MinHeap MH , ElementType item)
{
	
	if (IsFull(MH))
	{
		cout << "当前堆已满，无法插入！" << endl;
		return;
	}
	int i = ++MH->Size;
	for (; MH->Element[i / 2] > item; i /= 2)
	{
		MH->Element[i] = MH->Element[i / 2];
	}
	MH->Element[i] = item;
}

/* 删除并返回MH中最小的元素 */
ElementType DeleteMin(MinHeap MH)
{
	ElementType DeleteItem,Temp;
	int Parents,Child;
	if (IsEmpty(MH))
		cout << "当前堆已空，无法删除！" << endl;
	DeleteItem = MH->Element[1];

	Temp = MH->Element[MH->Size--];
	for (Parents = 1; Parents * 2 <= MH->Size; Parents = Child)  /* 终止条件：1、当前结点无左右子树；2、当前结点的子树值比最后一个子树的值小 */
	{
		Child = Parents * 2;
		if ((Child != MH->Size) && (MH->Element[Child] > MH->Element[Child + 1]))
			Child++;  /*  选取左右子树中数据较小的一方 */
		if (Temp < MH->Element[Child])  break;
		else MH->Element[Parents] = MH->Element[Child];  /* 将子结点的数据赋给父节点，并下移至子节点的树层 */
	}
	MH->Element[Parents] = Temp;  /* 将Temp赋值给判定的位置 */
	return DeleteItem;
}