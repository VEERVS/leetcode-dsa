## Problem

Given a positive integer `n`, calculate:

- The **digit sum** of `n`.
- The **digit product** of `n`.

Return `true` if `n` is divisible by the sum of these two values.

Otherwise, return `false`.

## My Approach

I used a temporary variable `temp` to process every digit of `n`.

For each digit:

- Add it to `sum`.
- Multiply it into `prod`.

I extract the digit using `% 10` and remove it using `/ 10`.

After calculating both values, I check:

```cpp
n % (sum + prod) == 0
```

## Key Logic

For:

```text
n = 99
```

The digit sum is:

```text
9 + 9 = 18
```

The digit product is:

```text
9 × 9 = 81
```

Therefore:

```text
sum + prod = 18 + 81 = 99
```

Since:

```text
99 % 99 = 0
```

the answer is `true`.

The important digit-processing pattern is:

```cpp
int digit = temp % 10;
temp /= 10;
```

## Solution

```cpp
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1, temp = n;

        while(temp != 0) {
            sum += temp % 10;
            prod *= temp % 10;
            temp /= 10;
        }

        return n % (sum + prod) == 0;
    }
};
```

## Complexity

**Time:** `O(log n)`

**Space:** `O(1)`

## What I Learned

- `% 10` and `/ 10` can be used to process every digit.
- Multiple properties of digits can be calculated in the same loop.
- A boolean condition can be returned directly instead of using `if-else`.
- Initializing a product accumulator with `1` is important because `1` is the multiplicative identity.