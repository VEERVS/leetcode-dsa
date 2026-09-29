## Problem

Given an integer `n`, transform it into `0` using the allowed bit operations.

Return the minimum number of operations required.

## My Approach

I noticed that the minimum number of operations follows a pattern related to Gray code.

Instead of simulating the operations directly, I repeatedly XOR the current number with its right-shifted versions.

The key idea is:

```cpp
ans ^= n;
n >>= 1;
```

This effectively calculates:

```text
n ^ (n >> 1) ^ (n >> 2) ^ (n >> 3) ...
```

This is the inverse Gray-code transformation, which gives the minimum number of operations required.

## Key Logic

For every iteration:

```cpp
ans ^= n;
```

XORs the current shifted version of `n` into the answer.

Then:

```cpp
n >>= 1;
```

Moves to the next shifted version.

For example, if:

```text
n = 6
```

the calculation becomes:

```text
6 ^ 3 ^ 1
```

which gives:

```text
4
```

So the answer is `4`.

## Solution

```cpp
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;

        while(n > 0) {
            ans ^= n;
            n >>= 1;
        }

        return ans;
    }
};
```

## Complexity

- Time: O(log n)
- Space: O(1)

## What I Learned

- Some Hard problems can hide a mathematical/bitwise pattern instead of requiring simulation.
- Repeated right shifts let us process every significant bit.
- XOR can combine the shifted values to perform the inverse Gray-code transformation.
- The expression `n ^ (n >> 1) ^ (n >> 2) ...` represents the key pattern behind this solution.