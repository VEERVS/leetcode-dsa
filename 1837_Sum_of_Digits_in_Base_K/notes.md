## Problem

Given an integer `n` in base 10 and a base `k`, return the sum of the digits of `n` after converting `n` from base 10 to base `k`.

For example:
- `34` in base `6` = `54`
- Sum of digits = `5 + 4 = 9`

## My Approach

I used the standard base-conversion technique without actually storing the converted number.

For every step:
- `n % k` gives the last digit of `n` in base `k`.
- Add that digit to `sum`.
- `n /= k` removes that digit.
- Repeat until `n` becomes `0`.

This directly calculates the sum of the digits in base `k`.

## Key Logic

```cpp
sum += n % k;
n /= k;
```

`n % k` extracts the current digit in base `k`, while `n /= k` removes that digit.

For `n = 34, k = 6`:

- `34 % 6 = 4` → sum = 4
- `34 / 6 = 5`
- `5 % 6 = 5` → sum = 9
- `5 / 6 = 0`

Answer = `9`.

## Solution

```cpp
class Solution {
public:
    int sumBase(int n, int k) {
        int sum = 0;

        while(n > 0) {
            sum += n % k;
            n /= k;
        }

        return sum;
    }
};
```

## Complexity

- Time: `O(logₖ n)`
- Space: `O(1)`

## What I Learned

- `% k` extracts a digit when converting a number to base `k`.
- `/ k` removes the last digit in that base.
- We don't need to actually construct the converted number when we only need the digit sum.
- The same `%` and `/` pattern used for decimal digit problems works for any base.