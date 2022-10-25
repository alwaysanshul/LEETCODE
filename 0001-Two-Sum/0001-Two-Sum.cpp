class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
            vector<pair<int,int>> newnum(n);
            for(int i=0;i<n;i++) 
            {
                newnum[i].first = nums[i];
                newnum[i].second = i;
            }
            // quickSort(newnum,0,n-1);
            sort(newnum.begin(),newnum.end());
            vector<int> ans;
            int i=0,j=n-1;
            while(i<j)
            {
                if(newnum[i].first+newnum[j].first==target){
                    ans.push_back(newnum[i].second);
                    ans.push_back(newnum[j].second); 
                    return ans;
                }
                else if(newnum[i].first+newnum[j].first<target)
                    i++;
                else
                    j--;
            }       
            return ans;  
        }
        // void quickSort(vector<pair<int,int>>& nums, int low, int high)
        // {
        //     if(low<high)
        //     {
        //         int partitionIndex = partition(nums,low,high);
        //         quickSort(nums,low,partitionIndex-1);
        //         quickSort(nums,partitionIndex+1,high);
        //     }
        // }
        // int partition(vector<pair<int,int>>& nums, int low, int high)
        // {
        //     int pivot = nums[low].first;
        //     int i=low+1;
        //     int j=high;
        //     do{
        //         while(nums[i].first<=pivot && i<high)
        //         {
        //             i++;
        //         }
        //         while(nums[j].first>pivot)
        //         { 
        //             j--; 
        //         }
        //         if(i<j){
        //             swap(nums[i],nums[j]);
        //         }
        //     }while(i<j);
        //     swap(nums[j],nums[low]);
        //     return j;
        // }   
    };          
