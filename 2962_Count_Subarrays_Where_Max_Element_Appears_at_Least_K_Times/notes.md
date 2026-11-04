# 2962. Count Subarrays Where Max Element Appears at Least K Times

## Problem
Given an integer array `nums` and a positive integer `k`, return the number of contiguous subarrays in which the maximum element of the entire array appears at least `k` times.

## My Approach
Used a variable-size sliding window.

1. Find the maximum element in the entire array using `max_element()`.
2. Expand the window using the `right` pointer.
3. Maintain a count of how many times the global maximum appears in the current window.
4. Whenever the count becomes at least `k`, the current window is valid.
5. Add `nums.size() - right` to the answer because every extension of the current window to the right remains valid.
6. Shrink the window from the left while it remains valid, updating the maximum element count.

## Key Logic
- `count >= k`: The current window contains the global maximum at least `k` times.
- `ans += nums.size() - right`: Counts all valid subarrays starting at the current `left` and ending at `right` or later.
- If `nums[left] == maxEle`, decrement `count` before moving `left`.
- Continue shrinking until the window becomes invalid.

## Solution

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxEle = *max_element(nums.begin(), nums.end());

        int left = 0, count = 0;
        long long ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == maxEle) {
                count++;
            }

            while (count >= k) {
                ans += nums.size() - right;

                if (nums[left] == maxEle) {
                    count--;
                }

                left++;
            }
        }

        return ans;
    }
};
```

## Complexity
- **Time Complexity:** O(n) — Each element is visited at most twice by the sliding-window pointers.
- **Space Complexity:** O(1) — Only a constant number of variables are used.

## What I Learned
- How to count subarrays where a specific element occurs at least `k` times.
- The `n - right` contribution pattern for counting valid extensions.
- How to combine a global maximum calculation with a variable-size sliding window.
- Why shrinking the window while it remains valid helps count every valid subarray exactly once.