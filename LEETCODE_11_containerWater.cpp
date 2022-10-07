#include<iostream>
using namespace std;

int maxVolume(int arr[], int n, int maxVol){
    for(int i=0;i<n;i++){   
        for(int j=i+1;j<n;j++){  
            int Wall = min(arr[i],arr[j]);
            int containerBase = j-i; 
            int volume = Wall*containerBase; 
            if(volume>maxVol)
                maxVol = volume;
        } 
    }
    return maxVol; 
}
int main(){ 
    int n = 9;
    int arr[n] = {1,8,6,2,5,4,8,3,7};
    int maxVol = 0; 
    cout<<maxVolume(arr,n,maxVol)<<endl;  
    int i=0;
    int j=n-1;
    while(i<j){
        int volume = (j-i)*min(arr[i],arr[j]);
        if(volume>maxVol)
            maxVol = volume;
        (i<j)?i++:j--;  
    } 
    cout<<maxVol<<endl; 
    return 0;
}
