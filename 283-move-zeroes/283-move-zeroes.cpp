class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                count++;
        }
        for(int c=0;c<count;c++)
        {
            int i = 0;
            while(i<n-1-c)
            {
                if(nums[i]==0)
                {
                    swap(nums[i],nums[i+1]);
                }
                i++;
            }
        }
    }
};