class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for(int i=0;i<operations.size();i++) {
            for(int j=0;j<operations[i].length();j++) {
                if(operations[i].at(j)=='+') {
                    X++;
                    break;
                }
                else if(operations[i].at(j)=='-') {
                    X--;
                    break;
                }
            }
        }
        return X;
    }
};