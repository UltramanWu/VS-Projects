#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

long long n;
long long k;

int fac(int x,int y){
	int f;
	if (x == y)
		return y;
	else
		return x*fac(x-1,y);
}



int main()
{
	long long  count = 0;
	string target = "sensetime";
	cin >> n >> k;  /* 数据输入 */
	if (n < 9)
		cout << 0 << endl;
	else{
		switch (k){
		case 1:
			
			break;
		case 2:
			int a = n / 9;
			for (int i = a; i > 0; i++){
				if (n - a * 9){
					count += pow(26, (n - a * 9));
				}
				else  /* 如果没有余数 */
					count++;
				if (count / 998244353)
					count = count % 998244353;
			}
			break;
		case 3:
			count = fac(26,9)/fac(9,1)*pow(26, n - 9);
			if (count / 998244353)
				count = count % 998244353;
			break;
		case 4:
			count = (n - 9) / 2 * pow(26, n - 9);
			if (count /998244353)
				count = count % 998244353;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
