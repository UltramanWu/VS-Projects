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
//int mySqrt(int x);
//int main()
//{
//	int re = mySqrt(23);
//	system("pause");
//	return 0;
//}
//
//int mySqrt(int x) {
//	if (x == 0 || x == 1)
//		return x;
//	int left = 0;
//	int right = x;
//	int middle = (left+right) / 2;
//	while (1){
//		if (pow(middle, 2) <= x && pow(middle + 1, 2) > x)
//			break;
//		else if (pow(middle, 2) < x && pow(middle + 1, 2) >= x){
//			middle++;
//			break;
//		}	
//		else if (pow(middle,2) > x)
//			right = middle;
//		else if (pow(middle + 1, 2) < x)
//			left = middle;
//		middle = (left + right) / 2;
//	}
//	return middle;
//}
