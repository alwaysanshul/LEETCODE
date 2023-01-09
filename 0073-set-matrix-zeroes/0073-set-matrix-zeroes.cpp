class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> pairs;
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                if(matrix[i][j]==0) {
                    pairs.push_back(make_pair(i,j));
                }
            }
        }
        for(int i=0;i<pairs.size();i++) {
            makeZero(pairs[i].first,pairs[i].second,matrix);
        }
    }
    void makeZero(int i, int j, vector<vector<int>>& matrix) {
        for(int y=0;y<matrix[0].size();y++) 
            matrix[i][y]=0;
        for(int x=0;x<matrix.size();x++) 
            matrix[x][j]=0;
    }
};