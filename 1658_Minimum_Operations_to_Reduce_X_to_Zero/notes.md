## Problem
Given an integer array `nums` and an integer `x`, remove elements from either the left or right end of the array and subtract their values from `x`.

Return the minimum number of operations required to reduce `x` to exactly `0`. If it is impossible, return `-1`.

**LeetCode:** 1658. Minimum Operations to Reduce X to Zero

## My Approach
Instead of removing elements directly from both ends, I converted the problem into finding the longest contiguous subarray whose sum equals `totalSum - x`.

Let:
- `sum` = total sum of the array
- `target = sum - x`
- `longest` = length of the longest subarray with sum equal to `target`

The minimum operations required are:

`nums.size() - longest`

I used a variable-size sliding window to find the longest subarray with the required sum.

## Key Logic
1. Calculate the total sum using `accumulate()`.
2. Calculate `target = sum - x`.
3. If `target < 0`, return `-1`.
4. If `target == 0`, return `nums.size()` because every element must be removed.
5. Expand the window by adding `nums[right]` to `winSum`.
6. While `winSum > target`, shrink the window from the left.
7. Whenever `winSum == target`, update the longest valid window using `right - left + 1`.
8. If no valid subarray exists, return `-1`; otherwise, return `nums.size() - longest`.

## Solution
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;

        if (target < 0) return -1;
        if (target == 0) return nums.size();

        int longest = -1, left = 0, winSum = 0;

        for (int right = 0; right < nums.size(); right++) {
            winSum += nums[right];

            while (winSum > target) {
                winSum -= nums[left];
                left++;
            }

            if (winSum == target) {
                longest = max(longest, right - left + 1);
            }
        }

        return longest == -1 ? -1 : nums.size() - longest;
    }
};
```

## Complexity
- **Time Complexity:** `O(n)` — each element enters and leaves the sliding window at most once.
- **Space Complexity:** `O(1)` — only a constant number of extra variables are used.

## What I Learned
- A problem about removing elements from both ends can be converted into a longest-subarray problem.
- The target sum becomes `totalSum - x`.
- Finding the longest valid subarray minimizes the number of elements that must be removed.
- The condition `while (winSum > target)` ensures the window shrinks only when its sum exceeds the target.
- Edge cases such as `target < 0`, `target == 0`, and no valid subarray must be handled.
- Sliding window works efficiently here because all array elements are positive.