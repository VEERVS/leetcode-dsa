
## Problem
Given a binary array `nums` and an integer `goal`, return the number of non-empty subarrays whose sum equals `goal`.

## My Approach
Used the AtMost sliding window technique.

Created a helper function `atMost()` that counts subarrays whose sum is less than or equal to a given goal.

Then calculated the exact number of subarrays using:

`Exactly K = AtMost(K) - AtMost(K - 1)`

Inside the helper:
1. Expand the window by adding `nums[right]` to the sum.
2. If the sum exceeds the goal, shrink the window from the left.
3. Add `right - left + 1` to the answer because all subarrays ending at `right` within the valid window satisfy the condition.

If the goal is negative, return 0 because a binary array cannot have a negative sum.

## Key Logic
**Exactly K = AtMost(K) - AtMost(K - 1)**

For every valid window:
- `sum <= goal` keeps the window valid.
- `right - left + 1` counts all valid subarrays ending at `right`.
- Subtracting `AtMost(goal - 1)` removes subarrays with smaller sums.

This leaves only subarrays whose sum is exactly `goal`.

## Solution

```cpp
class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if(goal < 0) return 0;

        int left = 0, ans = 0, sum = 0;

        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while(sum > goal) {
                sum -= nums[left];
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};
```

## Complexity
- **Time Complexity:** O(n), each pointer traverses the array at most once per helper call.
- **Space Complexity:** O(1), no additional data structure is used.

## What I Learned
- Counting subarrays with an exact sum using the AtMost technique.
- Using `right - left + 1` to count valid subarrays.
- Why sliding window works efficiently for non-negative arrays.
- Handling `goal = 0` and negative limits correctly.
