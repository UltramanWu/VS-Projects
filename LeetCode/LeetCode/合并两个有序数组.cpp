//#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
//#include <queue>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//
//void Merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
//int main()
//{
//	vector<int> num1 = { 1, 2, 3, 0, 0, 0 };
//	vector<int> num2 = { 2, 5, 6 };
//	Merge(num1, 3, num2, 3);
//	system("pause");
//	return 0;
//}
///*  ¹é²¢ÅÅĞò*/
//void Merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//	if (!m)
//		return sort(nums2.begin(),nums2.end());
//	if (!n)
//		return sort(nums1.begin(), nums1.end());
//	int i = 0;
//	int j = 0;
//	while (i < m+n){
//		while (nums1[i] < nums2[j]&&nums1[i]!=0)
//			i++;
//		nums1.insert(nums1.begin() + i, nums2[j]);
//		j++;
//		if (j >= n)
//			break;
//	}
//	nums1.erase(nums1.begin() + i + 1,nums1.end());
//}