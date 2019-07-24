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
///* �ݹ�ʵ�� */
//void inSubOrder(TreeNode *root, vector<int> &pre){
//	if (root == NULL)
//		return;
//
//	inSubOrder(root->left, pre);
//	pre.push_back(root->val);
//	inSubOrder(root->right, pre);
//}
//
///* N������ǰ����� */
//vector<int> inorderTraversal(TreeNode* root) {
//	if (root == NULL)
//		return{};
//	vector<int> Pre;
//	inSubOrder(root, Pre);
//
//	return Pre;
//}
//
///* �ǵݹ�ʵ��������� */
///* ԭ���������������ķ���˳���ա��Ƚ��������ԭ���ȶ������ѹջ����ѹջ���ұߵ�������
//��ѹջ����ߵ�������������ʱ�ȵ������������������ִ���Ϳ���ʵ��ǰ������� */
//vector<int> inorderTraversal(TreeNode* root){
//	if (root == NULL)
//		return{};
//	stack<TreeNode* > S;  /* ��ջ */
//	vector<int>  Pre;  /* ������� */
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