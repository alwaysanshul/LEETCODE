class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int greatest = *max_element(candies.begin(),candies.end());
        vector<bool> ans(candies.size(),false);
        for(int i=0;i<candies.size();i++) {
            if(extraCandies+candies[i]>=greatest)
                ans[i] = true;
        }
        return ans;
    }
};