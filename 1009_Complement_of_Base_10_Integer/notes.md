## Problem

Given an integer `n`, return its binary complement.

The complement means flipping every bit in its binary representation.

Example:

```text
n = 5
Binary = 101
Complement = 010
Answer = 2
```

## My Approach

The `~` operator flips every bit of an integer, including the leading bits that are not part of the number.

For example:

```text
5 = 00000101
~5 = 11111010
```

But the problem only wants to flip the meaningful bits:

```text
101 → 010
```

So I create a mask containing the same number of `1`s as the number has bits.

For `5`:

```text
101 → mask = 111
```

Then I use:

```cpp
(~n) & mask
```

The mask removes all the unwanted flipped bits.

## Key Logic

First handle `n = 0`:

```cpp
if(n == 0) return 1;
```

Then create the mask:

```cpp
int mask = 0;

while(n != 0) {
    mask = (mask << 1) | 1;
    n = n >> 1;
}
```

For `n = 5`:

```text
mask:

0
01
011
111
```

So the final mask is:

```text
111
```

Then use the original number:

```cpp
(~original) & mask
```

For `5`:

```text
~5    = 11111010
mask  = 00000111
        --------
          00010
```

The result is `2`.

## Solution

```cpp
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        int original = n;
        int mask = 0;

        while(n != 0) {
            mask = (mask << 1) | 1;
            n = n >> 1;
        }

        return (~original) & mask;
    }
};
```

## Complexity

- **Time:** `O(log n)`
- **Space:** `O(1)`

We process each bit of `n` once.

## What I Learned

- `~n` flips every bit of an integer.
- A **mask** can restrict which bits we want to keep.
- `mask = (mask << 1) | 1` builds a sequence of `1`s:
  `1 → 11 → 111 → 1111`.
- `~n & mask` flips only the meaningful bits.
- A temporary copy is useful when the original value is needed after modifying `n`.
- `n = 0` needs special handling because it has no meaningful `1` bit to use for building the mask.