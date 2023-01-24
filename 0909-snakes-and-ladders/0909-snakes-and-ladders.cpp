class Solution {
public:
    vector<int> intToPos(int square,vector<vector<int>>& board) {
        int length = board.size();
        int r = (square-1) / length;
        int c = (square-1) % length;
        if(r%2!=0) 
            c = length - 1 - c;
        vector<int> ans;
        return {r,c};
    }
    int _snakesAndLadders(vector<vector<int>>& board) {
        int length = board.size();
        reverse(board.begin(),board.end());
        deque<vector<int>> q;
        q.push_back({1,0});
        set<int> visit;
    
        while(!q.empty()) {
            vector<int> temp = q.front();
            q.pop_front();
            int square = temp[0];
            int moves = temp[1];
            
            for(int i=1;i<7;i++) {
                int nextSquare = square + i;
                vector<int> t = intToPos(nextSquare,board);
                int r = t[0];
                int c = t[1];
                
                if(board[r][c]!=-1)
                    nextSquare = board[r][c];
                if(nextSquare == length*length)
                    return moves+1;
                for (auto it=visit.begin() ;it!=visit.end();it++) {
                    if(nextSquare!=*it){
                        visit.insert(nextSquare);
                        q.push_back({nextSquare,moves+1});
                    }
                }
            }
        }
        return -1;
    }
    
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<pair<int, int>> cells(n * n + 1);
        int label = 1;
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[label++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> dist(n * n + 1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                auto [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }
        return dist[n * n];
    }
};