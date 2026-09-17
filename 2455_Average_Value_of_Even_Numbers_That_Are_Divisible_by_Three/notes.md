## Problem

Given an integer array `nums`, return the average of all numbers that are both:

- Even
- Divisible by 3

If there are no such numbers, return `0`.

The average is rounded down.

## My Approach

I traverse the array once.

For every element, I check:

```cpp
nums[i] % 3 == 0 && nums[i] % 2 == 0
```

If the condition is true, I add the number to `sum` and increase `count`.

After the loop, if no valid number was found, I return `0`.

Otherwise, integer division `sum / count` automatically gives the required rounded-down average.

## Key Logic

A number must satisfy both conditions:

```cpp
nums[i] % 3 == 0 && nums[i] % 2 == 0
```

For example:

`[1,3,6,10,12,15]`

Valid numbers are `6` and `12`.

```text
sum = 18
count = 2
average = 18 / 2 = 9
```

## Solution

```cpp
class Solution {
public:
    int averageValue(vector<int>& nums) {
        int count = 0, sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 3 == 0 && nums[i] % 2 == 0) {
                sum += nums[i];
                count++;
            }
        }

        if(!count) {
            return 0;
        }

        return sum / count;
    }
};
```

## Complexity

- Time Complexity: `O(n)`
- Space Complexity: `O(1)`

## What I Learned

- Multiple divisibility conditions can be combined using `&&`.
- A single traversal is enough to calculate both the sum and count.
- Integer division in C++ automatically truncates the decimal part.
- Always handle the zero-count case before performing division.