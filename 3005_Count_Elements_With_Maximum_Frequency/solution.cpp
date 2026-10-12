class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int x : nums){
            freq[x]++;
        }

        int max = 0;
        for(auto&pair : freq){
            if(pair.second > max){
                max = pair.second;
            }
        }

        int count = 0;
        for(auto&pair : freq){
            if(pair.second == max){
                count += max;
            }
        }

        return count;
    }
};