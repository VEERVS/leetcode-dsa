## Problem

Given an integer array `nums` and an integer `target`, count the number of pairs `(i, j)` where:

```text
i < j
nums[i] + nums[j] < target
```

## My Approach

Use two nested loops to check every possible pair.

The outer loop selects the first element and the inner loop starts from `i + 1` so that:

- `i < j`
- No element is paired with itself.
- Each pair is checked only once.

If the sum is less than `target`, increment `count`.

## Key Logic

```c
for(int i = 0; i < numsSize; i++) {
    for(int j = i + 1; j < numsSize; j++) {
        if(nums[i] + nums[j] < target) {
            count++;
        }
    }
}
```

Starting `j` from `i + 1` is important because it guarantees `i < j`.

## Solution

```c
int countPairs(int* nums, int numsSize, int target) {
    int count = 0;

    for(int i = 0; i < numsSize; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] < target) {
                count++;
            }
        }
    }

    return count;
}
```

## Complexity

Time: O(n²)

Space: O(1)

## What I Learned

- Nested loops can be used to check every unique pair.
- Starting the second loop at `i + 1` avoids duplicate pairs.
- The condition must be strictly `< target`, not `<= target`.
- This is the basic brute-force solution; it can later be optimized using sorting and two pointers.