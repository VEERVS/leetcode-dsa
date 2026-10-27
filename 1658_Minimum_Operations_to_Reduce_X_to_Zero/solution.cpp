class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;

        if(target < 0) return -1;
        if(target == 0) return nums.size();

        int longest = -1, left = 0, winSum = 0;

        for(int right=0; right<nums.size(); right++){
            winSum += nums[right];

            while(winSum > target){
                winSum -= nums[left];
                left++;
            }

            if(winSum == target){
                longest = max(longest, right-left+1);
            }
        }

        return longest == -1 ? -1 : nums.size() - longest;
    }
};