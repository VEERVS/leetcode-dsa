class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        long long winSum = 0;
        for(int i=0; i<k; i++){
            winSum += nums[i];
            freq[nums[i]]++;
        }

        long long maxSum = 0;
        if(freq.size() == k){
            maxSum = winSum;
        }

        for(int i=k; i<nums.size(); i++){
            winSum = winSum + nums[i] - nums[i-k];

            freq[nums[i-k]]--;
            if(freq[nums[i-k]] == 0){
                freq.erase(nums[i-k]);
            }
            freq[nums[i]]++;

            if(freq.size() == k){
                maxSum = max(maxSum, winSum);
            }
        }
        return maxSum;
    }
};