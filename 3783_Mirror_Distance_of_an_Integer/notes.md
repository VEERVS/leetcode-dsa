## Problem

Given an integer `n`, calculate its **mirror distance**:

```text
abs(n - reverse(n))
```

where `reverse(n)` is the integer formed by reversing its digits.

Example:

```text
n = 25
reverse(25) = 52

abs(25 - 52) = 27
```

## My Approach

Use the same digit-reversal technique learned from **Reverse Integer**.

Extract the last digit using `% 10`, add it to `rev`, and remove it from `temp` using `/ 10`.

After reversing the number, calculate the absolute difference between the original number and the reversed number.

## Key Logic

```c
rev = (rev * 10) + (temp % 10);
temp /= 10;
```

For `25`:

```text
25 → 5 → 2
rev = 5 → 52
```

Then:

```c
abs(n - rev)
```

gives the mirror distance.

## Solution

```c
#include <math.h>

int mirrorDistance(int n) {
    int rev = 0, temp = n;

    while(temp != 0) {
        rev = (rev * 10) + (temp % 10);
        temp /= 10;
    }

    return abs(n - rev);
}
```

## Complexity

**Time:** O(log n) — each digit is processed once.

**Space:** O(1) — only a few variables are used.

## What I Learned

- Reused the digit-reversal pattern from **LeetCode 7**.
- `% 10` extracts the last digit.
- `/ 10` removes the last digit.
- `rev * 10 + digit` builds the reversed number.
- `abs()` gives the positive difference between two values.
- Recognizing a pattern from an earlier problem makes new problems much easier.