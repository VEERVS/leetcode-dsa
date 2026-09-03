## Problem

Given an array `nums1` of distinct integers, construct another array `nums2` of the same length such that all elements in `nums2` are either all odd or all even.

For each index `i`, we can choose either:
- `nums2[i] = nums1[i]`
- `nums2[i] = nums1[i] - nums1[j]`, where `j != i`

Return `true` if such an array can always be constructed, otherwise `false`.

## My Approach

I noticed that we only care about the **parity** (odd/even) of the numbers.

For two numbers:
- odd - odd = even
- even - even = even
- odd - even = odd
- even - odd = odd

If all numbers already have the same parity, we can simply choose every original number.

If there are both odd and even numbers, for each number we can subtract a number of the opposite parity, producing an odd result.

Therefore, it is always possible to construct a uniform-parity array.

So the answer is always `true`.

## Key Logic

The important observation is that because the elements are distinct, if both parities exist, every element can use another element with the opposite parity.

Thus:
- All same parity → keep them as they are.
- Mixed parity → subtract an opposite-parity number from each element.

Therefore, the result is always possible.

## Solution

```c
bool uniformArray(int* nums1, int nums1Size) {
    return true;
}
```

## Complexity

- Time: `O(1)`
- Space: `O(1)`

## What I Learned

- Sometimes a problem that looks like it needs construction can be solved by proving that the construction is **always possible**.
- Parity rules are extremely useful:
  - same parity subtraction → even
  - different parity subtraction → odd
- Before writing loops, look for an invariant or mathematical property that makes the answer constant.