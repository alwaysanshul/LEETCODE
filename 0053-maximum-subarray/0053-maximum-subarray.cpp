class Solution {
public:
    int maxSubArray(vector<int>& nums) { // TC,SC: nlogn,nlogn
        int low = 0, high=nums.size()-1;
        return maxSubArray_divide_conquer(nums, low, high);
    }
    int maxSubArray_n(vector<int>& nums) { // TC,SC: O(n),O(1)
        int max_sum=INT_MIN,current_sum=0;
        for(int i=0;i<nums.size();i++) {
            current_sum+=nums[i];
            if(current_sum>max_sum) {
                max_sum=current_sum;
                cout<<max_sum<<endl;
            }
            if(current_sum<0) {
                current_sum=0;
                cout<<max_sum<<endl;
            }
        }
        return max_sum;
    }
    int maxSubArray_divide_conquer(vector<int>& nums, int low, int high) {
        if(low == high){
            return nums[low];
        }        
        int mid = (low+high)>>1;
        int left_max=INT_MIN,right_max=INT_MIN;
        int temp=0;
        for(int i=mid;i>=low;i--) {
            temp+=nums[i];
            left_max=max(left_max,temp);
        }
        temp=0;
        for(int i=mid+1;i<=high;i++) {
            temp+=nums[i];
            right_max=max(right_max,temp);            
        }
        int tot_sub_max=left_max+right_max;
        int max_left=maxSubArray_divide_conquer(nums,low,mid);
        int max_right=maxSubArray_divide_conquer(nums,mid+1,high);
        return max(tot_sub_max,max(max_left,max_right));
    }
};