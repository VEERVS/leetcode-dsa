## Problem
Given an integer array `nums` and an integer `target`, sort the array in non-decreasing order and return all indices where `nums[i] == target`.

The returned indices must be in increasing order.

## My Approach
I sorted the array using `sort()`, then traversed it from left to right. Whenever an element matched `target`, I added its index to the answer vector.

## Key Logic
- Sort the array using `sort(nums.begin(), nums.end())`.
- Traverse every index from `0` to `nums.size() - 1`.
- If `nums[i] == target`, add `i` to `ans`.
- Since the array is sorted and traversed from left to right, the returned indices are already in increasing order.
- If the target doesn't exist, the answer vector remains empty.

## Solution
```cpp
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
```

## Complexity
- Time: `O(n log n)` due to sorting, followed by an `O(n)` traversal.
- Auxiliary space: `O(log n)` typically for the sorting implementation, excluding the output vector.

## What I Learned
- Sorting makes equal elements appear consecutively.
- Traversing a sorted array from left to right naturally produces increasing indices.
- `push_back(i)` stores the index, not the element itself.
- An empty vector is a valid result when no element matches the target.