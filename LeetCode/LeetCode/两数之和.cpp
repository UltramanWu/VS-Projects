//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//vector<int> twoSum(vector<int>& nums, int target);
//int main()
//{
//	vector<int> test = { 3, 3 };
//	vector<int> a = twoSum(test, 6);
//	system("pause");
//	return 0;
//}
//
//vector<int> twoSum(vector<int>& nums, int target) {
//	map<int, int> a;  /* 存放数据值 */
//	vector<int> b;
//	int Comp;
//	for (int i = 0; i < nums.size(); i++){
//		Comp = target - nums[i];
//		if (a.size()&&a.count(Comp)&& (a[Comp] != i)){
//			b.push_back(a[Comp]);
//			b.push_back(i);
//			break;
//		}
//		a[nums[i]] = i;  /* 插入map */
//	}
//	return b;
//}