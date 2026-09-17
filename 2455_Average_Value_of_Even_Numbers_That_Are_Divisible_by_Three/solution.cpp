class Solution {
public:
    int averageValue(vector<int>& nums) {
        int count = 0, sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%3==0 && nums[i]%2==0){
                sum += nums[i];
                count++;
            }
        }
        if(!count){
            return 0;
        }
        return sum/count;
    }
};