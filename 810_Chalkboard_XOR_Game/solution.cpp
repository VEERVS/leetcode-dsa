class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int sumXor = 0;
        for(int i=0; i<nums.size(); i++){
            sumXor ^= nums[i];
        }
        return sumXor == 0 || nums.size() % 2 == 0;
    }
};