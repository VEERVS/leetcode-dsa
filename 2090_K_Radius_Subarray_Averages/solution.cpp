class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int>ans(nums.size(), -1);
        if(nums.size() < 2*k+1) return ans;

        long long winSum = 0;
        for(int i=0; i<(2*k)+1; i++){
            winSum += nums[i];
        }

        ans[k] = winSum/((2*k)+1);

        for(int i=k+1; i<nums.size()-k; i++){
            winSum = winSum - nums[i-k-1] + nums[i+k];
            ans[i] = winSum/((2*k)+1);
        }

        return ans;
    }
};