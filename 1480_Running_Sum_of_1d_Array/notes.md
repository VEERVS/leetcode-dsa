## Problem

Given an integer array `nums`, create a running sum array where:

```text
runningSum[i] = nums[0] + nums[1] + ... + nums[i]
```

Return the resulting array.

## My Approach

I used a separate `sum` variable to keep track of the running total.

For every element:
1. Add `nums[i]` to `sum`.
2. Store the updated `sum` in `ans[i]`.

Since LeetCode requires the returned array to be dynamically allocated, I used `malloc()`.

## Key Logic

```c
sum += nums[i];
ans[i] = sum;
```

For example:

```text
nums = [1, 2, 3, 4]

i = 0 → sum = 1  → ans[0] = 1
i = 1 → sum = 3  → ans[1] = 3
i = 2 → sum = 6  → ans[2] = 6
i = 3 → sum = 10 → ans[3] = 10

ans = [1, 3, 6, 10]
```

## Solution

```c
int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int sum = 0;
    int *ans = malloc((*returnSize) * sizeof(int));

    for(int i = 0; i < numsSize; i++) {
        sum += nums[i];
        ans[i] = sum;
    }

    return ans;
}
```

## Complexity

Time: O(n)

Space: O(n)

The `ans` array requires O(n) space because we need to return a new array.

## What I Learned

- A running sum can be maintained using one variable instead of repeatedly calculating the sum from the beginning.
- `sum += nums[i]` keeps the cumulative total.
- `returnSize` tells LeetCode the size of the dynamically allocated returned array.
- `malloc()` is required because the returned array must remain valid after the function finishes.
- This is a basic example of the **prefix sum** pattern, which will become very useful in harder array problems.