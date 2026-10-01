## Problem

Given two integers `a` and `b`, return their sum without using the `+` or `-` operators.

## My Approach

I recreate binary addition using bitwise operations.

Binary addition has two separate parts:

1. Calculate the sum without considering carry.
2. Calculate the carry and move it to the next bit.

XOR handles the first part:

```cpp
a ^ b
```

AND finds where a carry occurs:

```cpp
a & b
```

The carry needs to move one position to the left:

```cpp
(a & b) << 1
```

I repeatedly perform these two operations until there is no carry left.

## Key Logic

The main idea is:

```cpp
a ^ b
```

gives the addition of the bits **without carry**.

For example:

```text
5 = 101
3 = 011

101
011
---
110
```

So:

```text
5 ^ 3 = 6
```

Now find the carry:

```text
101
011
---
001
```

Therefore:

```text
5 & 3 = 1
```

Move the carry one position left:

```text
001 << 1 = 010 = 2
```

So the problem becomes adding:

```text
6 + 2
```

We repeat until the carry becomes `0`.

The loop:

```cpp
while(b != 0)
```

uses `b` to store the carry.

At each step:

```cpp
int carry = (a & b) << 1;
a = a ^ b;
b = carry;
```

When there is no carry left, `a` contains the final answer.

## Solution

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }

        return a;
    }
};
```

## Complexity

- Time: O(1)
- Space: O(1)

For fixed-width integers, the number of bit operations is bounded by the integer width.

## What I Learned

- XOR performs binary addition without carry.
- AND identifies positions where a carry is generated.
- `<< 1` moves the carry to the next bit.
- Repeating this process can perform addition without using `+`.
- The pattern to remember is:

```text
XOR → sum without carry
AND → find carry
LEFT SHIFT → move carry
```