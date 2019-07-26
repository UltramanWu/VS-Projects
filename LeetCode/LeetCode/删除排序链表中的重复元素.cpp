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

int main()
{



	system("pause");
	return 0;
}

/* 使用双指针实现 */
ListNode* deleteDuplicates(ListNode* head) {
	if (!head || !(head->next))
		return head;
	ListNode* Pre = head;
	ListNode* Last = Pre->next;
	ListNode* Tmp;
	while (Last){
		if (Pre->val == Last->val){
			Pre->next = Last->next;
			delete(Last);
			Last = Pre->next;
		}
		else{
			Pre = Pre->next;
			Last = Last->next;
		}
	}
	return head;
}


/* 使用递归实现 */
ListNode* deleteDuplicates(ListNode* head) {
	if (!head || !head->next)
		return head;
	head->next = deleteDuplicates(head->next);
	if (head->val == head->next->val) head = head->next;
	return head;
}
