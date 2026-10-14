## Problem

You are given a 0-indexed integer array `nums`.

A pair of integers `x` and `y` is called a strong pair if:

```text
|x - y| <= min(x, y)
```

Choose a strong pair whose bitwise XOR is maximum and return that maximum XOR value.

The same integer can be chosen twice to form a pair.

## My Approach

I use two nested loops to examine every possible pair of elements, including pairs where both elements are the same.

For each pair, I first check whether it satisfies the strong pair condition:

```cpp
abs(nums[i] - nums[j]) <= min(nums[i], nums[j])
```

If the pair is strong, I calculate its bitwise XOR using the `^` operator.

If the XOR value is greater than the current maximum, I update `max`.

After checking all pairs, I return `max`.

## Key Logic

Check whether the pair is strong and its XOR improves the current maximum:

```cpp
if(abs(nums[i] - nums[j]) <= min(nums[i], nums[j])
   && (nums[i] ^ nums[j]) > max) {
    max = nums[i] ^ nums[j];
}
```

The two important operations are:

- `abs(x - y)` calculates the absolute difference.
- `x ^ y` calculates the bitwise XOR.

**Example:**

```text
Input:  [1,2,3,4,5]
Output: 7
```

The pair `(3,4)` is strong because:

```text
|3 - 4| = 1
min(3,4) = 3

1 <= 3 → true
```

Their XOR is:

```text
3 ^ 4 = 7
```

This is the maximum XOR among all strong pairs.

## Solution

```cpp
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int max = 0;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i; j < nums.size(); j++) {
                if(abs(nums[i] - nums[j]) <= min(nums[i], nums[j])
                   && (nums[i] ^ nums[j]) > max) {
                    max = nums[i] ^ nums[j];
                }
            }
        }

        return max;
    }
};
```

## Complexity

- **Time:** `O(n²)` because every pair with `i <= j` is checked.
- **Space:** `O(1)` auxiliary space because only a fixed number of variables are used.

## What I Learned

- Bitwise XOR (`^`) produces `1` where the corresponding bits differ.
- A strong pair must satisfy the absolute-difference condition.
- Nested loops can examine every pair, including self-pairs.
- Starting the inner loop at `i` avoids checking both `(i,j)` and `(j,i)` while still allowing `(i,i)`.
- Brute force is a useful starting point before exploring more advanced XOR optimizations.