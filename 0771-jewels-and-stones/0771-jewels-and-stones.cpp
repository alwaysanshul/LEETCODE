class Solution {
public:
    // cout<< str.find("programming");  
    // cout<< str.find("fruit",12);   search start form 12
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        for(int i=0;i<stones.length();i++) {
            if(jewels.find(stones.at(i))!=-1)
                count++;
        }
        return count;
    }
};