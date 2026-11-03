## Problem
Given a positive integer array `nums` and an integer `k`, return the number of non-empty subarrays whose score is strictly less than `k`.

The score of a subarray is defined as:

`sum of elements × length of subarray`

**LeetCode:** 2302. Count Subarrays With Score Less Than K

## My Approach
I used a variable-size sliding window.

I maintained a running sum and expanded the window by moving `right`.

Whenever the window score became greater than or equal to `k`, I shrank the window from the left until the score became valid again.

For every valid window, I counted all possible subarrays ending at the current `right` index.

## Key Logic
1. Initialize `left = 0`, `sum = 0`, and `ans = 0`.
2. Expand the window by adding `nums[right]` to the running sum.
3. While the score is greater than or equal to `k`:

   `sum * (right - left + 1) >= k`

   Remove `nums[left]` and increment `left`.
4. Once the window becomes valid, add:

   `right - left + 1`

   to the answer.
5. Return `ans`.

**Why `right - left + 1`?**

Every subarray ending at `right` and starting anywhere between `left` and `right` is valid.

Therefore, the number of valid subarrays ending at `right` equals the current window length.

## Solution
```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int left = 0;
        long long ans = 0, sum = 0;

        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while(sum * (right - left + 1) >= k) {
                sum -= nums[left];
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};
```

## Complexity
- **Time Complexity:** O(n) — each element enters and leaves the window at most once.
- **Space Complexity:** O(1) — only a few variables are maintained.

## What I Learned
- Sliding window can count subarrays, not just find their maximum or minimum length.
- `right - left + 1` counts valid subarrays ending at the current right pointer.
- When the condition is strictly less than `k`, invalid windows must be shrunk when the score is `>= k`.
- Positive array elements allow the sliding window to work because shrinking reduces the sum and window length.
- Use `long long` for the sum, score calculation, and answer to avoid integer overflow.