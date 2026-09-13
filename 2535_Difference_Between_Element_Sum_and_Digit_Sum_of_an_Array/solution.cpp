#include<numeric>

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int dSum = 0;

        for(int num : nums){
            int dig = 0;
            while(num>0){
                dig += num%10;
                num /= 10;
            }
            dSum += dig;
        }

        return sum - dSum;
    }
};