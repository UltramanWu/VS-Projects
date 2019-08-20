//# include <stdio.h>
//# include <iostream>
//# include <string.h>
//# include <string>
//# include <algorithm>
//# define MAXN 100005
//# define INFI 0x3f3f3f3f
//
//using namespace std;
//long long sum, mx = 0, mi = 0, Mx = 0, Mi = 0;
//long long num[MAXN], n;
//int main()
//{
//	//  freopen("in.txt","r",stdin);
//	ios::sync_with_stdio(false);
//	while (cin >> n)
//	{
//		memset(num, 0, sizeof(num));
//		Mx = -INFI;
//		Mi = INFI;
//		mx = mi = sum = 0;
//		long long tmp = 0;
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> num[i];
//			sum += num[i];
//			mx += num[i];
//			mi += num[i];
//			Mx = max(Mx, mx);
//			Mi = min(Mi, mi);
//			if (mi > 0) mi = 0;
//			if (mx < 0) mx = 0;
//		}
//		cout << max(sum - Mi, Mx) << endl;
//	}
//	return 0;
//}