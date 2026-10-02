## Problem

Given two integers `x` and `y`, return their Hamming distance.

The Hamming distance is the number of positions where the corresponding bits of the two numbers are different.

For example:

```text
x = 1 = 0001
y = 4 = 0100

        ↑  ↑
        different bits

Hamming distance = 2
```

## My Approach

I first use XOR between `x` and `y`:

```cpp
int dist = x ^ y;
```

XOR gives `1` exactly at the positions where the corresponding bits of `x` and `y` are different.

Then I count the number of set bits in the XOR result using:

```cpp
__builtin_popcount(dist)
```

Therefore, the number of set bits in `x ^ y` is exactly the Hamming distance.

## Key Logic

The important observation is:

```cpp
x ^ y
```

XOR behaves like this for each bit:

```text
0 ^ 0 = 0
1 ^ 1 = 0
0 ^ 1 = 1
1 ^ 0 = 1
```

So:

```text
XOR = 1 → bits are different
XOR = 0 → bits are the same
```

For example:

```text
x = 1 → 0001
y = 4 → 0100

     0001
XOR  0100
     ----
     0101
```

There are two set bits in `0101`, so the Hamming distance is `2`.

Thus:

```cpp
__builtin_popcount(x ^ y)
```

directly gives the answer.

## Solution

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = x ^ y;
        return __builtin_popcount(dist);
    }
};
```

## Complexity

- Time: O(1)
- Space: O(1)

The integers have a fixed number of bits, so the bit operations and popcount operate on a fixed-width integer.

## What I Learned

- XOR is useful for finding positions where two numbers differ.
- `x ^ y` produces `1` exactly at the differing bit positions.
- Counting the set bits of `x ^ y` gives the Hamming distance.
- This combines two important bitwise weapons:

```text
XOR → find differences
popcount → count set bits
```