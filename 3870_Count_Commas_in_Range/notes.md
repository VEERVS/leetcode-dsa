## Problem

Given an integer `n`, return the total number of commas used when writing every integer from `1` to `n` in standard number formatting.

A comma is inserted after every three digits from the right.

Therefore, numbers below `1000` contain no commas.

## My Approach

I noticed that the only numbers that contain a comma in the given range are the numbers from:

```text
1000 → n
```

Every number in this range has exactly **one comma** under the given constraints.

Therefore:

- If `n < 1000`, the answer is `0`.
- Otherwise, the number of integers from `1000` to `n` is:

```text
n - 1000 + 1
```

which simplifies to:

```text
n - 999
```

## Key Logic

For:

```text
n = 1002
```

The numbers containing commas are:

```text
1,000
1,001
1,002
```

There are `3`.

Using:

```cpp
(n - 1000) + 1
```

we get:

```text
(1002 - 1000) + 1 = 3
```

So the answer is:

```cpp
n - 999
```

## Solution

```cpp
class Solution {
public:
    int countCommas(int n) {
        if(n < 1000) {
            return 0;
        } else {
            return (n - 1000) + 1;
        }
    }
};
```

## Complexity

**Time:** `O(1)`

**Space:** `O(1)`

## What I Learned

- Sometimes the best solution comes from counting a range instead of checking every value.
- The number of integers from `a` to `b` inclusive is:

```text
b - a + 1
```

- Recognizing that every valid number contributes exactly one comma allows the entire problem to be reduced to a simple formula.
- A problem that appears to require iteration can sometimes be solved in `O(1)` using a mathematical observation.