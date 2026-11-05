# 1695. Maximum Erasure Value

## Problem
Given an array of positive integers `nums`, find a contiguous subarray containing only unique elements such that the sum of its elements is maximum.

Return the maximum possible sum.

## My Approach
Used a variable-size sliding window with an `unordered_map` to maintain element frequencies.

1. Traverse the array using the `right` pointer.
2. Add the current element to the frequency map and update the window sum.
3. If the frequency of the current element becomes greater than one, shrink the window from the left.
4. While shrinking:
   - Decrease the frequency of the leftmost element.
   - Subtract it from the window sum.
   - Remove it from the map if its frequency becomes zero.
   - Move the `left` pointer forward.
5. After restoring the uniqueness condition, update the maximum answer.

## Key Logic
- `freq[nums[right]] > 1`: A duplicate exists in the current window.
- `while (freq[nums[right]] > 1)`: Keep shrinking until the window contains unique elements.
- `winSum`: Maintains the sum of the current window.
- `ans = max(ans, winSum)`: Updates the maximum valid subarray sum.

## Solution

```cpp
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> freq;

        int ans = 0, left = 0, winSum = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            winSum += nums[right];

            while (freq[nums[right]] > 1) {
                freq[nums[left]]--;
                winSum -= nums[left];

                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }

                left++;
            }

            ans = max(ans, winSum);
        }

        return ans;
    }
};
```

## Complexity
- **Time Complexity:** O(n) expected — Each element enters and leaves the sliding window at most once. Hash map operations take O(1) on average.
- **Space Complexity:** O(n) — The frequency map can store up to n distinct elements.

## What I Learned
- How to maintain a window containing only unique elements.
- How an `unordered_map` helps track element frequencies.
- How to maintain a running window sum instead of recalculating it.
- How shrinking a variable-size window restores a required condition.
- How sliding window can optimize problems involving maximum sums and uniqueness.