## Problem

Given an integer array `nums` of length `n`, create an array `ans` of length `2 * n` such that the first `n` elements are the same as `nums` and the next `n` elements contain `nums` in reverse order.

Example:

```text
nums = [1,2,3]

ans = [1,2,3,3,2,1]
```

## My Approach

First allocate memory for `2 * numsSize` integers using `malloc()`.

Set:

```c
*returnSize = 2 * numsSize;
```

Then use two loops:

1. Copy `nums` normally into the first half.
2. Copy `nums` in reverse order into the second half.

## Key Logic

First half:

```c
ans[i] = nums[i];
```

For the reversed half:

```c
ans[i] = nums[(*returnSize) - i - 1];
```

For `nums = [1,2,3]`:

```text
i = 3 → nums[6 - 3 - 1] = nums[2] = 3
i = 4 → nums[6 - 4 - 1] = nums[1] = 2
i = 5 → nums[6 - 5 - 1] = nums[0] = 1
```

So:

```text
[1,2,3,3,2,1]
```

## Solution

```c
int* concatWithReverse(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2 * numsSize;

    int *ans = malloc((*returnSize) * sizeof(int));

    for(int i = 0; i < numsSize; i++) {
        ans[i] = nums[i];
    }

    for(int i = numsSize; i < *returnSize; i++) {
        ans[i] = nums[(*returnSize) - i - 1];
    }

    return ans;
}
```

## Complexity

**Time:** O(n) — every element is copied twice.

**Space:** O(n) — a new array of size `2n` is allocated.

## What I Learned

- `malloc()` dynamically allocates memory for the result array.
- `*returnSize` stores the size of the returned array.
- The source and destination indices can move in different directions.
- `(*returnSize) - i - 1` lets us access the original array from the last element to the first.
- A small indexing change can make the difference between normal and reversed copying.
- This reinforced the dynamic-array and `malloc()` concepts learned from **Two Sum** and **Concatenation of Array**.