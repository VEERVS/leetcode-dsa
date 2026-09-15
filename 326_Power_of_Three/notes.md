## Problem

Given an integer `n`, return `true` if it is a power of three. Otherwise, return `false`.

A number is a power of three if there exists an integer `x` such that:

`n = 3^x`

Examples:
- `27 = 3^3` → `true`
- `0` → `false`
- `-1` → `false`

## My Approach

I start with `i = 1`, which represents `3^0`.

I repeatedly multiply `i` by `3` until it becomes greater than or equal to `n`.

If `i == n`, then `n` is a power of three. Otherwise, it is not.

## Key Logic

Starting from `1`:

```text
1 → 3 → 9 → 27 → 81 → ...
```

For `n = 27`:

```text
i = 1
i = 3
i = 9
i = 27
```

Since `i == n`, the answer is `true`.

For `n = 20`:

```text
1 → 3 → 9 → 27
```

Since `27 > 20`, `20` is not a power of three.

## Solution

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        long long i = 1;

        while(i < n) {
            i *= 3;
        }

        return i == n;
    }
};
```

## Complexity

- Time: `O(log₃ n)`
- Space: `O(1)`

## What I Learned

- Powers can be checked by repeatedly multiplying from the base.
- Starting from `1` represents the zeroth power.
- `long long` helps prevent overflow while repeatedly multiplying.
- The same pattern works for checking powers of different bases.