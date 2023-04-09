class Solution {
public:
    int largestPathValue(string c, vector<vector<int>>& e) {
        int nn = c.length();
        vector<vector<int>> adj(nn);
        for (auto& ed : e) 
            adj[ed[0]].push_back(ed[1]);
        vector<vector<int>> cc(nn, vector<int>(26));
        vector<bool> v(nn), icp(nn);
        int mpv = 0;
        for (int i = 0; i < nn; i++) 
            mpv = max(mpv, dfs(i, c, adj, cc, v, icp));
        if (mpv == INT_MAX) return -1;
        return mpv;
    }    
    int dfs(int n, string& c, vector<vector<int>>& adj, vector<vector<int>>& cc, vector<bool>& v, vector<bool>& icp) {
        if (icp[n]) 
            return INT_MAX;
        if (v[n]) 
            return cc[n][c[n]-'a'];
        v[n] = true;
        icp[n] = true;
        for (auto& nbr : adj[n]) {
            if (dfs(nbr, c, adj, cc, v, icp) == INT_MAX) 
                return INT_MAX;
            for (int i = 0; i < 26; i++) 
                cc[n][i] = max(cc[n][i], cc[nbr][i]);
        }
        cc[n][c[n]-'a']++;
        icp[n] = false;
        return cc[n][c[n]-'a'];
    }
};