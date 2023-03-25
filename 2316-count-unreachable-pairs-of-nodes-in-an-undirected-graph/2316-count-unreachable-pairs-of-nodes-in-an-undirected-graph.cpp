using vvi = vector<vector<int>>;
using vi = vector<int> ;
using ll = long long ;

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long unreach_pairs = 0;
        
        vvi adj(n);
        for(vi& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visit(n);
        int connectComponents = 0;
        ll sizeOfcomponent=0;
        ll remainingNode=n;
        
        for(int i=0;i<adj.size();i++) {
            if(visit[i]==false){
                sizeOfcomponent = dfs(i,adj,visit);
                unreach_pairs += sizeOfcomponent * (remainingNode - sizeOfcomponent);
                remainingNode -= sizeOfcomponent;
            }
        }
        return unreach_pairs;
    }
    int dfs(int node, vvi& adj, vector<bool>& visit) {
        int count = 1;
        visit[node] = true;
        for(int neighbour : adj[node]) {
            if(visit[neighbour]==false) {
                count += dfs(neighbour,adj,visit); 
            }
        }
        return count;       
    }
};