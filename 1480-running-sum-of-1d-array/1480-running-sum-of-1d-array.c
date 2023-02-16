/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *res = (int*)malloc(numsSize*sizeof(int));
    int acc = 0;
    int i = 0;
    for(i=0;i<numsSize;i++) 
    {
        acc = acc + nums[i];
        res[i] = acc;
    }
    return res;
}