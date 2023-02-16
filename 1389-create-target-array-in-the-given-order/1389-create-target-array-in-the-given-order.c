/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    *returnSize = numsSize;
    int* target = (int*)malloc(numsSize*sizeof(int));
    int i=0;
    while(i<numsSize)
        target[i++] = -1;
    for(i=0;i<numsSize;i++) 
    {
        if(target[index[i]]==-1)
            target[index[i]] = nums[i];
        else {
            int j=numsSize-1;
            while(j>index[i])
                target[j] = target[j-1],j--;
            target[index[i]] = nums[i];
        }
    }
    return target;
}