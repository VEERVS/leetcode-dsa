class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            int bitAnd = nums[i];
            int minEle = nums[i];
            for(int j=i; j<nums.size(); j++){
                bitAnd &= nums[j];
                minEle = min(minEle, nums[j]);

                if(bitAnd == minEle){
                    count++;
                }
            }
        }
        return count;
    }
};