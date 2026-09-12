class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single = 0, dob = 0, i;
        for(i=0; i<nums.size(); i++){
            if(nums[i]>=1 && nums[i]<=9){
                single += nums[i];
            }else{
                dob += nums[i];
            }
        }
        return single != dob;
    }
};