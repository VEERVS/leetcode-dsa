# 2537. Count the Number of Good Subarrays

## Problem
Given an integer array `nums` and an integer `k`, return the number of good subarrays.

A subarray is called good if it contains at least `k` pairs of indices `(i, j)` such that:
- `i < j`
- `nums[i] == nums[j]`

## My Approach
Used a variable-size sliding window with an `unordered_map` to maintain element frequencies and a variable `pairs` to track equal pairs.

1. Traverse the array using the `right` pointer.
2. Before adding the current element, add its existing frequency to `pairs`.
3. Increment the frequency of the current element.
4. When `pairs >= k`, the current window is good.
5. Add `nums.size() - right` to the answer because extending the current window to the right will preserve the good-subarray condition.
6. Shrink the window from the left:
   - Decrease the frequency of `nums[left]`.
   - Subtract its remaining frequency from `pairs`.
   - Move `left` forward.
7. Continue until the window becomes invalid.

## Key Logic
- `pairs += freq[nums[right]]`: Every existing occurrence of the current element forms one new equal pair with it.
- `freq[nums[right]]++`: Add the current element to the window.
- `pairs >= k`: The current window contains at least `k` equal pairs.
- `ans += nums.size() - right`: Count all valid extensions of the current window.
- `pairs -= freq[nums[left]]`: After removing the leftmost element, subtract the number of pairs that included it.

## Solution

```cpp
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        long long left = 0, ans = 0, pairs = 0;

        for (int right = 0; right < nums.size(); right++) {
            pairs += freq[nums[right]];
            freq[nums[right]]++;

            while (pairs >= k) {
                ans += nums.size() - right;

                freq[nums[left]]--;
                pairs -= freq[nums[left]];

                left++;
            }
        }

        return ans;
    }
};
```

## Complexity
- **Time Complexity:** O(n) expected — Each element enters and leaves the window at most once. Hash map operations take O(1) on average.
- **Space Complexity:** O(n) — The frequency map can store up to n distinct elements.

## What I Learned
- How to count equal pairs dynamically using element frequencies.
- Why adding an element with an existing frequency of `f` creates exactly `f` new pairs.
- Why removing an element requires subtracting its remaining frequency from the pair count.
- How to use the `n - right` counting pattern when every rightward extension of a valid window remains valid.
- How to combine frequency maps and variable-size sliding windows for counting subarrays.