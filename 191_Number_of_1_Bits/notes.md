## Problem

Given a positive integer `n`, return the number of `1` bits in its binary representation.

For example:

```text
n = 11
Binary = 1011
Answer = 3
```

## My Approach

I used the bit manipulation trick:

```cpp
n & (n - 1)
```

This removes the **lowest set bit (`1`)** from `n`.

So I keep removing one `1` bit at a time and increment `count`.

```cpp
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while(n != 0) {
            n = n & (n - 1);
            count++;
        }

        return count;
    }
};
```

## Key Logic

The main trick is:

```cpp
n & (n - 1)
```

It removes the rightmost `1` bit.

For example:

```text
n     = 1011
n - 1 = 1010

1011
1010
----
1010
```

One `1` has been removed.

Then:

```text
1010 & 1001 = 1000
1000 & 0111 = 0000
```

We removed three `1` bits, so the answer is `3`.

Important bit operations learned:

```text
n & 1           → check the last bit
n >> 1          → shift bits right
n << 1          → shift bits left
n & (n - 1)     → remove the lowest 1-bit
```

## Solution

```cpp
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while(n != 0) {
            n = n & (n - 1);
            count++;
        }

        return count;
    }
};
```

## Complexity

- **Time:** `O(k)`, where `k` is the number of set bits.
- **Worst-case Time:** `O(log n)`
- **Space:** `O(1)`

The loop runs once for every `1` bit instead of checking every bit individually.

## What I Learned

- A **set bit** is a bit whose value is `1`.
- `n & (n - 1)` removes the lowest set bit.
- This is a useful technique for counting or processing `1` bits.
- Bit manipulation can solve some problems using very little code and `O(1)` extra space.
- `while(n != 0)` naturally stops once all the `1` bits have been removed.