using vi = vector<int>;
using vvpii = vector<vector<pair<int,int>>>;

class Solution {
public:
    int flips=0;
    int minReorder(int n, vector<vector<int>>& connections) {
        vvpii adj(n);
        for(auto& connection : connections) {
            adj[connection[0]].push_back({connection[1],1});
            adj[connection[1]].push_back({connection[0],0});

        }
        dfs (0,-1,adj);
        return flips;
    }
    void dfs (int node, int parent, vvpii& adj) {
        for(auto& [child,sign] : adj[node]) {
            if(child!=parent) {
                flips += sign;
                dfs(child, node, adj);
            }
        }
    }
};
