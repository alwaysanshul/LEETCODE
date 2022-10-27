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
    int getDecimalValue(ListNode* head) {
        if(head->next==nullptr)
            return head->val;
        vector<bool> b(30,false);
        int n = 0;
        ListNode *temp = head;
        while(temp!=nullptr) {
            b[n] = (temp->val==1)?true:false;
            n++;
            temp = temp->next;
        }
        int sum=0;
        for(int i=0;i<n;i++) {
            if(b[i]==1) {
                sum = sum + pow(2,(n-1-i));
            }
        }
        return sum;
    }
};