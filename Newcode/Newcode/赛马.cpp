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
	int T;
	int n,i;
	int num;
	vector<int> vel;

	cin >> T;
	while (T--){
		cin >> n;
		for (i = 0; i < 2 * n; i++){
			cin >> num;
			vel.push_back(num);
		}
		sort(vel.begin(),vel.end());
		for (i = 0; i < n; i++)
			if (vel[i] >= vel[i + n])
				break;
		if (i <= n - 1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
		vel.clear();
	}
	system("pause");
	return 0;
}