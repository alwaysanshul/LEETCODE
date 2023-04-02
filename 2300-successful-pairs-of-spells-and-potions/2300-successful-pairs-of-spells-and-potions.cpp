class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs;
        
        sort(potions.begin(),potions.end()); 
        
        for(int i=0;i<spells.size();i++) {
            long long minPotion = ceil((1.0*success)/spells[i]);
            if(minPotion>potions[potions.size()-1]){
                pairs.push_back(0);
                continue;
            }
            // for(int j=0;j<potions.size();j++) {
            //     if(potions[j]>=minPotion){
            //         pairs.push_back(potions.size() - j) ; 
            //         break;
            //     }
            // }
            
            auto idx = lower_bound(potions.begin(),potions.end(),minPotion) - potions.begin();
            pairs.push_back(potions.size()-idx);
            
        }
        return pairs;        
    }
};