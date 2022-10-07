#include<iostream>
#include<vector>

using namespace std;

// -----------------------------------------------------------    
int main(){
    vector <int> vrr1;
    int n = 3,key;
    cout<<"\nWrite vrr1: ";
    for(int j=0;j<n;j++){
        cin>>key;
        vrr1.push_back(key);
    }
    cout<<endl;
    cout<<"\nvrr1: "; 
    for(int j=0;j<n;j++){
        cout<<vrr1[j]<<" ";
    }    
    cout<<endl;
    cout<<"front();"<<vrr1.front()<<endl;
    cout<<"back();"<<vrr1.back()<<endl;
    cout<<"max_size();"<<vrr1.max_size()<<endl;
    cout<<"capacity();"<<vrr1.capacity()<<endl;
    cout<<"adding 2 elements to vrr1..."<<endl;
    vrr1.push_back(23);
    vrr1.push_back(557);
    cout<<"capacity();"<<vrr1.capacity()<<endl;
    cout<<"capacity increases in 2's power: 2,4,8,16,32,64.....2^n."<<endl;
// -----------------------------------------------------------    
    // vector <int> vrr1;
    // vector <int> vrr2;
    // int n = 3,key;
    // cout<<"\nWrite vrr1: ";
    // for(int j=0;j<n;j++){
    //     cin>>key;
    //     vrr1.push_back(key);
    // }
    // cout<<endl;
    // cout<<"\nWrite vrr2: ";
    // for(int j=0;j<n;j++){
    //     cin>>key;
    //     vrr2.push_back(key);
    // }
    // cout<<endl;
    // vrr2.swap(vrr1);
    // cout<<"\nvrr1: "; 
    // for(int j=0;j<n;j++){
    //     cout<<vrr1[j]<<" ";
    // }    
    // cout<<"\nvrr2: "; 
    // for(int j=0;j<n;j++){
    //     cout<<vrr2[j]<<" ";
    // } 
// -----------------------------------------------------------
    // vector <int> vrr1;
    // int n = 3,key;
    // for(int j=0;j<n;j++){
    //     cin>>key;
    //     vrr1.push_back(key);
    // }
    // cout<<endl;
    // for(int j=0;j<n;j++){
    //     cout<<vrr1[j]<<" ";
    // }
// -----------------------------------------------------------
    // int row, column, key;
    // cin>>row>>column;
    // vector <vector<int> > vrr;
    // for(int i=0;i<row;i++){
    //     vector <int> temp;
    //     for(int j=0;j<column;j++){
    //         cin>>key;
    //         temp.push_back(key);
    //     }
    //     vrr.push_back(temp);
    // }
    // cout<<endl;        
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<column;j++){
    //         cout<<vrr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
// -----------------------------------------------------------
    return 0;
}