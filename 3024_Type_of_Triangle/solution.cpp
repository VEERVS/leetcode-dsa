class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums.at(0) == nums.at(1) && nums.at(0) == nums.at(2) 
            && nums.at(1) == nums.at(2)){
            return "equilateral";
        }else if(nums.at(0)+nums.at(1)>nums.at(2) 
        && nums.at(0)+nums.at(2)>nums.at(1)
        && nums.at(1)+nums.at(2)>nums.at(0)){
            if(nums.at(0) != nums.at(1) && nums.at(0) != nums.at(2) 
            && nums.at(1) != nums.at(2)){
                return "scalene";
            }else{
                return "isosceles";
            }
        }else{
            return "none";
        }
    }
};