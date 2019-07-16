//#include <iostream>
//#include<iomanip>
//using namespace std;
//
//const int LIMIT = 100001;  /* 最大容量 */
//
//struct ListNode{
//	int Data;  /* 当前结点位置 */
//	int Next;  /* 下一结点地址 */
//}L[LIMIT];
//typedef struct ListNode * List;
//
//
///* 逆转链表 */
//int Reverse(ListNode L[], int Head, int RN)
//{
//	int i, j, p;
//	int NextHead;
//	for (j = 0, p = L[Head].Next; j < RN && p != -1; j++)
//		p = L[p].Next;
//	NextHead = L[Head].Next;
//	
//	L[Head].Next = p;
//	for (j = 0, i = NextHead; j < RN&&i != -1; j++){
//		p = L[i].Next;
//		L[i].Next = L[Head].Next;
//		L[Head].Next = i;
//		i = p;
//	}
//	return NextHead;
//}
//
//
//int main()
//{
//
//	int FristAddress, N, ReverseNum,Count,TmpN;
//	int i, j;
//	int Address;
//	Count = 0;
//	cin >> FristAddress >> N >> ReverseNum;  /* 输入反转 */
//	
//	L[LIMIT-1].Next = FristAddress;  /* 保存头结点的值 */
//	TmpN = N;
//
//	/* 收录数据 */
//	while (TmpN--){  
//		cin >> Address;
//		cin >> L[Address].Data >> L[Address].Next;
//		}			
//	
//	/* 对元素个数重新统计 */
//	for (i = L[LIMIT - 1].Next; i != -1; i = L[i].Next)
//		Count++;
//	for (j = Count / ReverseNum, i = LIMIT - 1; j > 0&& i != -1; j--)
//		i = Reverse(L, i, ReverseNum);
//
//
//	/* 打印数据 */
//	for (j = 0, i = LIMIT - 1; j < Count &&i != -1; j++){
//		i = L[i].Next;
//		cout << setw(5) << setfill('0') << i << " ";
//		cout << L[i].Data << " ";
//		if (L[i].Next != -1)
//			cout << setw(5)<<setfill('0')<< L[i].Next << endl;
//		else
//			cout << L[i].Next << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}