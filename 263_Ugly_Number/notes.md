## Problem

An ugly number is a positive integer whose only prime factors are `2`, `3`, and `5`.

Given an integer `n`, return `true` if `n` is an ugly number, otherwise return `false`.

Examples:
- `6 = 2 × 3` → `true`
- `1` → `true`
- `14 = 2 × 7` → `false` because `7` is not an allowed prime factor.

## My Approach

I repeatedly divided `n` by the allowed prime factors `2`, `3`, and `5`.

For each prime:
- While `n` is divisible by that prime, divide `n` by it.
- After removing all factors of `2`, `3`, and `5`, check the remaining value.

If the remaining value becomes `1`, then `n` had no prime factors other than `2`, `3`, and `5`.

Otherwise, some other prime factor exists, so the number is not ugly.

## Key Logic

```cpp
for(int prime : {2, 3, 5}) {
    while(n % prime == 0) {
        n /= prime;
    }
}

return n == 1;
```

Example: `n = 30`

- Divide by `2` → `15`
- Divide by `3` → `5`
- Divide by `5` → `1`

Final value is `1`, so `30` is ugly.

Example: `n = 14`

- Divide by `2` → `7`
- `7` cannot be divided by `3` or `5`
- Final value = `7`

Since `7 != 1`, `14` is not ugly.

## Solution

```cpp
class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) {
            return false;
        }

        for(int prime : {2, 3, 5}) {
            while(n % prime == 0) {
                n /= prime;
            }
        }

        return n == 1;
    }
};
```

## Complexity

- Time: `O(log n)`
- Space: `O(1)`

## What I Learned

- Repeated division can be used to remove specific prime factors.
- If all factors `2`, `3`, and `5` are removed and the result is `1`, the number is ugly.
- `n <= 0` cannot be an ugly number.
- `1` is considered an ugly number because it has no prime factors.
- Range-based `for` loops can be used to iterate through a fixed set of values.