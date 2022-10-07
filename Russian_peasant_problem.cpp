#include<iostream>
using namespace std;
int main(){
    int x=6, y=5, result=0;
    while(y!=0)
    { 
        if(y%2!=0)
        {
            result+=x;
        }
        x<<1;
        y>>1;
    }
    cout<<result<<endl; 
}