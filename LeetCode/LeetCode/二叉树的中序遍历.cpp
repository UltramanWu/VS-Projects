//#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
//#include <algorithm>
//using namespace std;
//
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//vector<int> inorderTraversal(TreeNode* root);
//
//int main()
//{
//	TreeNode* Root = new TreeNode(1);
//	TreeNode* Left = new TreeNode(2);
//	TreeNode* Right = new TreeNode(3);
//	Root->right = Left;
//	Left->left = Right;
//	vector<int> Result = inorderTraversal(Root);
//	system("pause");
//	return 0;
//}
//
///* 递归实现 */
//void inSubOrder(TreeNode *root, vector<int> &pre){
//	if (root == NULL)
//		return;
//
//	inSubOrder(root->left, pre);
//	pre.push_back(root->val);
//	inSubOrder(root->right, pre);
//}
//
///* N叉树的前序遍历 */
//vector<int> inorderTraversal(TreeNode* root) {
//	if (root == NULL)
//		return{};
//	vector<int> Pre;
//	inSubOrder(root, Pre);
//
//	return Pre;
//}
//
///* 非递归实现中序遍历 */
///* 原理：按照子树遍历的反向顺序按照“先进后出”的原理先对其进行压栈，先压栈最右边的子树，
//再压栈最左边的子树。当弹出时先弹出左子树，按照这种次序就可以实现前序遍历。 */
//vector<int> inorderTraversal(TreeNode* root){
//	if (root == NULL)
//		return{};
//	stack<TreeNode* > S;  /* 堆栈 */
//	vector<int>  Pre;  /* 容器存放 */
//	while (root || !S.empty()){
//		while (root){
//			S.push(root);
//			root = root->left;
//		}
//		root = S.top(); S.pop();
//		Pre.push_back(root->val);
//		root = root->right;
//	}
//	return Pre;
//}