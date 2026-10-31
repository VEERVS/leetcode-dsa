class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int ans;
        int maxEle = *max_element(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != maxEle && nums[i]*2 > maxEle){
                return -1;
            }
            if(nums[i] == maxEle){
                ans = i;
            }
        }
        return ans;
    }
};