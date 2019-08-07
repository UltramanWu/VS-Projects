//#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
//#include <queue>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//
//vector<vector<int>> subsetsWithDup(vector<int>& nums);
//int main()
//{
//	vector<int> test = { 2,1,2,1,3 };
//	vector<vector<int>> re = subsetsWithDup(test);
//	system("pause");
//	return 0;
//}
//
//void backtrack(vector<int> nums, vector<vector<int>> &ans, vector<int> curr, int n, int level){
//	if (level <= nums.size()){
//		ans.push_back(curr);
//	}
//	for (int j = level; j < n + 1; j++){
//		if (j>level && nums[j - 1] == nums[j])
//			continue;
//		curr.push_back(nums[j]);
//		backtrack(nums, ans, curr, n, j + 1);
//		curr.pop_back();
//	}
//
//}
//vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//	int Len = nums.size();
//	vector<int> curr;
//	vector<vector<int>> ans;
//	sort(nums.begin(), nums.end());
//	backtrack(nums, ans, curr, Len - 1, 0);
//	return ans;
//}