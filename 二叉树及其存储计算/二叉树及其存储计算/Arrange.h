#include<iostream>
using namespace std;

#define MaxTree 10
typedef  char  ElementType ;
typedef  int  Tree;
#define Null -1

struct TreeNode{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree], T2[ MaxTree ]; 

/*�������ڵ�*/
/*���أ����ڵ��ֵ*/
Tree BulidTree(struct TreeNode T[]);

/*������ͬ���ж�*/
/*����ֵ��Boolֵ*/
int Isomorphic(Tree R1, Tree  R2);


Tree BulidTree(struct TreeNode T[])
{
	int N;
	char cl, cr;
	int Check[MaxTree];
	cin >> N;

	if (N <= MaxTree)
	{
		for (int i = 0; i < N; i++)
		{
			Check[i] = 0;
			cin >> T[i].Element >> cl >> cr;
			if (cl != '-')   //�������������ж�
			{
				T[i].Left = cl - '0';
				Check[T[i].Left] = 1;
			}
			else T[i].Left = -1;
			if (cr != '-')  //�������������ж�
			{
				T[i].Right = cr - '0';
				Check[T[i].Right] = 1;
			}
			else T[i].Right = -1;
		}

		for (int i = 0; i< N; i++)//���Ҹ����
		{
			if (Check[i] == 0)
				return i;
		}


	}
	else
		cout << "����������������ֵ������ʧ��";
		return Null;
}

int Isomorphic(Tree R1, Tree  R2)
{
	if ((R1 == Null) && (R2 == Null))  /*�жϵ�ǰ���Ƿ�ΪҶ�ڵ�*/
		return 1;
	if (((R1 != Null) && (R2 == Null)) || ((R1 == Null) && (R2 != Null)))
		return 0;
	if (T1[R1].Element != T2[R2].Element)
		return 0;
	if ((T1[R1].Left == Null) && (T2[R2].Left == Null))  /*������ͬ��*/
		return (Isomorphic(T1[R1].Right, T2[R2].Right));  /*�����������бȽ�*/
	if (((T1[R1].Left != Null) && (T2[R2].Left != Null)) && (T1[T1[R1].Left].Element == T2[T2[R2].Left].Element))
			/*�������������������ҽ��Ԫ����ͬ*/
			/*����Ҫ������������*/
			return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
	else
			/*�������������������ҽ��Ԫ�ز���ͬ*/
			/*��Ҫ������������*/
			return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));
}
