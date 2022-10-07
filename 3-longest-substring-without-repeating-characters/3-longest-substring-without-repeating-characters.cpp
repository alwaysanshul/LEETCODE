class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        string t = "";
        
        if(n==0) return 0;
        if(n==1) return 1;
        
        for(int i=0;i<n;i++)
        {
            char c = s[i];
            if(contains(t,c))
            {
                int pos = t.find(c);
                t = t.substr(pos+1);
            }
            t = t + c;
            maxLen = (maxLen<t.length()) ? t.length() : maxLen;
        }
        
        return maxLen;
    }
    bool contains(string t, char c)
    {
        for(int i=0;i<t.length();i++)
        {
            if(t[i]==c)
                return true;
        }
        return false;
    }
};