class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        map<int,vector<int>> mp;
        for(int i=0;i<groupSizes.size();i++) {
            mp[groupSizes[i]].push_back(i);
        }
        for(auto i=mp.begin();i!=mp.end();i++) {
            int size = i->first,c=0;
            vector<int> temp;
            for(auto it=i->second.begin();it!=i->second.end();it++) {
                if(c==size){
                    ans.push_back(temp);
                    temp.clear();
                    c=0;
                }
                temp.push_back(*it);
                c++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};