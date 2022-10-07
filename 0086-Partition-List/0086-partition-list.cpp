#include<bits/stdc++.h>
using namespace std;

typedef struct ListNode
{
    int val;
    struct ListNode* next;
}ln;

ln* add(ln* head, int data)
{
    ln* t = new ln();
    t->val = data;
    t->next = head;
    return t; 
}

void print(ln* head)
{
    ln* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<"\n"; 
}
ln* del(ln*, int); 
ln* partition_list(ln*, int );
int main()
{
    ln* head = new ln();
    head->val = 2;
    head->next = NULL;

    // input: [1,4,3,2,5,2]  x: 3
    // output: [1,2,2,4,3,5] 
    head = add(head,5);
    head = add(head,2);
    head = add(head,3);
    head = add(head,4);
    head = add(head,1);  
    print(head);      

    int x = 3;
    // head = del(head,<index>);  
    head = partition_list(head,x);  
    print(head); 
    return 0;
}

ln* del(ln* head, int target)
{
    ln* p = head;
    ln* q = head->next; 
    int i=1;
    if(target==0)
    {
        head = q;
        free(p); 
        return head; 
    }
    while(q!=NULL && i<=target) 
    {
        if(i==target)
        {
            p->next = q->next;
            free(q);
            return head;
        }
        p = p->next; 
        q = q->next; 
        i++;
    }
    return head; 
}

ln* partition_list(ln* head, int x)
{
    stack<int> st;
    ln* ptr = head;
    int i=0;
    while(ptr!=NULL)
    {
        if(ptr->val < x)
        {
            st.push(ptr->val);
            head = del(head,i);     
        } 
        ptr = ptr->next; 
        i++; 
    } 
    for(int i=0;i<st.size();i++)
    {
        cout<<st.top()<<" "; 
        st.pop();    
    } 
    cout<<"\n"; 
    return head;    
}