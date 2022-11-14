class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int len = 0,maxlen=0;
        int l=0;
        for(int i=0;i<s.length();i++) {
            mp[s[i]]++;
            len++;
            while(mp[s[i]]>1) {
                mp[s[l++]]--;
                len--;
            }
            maxlen = max(len,maxlen);
        }
        return maxlen;
    }
};