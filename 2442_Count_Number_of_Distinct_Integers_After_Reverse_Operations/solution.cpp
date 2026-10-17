class Solution {
public:

    int reverse(int n){
        long long rev = 0;
        while(n > 0){
            rev = (rev*10) + (n%10);
            n/=10; 
        }
        return rev;
    }

    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> ans(nums.begin(), nums.end());
        for(int x : nums){
            ans.insert(reverse(x));
        }
        return ans.size();
    }
};