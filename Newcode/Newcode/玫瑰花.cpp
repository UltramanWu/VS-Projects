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
	int n, k;
	cin >> n >> k;
	int Re;
	Re = (long long)(fact(n) / (fact(n - k)*fact(k))*pow(k, n - k))%772235;
	cout << Re << endl;
	system("pause");
	return 0;
}



int fact(int n){
	int res = 1;
	for (int i = 1; i <= n; i++)
		res *= i;
	return res;
}