## Problem
Given an integer array `nums`, find the largest element and check whether it is at least twice as large as every other element.

Return the index of the largest element if the condition is satisfied. Otherwise, return `-1`.

**LeetCode:** 747. Largest Number At Least Twice of Others

## My Approach
I used `max_element()` to find the largest element in the array.

Then I traversed the array and checked whether any other element, when multiplied by 2, was greater than the maximum element.

If such an element existed, the condition was violated and I returned `-1`.

Otherwise, I stored the index of the maximum element and returned it.

## Key Logic
1. Find the maximum element using `max_element()`.
2. Traverse the array.
3. Ignore the maximum element itself.
4. Check whether:

   `nums[i] * 2 > maxEle`

5. If true, return `-1`.
6. Otherwise, return the index of the maximum element.

## Solution
```cpp
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int ans;
        int maxEle = *max_element(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != maxEle && nums[i] * 2 > maxEle) {
                return -1;
            }

            if (nums[i] == maxEle) {
                ans = i;
            }
        }

        return ans;
    }
};
```

## Complexity
- **Time Complexity:** `O(n)` — finding the maximum and traversing the array both take linear time.
- **Space Complexity:** `O(1)` — only a few variables are used.

## What I Learned
- `max_element()` returns an iterator to the largest element.
- Dereferencing it with `*` gives the actual maximum value.
- A second traversal can verify a condition against the maximum.
- The largest element's index can be tracked without sorting.
- Avoid sorting when a simple linear scan is sufficient.