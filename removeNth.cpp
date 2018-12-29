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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
 		 ListNode *dump=new ListNode;        
		 dump->next=head;	
		 ListNode *pre=dump, *last=dump;
		 int i=0;
		 while(i<n+1)
		 {
			 last=last->next;
			 i++;
		 }
		 while(last != nullptr)
		 {
			 pre=pre->next;
			 last=last->next;
		 }
		 pre->next = pre->next->next;
		 ListNode *ans=dump->next;
		 delete dump;
		 return ans;
    }
};
