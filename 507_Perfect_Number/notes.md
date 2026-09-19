## Problem

Given a positive integer `num`, determine whether it is a perfect number.

A perfect number is a positive integer that is equal to the sum of all its positive divisors excluding itself.

For example:

`28 = 1 + 2 + 4 + 7 + 14`

Therefore, `28` is a perfect number.

## My Approach

I loop from `1` to `num / 2`.

For every number `i`, I check whether it divides `num` exactly using:

`num % i == 0`

If it is a divisor, I add it to `sum`.

After checking all possible proper divisors, I compare `sum` with `num`.

If they are equal, the number is perfect.

## Key Logic

The number itself should not be included in the divisor sum.

Also, no proper divisor of `num` can be greater than `num / 2`.

For example, for `num = 28`:

- `1` → divisor
- `2` → divisor
- `4` → divisor
- `7` → divisor
- `14` → divisor

So:

`1 + 2 + 4 + 7 + 14 = 28`

Therefore, `28` is a perfect number.

## Solution

```cpp
class Solution {
public:
    bool checkPerfectNumber(int num) {
        long long sum = 0;

        for(int i = 1; i <= num / 2; i++) {
            if(num % i == 0) {
                sum += i;
            }
        }

        return sum == num;
    }
};
```

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## What I Learned

- `%` can be used to check whether one number is a divisor of another.
- Proper divisors of `num` cannot be greater than `num / 2`.
- The divisor sum can be accumulated in one pass.
- This approach can be optimized further by checking divisor pairs only up to `sqrt(num)`.