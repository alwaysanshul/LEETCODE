class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output_arr;
        backtrack(output_arr, "", 0, 0, n);
        return output_arr;
    }
    void backtrack(vector<string>& output_arr, string current_string, int open, int close, int max) {
        
        if(open==max && close==max) {
            output_arr.push_back(current_string);
            return;
        }
        
        if(open < max)
            backtrack(output_arr, current_string + "(", open+1, close, max);
        
        if(close < open) 
            backtrack(output_arr, current_string + ")", open, close+1, max);
        
    }
};