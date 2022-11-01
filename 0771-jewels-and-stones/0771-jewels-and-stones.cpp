class Solution {
public:
    // cout<< str.find("programming");  
    // cout<< str.find("fruit",12);   search start form 12
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        for(int i=0;i<stones.length();i++) {
            size_t found = jewels.find(stones.at(i));
            if(found!=string::npos)
                count++;
        }
        cout<<" the highest possible value for an element of type size_t: string::npos="<<string::npos;
        return count;
    }
};