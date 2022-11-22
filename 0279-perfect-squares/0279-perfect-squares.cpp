class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        for(int i=0;i<n+1;i++) dp[i] = n;
        dp[0] = 0;
        for(int target=1;target<n+1;target++) {
            for(int s=1;s<target+1;s++) {
                if(target<s*s) 
                    break;
                dp[target] = min(dp[target],1+dp[target-s*s]);
            }
            // cout<<"No. of Perfect Squares to reach "<<target<< " is: "<<dp[target]<<endl;
        }
        return dp[n];
    }
};