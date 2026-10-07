class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());
        vector<int>ans;
        unordered_map<int, int>freq;
        for(int x : nums){
            freq[x]++;
        }

        for(int i=min; i<=max; i++){
            if(freq[i] == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};