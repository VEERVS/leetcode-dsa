class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int sum = 0, left = 0, ans = nums.size() + 1;
        for(int right=0; right<nums.size(); right++){
            freq[nums[right]]++;
            if(freq[nums[right]] == 1){
                sum += nums[right];
            }
            while(sum >= k){
                ans = min(ans, right-left+1);

                freq[nums[left]]--;

                if(freq[nums[left]] == 0){
                    sum -= nums[left];
                    freq.erase(nums[left]);
                }
                left++;
            }
        }
        return ans == nums.size()+1 ? -1 : ans;
    }
};