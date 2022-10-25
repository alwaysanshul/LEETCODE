#include<iostream>
#include<cstring> 
using namespace std;
int main(){
    string s = "bcefh";
    string t = "abcdefgh"; 
    int i=0, j=0; 
    while(i<s.length() && j<t.length()){ 
        if(s[i]==t[j]){ 
            i++;  
        }
        j++; 
    } 
    if(i==s.length()) 
        cout<<"Subsequence";
    else     
        cout<<"Not Subsequence"; 
    return 0;
}






// #include<iostream>
// using namespace std;
 
// class Solution { 
// public:
//     // string s = 'Anshul';
//     // string t = 'Asl'; 
//     bool isSubsequence(string s, string t) { 
//         int i,j; 
//         for(i=0,j=0;i<t.length()&&j<s.length();i++){
//             if(t[i]==s[j]){
//                 j++;
//             } 
//         }
//         cout<<endl<<j<<endl;
//         if(j==s.length()){   
//             return true;  
//         }
//         else{ 
//             return false;
//         }
//     }
// }; 

// int main(){
//     string s = "Asl"; 
//     string t = "Anshul"; 
//     Solution c;
//     cout<<c.isSubsequence(s,t);
//     return 0;
// } 