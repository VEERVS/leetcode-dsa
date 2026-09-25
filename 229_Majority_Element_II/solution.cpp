class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int>freq;
        vector<int>ans;
        for(int val : nums){
            freq[val]++;
        }
        for(auto& pair : freq){
            if(pair.second > nums.size()/3){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};