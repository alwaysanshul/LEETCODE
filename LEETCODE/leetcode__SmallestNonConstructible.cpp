#include<iostream>
#include<vector>
using namespace std; 
bool isSubsetSum(int arr[],int n,int i){
    if(i==0)
        return true;  
    if(n==0)
        return false; 
    if(arr[n-1]>i)
        return isSubsetSum(arr,n-1,i);
    return isSubsetSum(arr,n-1,i) || isSubsetSum(arr,n-1,i-arr[n-1]);
}
int main(){    
    int n=6; // 1,3,6,10,11,15  // 1,1,2,3 // 1,1,1,1  
    int arr[n] = {1,3,6,10,11,15}; 
    for(int i=1;;i++){
        if(!isSubsetSum(arr,n,i)){
            cout<<i<<endl;
            break;
        } 
    }
    return 0;
}