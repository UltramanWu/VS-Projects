#include<iostream>
#include <cmath>
#include<cstring>
using namespace std;

const int KEYLENGTH = 11;  /* �����ַ�������󳤶� */
const int MAXTABLESIZE = 100000;  /* �����ٵ����ɢ�г��� */
const int MaxN = 5;  /* ��ʾ�������ݵ�λ�� */
typedef char ElementType[KEYLENGTH + 1];  /*  �ؼ������������� */
typedef int Index;  /* ɢ�е�ַ���� */

/* ɢ�е�Ԫ */
typedef struct LNode *PtrToLNode;
typedef PtrToLNode Position;
typedef PtrToLNode List;

struct LNode{
	ElementType Data;
	int Count;
	PtrToLNode next;
};

/**** �����ǵ�����Ķ��� *****/

typedef struct TblNode *HashTable;  /* ɢ�б����� */
struct TblNode{  /* ɢ�б��㶨�� */
	int TableSize;  /* �����󳤶� */
	List Heads;		/* ָ������ͷ�������� */
};


/* ɢ����ֵ */
int Hash(int Key, int TableSize)
{
	return (Key%TableSize);
}

/* ��ȡ��N������ӽ�N������ */
int NextPrime(int N)
{
	int i, P = (N % 2) ? (N + 2) : (N + 1);
	while (P < MAXTABLESIZE){
		for (i = sqrt(P); i > 2; i--)
			if (!(P%i))  break;
		if (i == 2)   break;  /* ֤�������� */
		else P += 2;  /* �����ٽ�����һ�γ��� */
	}
	return P;/* ����������ֵ */
}

/* ����ɢ�б� */
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

/* ���Ҳ��� */
Position Find(HashTable H, ElementType Key)
{
	Position P;
	Index Pos;

	Pos = Hash(atoi(Key + KEYLENGTH - MaxN), H->TableSize);
	P = H->Heads[Pos].next;
	while (P &&strcmp(P->Data, Key))  /*  ��P��Ϊ��ͬʱ�����ַ�����ͬʱ */
		P = P->next;  /* ������ */

	return P;
}

/* ������� */
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
		strcpy_s(NewCell->Data, Key);  /* �Խṹ�����ַ������и�ֵ */
		NewCell->next = H->Heads[Pos].next;
		H->Heads[Pos].next = NewCell;
		return true;
	}
	else
	{  /* ���ý�㲻Ϊ��ʱ�������������1 */
		P->Count++;
		return false;
	}
}



/* ����ɢ�б� */
void DestroyTable(HashTable H)
{
	int i;
	Position P, Tmp;

	/* �ͷ�ÿ������Ľ�� */
	for (i = 0; i < H->TableSize; i++){
		P = H->Heads[i].next;
		while (P){
			Tmp = P->next;
			delete(P);
			P = Tmp;
		}
	}
	delete(H->Heads);  /* �ͷ�ͷ������� */
	delete(H);  /* �ͷ�ɢ�б��� */

}

/* ��������ͯ�������ĺ��� */
void ScanAndOutput(HashTable H)
{
	int Max, PCnt, i;
	Position P;
	ElementType MinDialogNum;  /*��Сͯ����¼�� */
	Max  = PCnt = 0;
	MinDialogNum[0] = '\0';

	/* ��Ѱ�����ֵ */
	for (i = 0; i < H->TableSize; i++){
		P = H->Heads[i].next;  /* �������һ���ڵ㿪ʼ */
		while (P){  /* ����㲻Ϊ��ʱ */
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
			P = P->next;  /* �������ƶ� */
		}
	}

	cout << MinDialogNum << " " << Max;
	if (PCnt > 1) cout << PCnt;

	cout << endl;
}