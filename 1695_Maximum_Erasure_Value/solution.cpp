class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int>freq;
        int ans = 0, left = 0, winSum = 0;
        for(int right=0; right<nums.size(); right++){
            freq[nums[right]]++;
            winSum += nums[right];
            while(freq[nums[right]] > 1){
                freq[nums[left]]--;
                winSum -= nums[left];
                if(freq[nums[left]] == 0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            ans = max(ans, winSum);
        }
        return ans;
    }
};