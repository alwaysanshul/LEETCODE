using vi = vector<int>;
using vb = vector<bool>;
using umii = unordered_map<int,int>;

class Solution {
public:
    int longestCycle(vi& edges) {
        int res = -1;
        int n = edges.size();
        vb visit(n);
        
        for(int i=0;i<n;i++) {
            if(visit[i]==false) {
                umii dist;
                dist[i] = 1;
                dfs(i,edges,dist,visit,res);
            }
        }
        return res;
    }
    void dfs(int node, vi& edges, umii& dist, vb& visit, int& res) {
        visit[node] = true;
        int neighbour = edges[node];
        if(neighbour!=-1 && visit[neighbour]==false) {
            dist[neighbour] = dist[node] + 1;
            dfs(neighbour,edges,dist,visit,res);
        }
        else if(neighbour!=-1 && dist.count(neighbour)) {
            res = max(res,dist[node]-dist[neighbour]+1);
        }
    }
};