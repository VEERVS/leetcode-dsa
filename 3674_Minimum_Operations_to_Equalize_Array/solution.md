## Problem

Given an integer array `nums`, one operation allows choosing any non-empty subarray and replacing every element in that subarray with the bitwise AND of all elements in it.

Return the minimum number of operations required to make all elements equal.

## My Approach

I noticed that the answer can only be `0` or `1`.

If all elements are already equal, no operation is required.

If at least two elements are different, I can choose the **entire array** as the subarray.

The bitwise AND of the entire array produces one value, and replacing every element with that value makes the whole array equal in one operation.

Therefore, I only need to check whether all elements are equal.

I compared every element with the first element and immediately returned `1` if I found a difference.

## Key Logic

There are only two cases:

1. All elements are equal → answer is `0`.
2. At least one element differs → choose the entire array → answer is `1`.

This means we don't actually need to calculate any bitwise AND.

## Solution

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[0]) {
                return 1;
            }
        }

        return 0;
    }
};
```

## Complexity

Time: `O(n)`

Space: `O(1)`

## What I Learned

I learned to look for the simplest possible outcome before trying to simulate an operation.

The operation itself looks more complicated because it involves bitwise AND and subarrays, but the key observation is that choosing the entire array solves every non-equal case in exactly one operation.