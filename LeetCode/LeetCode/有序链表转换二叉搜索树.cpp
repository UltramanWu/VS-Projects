#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main()
{

	system("pause");
	return 0;
}

//TreeNode* CreateBinTree(vector<int>vec,int left,int right){
//	if (left > right)
//		return NULL;
//	int middle = (left + right)/2;
//	TreeNode* Start = new TreeNode(vec[middle]);
//	Start->left = CreateBinTree(vec, left, middle - 1);
//	Start->right = CreateBinTree(vec, middle + 1, right);
//
//	return Start;
//}
//
//TreeNode* sortedListToBST(ListNode* head) {
//	if (!head)
//		return NULL;
//	vector<int> vec;
//	
//	while (head){
//		vec.push_back(head->val);
//		head = head->next;
//	}
//	return CreateBinTree(vec, 0, vec.size() - 1);
//}


TreeNode* sortedListToBST(ListNode* head) {
	if (!head)
		return NULL;
	else if (!head->next)
		return new TreeNode(head->val);
	ListNode* pre = head;
	ListNode* slow = pre->next;
	ListNode* fast = slow->next;
	/* Ѱ�������е� */
	while (fast && fast->next){
		pre = slow;  /* ���� */
		slow = slow->next;  /* ��ָ�� */
		fast = fast->next->next;  /* ��ָ�� */
	}
	pre->next = NULL;  /* ���е���ߵ�����ֿ���Ϊ��ݹ�������ֹ���� */
	TreeNode* node = new TreeNode(slow->val);
	node->left = sortedListToBST(head);
	node->right = sortedListToBST(slow->next);
	return  node;
}
