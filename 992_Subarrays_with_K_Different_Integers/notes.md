## Problem
Given an integer array `nums` and an integer `k`, return the number of good subarrays containing exactly `k` different integers.

**LeetCode:** 992. Subarrays with K Different Integers

## My Approach
I used the sliding window technique with a frequency map.

Instead of directly counting subarrays with exactly `k` distinct integers, I calculated:

`atMost(k) - atMost(k - 1)`

The `atMost()` helper function counts subarrays containing at most `k` distinct integers.

I expanded the window from the right and shrank it whenever the number of distinct elements exceeded `k`.

For every valid window, I added `right - left + 1` to the answer because every subarray ending at `right` and starting between `left` and `right` is valid.

## Key Logic
1. Create an `atMost()` helper function.
2. Maintain a frequency map.
3. Expand the window by adding `nums[right]`.
4. While the number of distinct elements exceeds `k`:
   - Decrease the frequency of `nums[left]`.
   - Erase the element if its frequency becomes zero.
   - Increment `left`.
5. Add `right - left + 1` to the count.
6. Calculate:

   `atMost(k) - atMost(k - 1)`

## Solution
```cpp
class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            while (freq.size() > k) {
                freq[nums[left]]--;

                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }

                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
```

## Complexity
- **Time Complexity:** `O(n)` average — each element enters and leaves the window at most once, and the helper runs twice.
- **Space Complexity:** `O(n)` — frequency map can store up to `n` distinct elements.

## What I Learned
- Exactly K can be calculated using `atMost(K) - atMost(K-1)`.
- `freq.size()` tracks the number of distinct elements.
- `right - left + 1` counts all valid subarrays ending at the current right pointer.
- Sliding window can solve difficult subarray-counting problems using a helper function.
- The at-most technique is reusable for many exact-count problems.