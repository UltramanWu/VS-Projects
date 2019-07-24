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
//
//vector<int> postorderTraversal(TreeNode* root);
//
//int main()
//{
//	TreeNode* Root = new TreeNode(1);
//	TreeNode* Left = new TreeNode(2);
//	TreeNode* Right = new TreeNode(3);
//	Root->right = Left;
//	Left->left = Right;
//	vector<int> Result = postorderTraversal(Root);
//	system("pause");
//	return 0;
//}
//
///* 非递归实现二叉树后序遍历 */
//vector<int> postorderTraversal(TreeNode* root) {
//	if (!root)
//		return{};
//	vector<int> Post;
//	stack<TreeNode*> S;
//	while (root || !S.empty()){
//		while (root){
//			S.push(root);
//			Post.insert(Post.begin(), root->val);
//			root = root->right;
//		}
//		root = S.top(); 
//		S.pop();  /* 弹出元素 */
//		root = root->left;
//		}
//	return Post;
//}
//
