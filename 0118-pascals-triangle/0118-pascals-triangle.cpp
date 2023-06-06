class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {{1},{1,1}};
        
        if(numRows==1) return {{1}};
        if(numRows==2) return ans;
        
        while(ans.size()!=numRows) {
            int n = ans.size();
            
            // vector<int> temp(n+1,1);
            vector<int> temp(n+1);
            fill(temp.begin(),temp.end(),1);
            
            for(int i=1;i<ans[n-1].size();i++) {
                temp[i] = ans[n-1][i-1] + ans[n-1][i];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};