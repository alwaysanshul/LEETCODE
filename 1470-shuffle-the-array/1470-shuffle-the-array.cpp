class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        bool flag = true;
        int j = 0;
        int k = j+n;
        while(k!=(n*2)) {
            if(flag) 
                ans.push_back(nums[j++]);
            else 
                ans.push_back(nums[k++]);
            flag = !flag;
        }
        return ans;
    }
};