class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans=0;
        for(int i=0;i<sentences.size();i++) {
            int words=0;
            if(sentences[i].size()!=0) words++;
            for(int j=0;j<sentences[i].size();j++) {
                if(sentences[i].at(j)==' ')
                    words++;
            }
            ans = max(ans,words);
        }
        return ans;
    }
};