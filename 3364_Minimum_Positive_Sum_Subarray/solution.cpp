class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int n = nums.size();

        for (int k = l; k <= r; ++k) {
            int sum = 0;

            for (int i = 0; i < n; ++i) {
                sum += nums[i];

                if (i >= k) {
                    sum -= nums[i - k];
                }

                if (i >= k - 1 && sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};