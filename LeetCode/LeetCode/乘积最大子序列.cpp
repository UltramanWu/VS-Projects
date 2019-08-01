//#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
//#include <queue>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//
//int maxProduct(vector<int>& nums);
//int main()
//{
//	vector<int> vec = { -2,0,-1};
//	int Re = maxProduct(vec);
//
//	system("pause");
//	return 0;
//}
//
//int maxProduct(vector<int>& nums) {
//	int len = nums.size();
//	if (!len)
//		return 0;
//	int MaxSum = nums[0];
//	int Sum = nums[0];
//	for (int i = 1; i < len; i++){
//		Sum = nums[i]>Sum*nums[i] ? nums[i] : Sum*nums[i];
//		if (Sum > MaxSum)
//			MaxSum = Sum;
//	}
//	return MaxSum;
//}