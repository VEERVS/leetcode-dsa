## Problem

Given positive integers `n` and `m`, calculate:

- `num1` → sum of all numbers from `1` to `n` that are **not divisible by `m`
- `num2` → sum of all numbers from `1` to `n` that **are divisible by `m`

Return:

```text
num1 - num2
```

Example:

```text
n = 10, m = 3

Not divisible by 3:
1 + 2 + 4 + 5 + 7 + 8 + 10 = 37

Divisible by 3:
3 + 6 + 9 = 18

Answer = 37 - 18 = 19
```

## My Approach

Use a single `for` loop from `1` to `n`.

For every number, check whether it is divisible by `m` using:

```c
i % m == 0
```

If it is divisible, add it to `sum2`.

Otherwise, add it to `sum1`.

Finally return:

```c
sum1 - sum2
```

## Key Logic

```c
if(i % m != 0) {
    sum1 += i;
} else {
    sum2 += i;
}
```

The `%` operator gives the remainder.

```text
i % m == 0 → divisible
i % m != 0 → not divisible
```

## Solution

```c
int differenceOfSums(int n, int m) {
    int sum1 = 0, sum2 = 0;

    for(int i = 1; i <= n; i++) {
        if(i % m != 0) {
            sum1 += i;
        } else {
            sum2 += i;
        }
    }

    return sum1 - sum2;
}
```

## Complexity

**Time:** O(n) — every number from `1` to `n` is checked once.

**Space:** O(1) — only two sum variables are used.

## What I Learned

- `%` can be used to check divisibility.
- A single loop can divide elements into two groups while processing them.
- `if-else` is useful when every value belongs to exactly one of two categories.
- This is a straightforward linear scan, so there is no need for extra data structures.