class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int winSum = 0;
        for(int i=0; i<k; i++){
            winSum += nums[i];
        }

        double maxAvg = (double)winSum/k;

        for(int i=0; i<nums.size()-k; i++){
            winSum = winSum + nums[i+k] - nums[i];
            double winAvg = (double)winSum/k;

            maxAvg = max(maxAvg, winAvg);
        }
        return maxAvg;
    }
};