class Solution {
public:
    vector<string> cellsInRange(string s) {
        int i=0;
        char lb = s.at(i), ub = s.at(i+3);
        int lb_r = (int)s.at(i+1), ub_r = (int)s.at(i+4);
        vector<string> str;
        for(char ch=lb;ch<=ub;ch++) {
            for(int i=lb_r;i<=ub_r;i++) {
                str.push_back(ch+to_string(i-48));
            }
        }
        return str;
    }
};