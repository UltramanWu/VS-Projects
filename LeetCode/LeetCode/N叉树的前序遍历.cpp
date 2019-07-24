#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

vector<int> preorder(Node* root);
int main()
{

	system("pause");
	return 0;
}

/* 递归实现 */
void PreSubOrder(Node *root, vector<int> &pre){
	if (root == NULL)
		return;
	pre.push_back(root->val);
	for (int i = 0; i < root->children.size(); i++)
		if (root->children[i])
			PreSubOrder(root->children[i], pre);
}

/* N叉树的前序遍历 */
vector<int> preorder(Node* root) {
	if (root == NULL)
		return{};
	vector<int> Pre;
	PreSubOrder(root, Pre);

	return Pre;
}

/* 非递归实现 */
vector<int> preorder(Node* root){
	if (root == NULL)
		return{};


}