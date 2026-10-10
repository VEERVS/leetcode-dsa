class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int x : nums){
            freq[x]++;
        }

        int sum = 0;
        for(auto&x : freq){
            if(x.second % k == 0){
                sum += x.first * x.second;
            }
        }
        return sum;
    }
};