class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int ROW = matrix.size();
        int COL = matrix[0].size();
        // Declaring 2-D Vector with its rows and columns
        
        vector<vector<int>> ans(COL, vector<int> (ROW));
        
        for(int i=0;i<COL;i++)
        {
            for(int j=0;j<ROW;j++)
            {
                ans[i][j] = matrix[j][i];
            }
        }
        
        return ans;
    }
};
