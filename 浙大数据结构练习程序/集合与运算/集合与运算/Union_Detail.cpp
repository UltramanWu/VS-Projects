#include"Union.h"

/* 并集操作 */
void Union(SetType S, SetName Root1, SetName Root2)
{
	if (S[Root1]  > S[Root2])   /* 如果集合2比较大 */
	{
		S[Root2] += S[Root1];  /* 集合1并入集合2 */
		S[Root1] = Root2;  /* 将Root1的根节点转换为Root2 */
	}
	else  /* 如果集合1比较大 */
	{
		S[Root1] += S[Root2];  /* 集合2并入集合1 */
		S[Root2] = Root1;  /* 将Root2的根节点转换为Root1 */
	}
}

/* 查找元素 */
SetName Find(SetType S, ElementType X)
{  /* 默认集合元素全部初始化为1 */
	if (S[X] < 0)  /* 找到集合的根 */
		return X;
	else
		return S[X] = Find(S, S[X]);  /* 路径压缩 */    /* 返回其根节点并将其根节点的父节点指向根节点 */
}