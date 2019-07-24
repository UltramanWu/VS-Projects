#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;


int main()
{

	system("pause");
	return 0;
}


/* 非递归实现幂运算 */
double myPow(double x, int n) {
	long long N = n;
	if (N < 0){
		x = 1 / x;
		N = -N;
	}
	double current_product = x;
	double ans = 1;
	for (long long i = N; i; i /= 2){
		if (i % 2)
			ans *= current_product;
		current_product *= current_product;
	}
	return ans;
}

double myPow(double x, int n) {
	long long N = n;
	if (N < 0) {
		x = 1 / x;
		N = -N;
	}
	double ans = 1;  /* 结果保存 */
	double current_product = x;  /* 当前运算值 */
	for (long long i = N; i; i /= 2) {
		if ((i % 2) == 1) {
			ans = ans * current_product;
		}
		current_product = current_product * current_product;
	}
	return ans;
}

double fastPow(double x, long long n){
	if (!n)
		return 1.0;
	double half = fastPow(x, n / 2);  /* 获取折半后的结果 */
	if (n % 2)  /* 如果幂为奇数 */
		return half * half;
	else
		return half*half*x;
}

/* 递归实现幂运算 */
double myPow(double x, int n){
	long long N = n;
	if (N < 0){
		x = 1 / x;
		N = -N;
	}
	return fastPow(x,N);
}