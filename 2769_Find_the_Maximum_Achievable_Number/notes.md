## Problem

Given two integers `num` and `t`, a number `x` is achievable if it can become equal to `num` after applying an operation at most `t` times.

In each operation, we can increase or decrease both `x` and `num` by `1`.

Return the maximum possible value of `x`.

## My Approach

I looked at how one operation affects the difference between `x` and `num`.

To make `x` as large as possible, we should:
- increase `x` by `1`
- decrease `num` by `1`

This closes the gap by `2`.

After `t` operations, `x` can therefore be `2 * t` greater than `num`.

So:

`answer = num + 2 * t`

## Key Logic

Each operation can increase the maximum achievable value of `x` by `2`.

For example:

```text
num = 4, t = 1

x = 6
```

Apply one operation:

```text
x:   6 → 5
num: 4 → 5
```

Now they are equal.

Therefore, the maximum is:

```text
num + 2 * t
```

## Solution

```c
int theMaximumAchievableX(int num, int t) {
    return num + t + t;
}
```

## Complexity

- Time: `O(1)`
- Space: `O(1)`

## What I Learned

- Sometimes the best solution comes from analyzing how an operation changes the **difference between two values**.
- I derived the formula instead of simulating the operations.
- `num + t + t` is simply `num + 2 * t`.