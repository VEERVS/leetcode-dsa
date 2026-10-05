## Problem

Given an integer array `nums`, return the smallest index `i` such that the sum of the digits of `nums[i]` is equal to `i`.

If no such index exists, return `-1`.

## My Approach

I created a separate function `sumOfDigits()` to calculate the sum of digits of a number.

Then I traversed the array from index `0` to the end.

For every index `i`, I calculated:

```cpp
sumOfDigits(nums[i])
```

and checked whether it equals `i`.

Since the array is traversed from left to right, the first matching index is automatically the smallest index.

## Key Logic

To calculate the digit sum, repeatedly use:

```cpp
sum += n % 10;
n /= 10;
```

For example:

```text
nums[i] = 23

23 % 10 = 3
23 / 10 = 2

2 % 10 = 2
2 / 10 = 0

digit sum = 3 + 2 = 5
```

Then compare:

```cpp
if(i == sumOfDigits(nums[i]))
```

If true, return `i` immediately.

## Solution

```cpp
class Solution {
public:
    int sumOfDigits(int n) {
        int sum = 0;

        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(i == sumOfDigits(nums[i])) {
                return i;
            }
        }

        return -1;
    }
};
```

## Complexity

- **Time:** `O(n * d)`, where `d` is the number of digits in an element.
- **Space:** `O(1)`.

The array is traversed once, and each number's digits are processed individually.

## What I Learned

- `% 10` extracts the last digit of a number.
- `/ 10` removes the last digit.
- Traversing from left to right means the first valid index is automatically the smallest.
- Creating a helper function like `sumOfDigits()` makes the main logic cleaner.
- Returning immediately when the condition is satisfied avoids unnecessary work.