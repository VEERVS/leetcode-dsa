## Problem

Given an integer `n`, return the minimum number of cuts needed to divide a circle into `n` equal slices.

A cut can either pass through the center of the circle or from the center to the edge.

## My Approach

I handled the problem using three cases:

- If `n == 1`, no cut is needed, so return `0`.
- If `n` is even, each cut through the center creates two slices, so the required cuts are `n / 2`.
- If `n` is odd and greater than `1`, `n` cuts are required.

Therefore:

- `n == 1` → `0`
- `n % 2 == 0` → `n / 2`
- Otherwise → `n`

## Key Logic

For an even number of slices, one diameter cut divides the circle into two equal parts.

So for `n` slices:

`n / 2` cuts are enough.

For an odd number of slices, diameter cuts always create an even number of regions, so we instead need `n` cuts from the center to the edge.

## Solution

```cpp
class Solution {
public:
    int numberOfCuts(int n) {
        if(n == 1) return 0;
        if(n % 2 == 0) return n / 2;
        return n;
    }
};
```

## Complexity

- Time: `O(1)`
- Space: `O(1)`

## What I Learned

- Mathematical observation can completely eliminate simulation.
- Even and odd cases can require completely different strategies.
- Understanding how one operation changes the number of regions is the key to solving this problem efficiently.