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

	system("pause");
	return 0;
}

void backtrack(vector<vector<int>>&res, vector<int>& nums,vector<int>&ans,int len,int j){
	if (ans.size() == len)
		res.push_back(ans);
	else{
		for (int i = 0; i < len; i++){
			if (i == j)
				continue;
			ans.push_back(nums[i]);
			backtrack(res, nums, ans, len, i);
			ans.pop_back();
		}
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	int len = nums.size();
	if (!len)
		return{};
	vector<vector<int>> res;
	vector<int>ans;
	backtrack(res, nums, ans, len, -1);
	return res;
}