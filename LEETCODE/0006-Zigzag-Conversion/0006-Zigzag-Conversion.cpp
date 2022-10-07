class Solution {
public:
    string convert(string s, int numRows) {
        int k=0;
        int col;
        int pos=numRows-1;
        int len = s.length();
        char a[numRows][len];
        string res;
        
        if(numRows==1 || len==1)
            return s;
        
        for(int i=0;i<len;i++)
        {
            if(k>=len)
            {
                col = i;
                break;
            }
            if(pos==0)
                pos = numRows-1;
            if(pos==numRows-1)
            {
                for(int j=0;j<numRows;j++)
                {
                    if(k<len)
                        a[j][i] = s[k++];
                    else
                        a[j][i] = '$';
                }
            }
            else
            {
                for(int j=0;j<numRows;j++)
                {
                    if( pos==j && k<len)
                        a[j][i] = s[k++];
                    else
                        a[j][i] = '$';
                }
            }
            pos--;
        }
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(a[i][j]!='$')
                    res = res + a[i][j];
            }
        }
        return res;
    }
};
// Time: 91ms , Memory: 96MB
