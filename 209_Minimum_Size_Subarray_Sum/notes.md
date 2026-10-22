## Problem
**LeetCode 209 — Minimum Size Subarray Sum**

Given an array of positive integers `nums` and a positive integer `target`, return the minimum length of a contiguous subarray whose sum is greater than or equal to `target`.

If no such subarray exists, return `0`.

**Example:**
- Input: `target = 7, nums = [2,3,1,2,4,3]`
- Output: `2`
- Explanation: The subarray `[4,3]` has sum `7` and minimum length `2`.

## My Approach
Used the **variable-size sliding window** technique with two pointers, `left` and `right`.

1. Expand the window by moving `right` and adding `nums[right]` to `sum`.
2. When `sum >= target`, update the minimum length.
3. Shrink the window from the left while the sum remains at least the target.
4. If no valid subarray is found, return `0`.

## Key Logic
- `sum += nums[right]` expands the window.
- `while (sum >= target)` keeps shrinking the window while it is valid.
- `ans = min(ans, right - left + 1)` records the shortest valid window.
- `sum -= nums[left]` removes the leftmost element from the window.
- `left++` advances the left pointer.
- If `ans == INT_MAX`, no valid subarray exists, so return `0`.

**Important:** We use `while`, not `if`, because multiple consecutive shrinking operations may be possible while the window remains valid.

This technique works because all array elements are positive. Removing an element from the left decreases the sum.

## Solution

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0;
        int ans = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
```

## Complexity
- **Time Complexity:** `O(n)` — Each element is added to and removed from the window at most once.
- **Space Complexity:** `O(1)` — Only a constant number of variables are used.

## What I Learned
- How variable-size sliding windows differ from fixed-size windows.
- Expand the window when the condition is not satisfied.
- Shrink the window when the condition is satisfied to find a shorter valid subarray.
- Use a `while` loop to check every possible shrinking step.
- Maintain the minimum length throughout the traversal.
- A sliding window can achieve `O(n)` time instead of checking every possible subarray with a brute-force approach.