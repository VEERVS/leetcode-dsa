## Problem

Given an integer array `nums`, calculate its **alternating sum**.

The alternating sum is:

```text
nums[0] - nums[1] + nums[2] - nums[3] + ...
```

Elements at **even indices** are added, while elements at **odd indices** are subtracted.

Example:

```text
nums = [1,3,5,7]

1 - 3 + 5 - 7 = -4
```

## My Approach

Traverse the array using a `for` loop.

For every index, check whether the index is even or odd using:

```c
i % 2 == 0
```

- Even index → add `nums[i]`
- Odd index → subtract `nums[i]`

## Key Logic

```c
if(i % 2 == 0) {
    sum += nums[i];
} else {
    sum -= nums[i];
}
```

Since array indexing starts from `0`, the pattern naturally becomes:

```text
Index:  0   1   2   3   4
        +   -   +   -   +
```

## Solution

```c
int alternatingSum(int* nums, int numsSize) {
    int sum = 0;

    for(int i = 0; i < numsSize; i++) {
        if(i % 2 == 0) {
            sum += nums[i];
        } else {
            sum -= nums[i];
        }
    }

    return sum;
}
```

## Complexity

**Time:** O(n) — every element is processed once.

**Space:** O(1) — only the `sum` variable is used.

## What I Learned

- Array indices start from `0`.
- `% 2` can be used to check whether an index is even or odd.
- Even indices can be processed with addition and odd indices with subtraction.
- A simple condition inside a single loop can handle alternating operations efficiently.
- This is another example of solving an array problem with a simple linear scan.