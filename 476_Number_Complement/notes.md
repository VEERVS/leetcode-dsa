## Problem

Given an integer `num`, return its binary complement.

The complement is obtained by flipping all `0`s to `1`s and all `1`s to `0`s in the binary representation.

Example:

```text
num = 5
Binary = 101
Complement = 010
Answer = 2
```

## My Approach

I use the same masking technique as the complement problem.

The `~` operator flips all bits of the integer, so I create a mask containing `1`s only for the meaningful bits of `num`.

For example:

```text
num = 5 = 101
mask = 111
```

Then:

```cpp
(~original) & mask
```

keeps only the relevant complemented bits.

I also handle `num = 0` separately.

## Key Logic

First:

```cpp
if(num == 0) return 1;
```

Then save the original value because `num` will be shifted while creating the mask:

```cpp
int original = num;
int mask = 0;
```

Build the mask:

```cpp
while(num != 0) {
    mask = (mask << 1) | 1;
    num = num >> 1;
}
```

For:

```text
num = 101
```

the mask becomes:

```text
111
```

Finally:

```cpp
return (~original) & mask;
```

This removes the unwanted leading bits created by `~`.

## Solution

```cpp
class Solution {
public:
    int findComplement(int num) {
        if(num == 0) return 1;

        int original = num;
        int mask = 0;

        while(num != 0) {
            mask = (mask << 1) | 1;
            num = num >> 1;
        }

        return (~original) & mask;
    }
};
```

## Complexity

- **Time:** `O(log n)`
- **Space:** `O(1)`

The loop processes each bit of `num` once.

## What I Learned

- Binary complement means flipping only the meaningful bits.
- `~` alone is not enough because it flips all bits of the integer.
- A mask allows us to keep only the relevant bits.
- `mask = (mask << 1) | 1` builds `111...`.
- `~original & mask` gives the required complement.
- This problem reinforces the masking technique used in binary manipulation.