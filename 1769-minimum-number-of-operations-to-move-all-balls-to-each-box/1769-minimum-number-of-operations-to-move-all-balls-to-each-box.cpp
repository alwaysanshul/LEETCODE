class Solution {
public:
    vector<int> minOperations(string boxes) {
        int leftcount=0;
        int leftsum=0;
        int rightcount=0;
        int rightsum=0;
        vector<int> ans;
        for(int i=0;i<boxes.size();i++) {
            if(boxes.at(i)=='1'){
                rightsum += i;
                rightcount++;
            }
        }
        for(int i=0;i<boxes.size();i++) {
            if(boxes.at(i)=='1'){
                rightsum -= i;
                rightcount--;
            }
            int sum = abs(rightsum-(rightcount*i)) + abs(leftsum-(leftcount*i));
            ans.push_back(sum);
            if(boxes.at(i)=='1'){
                leftsum += i;
                leftcount++;
            }
        }
        return ans;
    }
    vector<int> brute_minOperations(string boxes) {
        vector<int> ans;
        for(int i=0;i<boxes.size();i++) {
            int count=0;
            if(boxes.at(i)=='0') {
                for(int j=0;j<boxes.size();j++) {
                    if(boxes.at(j)=='1') 
                        count += abs(i-j);
                }
            }
            else if(boxes.at(i)=='1') {
                for(int j=0;j<boxes.size();j++) {
                    if(i!=j && boxes.at(j)=='1') 
                        count += abs(i-j);
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};