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
	//c1:null list, c2.normal case 1, 2, 3, 4. c3.1, 2, 3
    ListNode* swapPairs(ListNode* head) {
       ListNode dump_node; 
	   ListNode *dump=&dump_node, pre= dump;
	   dump->next = head;
	   ListNode *one = pre->next;
	   while( one!=nullptr && one->next =nullptr){
		   ListNode *two =one->next;
		   ListNode *post=two->next;
		   pre->next = two;
		   two->next = one;
		   one->next = post;
		   pre = one;
		   one = pre->next;
	   }
		return dump->next;
    }
};
