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
    bool hasCycle(ListNode *head) {
        if(head!=NULL){
            ListNode* slow = head->next;
            ListNode* fast = head;
            if(fast->next!=NULL)
                fast = head->next->next;
            else 
                return false;
            while(fast!=NULL)
            {
                if(slow==fast)
                    return true;
                if(fast->next!=NULL)
                    fast = fast->next->next;
                else 
                    return false;
                slow = slow->next;

            }
        }
        return false; 
    }
}; 
