/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* concatWithReverse(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2 * numsSize;
    int *ans = malloc((*returnSize) * sizeof(int)), i;

    for(i=0; i<numsSize; i++){
        ans[i] = nums[i];
    }

    for(i=numsSize; i<*returnSize; i++){
        ans[i] = nums[(*returnSize)-i-1];
    }

    return ans;
}