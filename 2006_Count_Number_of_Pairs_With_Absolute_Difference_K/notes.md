## Problem

Given an integer array `nums` and an integer `k`, return the number of pairs `(i, j)` where `i < j` such that:

`|nums[i] - nums[j]| == k`

Example:

`nums = [1,2,2,1], k = 1`

The answer is `4`.

## My Approach

I used **nested loops** to check every possible pair of elements.

The outer loop selects the first element, while the inner loop starts from `i + 1` so that:

- `i < j` is always satisfied.
- We don't check the same pair twice.
- We don't compare an element with itself.

For every pair, I calculate the absolute difference using `abs()`.

If the absolute difference equals `k`, I increase `count`.

## Key Logic

The main logic is:

```cpp
for(int i = 0; i < nums.size(); i++) {
    for(int j = i + 1; j < nums.size(); j++) {
        if(abs(nums[i] - nums[j]) == k) {
            count++;
        }
    }
}
```

Starting `j` from `i + 1` makes sure every pair is checked only once.

For example:

```text
i = 0 → j = 1, 2, 3
i = 1 → j = 2, 3
i = 2 → j = 3
```

`abs()` gives the absolute difference:

```text
abs(1 - 2) = 1
abs(2 - 1) = 1
```

So the order of the two values doesn't matter.

## Solution

```cpp
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(abs(nums[i] - nums[j]) == k) {
                    count++;
                }
            }
        }

        return count;
    }
};
```

## Complexity

- **Time:** `O(n²)`
- **Space:** `O(1)`

The nested loops check every possible pair, giving `O(n²)` time.

Only a few variables are used, so the extra space is `O(1)`.

## What I Learned

- Nested loops can be used to check every possible pair.
- Starting the inner loop from `i + 1` avoids duplicate pairs.
- `abs()` gives the absolute difference between two numbers.
- The condition `i < j` can be naturally maintained using the loop structure.
- This is a straightforward brute-force pair-checking approach.