# 3795. Minimum Subarray Length With Distinct Sum At Least K

## Problem
Given an integer array `nums` and an integer `k`, find the minimum length of a contiguous subarray whose sum of distinct elements (each value counted only once) is at least `k`.

If no such subarray exists, return `-1`.

## My Approach
Used a variable-size sliding window with an `unordered_map` to maintain element frequencies and the sum of distinct elements.

1. Initialize a frequency map, `left`, `sum`, and `ans`.
2. Expand the window using the `right` pointer.
3. Increase the frequency of the current element.
4. If its frequency becomes 1, add it to the distinct sum.
5. When `sum >= k`, the current window is valid.
6. Update the minimum window length.
7. Shrink the window from the left:
   - Decrease the frequency of the leftmost element.
   - If its frequency becomes zero, subtract it from the distinct sum and erase it from the map.
   - Move `left` forward.
8. Return `-1` if no valid window was found.

## Key Logic
- `freq[nums[right]] == 1`: The element has appeared for the first time in the current window, so add it to the distinct sum.
- `sum >= k`: The current window satisfies the required condition.
- `ans = min(ans, right - left + 1)`: Update the shortest valid window.
- `freq[nums[left]] == 0`: The element no longer exists in the window, so subtract its value from the distinct sum.
- The frequency map ensures duplicate elements are counted only once.

## Solution

```cpp
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        int sum = 0, left = 0;
        int ans = nums.size() + 1;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            if (freq[nums[right]] == 1) {
                sum += nums[right];
            }

            while (sum >= k) {
                ans = min(ans, right - left + 1);

                freq[nums[left]]--;

                if (freq[nums[left]] == 0) {
                    sum -= nums[left];
                    freq.erase(nums[left]);
                }

                left++;
            }
        }

        return ans == nums.size() + 1 ? -1 : ans;
    }
};
```

## Complexity
- **Time Complexity:** O(n) expected — Each element enters and leaves the sliding window at most once. Hash map operations take O(1) on average.
- **Space Complexity:** O(n) — The frequency map can store up to n distinct elements.

## What I Learned
- How to calculate the sum of distinct elements inside a sliding window.
- Why frequency tracking is necessary when duplicate elements are present.
- How to update a distinct sum only when an element enters or leaves the window completely.
- How to find the minimum-length valid subarray using a variable-size sliding window.