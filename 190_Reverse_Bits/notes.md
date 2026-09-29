## Problem

Reverse the bits of a given 32-bit unsigned integer.

For example, the binary representation of the number is reversed bit-by-bit and the resulting 32-bit integer is returned.

## My Approach

I process exactly 32 bits because the problem specifically works with a 32-bit integer.

For every bit:
1. Extract the last bit using `n & 1`.
2. Shift `ans` left to make space for the new bit.
3. Insert the extracted bit using `|`.
4. Shift `n` right to process the next bit.

The important line is:

```cpp
ans = (ans << 1) | last;
```

This takes the extracted bit from `n` and adds it to the right side of the reversed result.

## Key Logic

```cpp
int last = n & 1;
```

Extracts the rightmost bit.

```cpp
ans = (ans << 1) | last;
```

Shifts the current answer left and places `last` at the new rightmost position.

```cpp
n >>= 1;
```

Removes the bit we just processed.

We repeat this exactly 32 times because leading zeroes are also part of the 32-bit representation.

## Solution

```cpp
class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;

        for(int i = 0; i < 32; i++) {
            int last = n & 1;
            ans = (ans << 1) | last;
            n >>= 1;
        }

        return ans;
    }
};
```

## Complexity

- Time: O(32) = O(1)
- Space: O(1)

## What I Learned

- `n & 1` extracts the last bit.
- `n >> 1` removes the last bit.
- `ans << 1` creates space for a new bit.
- `|` can insert a bit into the result.
- For fixed-size bit problems, processing exactly 32 bits is important.