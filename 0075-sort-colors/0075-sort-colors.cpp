class Solution {
public:
    void sortColors(vector<int>& nums) {    // n,3 singlepass-dutchflag algorithm
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high) {
            if(nums[mid]==0) {
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1) {
                mid++;
            }
            else if(nums[mid]==2) {                
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
    void sortColors_other(vector<int>& nums) { //  n,3
        int ball[]={0,0,0};
        for(int i=0;i<nums.size();i++) {
            ball[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++) {
            if(ball[0]>0){
                nums[i]=0;
                ball[0]--;
            }
            else if(ball[1]>0){
                nums[i]=1;
                ball[1]--;
            }
            else {
                nums[i]=2;
                ball[2]--;
            }
        }
    }
};