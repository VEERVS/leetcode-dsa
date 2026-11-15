class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        long long next1 = 0;
        long long next2 = 0;
        
        for(int i=nums.size()-1; i>=0; i--){
            long long take1 = nums[i];
            long long best = (take1 % 3 == 0) ? (take1-next1) : (take1+next1);

            if(i+1 < (int)nums.size()){
                long long take2 = (long long)nums[i] + nums[i+1];
                long long res = (take2 % 3 == 0) ? (take2-next2) : (take2+next2);
                best = max(best, res);
            }
            next2 = next1;
            next1 = best;
        }
        return next1;
    }
};