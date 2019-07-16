#include"Heap.h"

int main()
{
	/*MinHeap MH;
	MH = CreatMin(10);
	InsertMin(MH, 99);
	InsertMin(MH, 100);
    InsertMin(MH, 95);
	InsertMin(MH, 93);
	InsertMin(MH, 80);
	InsertMin(MH, 96);
	DeleteMin(MH);
	/*Insert(MH, 94);
	Insert(MH, 50);*/
	MinHeap MH;
	int N, L, End;;
	ElementType item;  /* 需要插入的元素 */
	cin >> N >> L;
	MH = CreatMin(10);
	while (N--)
	{
		cin >> item;
		InsertMin(MH, item);
	}
	while (L--)
	{
		cin >> End;
		for (int j = End; MH->Element[j]>0; j /= 2)
		{
			cout << MH->Element[j] << " ";  /* 打印路径 */
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}