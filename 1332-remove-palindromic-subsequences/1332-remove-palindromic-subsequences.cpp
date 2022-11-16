class Solution {
public:
    int removePalindromeSub(string s) {
        string s_ = s;
        reverse(s_.begin(), s_.end());
        if(s_ == s) return 1;
        return 2;
    }
};