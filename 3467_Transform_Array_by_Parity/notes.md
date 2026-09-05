## Problem

Given an integer array `nums`, transform it using these operations in order:

1. Replace every even number with `0`.
2. Replace every odd number with `1`.
3. Sort the resulting array in non-decreasing order.

Return the transformed array.

## My Approach

I realized that after replacing the numbers based on parity, the array can contain only:

```text
0 and 1
```

So instead of actually sorting the array, I simply counted how many even and odd numbers there are.

- Every even number becomes `0`.
- Every odd number becomes `1`.

Since `0 < 1`, the sorted result must contain:

```text
all 0s first
then all 1s
```

So I filled the answer array directly using the counts.

## Key Logic

For every number:

```c
if(nums[i] % 2 == 0)
    even++;
else
    odd++;
```

Then:

```text
even numbers → 0
odd numbers  → 1
```

For example:

```text
nums = [4, 3, 2, 1]
```

There are:

```text
even = 2
odd = 2
```

Therefore, after transformation and sorting:

```text
[0, 0, 1, 1]
```

There is no need to call a sorting algorithm because we already know exactly what the sorted array must look like.

## Solution

```c
int* transformArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int even = 0, odd = 0;
    int* ans = malloc((*returnSize) * sizeof(int));

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    for(int i = 0; i < even; i++) {
        ans[i] = 0;
    }

    for(int i = even; i < even + odd; i++) {
        ans[i] = 1;
    }

    return ans;
}
```

## Complexity

- Time: `O(n)`
- Space: `O(n)` for the returned array.

## What I Learned

- When an operation reduces all values to only a few possible values, I don't necessarily need a sorting algorithm.
- Since the transformed values are only `0` and `1`, counting them is enough to construct the sorted result.
- This is similar to a counting-sort idea: count each value and place them directly.
- Parity can be checked easily using:

```c
nums[i] % 2 == 0
```

for even numbers.