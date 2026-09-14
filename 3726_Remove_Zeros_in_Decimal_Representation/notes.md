## Problem

Given a positive integer `n`, remove all zeros from its decimal representation and return the resulting integer.

For example:
- `1020030` → `123`
- `1` → `1`

## My Approach

I process the digits of `n` from right to left using `% 10` and `/ 10`.

Whenever the current digit is not zero, I append it to `sum` using:

`sum = (sum * 10) + digit`

Since the digits are extracted from right to left, this creates the remaining digits in reverse order.

After removing all zeros, I reverse `sum` again using another `% 10` and `/ 10` loop to obtain the correct final number.

## Key Logic

- `n % 10` extracts the last digit.
- `n /= 10` removes the last digit.
- If the digit is non-zero, add it to `sum`.
- Because digits are processed from right to left, `sum` is reversed.
- A second loop reverses `sum` to produce the final answer.

Example:

`1020030`

First pass:
- `0` → ignore
- `3` → `3`
- `0` → ignore
- `0` → ignore
- `2` → `32`
- `0` → ignore
- `1` → `321`

Second pass:

`321` → `123`

## Solution

```cpp
class Solution {
public:
    long long removeZeros(long long n) {
        long long sum = 0, ans = 0, temp = n;

        while (temp > 0) {
            if (temp % 10 != 0) {
                sum = (sum * 10) + (temp % 10);
            }
            temp /= 10;
        }

        while (sum > 0) {
            ans = (ans * 10) + (sum % 10);
            sum /= 10;
        }

        return ans;
    }
};
```

## Complexity

- Time: `O(log n)`
- Space: `O(1)`

## What I Learned

- `% 10` and `/ 10` are powerful tools for digit manipulation.
- When processing digits from right to left, the result may need to be reversed.
- Building a number using `ans = ans * 10 + digit` is a useful alternative to strings for digit problems.
- A place-value variable can sometimes allow the same task to be done in one pass.