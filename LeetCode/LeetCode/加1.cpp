//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//vector<int> plusOne(vector<int>& digits);
//int main()
//{
//	vector<int> vec = {8,9,9,9};
//	vec = plusOne(vec);
//	system("pause");
//	return 0;
//}
//
//vector<int> plusOne(vector<int>& digits) {
//	int len = digits.size();
//	if (len == 0)
//		return{};
//	int position = len - 1;
//	int last = digits[position];
//	while (last == 9){   /* 针对特殊的各位都是9的情况 */
//		if (position == 0){
//			digits.insert(digits.begin(), 1);  /* 向第一位插入值 */
//			digits[position+1] = 0;
//			break;
//		}
//		else	
//			digits[position] = 0;
//			position --;  /* 指针向前移动 */
//			last = digits[position];
//	}
//	if (digits.size() == len)
//		digits[position]++;
//	return digits;
//}