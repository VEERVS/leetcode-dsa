## Problem

Given an integer array `nums` of length `n`, create an array `ans` of length `2n` such that:

```text
ans[i] = nums[i]
ans[i + n] = nums[i]
```

In simple words, concatenate the array with itself.

Example:

```text
nums = [1,2,1]

ans = [1,2,1,1,2,1]
```

## My Approach

Since the result needs `2 * numsSize` elements, dynamically allocate an array of that size using `malloc()`.

Set:

```c
*returnSize = 2 * numsSize;
```

Then use two loops:

1. Copy the original array into the first half of `ans`.
2. Copy the original array again into the second half.

## Key Logic

```c
ans[i] = nums[i];
```

copies the first half.

For the second half:

```c
ans[i] = nums[i - numsSize];
```

When `i` starts at `numsSize`, subtracting `numsSize` brings the index back to `0`.

Example:

```text
i = 3 → nums[3 - 3] = nums[0]
i = 4 → nums[4 - 3] = nums[1]
i = 5 → nums[5 - 3] = nums[2]
```

So:

```text
nums = [1,2,1]

ans = [1,2,1,1,2,1]
```

## Solution

```c
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2 * numsSize;

    int *ans = malloc((*returnSize) * sizeof(int));

    for(int i = 0; i < numsSize; i++) {
        ans[i] = nums[i];
    }

    for(int i = numsSize; i < *returnSize; i++) {
        ans[i] = nums[i - numsSize];
    }

    return ans;
}
```

## Complexity

**Time:** O(n) — every element is copied twice.

**Space:** O(n) — the result array contains `2n` elements.

## What I Learned

- `malloc()` can dynamically create an array whose size depends on the input.
- `*returnSize` stores the size of the returned array.
- A pointer returned from `malloc()` can be accessed like a normal array using `[]`.
- `i - numsSize` maps the second half of the result back to the beginning of `nums`.
- Learned how to use `returnSize` instead of repeatedly writing `2 * numsSize`.
- This problem reinforced the dynamic array technique learned from **Two Sum**.