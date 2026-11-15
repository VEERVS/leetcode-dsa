# 4111. Count Consistent Subarrays I

## Problem
Given an integer array `nums`, a subarray is called consistent if the bitwise AND of all its elements is equal to the minimum value in that subarray.

Return the total number of consistent subarrays.

## My Approach
Used nested loops to generate every possible subarray and check whether it satisfies the condition.

1. Initialize `count = 0`.
2. Fix the starting index `i`.
3. Initialize `bitAnd` and `minEle` with `nums[i]`.
4. Extend the subarray using another loop with index `j`.
5. Update:
   - `bitAnd` using bitwise AND with `nums[j]`.
   - `minEle` using the minimum of the current minimum and `nums[j]`.
6. If `bitAnd == minEle`, increment the answer.
7. Return the total count.

## Key Logic
For every subarray, maintain two values:

- `bitAnd`: Bitwise AND of all elements in the current subarray.
- `minEle`: Minimum element in the current subarray.

A subarray is consistent when:

`bitAnd == minEle`

The starting index remains fixed while the ending index expands, allowing us to examine every possible subarray.

## Solution

```cpp
class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            int bitAnd = nums[i];
            int minEle = nums[i];

            for(int j = i; j < nums.size(); j++) {
                bitAnd &= nums[j];
                minEle = min(minEle, nums[j]);

                if(bitAnd == minEle) {
                    count++;
                }
            }
        }

        return count;
    }
};
```

## Complexity
- **Time Complexity:** O(n²) — Every possible subarray is considered.
- **Space Complexity:** O(1) — Only a constant number of variables are used.

## What I Learned
- How to maintain bitwise AND while expanding a subarray.
- How to track the minimum element simultaneously.
- How nested loops can generate every possible subarray.
- How to compare two running properties to validate a subarray.