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
	/* 寻找链表中点 */
	while (fast && fast->next){
		pre = slow;  /* 备份 */
		slow = slow->next;  /* 慢指针 */
		fast = fast->next->next;  /* 快指针 */
	}
	pre->next = NULL;  /* 将中点左边的链表分开，为左递归制造终止条件 */
	TreeNode* node = new TreeNode(slow->val);
	node->left = sortedListToBST(head);
	node->right = sortedListToBST(slow->next);
	return  node;
}
