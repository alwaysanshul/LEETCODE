class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        return binary(nums,target,l,r);
    }
    int binary(vector<int> nums, int target, int l ,int r) {
        if(l<=r){
            int mid = l + ((r-l)/2); 
            if(nums[mid]==target) 
                return mid;
            else if(nums[mid]>target) 
                return binary(nums,target,l,mid-1);
            else 
                return binary(nums,target,mid+1,r);
        }
        return -1; 
    }
};