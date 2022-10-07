//Given an integer array nums sorted in non-decreasing order, 
//return an array of the squares of each number sorted in non-decreasing order.

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
// int* sortedSquares(int* nums, int numsSize, int* returnSize){

// }

#include<stdio.h>
int main(){
    int ans[5];
    int nums[5] = {-4,-1,0,3,10};
    int i=0,j=4,k=0;
    while(i<=j){
        if((nums[i]*nums[i])>=(nums[j]*nums[j])){
            ans[k] = nums[i]*nums[i];
            i++;
            k++;
        }
        else{
            ans[k] = nums[j]*nums[j];
            k++;
            j--;
        }
    }
    for(int i=4;i>=0;i--){
        printf("%d, ",ans[i]);
    }
    return 0;
}