class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LLONG_MIN;
        long second = LLONG_MIN;
        long third = LLONG_MIN;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == first || nums[i] == second || nums[i] == third){
                continue;
            }

            if(nums[i] > first){
                third = second;
                second = first;
                first = nums[i];
            }
            else if(nums[i] > second){
                third = second;
                second = nums[i];
            }
            else if(nums[i] > third){
                third = nums[i];
            }
        }

        return third == LLONG_MIN ? (int)first : (int)third;
    }
};