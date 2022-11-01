class Solution {
public:
    string interpret(string command) {
        string ans = "";
        int i=0;
        while(i<command.size()) {
            if(command.substr(i,1)=="G"){
                ans += "G";
                i=i+1;
            }
            else if(command.substr(i,2)=="()"){
                ans += "o";
                i = i+2;
            }
            else if(command.substr(i,4)=="(al)"){
                ans += "al";
                i = i+4;
            }
            else 
                i++;
        }
        return ans;
    }
};