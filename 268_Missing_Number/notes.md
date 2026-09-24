## Problem

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

Example:

```text
nums = [3, 0, 1]
n = 3

Range = [0, 1, 2, 3]

Missing number = 2
```

## My Approach

I used the **XOR technique**.

The array contains `n` numbers from the range `[0, n]`, so there are actually `n + 1` possible numbers.

I initialize:

```cpp
int ans = nums.size();
```

This represents the last number `n`.

Then for every index `i`, I XOR:

```cpp
ans ^= i ^ nums[i];
```

The important property of XOR is:

```text
x ^ x = 0
x ^ 0 = x
```

So every number that exists both in the complete range and in the array cancels itself out.

Only the missing number remains.

## Key Logic

```cpp
int ans = nums.size();

for(int i = 0; i < nums.size(); i++) {
    ans ^= i ^ nums[i];
}
```

For:

```text
nums = [3, 0, 1]
```

Initially:

```text
ans = 3
```

Then:

```text
ans = 3 ^ 0 ^ 3
    = 0

ans = 0 ^ 1 ^ 0
    = 1

ans = 1 ^ 2 ^ 1
    = 2
```

So the missing number is:

```text
2
```

The XOR approach avoids sorting and avoids using an extra frequency array.

## Solution

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();

        for(int i = 0; i < nums.size(); i++) {
            ans ^= i ^ nums[i];
        }

        return ans;
    }
};
```

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## What I Learned

- XOR is extremely useful for finding a missing or unique value.
- `x ^ x = 0`, so duplicate values cancel each other.
- `x ^ 0 = x`, so the missing value remains.
- We can combine the complete range and array values using XOR without storing anything extra.
- Starting with `nums.size()` includes the final number `n`, which is not visited as an index inside the loop.