## Problem

Given a positive integer `n`, return the smallest positive integer that is a multiple of both `2` and `n`.

## My Approach

I started with `i = 1` and checked every number until I found one that was divisible by both `2` and `n`.

For every value of `i`, I checked:

```cpp
i % 2 == 0 && i % n == 0
```

As soon as both conditions were true, I returned `i`.

## Key Logic

The first number satisfying both conditions is the smallest common multiple of `2` and `n`.

Since `n` is positive and the constraints are small, checking numbers sequentially works.

For example:

`n = 5`

```text
1 → not divisible by 2
2 → not divisible by 5
...
10 → divisible by both
```

Answer = `10`.

## Solution

```cpp
class Solution {
public:
    int smallestEvenMultiple(int n) {
        int i = 1;

        while(1) {
            if(i % 2 == 0 && i % n == 0) {
                return i;
            }

            i++;
        }
    }
};
```

## Complexity

Time: `O(n)` in the worst case.

Space: `O(1)`.

## What I Learned

I learned how to find a common multiple by checking divisibility conditions directly.

A more mathematical solution could use the LCM, and because one number is always `2`, this problem can actually be simplified further.