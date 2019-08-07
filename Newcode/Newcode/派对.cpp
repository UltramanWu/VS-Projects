//#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
//#include <queue>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//
//
//int main()
//{
//	int r, g, b;
//	int T;
//	int count = 0;
//	int Max, Min;
//	cin >> T;
//
//	while (T--){
//		cin >> r >> g >> b;
//		count = 0;
//		count = min(min(r, g), b);
//		r -= count;
//		g -= count;
//		b -= count;
//		if (!r){
//			Max = max(g, b);
//			Min = min(g, b);
//		}
//		else if (!g){
//			Max = max(r, b);
//			Min = min(r, b);
//		}
//		else{
//			Max = max(r, g);
//			Min = min(r, g);
//		}
//		while (Min && Max >= 2 * Min){
//			count ++;
//			Min--;
//			Max -= 2;
//		}
//		cout << count << endl;
//	}
//	system("pause");
//	return 0;
//}