//#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
//#include <algorithm>
//using namespace std;
//
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
//int main()
//{
//
//	system("pause");
//	return 0;
//}
//
//#if 0
///* N�����ĺ������ */
//vector<int> postorder(Node* root) {
//	if (!root)
//		return{};
//	vector<int> Post;
//	stack<Node*> S;
//	int len,i;
//	S.push(root);
//	while (!S.empty()){ /* ����ջ����Ԫ��ʱ */
//		root = S.top();
//		S.pop();
//		if (!root) continue;
//		Post.insert(Post.begin(), root->val);
//		len = root->children.size();
//		for (i = 0; i <len; i++)
//			S.push(root->children[i]);
//	}
//	return Post;
//}
//#endif
//
//void PostOrd(Node* root, vector<int> &Post){
//	if (!root) return;
//	int len = root->children.size();
//	for (int i = 0; i < len; i++)
//		PostOrd(root->children[i], Post);
//	Post.push_back(root->val);
//}
//
///* �ݹ�ʵ��N�����ĺ��� */
//vector<int> postorder(Node* root){
//	if (!root)
//		return{};
//	vector<int> Post;
//	PostOrd(root, Post);
//	return Post;
//}