class Solution {
    int memo[366];
    unordered_set<int> dayset;
    vector<int> costs; 
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->costs = costs;
        for(int i=1;i<366;i++) memo[i]=-1;
        for(int i=0;i<days.size();i++) {
            dayset.insert(days[i]);
        } 
        return dp(1);
    }
    int dp(int i) {
        if(i>365) return 0; 
        if(memo[i]!=-1) return memo[i];
        int ans;
        if(dayset.find(i)!=dayset.end()) {
            ans = min(dp(i+1)+costs[0],dp(i+7)+costs[1]);
            ans = min(ans,dp(i+30)+costs[2]); 
        }
        else {
            ans = dp(i+1); 
        }
        memo[i] = ans;
        return ans;
    }
};
