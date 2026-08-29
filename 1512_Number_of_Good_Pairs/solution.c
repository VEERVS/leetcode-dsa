// int numIdenticalPairs(int* nums, int numsSize) {
//     int count = 0;
//     for(int i=0; i<numsSize; i++){
//         for(int j=i+1; j<numsSize; j++){
//             if(nums[i]==nums[j] && i<j){
//                 count++;
//             }
//         }
//     }
//     return count;
// }
int numIdenticalPairs(int* nums, int numsSize) {
    int freq[101] = {0};
    int count = 0;
    for(int i=0; i<numsSize; i++){
        count += freq[nums[i]];
        freq[nums[i]]++;
    }
    return count;
}