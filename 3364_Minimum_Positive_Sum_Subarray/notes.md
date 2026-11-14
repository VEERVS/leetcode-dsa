# 3364. Minimum Positive Sum Subarray

## Problem
Given an integer array `nums` and two integers `l` and `r`, find the minimum sum of a contiguous subarray whose length is between `l` and `r` (inclusive) and whose sum is greater than zero.

Return the minimum positive sum. If no such subarray exists, return `-1`.

## My Approach
Used nested loops with a fixed-size sliding window for every possible window length between `l` and `r`.

1. Initialize `ans = INT_MAX`.
2. Iterate through every possible subarray length `k` from `l` to `r`.
3. For each window size, initialize `sum = 0`.
4. Traverse the array while maintaining a rolling sum:
   - Add the incoming element `nums[i]`.
   - If `i >= k`, remove the outgoing element `nums[i-k]`.
5. Once the window reaches size `k`, check whether its sum is positive.
6. If positive, update the minimum answer.
7. If no positive-sum subarray is found, return `-1`.

## Key Logic
- The outer loop checks every permitted window size from `l` to `r`.
- `sum += nums[i]`: Adds the incoming element.
- `sum -= nums[i-k]`: Removes the element leaving the fixed-size window.
- `i >= k - 1`: Ensures the current window contains exactly `k` elements.
- `sum > 0`: Ensures only positive-sum subarrays are considered.
- `ans = min(ans, sum)`: Maintains the smallest positive sum.

## Solution

```cpp
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
```

## Complexity
- **Time Complexity:** O(n × (r - l + 1)) — We process the array once for every permitted window size.
- **Space Complexity:** O(1) — Only a constant number of variables are used.

## What I Learned
- How to apply fixed-size sliding windows for multiple possible window sizes.
- How to maintain a rolling sum when negative numbers are present.
- How to remove the outgoing element using `nums[i-k]`.
- How to find the minimum positive sum among all valid subarrays.
- How to combine a range of window sizes with an efficient rolling-sum technique.