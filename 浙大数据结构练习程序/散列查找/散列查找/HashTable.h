#include<iostream>
#include <cmath>
#include<cstring>
using namespace std;

const int KEYLENGTH = 11;  /* 创建字符串的最大长度 */
const int MAXTABLESIZE = 100000;  /* 允许开辟的最大散列长度 */
const int MaxN = 5;  /* 表示查找数据的位数 */
typedef char ElementType[KEYLENGTH + 1];  /*  关键词类型用整型 */
typedef int Index;  /* 散列地址类型 */

/* 散列单元 */
typedef struct LNode *PtrToLNode;
typedef PtrToLNode Position;
typedef PtrToLNode List;

struct LNode{
	ElementType Data;
	int Count;
	PtrToLNode next;
};

/**** 以上是单链表的定义 *****/

typedef struct TblNode *HashTable;  /* 散列表类型 */
struct TblNode{  /* 散列表结点定义 */
	int TableSize;  /* 表的最大长度 */
	List Heads;		/* 指向链表头结点的数组 */
};


/* 散列求值 */
int Hash(int Key, int TableSize)
{
	return (Key%TableSize);
}

/* 获取比N大但是最接近N的素数 */
int NextPrime(int N)
{
	int i, P = (N % 2) ? (N + 2) : (N + 1);
	while (P < MAXTABLESIZE){
		for (i = sqrt(P); i > 2; i--)
			if (!(P%i))  break;
		if (i == 2)   break;  /* 证明是素数 */
		else P += 2;  /* 否则再进行下一次尝试 */
	}
	return P;/* 返回素数的值 */
}

/* 创建散列表 */
HashTable CreateTable(int TableSize)
{
	HashTable H;
	int i;

	H = new struct TblNode;
	H->TableSize = NextPrime(TableSize * 2);
	H->Heads = new struct LNode[H->TableSize];
	for (i = 0; i < H->TableSize; i++){
		H->Heads[i].Count = 0;
		H->Heads[i].Data[0] = '\0';
		H->Heads[i].next = NULL;
	}
	return H;
}

/* 查找操作 */
Position Find(HashTable H, ElementType Key)
{
	Position P;
	Index Pos;

	Pos = Hash(atoi(Key + KEYLENGTH - MaxN), H->TableSize);
	P = H->Heads[Pos].next;
	while (P &&strcmp(P->Data, Key))  /*  当P不为空同时两者字符串不同时 */
		P = P->next;  /* 结点后移 */

	return P;
}

/* 插入操作 */
bool Insert(HashTable H, ElementType Key)
{
	Position P, NewCell;
	Index Pos;

	P = Find(H, Key);
	if (!P)
	{
		NewCell = new struct LNode;
		NewCell->Count = 1;
		Pos = Hash(atoi(Key + KEYLENGTH - MaxN), H->TableSize);
		strcpy_s(NewCell->Data, Key);  /* 对结构体内字符串进行赋值 */
		NewCell->next = H->Heads[Pos].next;
		H->Heads[Pos].next = NewCell;
		return true;
	}
	else
	{  /* 当该结点不为空时，将其计数器加1 */
		P->Count++;
		return false;
	}
}



/* 销毁散列表 */
void DestroyTable(HashTable H)
{
	int i;
	Position P, Tmp;

	/* 释放每个链表的结点 */
	for (i = 0; i < H->TableSize; i++){
		P = H->Heads[i].next;
		while (P){
			Tmp = P->next;
			delete(P);
			P = Tmp;
		}
	}
	delete(H->Heads);  /* 释放头结点数组 */
	delete(H);  /* 释放散列表结点 */

}

/* 查找最大的童话次数的号码 */
void ScanAndOutput(HashTable H)
{
	int Max, PCnt, i;
	Position P;
	ElementType MinDialogNum;  /*最小童话记录者 */
	Max  = PCnt = 0;
	MinDialogNum[0] = '\0';

	/* 先寻找最大值 */
	for (i = 0; i < H->TableSize; i++){
		P = H->Heads[i].next;  /* 从链表第一个节点开始 */
		while (P){  /* 当结点不为空时 */
			if (P->Count > Max){
				Max = P->Count;
				strcpy_s(MinDialogNum, P->Data);
				PCnt = 1;
			}
			else if (P->Count == Max){
				PCnt++;
				if (strcmp(P->Data, MinDialogNum))
					strcpy_s(MinDialogNum, P->Data);
			}
			P = P->next;  /* 结点向后移动 */
		}
	}

	cout << MinDialogNum << " " << Max;
	if (PCnt > 1) cout << PCnt;

	cout << endl;
}