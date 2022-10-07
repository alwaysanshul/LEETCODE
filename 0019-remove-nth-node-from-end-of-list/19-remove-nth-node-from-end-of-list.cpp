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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode* ptr = head;
        int size=0;
        while(ptr!=NULL){
            ptr=ptr->next;
            size++;
        }
        struct ListNode* prevptr = head;
        ptr = head->next; 
        int i=1;
        if(n==size && size==1){
            delete(prevptr);
            return NULL;
        }
        while(ptr!=NULL){
            if(size==n){ 
                delete(prevptr);
                return ptr;
            }
            else if(size-i==n){ 
                prevptr->next = ptr->next;
                delete(ptr);
                return head;
            }
            prevptr=prevptr->next;
            ptr=ptr->next;
            i++;
        }
        return head;
    }
};
