//#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
//#include <algorithm>
//using namespace std;
//
//class Node {
//public:
//	int val;
//	vector<Node*> children;
//
//	Node() {}
//
//	Node(int _val, vector<Node*> _children) {
//		val = _val;
//		children = _children;
//	}
//};
//
//vector<int> preorder(Node* root);
//int main()
//{
//
//	system("pause");
//	return 0;
//}

///* 递归实现 */
//void PreSubOrder(Node *root, vector<int> &pre){
//	if (root == NULL)
//		return;
//	pre.push_back(root->val);
//	for (int i = 0; i < root->children.size(); i++)
//		if (root->children[i])
//			PreSubOrder(root->children[i], pre);
//}
//
///* N叉树的前序遍历 */
//vector<int> preorder(Node* root) {
//	if (root == NULL)
//		return{};
//	vector<int> Pre;
//	PreSubOrder(root, Pre);
//
//	return Pre;
//}

/* 非递归实现 */
/* 原理：按照子树遍历的反向顺序按照“先进后出”的原理先对其进行压栈，先压栈最右边的子树，
再压栈最左边的子树。当弹出时先弹出左子树，按照这种次序就可以实现前序遍历。 */
//vector<int> preorder(Node* root) {
//	vector<int> ret;
//	stack<Node* > s;
//	s.push(root);
//	while (!s.empty()){
//		root = s.top(); s.pop();
//		if (!root) continue;
//		ret.push_back(root->val);
//		for (int i = root->children.size() - 1; i >= 0; --i){
//			s.push(root->children[i]);
//		}
//	}
//	return ret;
//}

