#include<iostream>
using namespace std;

// Definition for singly-linked list.

struct ListNode {
    int val;
    struct ListNode *next; 
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 
// % MY SOLUTION -> 08-APRIL-2002
class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int cy = 0,data;
        
        struct ListNode* ans = new ListNode(0);
        
        struct ListNode* ptr1 = l1;
        struct ListNode* ptr2 = l2;
        struct ListNode* ptr3 = ans;
        
        while(ptr1!=NULL || ptr2!=NULL){
            int x,y;
           
            if(ptr1==NULL)
                x = 0;
            else 
                x = ptr1->val ; 
            
            if(ptr2==NULL) //-> no need of creating new node, just pass 0 as val
                y = 0;
            else
                y = ptr2->val;
                
            data = x + y + cy ;
            cy = data/10;
            
            ptr3->next = new ListNode(data % 10);
            
            ptr3 = ptr3->next;
            if(ptr1!=NULL)
                ptr1 = ptr1->next;
            if(ptr2!=NULL)
                ptr2 = ptr2->next;
            
        }    
        
        if(cy>0)
            ptr3->next = new ListNode(cy);
            
        return ans->next;
    }
};

void traverse(struct ListNode* head);
struct ListNode* insertNodeFirst(struct ListNode* head, int data);
struct ListNode* createnodeLast(struct ListNode* num3,int data);
 
int main(){ 
    Solution s1;
    struct ListNode* l1; 
    struct ListNode* l2;
    l1 = createnodeLast(l1,3);
    l1 = createnodeLast(l1,4);
    l1 = createnodeLast(l1,2);

    l2 = createnodeLast(l2,4);
    l2 = createnodeLast(l2,6);
    l2 = createnodeLast(l2,5);

    traverse(l1);
    traverse(l2);

    return 0; 
}

void traverse(struct ListNode* head){
    while(head!=NULL){ 
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

struct ListNode* insertNodeFirst(struct ListNode* head, int data){
    struct ListNode* temp = new ListNode(data,head);
    head = temp;
    return head;  
}

struct ListNode* createnodeLast(struct ListNode* num3,int data){
    if(num3!=NULL){
        struct ListNode* temp = num3;
        while(temp->next!=NULL)
            temp = temp->next; 
        struct ListNode* ptr = new ListNode(data);
        temp->next = ptr; 
    }
    else{
        num3 = new ListNode(data);
    }
    return num3; 
}