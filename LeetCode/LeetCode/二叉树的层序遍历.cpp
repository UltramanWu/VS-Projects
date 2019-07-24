//#include <iostream>
//#include <vector>
//#include <string>
//#include <cmath>
//#include <math.h>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//vector<vector<int>> levelOrder(vector<int> root);
//vector<vector<int>> levelOrder(TreeNode* root);
//int main()
//{
//	TreeNode* TN = new TreeNode(3);
//	TreeNode* Left = new TreeNode(9);
//	TreeNode* Right = new TreeNode(20);
//	Right->left = new TreeNode(15);
//	Right->right = new TreeNode(7);
//	TN->left = Left;
//	TN->right = Right;
//	//cout << pow(2,0) << endl;
//	vector<vector<int>> Test = levelOrder(TN);
//	
//	system("pause");
//	return 0;
//}
//
//
//
//
//vector<vector<int>> levelOrder(TreeNode* root) {
//	if (root == NULL)
//		return{};
//	vector<vector<int>>  ArrayTree;
//	queue<TreeNode*> Q;
//	TreeNode * Tmp;
//	vector<int> vec;
//	Q.push(root);  /* 现将第一个元素push到队列中 */
//
//	while (Q.size()){
//		int len = Q.size();
//		for (int i = 0; i < len; i++){
//			Tmp = Q.front();
//			vec.push_back(Tmp->val);
//			if (Tmp->left)
//				Q.push(Tmp->left);
//			if (Tmp->right)
//				Q.push(Tmp->right);
//			Q.pop();  
//		}
//		ArrayTree.push_back(vec);  /* 将一维数组并入二维数组中 */
//		vec.clear();   /* 清除一维数组数据 */
//	}
//
//	return ArrayTree;
//}
//	
//
//
//vector<vector<int>> levelOrder(vector<int> root) {
//	int len = root.size();
//	if (len == 0)
//		return{};
//
//	vector<vector<int>>  ArrayTree;
//
//	int deepth = log2(len + 1);
//	for (int i = 0; i < deepth; i++)
//	{
//		vector<int> vec;
//		for (int j = 0; j < pow(2, i); j++)
//		{
//			int Tmp = root[pow(2, i) + j - 1];
//			if (Tmp != NULL)
//				vec.push_back(Tmp);
//		}
//		ArrayTree.push_back(vec);
//	}
//	return ArrayTree;
//}