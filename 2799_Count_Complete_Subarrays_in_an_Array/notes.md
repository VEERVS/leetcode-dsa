## Problem
Given an integer array `nums`, a subarray is called complete if it contains the same number of distinct elements as the entire array.

Return the total number of complete subarrays.

**LeetCode:** 2799. Count Complete Subarrays in an Array

## My Approach
I used a variable-size sliding window with an `unordered_map` to maintain the frequency of elements and an `unordered_set` to calculate the total number of distinct elements in the array.

I expanded the window by adding elements from the right. Whenever the window contained all distinct elements of the entire array, I counted all possible extensions to the right using `nums.size() - right`.

Then I shrank the window from the left to find additional complete subarrays.

## Key Logic
1. Create a frequency map and a set of all distinct elements.
2. Expand the window by incrementing `freq[nums[right]]`.
3. While `freq.size() == set.size()`:
   - Add `nums.size() - right` to the answer.
   - Decrease the frequency of `nums[left]`.
   - Erase the element if its frequency becomes zero.
   - Increment `left`.
4. Return the total count.

## Solution
```cpp
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_set<int> st(nums.begin(), nums.end());

        int left = 0, ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            while (freq.size() == st.size()) {
                ans += nums.size() - right;

                freq[nums[left]]--;

                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }

                left++;
            }
        }

        return ans;
    }
};
```

## Complexity
- **Time Complexity:** `O(n)` average — each element enters and leaves the window at most once.
- **Space Complexity:** `O(n)` — frequency map and distinct-element set.

## What I Learned
- Sliding windows can count subarrays, not just find maximum or minimum lengths.
- `unordered_set` helps calculate the total number of distinct elements.
- When a window is complete, every extension to the right remains complete.
- `n - right` counts the possible ending positions for a complete window.
- Shrinking while the window is valid helps count all possible complete subarrays.