class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), median;
        if(n%2 != 0){
            median = nums[n/2];
        }else{
            median = (nums[n/2-1] + nums[n/2])/2;
        }
        int moves = 0;
        for(int x : nums){
            moves += abs(x - median);
        }
        return moves;
    }
};