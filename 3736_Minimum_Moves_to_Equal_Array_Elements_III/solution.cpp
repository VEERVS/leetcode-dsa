class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for(int x : nums){
            ans += (maxEle - x);
        }
        return ans;
    }
};