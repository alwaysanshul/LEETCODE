class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0, sum=0, start=0;
        int n = gas.size();
        for(int i=0;i<n;i++)
        {
            sum = sum + gas[i] - cost[i];
            total = total + gas[i] - cost[i];
            if(sum<0){
                sum=0;
                start = i+1;
            }
        }
        if(total<0)
            return -1;
        else
            return start;
    }
};
// Time: 114ms , Memory: 69.4MB
