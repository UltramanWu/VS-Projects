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
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//
//int main()
//{
//
//	system("pause");
//	return 0;
//}
//
//
///* 递归实现 */
//bool backtracks(TreeNode* left, TreeNode*right){
//	if (!right && !left)
//		return true;
//	else if (!right || !left)
//		return false;
//	if (left->val == right->val)
//		return  backtracks(left->left, right->right) && backtracks(left->right, right->left);
//	else
//		return false;
//}
//
//
//bool isSymmetric(TreeNode* root) {
//	if (!root)
//		return true;
//	return backtracks(root->left, root->right);
//}
//
//
///* 非递归实现 */
//bool isSymmetric(TreeNode* root) {
//	if (!root)
//		return true;
//	queue<TreeNode*> q;
//	q.push(root->left);
//	q.push(root->right);
//	while (!q.empty()){
//		TreeNode* t1 = q.front();
//		q.pop();
//		TreeNode* t2 = q.front();
//		q.pop();
//		if (!t1 && !t2) continue;
//		if (!t1 || !t2) return false;
//		if (t1->val != t2->val)return false;
//		q.push(t1->left);
//		q.push(t2->right);
//		q.push(t1->right);
//		q.push(t2->left);
//	}
//	return true;
//}