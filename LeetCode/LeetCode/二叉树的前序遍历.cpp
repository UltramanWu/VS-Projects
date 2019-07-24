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
///* �ݹ���� */
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
///* ������ʵ��ǰ����� */
//vector<int> preorderTraversal(TreeNode* root){
//	if (root == NULL)
//		return{};
//	stack<TreeNode* > S;  /* ��ջ */
//	vector<int>  Pre;  /* ������� */
//	while (root || !S.empty())
//	{
//		while (root){
//			Pre.push_back(root->val);  /* �ȷ��ʽ���ֵ */
//			S.push(root);
//			root = root->left;   /* ת���������� */
//		}
//		root = S.top();
//		S.pop();
//		root = root->right;
//	}
//	return Pre;
//}