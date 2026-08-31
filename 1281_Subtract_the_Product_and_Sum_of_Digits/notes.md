## Problem

Given an integer `n`, return the difference between the product of its digits and the sum of its digits.

Example:

```text
n = 234

Product = 2 × 3 × 4 = 24
Sum = 2 + 3 + 4 = 9

Answer = 24 - 9 = 15
```

## My Approach

Use a temporary variable `temp` to process the digits one by one.

Extract the last digit using `% 10`, add it to `sum`, multiply it into `prod`, and then remove the last digit using `/ 10`.

Continue until `temp` becomes `0`.

## Key Logic

```c
digit = temp % 10;
prod *= digit;
sum += digit;
temp /= 10;
```

For example, with `234`:

```text
234 % 10 → 4
23  % 10 → 3
2   % 10 → 2
```

So every digit is processed exactly once.

## Solution

```c
int subtractProductAndSum(int n) {
    int prod = 1, sum = 0, temp = n, digit;

    while(temp != 0) {
        digit = temp % 10;
        prod *= digit;
        sum += digit;
        temp /= 10;
    }

    return prod - sum;
}
```

## Complexity

Time: O(log n)

Space: O(1)

## What I Learned

- `% 10` extracts the last digit.
- `/ 10` removes the last digit.
- A temporary variable lets me process the number without changing the original `n`.
- `prod` starts at `1` because multiplication needs an identity value.
- `sum` starts at `0` because addition needs an identity value.