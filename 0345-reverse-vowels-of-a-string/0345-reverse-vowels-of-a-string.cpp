class Solution {
public:
    bool vowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' 
          || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        vector<char> vow;
        for(char ch: s) {
            if(vowel(ch))
                vow.insert(vow.end(),ch);
        }
        for(int i=0;i<s.length();i++) {
            if(vowel(s.at(i))) {
                s.at(i) = vow.back();
                vow.pop_back(); 
            }
        }
        return s;
    }
};