class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int sum = 0,ans = INT_MAX;
        int left = 0;
        
        for(int i=0;i<len;i++)
        {
            sum+=nums[i];
            if(sum>=target)
            {
                while(sum>=target)
                {
                    sum -= nums[left];
                    left++;
                }
                
                left--;
                sum+=nums[left];       
                
                ans = min(ans, i-left+1);
            }
        }
        
        if(ans == INT_MAX)
            return 0;
        
        return ans;
       
    }
};
