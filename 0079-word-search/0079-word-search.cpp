class Solution {
public:
    bool search(vector<vector<char>>& board,vector<vector<bool>>& visited,int i,int j, int idx , string& word ) {
        if(idx == word.length()-1) return true;
        visited[i][j]=true;
        if(i>0 && !visited[i-1][j] && board[i-1][j]==word[idx+1] && search(board,visited,i-1,j,idx+1,word))     
            return true;
        if(i<board.size()-1 && !visited[i+1][j] && board[i+1][j]==word[idx+1] && search(board,visited,i+1,j,idx+1,word))     
            return true;
        if(j>0 && !visited[i][j-1] && board[i][j-1]==word[idx+1] && search(board,visited,i,j-1,idx+1,word))     
            return true;
        if(j<board[0].size()-1 && !visited[i][j+1] && board[i][j+1]==word[idx+1] && search(board,visited,i,j+1,idx+1,word))     
            return true;
        visited[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(board[i][j]==word[0] && search(board,visited,i, j,0,word )) 
                    return true;
            }
        }
        return false;
    }
};