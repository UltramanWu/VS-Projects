//#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
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
//vector<int> preorderTraversal(TreeNode* root);
//int main()
//{
//	TreeNode* Root = new TreeNode(1);
//	TreeNode* Left = new TreeNode(2);
//	TreeNode* Right = new TreeNode(3);
//	Root->right = Left;
//	Left->left = Right;
//	vector<int> Result = preorderTraversal(Root);
//	system("pause");
//	return 0;
//}
//
///* 递归调用 */
//void PreOrder(vector<int>&Pre,TreeNode* root){
//	if (root != NULL){
//		Pre.push_back(root->val);
//		PreOrder(Pre, root->left);
//		PreOrder(Pre, root->right);
//	}
//	else
//		return;
//}
//
//vector<int> preorderTraversal(TreeNode* root) {
//	if (root == NULL)
//		return{};
//	vector<int>  Pre;
//	PreOrder(Pre, root);
//	return Pre;
//}
//
///* 迭代法实现前序遍历 */
//vector<int> preorderTraversal(TreeNode* root){
//	if (root == NULL)
//		return{};
//	stack<TreeNode* > S;  /* 堆栈 */
//	vector<int>  Pre;  /* 容器存放 */
//	while (root || !S.empty())
//	{
//		while (root){
//			Pre.push_back(root->val);  /* 先访问结点的值 */
//			S.push(root);
//			root = root->left;   /* 转向其左子树 */
//		}
//		root = S.top();
//		S.pop();
//		root = root->right;
//	}
//	return Pre;
//}