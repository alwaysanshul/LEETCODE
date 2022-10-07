// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int lbad = -1;
    
        while(low<=high)
        {
            // int mid = (low+high)/2; 
            int mid = low + ((high - low)/2 );
            if(isBadVersion(mid))
            {
                high = mid-1;
                lbad = mid;
            }
            else 
            {
                low = mid+1;
            }
        }
        
        return lbad;
    }
};