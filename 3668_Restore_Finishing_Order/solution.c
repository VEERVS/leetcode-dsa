/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* recoverOrder(int* order, int orderSize, int* friends, int friendsSize, int* returnSize) {
    *returnSize = friendsSize;
    int *ans = malloc((*returnSize) * sizeof(int)), i,j,k=0;

    for(i=0; i<orderSize; i++){
        for(j=0; j<friendsSize; j++){
            if(order[i]==friends[j]){
                ans[k]=friends[j];
                k++;
                break;
            }
        }
    }
    return ans;
}