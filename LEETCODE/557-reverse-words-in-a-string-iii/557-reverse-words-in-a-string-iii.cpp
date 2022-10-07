class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        int b = 0;
        int i = b+1;
        while(i<=s.size())
        {
            if(i==s.size()||s[i]==' ')
            {
                arr.push_back(s.substr(b,i-b));
                reverse(arr.back().begin(), arr.back().end());
                b = i + 1;
                i = b + 1;
            }
            else{
                i = i + 1;
            }
        }
        if(arr.size() == 0)
            return "";

        string res = arr[0];
        for(int i = 1;  i < arr.size() ; i ++)
            res += " " + arr[i];

        return res;
    }
};