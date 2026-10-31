## Problem
Given an integer array `nums` and an integer `k`, a subarray is called nice if it contains exactly `k` odd numbers.

Return the total number of nice subarrays.

**LeetCode:** 1248. Count Number of Nice Subarrays

## My Approach
I used a variable-size sliding window with the at-most counting technique.

Instead of directly counting subarrays containing exactly `k` odd numbers, I calculated:

`atMost(k) - atMost(k - 1)`

The `atMost()` helper function counts subarrays containing at most `k` odd numbers.

I maintained an `odd` counter to track the number of odd elements in the current window.

Whenever the odd count exceeded `k`, I shrank the window from the left until it became valid again.

For every valid window, I added `right - left + 1` to the answer because every subarray ending at `right` and starting between `left` and `right` contains at most `k` odd numbers.

## Key Logic
1. Create an `atMost()` helper function.
2. If `k < 0`, return `0`.
3. Expand the window by checking whether `nums[right]` is odd.
4. Increment `odd` when the current number is odd.
5. While `odd > k`:
   - Check whether `nums[left]` is odd.
   - Decrease `odd` if necessary.
   - Increment `left`.
6. Add `right - left + 1` to the answer.
7. Calculate:

   `atMost(k) - atMost(k - 1)`

## Solution
```cpp
class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int left = 0, odd = 0;
        long long ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 != 0) {
                odd++;
            }

            while (odd > k) {
                if (nums[left] % 2 != 0) {
                    odd--;
                }
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
```

## Complexity
- **Time Complexity:** `O(n)` — each element enters and leaves the sliding window at most once. The helper function runs twice.
- **Space Complexity:** `O(1)` — only a few variables are maintained.

## What I Learned
- Exactly K can be calculated using `atMost(K) - atMost(K - 1)`.
- Odd numbers can be tracked using `nums[i] % 2 != 0`.
- `right - left + 1` counts all valid subarrays ending at the current right pointer.
- The at-most technique works for counting subarrays based on a constraint.
- Returning zero when `k < 0` handles the boundary case correctly.