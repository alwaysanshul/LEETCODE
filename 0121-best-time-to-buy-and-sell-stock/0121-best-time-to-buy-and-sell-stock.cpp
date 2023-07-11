class Solution {
public:
    int maxProfit(vector<int>& prices) { // n,1
        int ans=INT_MIN;
        int n=prices.size();
        int min_value=prices[0];
        for(int i=1;i<n;i++) {
            ans=max(ans,prices[i]-min_value);
            min_value=min(min_value,prices[i]);
        }
        if(ans>0)
            return ans;
        return 0;
    }
    int maxProfit_not_working(vector<int>& prices) {    // not_working n^2,n
        vector<int> prices_sorted=prices;
        sort(prices_sorted.begin(),prices_sorted.end());
        int n = prices.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            vector<int>::iterator it = find(prices.begin(),prices.end(),prices_sorted[i]);
            int idx=0;
            if(it!=prices.end()) {
                idx = it-prices.begin();
            }
            int temp_max = 0;
            for(int j=idx+1;j<prices.size();j++) {
                temp_max=max(temp_max,prices[j]);
            }
            ans=max(ans,temp_max);
        }
        return ans;
    }    
};