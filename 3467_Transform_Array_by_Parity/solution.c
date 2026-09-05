/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* transformArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int even = 0, odd = 0;
    int *ans = malloc((*returnSize) * sizeof(int));
    for(int i=0; i<numsSize; i++){
        if(nums[i]%2==0){
            even++;
        }else{
            odd++;
        }
    }
    for(int i=0; i<even; i++){
        ans[i] = 0;
    }
    for(int i=even; i<even+odd; i++){
        ans[i] = 1;
    }
    return ans;
}