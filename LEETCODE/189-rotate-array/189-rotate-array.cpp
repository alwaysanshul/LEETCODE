#include<bits/stdc++.h> 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n)
            k = k%n;
        vector<int> ans(n,0); 
        int index = n-k;
        int j=0;
        for(int i=index;i<n;i++)
            ans[j++] = nums[i];
        for(int i=0;i<index;i++)
            ans[j++] = nums[i];
        ans.swap(nums);
        return;
    }
    
    // Time Limit Exceeded - Recursive Method !!
    void rotate_TLE(vector<int>& nums, int& k) {
        int n = nums.size()-1; 
        if(k == 0)
            return;
        if(k>n)
        {
            k = k%n;
        }
        int temp = nums[n];
        int i = n;
        while(i>0)
        {
            nums[i] = nums[i-1];
            i--;
        }
        nums[0] = temp;
        
        k = k-1;
        rotate_TLE(nums,k);
    }
};