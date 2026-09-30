## Problem

Given a 0-indexed integer array `nums` and an integer `k`, return the sum of elements whose corresponding indices contain exactly `k` set bits in their binary representation.

A set bit is a `1` in the binary representation of a number.

## My Approach

I iterate through every index of the array.

For each index, I count the number of set bits using the built-in C++ function:

```cpp
__builtin_popcount(i)
```

If the number of set bits equals `k`, I add the value at that index to the answer.

For example:

```text
index 1 = 001 → 1 set bit
index 2 = 010 → 1 set bit
index 4 = 100 → 1 set bit
```

So when `k = 1`, the values at indices `1`, `2`, and `4` are included.

## Key Logic

The important operation is:

```cpp
__builtin_popcount(i)
```

It returns the number of `1` bits in the binary representation of `i`.

For example:

```text
21 = 10101
```

There are 3 set bits:

```cpp
__builtin_popcount(21) == 3
```

Then:

```cpp
if(__builtin_popcount(i) == k)
```

checks whether the current index has exactly `k` set bits.

If it does:

```cpp
sum += nums[i];
```

## Solution

```cpp
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(__builtin_popcount(i) == k) {
                sum += nums[i];
            }
        }

        return sum;
    }
};
```

## Complexity

- Time: O(n)
- Space: O(1)

`__builtin_popcount()` operates on a fixed-size integer, so its cost is effectively O(1) for this problem.

## What I Learned

- A set bit is simply a `1` in binary.
- `__builtin_popcount(x)` counts the set bits of an integer.
- Array indices can themselves be analyzed using bit manipulation.
- Bit counting is useful for filtering numbers based on their binary representation.