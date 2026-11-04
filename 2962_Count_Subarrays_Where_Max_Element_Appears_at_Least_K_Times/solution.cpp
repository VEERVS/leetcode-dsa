class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxEle = *max_element(nums.begin(), nums.end());
        int left = 0, count = 0;
        long long ans = 0;
        for(int right=0; right<nums.size(); right++){
            if(nums[right] == maxEle){
                count++;
            }
            while(count >= k){
                ans += nums.size() - right;
                if(nums[left] == maxEle){
                    count--;
                }
                left++;
            }
        }
        return ans;
    }
};