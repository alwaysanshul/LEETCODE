class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n));

        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1 && visit[i][0]==false) 
                dfs(i, 0, m, n, grid, visit);
        
            if (grid[i][n - 1] == 1 && visit[i][n - 1]==false) 
                dfs(i, n - 1, m, n, grid, visit);
        }

        for (int i = 0; i < n; ++i) {
            if (grid[0][i] == 1 && visit[0][i]==false) 
                dfs(0, i, m, n, grid, visit);
            
            if (grid[m - 1][i] == 1 && visit[m - 1][i]==false) 
                dfs(m - 1, i, m, n, grid, visit);
        }

        int c = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visit[i][j]==false) 
                    c++;
            }
        }
        return c;
    }
    void dfs(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || vis[x][y]==true) return;
        
        vis[x][y] = true;
        vector<int> X{0, 1, 0, -1};
        vector<int> Y{-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) 
            dfs(x + X[i], y + Y[i], m, n, grid, vis);
        return;
    }
};