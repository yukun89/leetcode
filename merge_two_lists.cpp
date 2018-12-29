/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
 		ListNode *dhead= new ListNode(0), *current=dhead;      
		while(l1 != nullptr && l2 != nullptr){
			new_node = new ListNode(0);
			new_node ->val = std::max((long long)(l1 != nullptr :l1->val, INT_MIN), 
									(long long)(l2 != nullptr :l2->val, INT_MIN));
			current->next = new_node;
		}
		ListNode *head = dhead->next;
		delete dhead;
		return head;
    }
};
