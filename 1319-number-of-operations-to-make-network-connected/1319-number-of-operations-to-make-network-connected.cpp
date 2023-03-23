class Solution {
public:
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        vector<vector<int>> adj(n);
        int connectedComponents = 0;
        vector<bool> visit(n);
        
        for(auto& connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        
        for(int i=0;i<n;i++) {
            if(visit[i]==false) {
                connectedComponents += 1 ;
                dfs(i, adj, visit);
            }
        }
        return connectedComponents-1;
    }
    
    void dfs (int node, vector<vector<int>>& adj, vector<bool>& visit) {
        visit[node] = true;
        for(int i=0;i<adj[node].size();i++) {
            if(visit[adj[node][i]]==false) { 
                dfs(adj[node][i], adj, visit);
            }
        }
    }
};