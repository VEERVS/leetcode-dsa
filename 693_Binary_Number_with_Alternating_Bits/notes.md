## Problem

Given a positive integer `n`, check whether its binary representation has alternating bits.

This means every pair of adjacent bits must be different.

Example:

`n = 5`

Binary:

`101`

The bits alternate, so the answer is `true`.

## My Approach

I process the binary number from right to left.

For every iteration:

1. Get the current last bit using `n & 1`.
2. Shift `n` right by one position.
3. Get the next bit using `n & 1`.
4. Compare the two bits using XOR.

If two adjacent bits are the same:

```cpp
next ^ last == 0
```

then the number does not have alternating bits, so I return `false`.

If the entire number is processed without finding equal adjacent bits, I return `true`.

## Key Logic

The important operations are:

```cpp
n & 1
```

Gets the last bit.

```cpp
n >> 1
```

Moves to the next bit.

```cpp
next ^ last
```

XOR gives:

```text
Different bits → 1
Same bits      → 0
```

So if:

```cpp
(next ^ last) == 0
```

the two adjacent bits are equal.

Example:

```text
n = 5

Binary = 101

1 ^ 0 = 1  → different
0 ^ 1 = 1  → different

Therefore → true
```

## Solution

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n != 0) {
            int last = n & 1;
            n = n >> 1;
            int next = n & 1;

            if(next ^ last == 0) {
                return false;
            }
        }

        return true;
    }
};
```

## Complexity

- **Time:** `O(log n)`
- **Space:** `O(1)`

We process each bit once, and an integer has `O(log n)` bits.

## What I Learned

- `n & 1` can extract the last bit.
- `n >> 1` moves to the next bit.
- XOR can be used to compare two bits.
- `a ^ b == 0` means `a` and `b` are equal.
- `a ^ b == 1` means the two bits are different.
- Bit manipulation can be used to inspect a binary representation without converting it to a string.