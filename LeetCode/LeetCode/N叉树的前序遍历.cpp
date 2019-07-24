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

///* �ݹ�ʵ�� */
//void PreSubOrder(Node *root, vector<int> &pre){
//	if (root == NULL)
//		return;
//	pre.push_back(root->val);
//	for (int i = 0; i < root->children.size(); i++)
//		if (root->children[i])
//			PreSubOrder(root->children[i], pre);
//}
//
///* N������ǰ����� */
//vector<int> preorder(Node* root) {
//	if (root == NULL)
//		return{};
//	vector<int> Pre;
//	PreSubOrder(root, Pre);
//
//	return Pre;
//}

/* �ǵݹ�ʵ�� */
/* ԭ���������������ķ���˳���ա��Ƚ��������ԭ���ȶ������ѹջ����ѹջ���ұߵ�������
��ѹջ����ߵ�������������ʱ�ȵ������������������ִ���Ϳ���ʵ��ǰ������� */
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

