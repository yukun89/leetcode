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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//1.not equal length.  
		//1.suc
		int extra=0;
		ListNode *result=l1;
		ListNode *tail_l1 = nullptr;
		while (l1 != nullptr && l2 != nullptr)
		{
			tail_l1 = l1;
			int v1=l1->value;
			int v2=l2->value;
			l1->val = (v1+v2+extra)%10;
			extra=(v1+v2+extra)/10;	
			l1=l1->next;
			l2=l2->next;
		}
		ListNode *rlist=l1;	
		if (l2!=nullptr)
		{
			tail_l1->next=l2;
			rlist = l2;
		}
			while (rlist != nullptr){
				tail_l1 = rlist; 
				int v1=rlist->value;
				rlist->value = (v1+extra)%10;
				extra = (v1+extra)/10;
				rlist=rlist->next;
				if(extra == 0)
					break;
			}
			if (extra != 0)
			{
				auto new_node = new ListNode(extra);
				tail_l1->next = new_node;
			}
		return result;
    }
};
