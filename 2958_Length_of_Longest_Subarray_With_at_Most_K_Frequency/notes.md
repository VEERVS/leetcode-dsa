## Problem
Given an integer array `nums` and an integer `k`, return the length of the longest contiguous subarray in which every element appears at most `k` times.

**LeetCode:** 2958. Length of Longest Subarray With at Most K Frequency

## My Approach
I used a variable-size sliding window and an `unordered_map` to maintain the frequency of each element in the current window.

For each `right` index, I added `nums[right]` to the frequency map. If its frequency exceeded `k`, I shrank the window from the left until the frequency became valid again.

After restoring the window's validity, I updated the maximum length using `right - left + 1`.

## Key Logic
1. Create an `unordered_map<int, int>` to store element frequencies.
2. Expand the window by incrementing `freq[nums[right]]`.
3. While `freq[nums[right]] > k`:
   - Decrease the frequency of `nums[left]`.
   - Increment `left`.
4. Update `ans = max(ans, right - left + 1)`.
5. Return `ans`.

## Solution
```cpp
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
```

## Complexity
- **Time Complexity:** `O(n)` average — each element enters and leaves the window at most once.
- **Space Complexity:** `O(n)` — the frequency map can store up to `n` distinct elements.

## What I Learned
- Variable-size sliding windows work well for maintaining frequency constraints.
- Expand the window when processing new elements and shrink it when a constraint is violated.
- When shrinking, update the frequency of the element leaving from the left, not the element entering from the right.
- `right - left + 1` calculates the current window length.
- Update the maximum length only after the window becomes valid.