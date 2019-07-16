#include"Union.h"

/* �������� */
void Union(SetType S, SetName Root1, SetName Root2)
{
	if (S[Root1]  > S[Root2])   /* �������2�Ƚϴ� */
	{
		S[Root2] += S[Root1];  /* ����1���뼯��2 */
		S[Root1] = Root2;  /* ��Root1�ĸ��ڵ�ת��ΪRoot2 */
	}
	else  /* �������1�Ƚϴ� */
	{
		S[Root1] += S[Root2];  /* ����2���뼯��1 */
		S[Root2] = Root1;  /* ��Root2�ĸ��ڵ�ת��ΪRoot1 */
	}
}

/* ����Ԫ�� */
SetName Find(SetType S, ElementType X)
{  /* Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ1 */
	if (S[X] < 0)  /* �ҵ����ϵĸ� */
		return X;
	else
		return S[X] = Find(S, S[X]);  /* ·��ѹ�� */    /* ��������ڵ㲢������ڵ�ĸ��ڵ�ָ����ڵ� */
}