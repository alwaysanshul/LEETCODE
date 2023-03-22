class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        vector<vector<pair<int, int>>> g(n+1);

        for(auto edge: roads) {
          g[edge[0]].push_back({edge[1],edge[2]});
          g[edge[1]].push_back({edge[0],edge[2]});
        }
        
        vector<bool> visited(n+1,false);
        queue<int> q;
        q.push(1); visited[1] = true;

        while(q.empty() != true) {
          auto node = q.front(); q.pop();

          for(auto& [v,dist]:g[node]) {
            ans = min(ans,dist);
            if(visited[v]==false) {
              visited[v] = true;
              q.push(v);
            }
          }
          
        }
        return ans;
    }
};
