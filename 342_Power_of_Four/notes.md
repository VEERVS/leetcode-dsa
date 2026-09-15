## Problem

Given an integer `n`, return `true` if it is a power of four. Otherwise, return `false`.

A number is a power of four if there exists an integer `x` such that:

`n = 4^x`

Examples:
- `16 = 4^2` → `true`
- `5` → `false`
- `1 = 4^0` → `true`

## My Approach

I start with `i = 1`, representing `4^0`.

I repeatedly multiply `i` by `4` until it becomes greater than or equal to `n`.

Finally, I check whether `i` is exactly equal to `n`.

## Key Logic

The powers of four are:

```text
1 → 4 → 16 → 64 → 256 → ...
```

For `n = 16`:

```text
i = 1
i = 4
i = 16
```

Since `i == n`, return `true`.

For `n = 5`:

```text
1 → 4 → 16
```

Now `16 > 5`, so `5` is not a power of four.

## Solution

```cpp
class Solution {
public:
    bool isPowerOfFour(int n) {
        long long i = 1;

        while(i < n) {
            i *= 4;
        }

        return i == n;
    }
};
```

## Complexity

- Time: `O(log₄ n)`
- Space: `O(1)`

## What I Learned

- The power-checking pattern can be generalized to any positive base.
- `1` is important because it represents the zeroth power.
- Comparing after the loop avoids needing a separate exact-match condition inside the loop.
- Power problems can later be optimized using bit manipulation and mathematical properties.