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

/*创建树节点*/
/*返回：根节点的值*/
Tree BulidTree(struct TreeNode T[]);

/*二叉树同构判定*/
/*返回值：Bool值*/
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
			if (cl != '-')   //对左子树进行判断
			{
				T[i].Left = cl - '0';
				Check[T[i].Left] = 1;
			}
			else T[i].Left = -1;
			if (cr != '-')  //对右子树进行判断
			{
				T[i].Right = cr - '0';
				Check[T[i].Right] = 1;
			}
			else T[i].Right = -1;
		}

		for (int i = 0; i< N; i++)//查找根结点
		{
			if (Check[i] == 0)
				return i;
		}


	}
	else
		cout << "输入结点个数大于最大值，创建失败";
		return Null;
}

int Isomorphic(Tree R1, Tree  R2)
{
	if ((R1 == Null) && (R2 == Null))  /*判断当前项是否为叶节点*/
		return 1;
	if (((R1 != Null) && (R2 == Null)) || ((R1 == Null) && (R2 != Null)))
		return 0;
	if (T1[R1].Element != T2[R2].Element)
		return 0;
	if ((T1[R1].Left == Null) && (T2[R2].Left == Null))  /*左子树同构*/
		return (Isomorphic(T1[R1].Right, T2[R2].Right));  /*对右子树进行比较*/
	if (((T1[R1].Left != Null) && (T2[R2].Left != Null)) && (T1[T1[R1].Left].Element == T2[T2[R2].Left].Element))
			/*左右子树均存在子树且结点元素相同*/
			/*不需要交换左右子树*/
			return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
	else
			/*左右子树均存在子树且结点元素不相同*/
			/*需要交换左右子树*/
			return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));
}
