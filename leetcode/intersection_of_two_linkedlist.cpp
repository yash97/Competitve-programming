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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
                
        ListNode *cur1=headA,*cur2=headB;
        while(cur1!=cur2)
        {
            cur1=cur1?cur1->next:headB;
            cur2=cur2?cur2->next:headA;
        }
        if(cur1)
        {
            cout<<" Reference of the node with value = "<<cur1->val;
            return cur1;
        }
        else
        {
            return NULL;
        }
        
    }
};