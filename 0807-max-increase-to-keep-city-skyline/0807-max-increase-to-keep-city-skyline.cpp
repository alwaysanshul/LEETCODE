class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid.size();j++) {
                int row_highest = 0, col_highest = 0;
                for(int k=0;k<grid.size();k++)
                    row_highest = max(row_highest,grid[i][k]);
                for(int k=0;k<grid.size();k++)
                    col_highest = max(col_highest,grid[k][j]);
                ans += min(row_highest, col_highest) - grid[i][j];
            }
        }
        return ans;
    }
};