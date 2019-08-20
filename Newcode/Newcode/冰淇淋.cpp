//#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
//#include <queue>
//#include <cmath>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//
//int n;
//long long m;
//vector<long long> w;
//vector<int> v;
//multimap<long long, int> s;
//
//int main()
//{
//	long long  count = 0;   /* 最大库存数 */
//	long long diff = 0;
//	int a;
//	long long b;
//	long long sum;
//	long long  i;
//	long long num = 0;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++){
//		cin >> a;
//		w.push_back(a);
//	}
//	for (int i = 0; i < n; i++){
//		cin >> b;
//		v.push_back(b);
//	}
//	for (int i = 0; i < n; i++)
//		s.insert(pair<long long, int>(w[i], v[i]));
//	count += s.begin()->first;   /* 直接获取第一个的值 */
//	auto preitor = s.begin();
//	auto postitor = s.begin();
//	postitor++;
//	while (preitor != s.end() && postitor != s.end()){
//		while (postitor != s.end() && preitor->first == postitor->first){
//			preitor++;
//			postitor++;
//		}
//		if (postitor == s.end())
//			diff = INT_MAX;
//		else
//			diff = postitor->first - preitor->first;
//		sum = 0;
//		for (auto itor = s.begin(); itor != postitor&&m > 0; itor++)
//			sum += itor->second;
//		for (i = 0; i < diff && m>sum; i++)
//			m -= sum;
//		if (i){
//			count += i;
//			if (postitor != s.end()){
//				preitor++;
//				postitor++;
//			}
//		}
//		else
//			break;
//	}
//	cout << count << endl;
//
//	system("pause");
//	return 0;
//}
//
