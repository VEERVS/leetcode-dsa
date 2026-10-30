class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_set<int> set(nums.begin(), nums.end());
        int left = 0, ans = 0;
        for(int right=0; right<nums.size(); right++){
            freq[nums[right]]++;
            while(freq.size() == set.size()){
                ans += nums.size() - right;

                freq[nums[left]]--;
                if(freq[nums[left]] == 0){
                    freq.erase(nums[left]);
                }

                left++;
            }
        }
        return ans;
    }
};