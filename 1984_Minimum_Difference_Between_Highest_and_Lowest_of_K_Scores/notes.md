## Problem
Given an integer array `nums` and an integer `k`, select any `k` scores such that the difference between the highest and lowest selected scores is minimized.

Return the minimum possible difference.

## My Approach
I sorted the array so that the scores were in ascending order. After sorting, I used a fixed-size window of `k` elements to check the difference between the highest and lowest scores in each window.

I initialized `min_diff` to `INT_MAX` and updated it whenever I found a smaller difference.

## Key Logic
- Sorting places the scores in ascending order.
- The minimum difference among any `k` selected elements can be found by checking consecutive groups of `k` elements in the sorted array.
- For a window starting at index `i`:
  - Lowest score: `nums[i]`
  - Highest score: `nums[i + k - 1]`
  - Difference: `nums[i + k - 1] - nums[i]`
- The loop runs while `i <= nums.size() - k` so that the final valid window is included.

## Solution
```cpp
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int min_diff = INT_MAX;

        for (int i = 0; i <= nums.size() - k; i++) {
            int diff = nums[i + k - 1] - nums[i];
            min_diff = min(min_diff, diff);
        }

        return min_diff;
    }
};
```

## Complexity
- Time: `O(n log n)` because sorting dominates the runtime, followed by an `O(n)` scan.
- Space: `O(log n)` auxiliary space for typical introsort implementations, excluding implementation-dependent sorting details.

## What I Learned
- Sorting can turn a selection problem into a fixed-size window problem.
- After sorting, checking consecutive groups of `k` elements is sufficient.
- `i + k - 1` gives the last index of a window starting at `i`.
- The condition `i <= n - k` includes every valid window, including the last one.