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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)  return head;
        
        struct ListNode* p = head;
        struct ListNode* q = head->next;
        
        p->next = q->next;
        q->next = p;
        
        head = q;
        p->next = swapPairs(p->next); //Recursive Call
        return head;
    }
};