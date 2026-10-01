## Problem

Given a positive integer `n`, return the smallest number `x` greater than or equal to `n` such that the binary representation of `x` contains only set bits (`1`s).

For example:

```text
n = 5
5 = 101
7 = 111
```

So the answer is `7`.

## My Approach

I use a bitwise OR propagation technique.

The goal is to turn every bit to the right of the highest set bit into `1`.

I repeatedly shift `n` to the right and OR it back into itself:

```cpp
n |= (n >> 1);
n |= (n >> 2);
n |= (n >> 4);
n |= (n >> 8);
n |= (n >> 16);
```

This gradually fills all lower bit positions with `1`.

For example, with:

```text
n = 5 = 101
```

After the first operation:

```text
101
001
---
101
```

After the next:

```text
101
001
---
101
```

For a value such as `10 = 1010`, the operations eventually produce:

```text
1111
```

which is the smallest number greater than or equal to `10` containing only set bits.

## Key Logic

The important operation is:

```cpp
n |= n >> k;
```

The right shift moves existing set bits toward the right, and OR combines them with the original number.

Repeated shifts of powers of two:

```text
1, 2, 4, 8, 16
```

ensure that all positions below the highest set bit become `1`.

For example:

```text
10 = 1010

1010
0101
----
1111
```

So the result becomes:

```text
15 = 1111
```

This is exactly the smallest all-ones binary number that is at least `10`.

## Solution

```cpp
class Solution {
public:
    int smallestNumber(int n) {
        n |= (n >> 1);
        n |= (n >> 2);
        n |= (n >> 4);
        n |= (n >> 8);
        n |= (n >> 16);

        return n;
    }
};
```

## Complexity

- Time: O(1)
- Space: O(1)

There are only a fixed number of bitwise operations for a 32-bit integer.

## What I Learned

- Bitwise OR can be used to propagate set bits.
- `n >> k` moves bits toward the right.
- Repeated `n |= n >> k` operations can turn all lower bits into `1`.
- A number containing only set bits has binary form like `1`, `11`, `111`, `1111`, etc.