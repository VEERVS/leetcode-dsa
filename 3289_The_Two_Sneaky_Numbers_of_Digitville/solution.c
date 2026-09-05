/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int* ans = malloc((*returnSize) * sizeof(int));
    int freq[101]={0}, k=0;

    for(int i=0; i<numsSize; i++){
        freq[nums[i]]++;
    }
    for(int i=0; i<numsSize; i++){
        if(freq[nums[i]]==2){
            ans[k] = nums[i];
            k++;
            freq[nums[i]]++;
        }
    }
    return ans;
}