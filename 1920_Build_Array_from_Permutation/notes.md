## Problem

Given a zero-based permutation `nums`, construct an array `ans` of the same length such that:

```text
ans[i] = nums[nums[i]]
```

for every valid index `i`.

## My Approach

I directly followed the definition of the problem.

For every index `i`, I first look at:

```c
nums[i]
```

This value itself becomes the index of the element we need:

```c
nums[nums[i]]
```

I stored that value in `ans[i]`.

For example:

```text
nums = [0, 2, 1, 5, 3, 4]
```

For `i = 1`:

```text
nums[1] = 2
ans[1] = nums[2] = 1
```

Repeating this for every index gives:

```text
ans = [0, 1, 2, 4, 5, 3]
```

## Key Logic

The main thing to understand is the **double indexing**:

```c
nums[nums[i]]
```

The inner `nums[i]` gives us an index.

Then the outer `nums[...]` accesses the value at that index.

## Solution

```c
int* buildArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int *ans = malloc((*returnSize) * sizeof(int));

    for(int i = 0; i < numsSize; i++) {
        ans[i] = nums[nums[i]];
    }

    return ans;
}
```

## Complexity

- Time: `O(n)`
- Space: `O(n)` for the returned array.

## What I Learned

- Array indexing can be nested: `nums[nums[i]]`.
- When LeetCode asks for an array to be returned in C, I need to dynamically allocate it using `malloc`.
- The `returnSize` parameter tells LeetCode how many elements are in the returned array.