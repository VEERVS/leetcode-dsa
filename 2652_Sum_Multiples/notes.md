## Problem

Given an integer `n`, return the sum of all integers in the range `[1, n]` that are divisible by `3`, `5`, or `7`.

## My Approach

My first approach was to loop from `1` to `n` and check:

```c
if(i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
```

This works in **O(n)**.

Then I looked for a mathematical way to avoid checking every number.

For multiples of a number `x`:

```text
x, 2x, 3x, ..., kx
```

where:

```text
k = n / x
```

Using the arithmetic series formula:

```text
1 + 2 + ... + k = k(k + 1) / 2
```

the sum of multiples of `x` becomes:

```text
x × k(k + 1) / 2
```

This lets us calculate each group directly in **O(1)**.

## Key Logic

For `3`, `5`, and `7`:

```text
k1 = n / 3
k2 = n / 5
k3 = n / 7
```

Then calculate:

```text
s1 = 3  × k1(k1 + 1) / 2
s2 = 5  × k2(k2 + 1) / 2
s3 = 7  × k3(k3 + 1) / 2
```

But some numbers are counted more than once.

## Inclusion-Exclusion

Numbers divisible by two of the values are counted twice:

```text
15 → divisible by 3 and 5
21 → divisible by 3 and 7
35 → divisible by 5 and 7
```

So subtract their sums.

However, numbers divisible by **all three** (`3`, `5`, and `7`) get subtracted too many times.

The smallest common multiple is:

```text
3 × 5 × 7 = 105
```

So multiples of `105` must be added back.

The pattern is:

```text
+ multiples of 3, 5, 7
- multiples of 15, 21, 35
+ multiples of 105
```

For example, `105` is initially counted 3 times, then subtracted 3 times, so adding it back makes it counted exactly once.

## Solution

```c
int sumOfMultiples(int n) {
    int k1 = n / 3, k2 = n / 5, k3 = n / 7;
    int k4 = n / 15, k5 = n / 21, k6 = n / 35, k7 = n / 105;

    int s1 = 3 * (k1 * (k1 + 1) / 2);
    int s2 = 5 * (k2 * (k2 + 1) / 2);
    int s3 = 7 * (k3 * (k3 + 1) / 2);

    int s4 = 15 * (k4 * (k4 + 1) / 2);
    int s5 = 21 * (k5 * (k5 + 1) / 2);
    int s6 = 35 * (k6 * (k6 + 1) / 2);
    int s7 = 105 * (k7 * (k7 + 1) / 2);

    return (s1 + s2 + s3) - (s4 + s5 + s6) + s7;
}
```

## Complexity

**Time:** O(1)  
**Space:** O(1)

The optimized solution performs a fixed number of calculations regardless of the size of `n`.

## What I Learned

- A brute-force O(n) solution can sometimes be replaced completely by mathematics.
- `k = n / x` gives the number of multiples of `x` up to `n`.
- Arithmetic series formula: `k(k + 1) / 2`.
- `k(k + 1)` is always even, so integer division by `2` is safe.
- Inclusion-exclusion prevents duplicate counting.
- For three groups: **add → subtract pair overlaps → add triple overlap**.
- This problem showed how mathematical knowledge can turn an O(n) solution into O(1).