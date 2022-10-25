/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* t3 = ans;
        int cy=0;
        
        while(t1!=NULL || t2!=NULL || cy!=0)
        {
            int val =((t1!=NULL)?t1->val:0) + ((t2!=NULL)?t2->val:0) + cy; 
            cy = 0;
            if(val>9)
            {
                val = val - 10 ;
                cy = 1;
            }
            t3->next = new ListNode(val);
            
            if(t1!=NULL) t1 = t1->next;
            if(t2!=NULL) t2 = t2->next;
            t3 = t3->next;
        }
        
        return ans->next;
    }
};
