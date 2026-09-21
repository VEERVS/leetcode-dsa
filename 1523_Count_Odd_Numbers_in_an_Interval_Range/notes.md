## Problem

Given two non-negative integers `low` and `high`, return the number of odd integers between `low` and `high`, inclusive.

## My Approach

I used a simple loop from `low` to `high`.

For every number, I checked whether it is odd using:

`i % 2 != 0`

If the condition is true, I incremented `count`.

After checking every number in the range, I returned `count`.

## Key Logic

A number is odd if its remainder after division by `2` is not zero.

So:

`i % 2 != 0`

means `i` is odd.

For example, for:

`low = 3, high = 7`

The numbers are:

`3, 4, 5, 6, 7`

The odd numbers are:

`3, 5, 7`

Therefore, the answer is `3`.

## Solution

```cpp
class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;

        for(int i = low; i <= high; i++) {
            if(i % 2 != 0) {
                count++;
            }
        }

        return count;
    }
};
```

## Complexity

- Time: `O(high - low + 1)`
- Space: `O(1)`

## What I Learned

- The modulo operator `%` can be used to check whether a number is odd or even.
- `i % 2 != 0` identifies odd numbers.
- A simple traversal is enough when the range is manageable.
- This problem can also be solved in `O(1)` using a mathematical formula.