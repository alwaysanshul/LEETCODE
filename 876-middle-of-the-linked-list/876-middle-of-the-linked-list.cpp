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
    ListNode* middleNode(ListNode* head) {
        int i=0;
        int target=-1;
        ListNode* ptr = head;
        while(ptr!=NULL)
        {
            i++;
            ptr = ptr->next;
        }
        target = i/2;
        ptr = head;
        i=0;
        while(ptr!=NULL)
        {
            if(i==target)
            {
                return ptr;
            }
            i++;
            ptr = ptr->next;
        }
        return head;
    }
};