#define mod 1000000007
class Solution {
public:
    int ways(vector<string>& p, int k) {
        int rows = p.size();
        int cols = p[0].size();
        vector fruit(rows + 1, vector<int>(cols + 1));
        vector dp(k, vector(rows, vector<int>(cols)));
        for (int r = rows - 1; r >= 0; r--) {
            for (int c = cols - 1; c >= 0; c--) {
                fruit[r][c] = (p[r][c] == 'A') + fruit[r + 1][c] + fruit[r][c + 1] - fruit[r + 1][c + 1];
                if(fruit[r][c] > 0)
                    dp[0][r][c] = true;
                else 
                    dp[0][r][c] = false;
            }
        }
        for (int left = 1; left < k; left++) {
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < cols; c++) {
                    for (int nextrow = r + 1; nextrow < rows; nextrow++) {
                        if (fruit[r][c] - fruit[nextrow][c] > 0) 
                            (dp[left][r][c] += dp[left - 1][nextrow][c]) %= mod;
                    }
                    for (int nextcol = c + 1; nextcol < cols; nextcol++) {
                        if (fruit[r][c] - fruit[r][nextcol] > 0) 
                            (dp[left][r][c] += dp[left - 1][r][nextcol]) %= mod; 
                    }
                }
            }
        }
        return dp[k - 1][0][0];
    }
};