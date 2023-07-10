class Solution {
public:
    int maxSubArray(vector<int>& nums) {
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
};