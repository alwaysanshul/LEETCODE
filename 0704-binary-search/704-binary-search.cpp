class Solution {
public:
    int search(vector<int>& a, int key) {
        int low = 0;
        int high = a.size()-1;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(a[mid]==key)
            {
                return mid;
            }
            else if(a[mid]<key)
            {
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};