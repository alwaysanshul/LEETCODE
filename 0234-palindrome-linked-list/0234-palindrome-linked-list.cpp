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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode *temp = head;
        while(temp!=NULL) {
            st.push(temp->val);
            temp = temp->next;
        }
        stack<int> st2;
        int size = st.size();
        for(int i=0;i<size/2;i++) {
            st2.push(st.top());
            st.pop();
        }
        if(size%2!=0) {
            if(st.size()>st2.size()) {
                st.pop();
            }
            else {
                st2.pop();
            }
        }
        for(int i=0;i<size/2;i++) {
            if(st.top() != st2.top()) 
                return false;
            st.pop();
            st2.pop();
        }
        return true;
    }
};