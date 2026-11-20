# 2567. Minimum Score by Changing Two Elements

## Problem
Given an integer array `nums`, define:

- Low score: Minimum absolute difference between any two elements.
- High score: Maximum absolute difference between any two elements.
- Total score: Sum of the low and high scores.

Return the minimum possible score after changing two elements.

## My Approach
Used sorting and greedy observation.

1. Sort the array in ascending order.
2. Store the array size in `n`.
3. Calculate three possible cases:

   - `case1 = nums[n-3] - nums[0]`
   - `case2 = nums[n-2] - nums[1]`
   - `case3 = nums[n-1] - nums[2]`

4. Return the minimum among these three cases.

## Key Logic
After sorting, the minimum score can be achieved by changing two elements so that the remaining range is minimized.

There are three possible ways to remove the effect of two extreme elements:

- **Case 1:** Change the two largest elements. Remaining range: `nums[n-3] - nums[0]`.
- **Case 2:** Change the smallest and largest elements. Remaining range: `nums[n-2] - nums[1]`.
- **Case 3:** Change the two smallest elements. Remaining range: `nums[n-1] - nums[2]`.

The minimum of these three differences gives the answer.

## Solution

```cpp
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int case1 = nums[n-3] - nums[0];
        int case2 = nums[n-2] - nums[1];
        int case3 = nums[n-1] - nums[2];

        return min({case1, case2, case3});
    }
};
```

## Complexity
- **Time Complexity:** O(N log N) — Sorting dominates the execution time.
- **Space Complexity:** O(log N) auxiliary space for the sorting implementation.

## What I Learned
- How sorting simplifies minimum and maximum difference problems.
- How to use greedy observations to reduce multiple possibilities to three cases.
- How changing extreme elements can minimize the remaining range.
- How to use `min({a, b, c})` to find the minimum among multiple values.