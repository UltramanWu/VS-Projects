#include"Heap.h"

/* ����һ���յ����� */
MaxHeap Create(int MaxSize)
{
	MaxHeap H = new struct HeapStruct;
	H->Element = new ElementType[MaxSize + 1];  /* �����һ���ռ䣬���������λ�÷����ڱ� */
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Element[0] = 1000;  
		/* ���塰�ڱ���Ϊ���ڶ������п���Ԫ�ص�ֵ�������Ժ������� */
	return H;
}

/* �ж�����H�Ƿ����� */
bool IsFull(MaxHeap H)
{
	if (H->Size == H->Capacity)
		return 1;
	return 0;
}

/* ��Ԫ��item���뵽������ */
void Insert(MaxHeap H, ElementType item)
{

	if (IsFull(H))
	{
		cout << "��ǰ���������޷����룡" << endl;
		return;
	}
		
	int i = ++H->Size;  /* iָ��������е����һ��Ԫ�ص�λ�� */
	for (  ; H->Element[i / 2]  < item ; i /= 2)
	{
		H->Element[i]= H->Element[i / 2];  /* ���丸�ڵ���������Ƶ��ӽڵ��� */
	}
	H->Element[i] = item;  /* ��item���� */
}

/* �ж�����H�Ƿ�Ϊ�� */
bool IsEmpty(MaxHeap H)
{
	if (H->Size == 0)
		return 1;
	return 0;
}

/* ɾ��������H�����Ԫ�� */
ElementType DeleteMax(MaxHeap H)
{
	ElementType DeleteItem,Temp;
	int  Parents, Child;
	if (IsEmpty(H))
	{
		cout << "��ǰ���ѿգ��޷�ɾ����" << endl;
		return Full;
	}
		
	DeleteItem = H->Element[1];  /* �����ֵ�洢 */

	Temp = H->Element[H->Size --];  /* ȡ�����һ�����ֵ */

	for (Parents = 1; Parents * 2 <= H->Size; Parents = Child)
	{
		Child = Parents * 2;  /* �����������λ�� */
		if ((Child != H->Size) && (H->Element[Child] < H->Element[Child + 1]))
			Child++;  /* Childָ�������ӽڵ�Ľϴ��� */
		if (Temp > H->Element[Child])  break;  /* ��������forѭ�� */
		else  /* �ƶ�tempԪ�ص���һ�� */
			H->Element[Parents] = H->Element[Child];
	}
	H->Element[Parents] = Temp;

	return DeleteItem;
}

/* ����һ���յ���С�� */
MinHeap CreatMin(int MaxSize)
{
	MinHeap MH = new struct HeapStruct;
	MH->Element = new ElementType[MaxSize + 1];
	MH->Size = 0;
	MH->Capacity = MaxSize;
	MH->Element[0] = 0;

	return MH;
}

/* ��Ԫ�ز��뵽��С���� */
void InsertMin(MinHeap MH , ElementType item)
{
	
	if (IsFull(MH))
	{
		cout << "��ǰ���������޷����룡" << endl;
		return;
	}
	int i = ++MH->Size;
	for (; MH->Element[i / 2] > item; i /= 2)
	{
		MH->Element[i] = MH->Element[i / 2];
	}
	MH->Element[i] = item;
}

/* ɾ��������MH����С��Ԫ�� */
ElementType DeleteMin(MinHeap MH)
{
	ElementType DeleteItem,Temp;
	int Parents,Child;
	if (IsEmpty(MH))
		cout << "��ǰ���ѿգ��޷�ɾ����" << endl;
	DeleteItem = MH->Element[1];

	Temp = MH->Element[MH->Size--];
	for (Parents = 1; Parents * 2 <= MH->Size; Parents = Child)  /* ��ֹ������1����ǰ���������������2����ǰ��������ֵ�����һ��������ֵС */
	{
		Child = Parents * 2;
		if ((Child != MH->Size) && (MH->Element[Child] > MH->Element[Child + 1]))
			Child++;  /*  ѡȡ�������������ݽ�С��һ�� */
		if (Temp < MH->Element[Child])  break;
		else MH->Element[Parents] = MH->Element[Child];  /* ���ӽ������ݸ������ڵ㣬���������ӽڵ������ */
	}
	MH->Element[Parents] = Temp;  /* ��Temp��ֵ���ж���λ�� */
	return DeleteItem;
}