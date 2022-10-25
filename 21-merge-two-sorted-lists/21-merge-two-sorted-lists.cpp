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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        struct ListNode* p = list1;
        struct ListNode* q = list2;
        struct ListNode* ans = new ListNode();
        struct ListNode* r = ans;
        while(p!=NULL || q!=NULL){
            int x,y;
            if(p!=NULL)
                x = p->val;
            if(q!=NULL)
                y = q->val;
            if(x<=y && p!=NULL && q!=NULL){
                r->next = new ListNode(x);
                p = p->next;
            }
            else if(x>y && p!=NULL && q!=NULL){
                r->next = new ListNode(y);
                q = q->next;
            }
            else if(p!=NULL){
                r->next = new ListNode(x);
                p = p->next;
            }
            else if(q!=NULL){
                r->next = new ListNode(y);
                q = q->next;
            }
            r = r->next;
        }
        return ans->next;
    }
};
// Time: 3ms , Memory: 15MB
