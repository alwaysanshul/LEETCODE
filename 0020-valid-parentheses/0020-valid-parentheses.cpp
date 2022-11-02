class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        while(i<s.length()) {
            if(s.at(i)=='(' || s.at(i)=='[' || s.at(i)=='{') {
                st.push(s.at(i));
            }
            else if(s.at(i)==')') {
                if(st.empty())
                    return false;
                else if(st.top()!='(')
                    return false;
                else
                    st.pop();
            }
            else if(s.at(i)==']') {
                if(st.empty())
                    return false;
                else if(st.top()!='[')
                    return false;
                else
                    st.pop();
            }
            else if(s.at(i)=='}') {
                if(st.empty())
                    return false;
                else if(st.top()!='{')
                    return false;
                else
                    st.pop();
            }
            i++;
        }
        if(st.empty())
            return true;
        return false;
    }
};