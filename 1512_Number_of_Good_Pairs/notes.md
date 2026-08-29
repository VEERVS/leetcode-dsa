## Problem

Given an integer array `nums`, count the number of **good pairs**.

A pair `(i, j)` is good when:

```text
i < j
nums[i] == nums[j]
```

Example:

```text
nums = [1,2,3,1,1,3]

Good pairs:
(0,3)
(0,4)
(3,4)
(2,5)

Answer = 4
```

## My Approach

My first thought was to check every possible pair using two nested loops.

That works, but takes **O(n²)** time.

The optimized idea is to use **frequency counting**.

Instead of checking every previous index, keep track of how many times each value has already appeared.

If the current number has appeared `k` times before, the current number forms exactly `k` new good pairs.

## Key Logic

```c
count += freq[nums[i]];
freq[nums[i]]++;
```

For:

```text
nums = [1,2,1,1]
```

The occurrences of `1` work like:

```text
1st 1 → 0 previous → +0 pairs
2nd 1 → 1 previous → +1 pair
3rd 1 → 2 previous → +2 pairs
```

Total:

```text
0 + 1 + 2 = 3
```

This is also the mathematical combination:

```text
kC2 = k(k - 1) / 2
```

So frequency counting and the mathematical approach are based on the same idea.

## Frequency Array

Since the values in the problem are limited to `0–100`, a frequency array can be used:

```c
int freq[101] = {0};
```

Here:

```text
freq[value] = number of times that value has appeared
```

For example:

```text
nums = [1,2,1,3,2,1]

freq[1] = 3
freq[2] = 2
freq[3] = 1
```

## Solution

```c
int numIdenticalPairs(int* nums, int numsSize) {
    int freq[101] = {0};
    int count = 0;

    for(int i = 0; i < numsSize; i++) {
        count += freq[nums[i]];
        freq[nums[i]]++;
    }

    return count;
}
```

## Complexity

**Time:** O(n) — one pass through the array.

**Space:** O(1) — the frequency array has a fixed size of 101.

## What I Learned

- When a problem involves **equal values**, think about frequency.
- `freq[value]` tells how many times a value has appeared.
- Each previous occurrence creates one new pair with the current occurrence.
- `count += freq[nums[i]]` counts those new pairs directly.
- If a value occurs `k` times, the total number of pairs is `k(k-1)/2`.
- Frequency counting can turn a pair-checking problem from O(n²) into O(n).
- This is an important pattern for problems involving duplicates, pairs, and occurrences.