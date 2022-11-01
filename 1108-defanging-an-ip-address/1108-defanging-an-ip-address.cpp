class Solution {
public:
    // No Extra Memory
    string defangIPaddr(string address) {
        int i=0;
        while(i<address.length()) {
            if(address.at(i)=='.') {
                address.replace(i,1,"[.]");
                i=i+3;
            }
            else
                i++;
        }
        return address;
    }
    string TLE_defangIPaddr(string address) {
        string ans = "";
        for(int i=0;i<address.length();i++) {
            if(address.at(i)=='.') 
                ans += "[.]";
            else
                ans += address.at(i);
        }
        return ans;
    }
};