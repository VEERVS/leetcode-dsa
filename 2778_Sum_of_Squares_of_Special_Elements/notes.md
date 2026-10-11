## Problem

You are given a 1-indexed integer array `nums` of length `n`.

An element `nums[i]` is called special if its 1-based index `i` divides `n` exactly, meaning `n % i == 0`.

Return the sum of the squares of all special elements.

## My Approach

I use a loop with a 1-based index `i`, running from `1` to `nums.size()`.

For every index, I check whether the array length is divisible by that index using:

```cpp
nums.size() % i == 0
```

If the condition is true, the element at the corresponding 0-based index `nums[i - 1]` is special. I add its square to `sum`.

Finally, I return the total sum.

## Key Logic

Check whether the current index divides the array length:

```cpp
if(nums.size() % i == 0)
```

Add the square of the special element:

```cpp
sum += nums[i - 1] * nums[i - 1];
```

Remember that `i` is 1-based, while C++ vector indexing is 0-based. Therefore, we access the element using `i - 1`.

For example:

```text
Input:  [1,2,3,4]
Length: 4

Special indices: 1, 2, 4
Special elements: 1, 2, 4

Sum = 1² + 2² + 4² = 21
Output: 21
```

## Solution

```cpp
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0;

        for(int i = 1; i <= nums.size(); i++) {
            if(nums.size() % i == 0) {
                sum += nums[i - 1] * nums[i - 1];
            }
        }

        return sum;
    }
};
```

## Complexity

- **Time:** `O(n)`, because every index from `1` to `n` is checked.
- **Space:** `O(1)` auxiliary space because only a fixed number of variables are used.

## What I Learned

- A special element is determined by its index, not its value.
- The modulo operator `%` checks divisibility.
- A 1-based index `i` corresponds to vector index `i - 1` in C++.
- Checking every index is a straightforward way to find all divisors of the array length.