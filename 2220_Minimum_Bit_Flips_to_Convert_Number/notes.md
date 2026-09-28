## Problem

Given two integers `start` and `goal`, return the minimum number of bit flips required to convert `start` into `goal`.

A bit flip changes a bit from `0` to `1` or from `1` to `0`.

Example:

```text
start = 10 = 1010
goal  = 7  = 0111
```

The bits that are different are:

```text
1010
0111
----
1101
```

There are `3` different bits, so the answer is `3`.

## My Approach

I first use XOR between `start` and `goal`.

```cpp
int diff = start ^ goal;
```

XOR produces:

```text
Same bits      → 0
Different bits → 1
```

Therefore, every `1` in `diff` represents a bit that needs to be flipped.

Then I count the number of `1`s using:

```cpp
diff = diff & (diff - 1);
```

This removes the lowest set bit each time.

## Key Logic

First:

```cpp
int diff = start ^ goal;
```

For example:

```text
start = 1010
goal  = 0111

1010
0111
----
1101
```

So:

```text
diff = 1101
```

Every `1` means the corresponding bits are different.

Then:

```cpp
diff = diff & (diff - 1);
```

removes one `1` bit.

For:

```text
1101
```

we get:

```text
1101 & 1100 = 1100
```

Then:

```text
1100 → 1000 → 0000
```

There were three `1`s, so the answer is `3`.

## Solution

```cpp
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int diff = start ^ goal;

        while(diff != 0) {
            diff = diff & (diff - 1);
            count++;
        }

        return count;
    }
};
```

## Complexity

- **Time:** `O(k)`, where `k` is the number of different bits.
- **Worst-case Time:** `O(log n)`
- **Space:** `O(1)`

The loop runs once for every set bit in `diff`.

## What I Learned

- XOR is useful for finding differences between two numbers.
- `start ^ goal` produces `1` exactly where the two numbers have different bits.
- `n & (n - 1)` removes the lowest set bit.
- Combining XOR with `n & (n - 1)` gives a clean way to count differing bits.
- The minimum number of flips is simply the number of differing bit positions.