class Solution {
public:
    int searchInsert(vector<int>& a, int key) {
        int low = 0;
        int high = a.size()-1;
        int idx = 0;
        while(low<=high)
        {
            int mid = low+((high-low)/2);
            if(a[mid]==key)
                return mid;
            else if(a[mid]<key){
                low = mid+1; 
                idx = mid+1;
            }
            else{
                high = mid-1;
                idx = mid;
            }
        }
        return idx; 
    }
};