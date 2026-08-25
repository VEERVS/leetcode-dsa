## Problem

Given a signed 32-bit integer `x`, return its digits reversed. If the reversed number goes outside the 32-bit signed integer range, return `0`.

Examples:

```text
123 → 321
-123 → -321
120 → 21
```

## My Approach

The basic idea was to extract the last digit using `% 10`, add it to `rev`, and remove the digit using `/ 10`.

```c
rev = rev * 10 + (x % 10);
x /= 10;
```

However, the problem does **not** allow using a 64-bit integer, so `rev` must remain an `int`. This means overflow has to be detected **before** performing `rev * 10 + digit`. :contentReference[oaicite:1]{index=1}

## Key Logic

```text
digit = x % 10
x = x / 10
rev = rev * 10 + digit
```

The important part is checking whether `rev` is safe before multiplying it by `10`.

I learned about `<limits.h>` and used:

```c
INT_MAX
INT_MIN
```

instead of manually writing the 32-bit limits.

## Trial & Error

My first version directly did:

```c
rev = (rev * 10) + (x % 10);
```

This caused a runtime error because the multiplication itself overflowed before I could check the result.

I initially tried checking the overflow **after** the calculation, but that was too late.

The important realization was:

> **Check for overflow before `rev * 10 + digit` happens.**

I also initially used `&&` for the upper and lower limits, but a value cannot be greater than `INT_MAX` and less than `INT_MIN` at the same time. The checks need to handle either type of overflow.

## Solution

```c
#include <limits.h>

int reverse(int x) {
    int rev = 0;

    while(x != 0) {
        if(rev > INT_MAX / 10 || rev < INT_MIN / 10) {
            return 0;
        }

        rev = (rev * 10) + (x % 10);
        x /= 10;
    }

    return rev;
}
```

## Complexity

**Time:** O(log n)

Each iteration removes one digit from `x`.

**Space:** O(1)

Only a few integer variables are used.

## What I Learned

- `% 10` extracts the last digit.
- `/ 10` removes the last digit.
- Integer overflow must be prevented **before** the dangerous operation.
- `<limits.h>` provides `INT_MAX` and `INT_MIN`.
- `&&` vs `||` matters when checking ranges.
- A runtime error can reveal a problem that normal test cases might not expose.