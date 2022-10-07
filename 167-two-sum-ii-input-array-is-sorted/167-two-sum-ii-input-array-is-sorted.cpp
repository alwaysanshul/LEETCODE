class Solution {
public:
    vector<int> twoSum(vector<int>& a, int key) {
        int n = a.size();
        vector<int> ans;
        int i = 0;
        int j = n-1;
        while(i<j)
        {
            int sum = a[i] + a[j] ;
            if(sum==key)
            { 
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            if(sum>key)
                j--;
            else 
                i++;
        }
        return ans;
    }
    
    
    //TLE 
    vector<int> twoSum_TLE(vector<int>& a, int key) {
        int n = a.size();
        vector<int> ans;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i]+a[j] == key)
                {
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                    return ans;
                }
            }
        }
        return ans;
    }
};