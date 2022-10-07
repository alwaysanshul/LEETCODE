#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> l1 {1,33,56,78,93}; // list l1,l2 must be sorted in-order to merge them and get a sorted merged list
    list<int> l2 {45,55,65,76,88};
    l1.merge(l2);
    // l2.merge(l1);
    cout<<endl<<"l1: ";
    auto it1 = l1.begin();
    while(it1!= l1.end()){
        cout<<*it1<<" ";
        it1++;
    }
    cout<<endl<<"l2: ";
    auto it2 = l2.begin();
    while(it2!= l2.end()){
        cout<<*it2<<" ";
        it2++;
    }
    return 0;
}