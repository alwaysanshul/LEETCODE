class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int i = 0;
        int j = nums.size()-1;
        while(i<=j)
        {
            if(nums[i]*nums[i] > nums[j]*nums[j])
            {
                ans.insert(ans.begin(),nums[i]*nums[i]);
                i++;
            }
            else
            {
                ans.insert(ans.begin(),nums[j]*nums[j]);
                j--;
            }
        }
        return ans;
    }
};