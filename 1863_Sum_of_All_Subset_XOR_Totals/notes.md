## Problem

Given an array, calculate the XOR total of every possible subset and return the sum of all those XOR totals.

The empty subset has an XOR total of `0`.

## My Approach

At first, this looks like a subset-generation problem because there are `2^n` subsets.

However, instead of generating every subset, I analyze the contribution of each individual bit.

If a bit is set in at least one element of `nums`, then that bit will be set in the XOR of exactly half of all subsets.

There are `2^n` total subsets, so each such bit contributes to:

```text
2^(n-1)
```

subset XOR totals.

The bitwise OR of all elements tells me exactly which bits appear in at least one element.

Therefore:

```text
answer = OR of all elements × 2^(n-1)
```

I implement the multiplication by shifting left:

```cpp
ans << (nums.size() - 1)
```

## Key Logic

First calculate the OR of all numbers:

```cpp
for(int x : nums) {
    ans |= x;
}
```

The OR tells us which bit positions are present in at least one number.

For every set bit, exactly half of the subsets have that bit set in their XOR.

For `n` elements:

```text
Number of subsets = 2^n
Subsets contributing each present bit = 2^(n-1)
```

Therefore:

```cpp
ans << (nums.size() - 1)
```

multiplies the OR value by `2^(n-1)`.

For example:

```text
nums = [5,1,6]

5 = 101
1 = 001
6 = 110

OR = 111 = 7
```

There are 3 elements, so every present bit contributes to:

```text
2^(3-1) = 4
```

subsets.

Therefore:

```text
7 × 4 = 28
```

## Solution

```cpp
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;

        for(int x : nums) {
            ans |= x;
        }

        return ans << (nums.size() - 1);
    }
};
```

## Complexity

- Time: O(n)
- Space: O(1)

## What I Learned

- We do not replace XOR with OR.
- OR identifies which bits are present in at least one element.
- XOR determines which bits survive in each individual subset.
- Every bit present in the array appears in exactly half of all subset XORs.
- This turns an exponential subset problem into an O(n) bitwise solution.