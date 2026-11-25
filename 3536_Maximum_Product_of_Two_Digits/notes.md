
## Problem
Given a positive integer `n`, return the maximum product of any two digits in `n`. The same digit can be used twice if it appears more than once.

## My Approach
Used digit extraction with modulo (`% 10`) and integer division (`/ 10`).

Maintained two variables:
- `max1`: Largest digit found so far.
- `max2`: Second-largest digit found so far.

For every digit:
1. If it is greater than `max1`, move `max1` into `max2` and update `max1`.
2. Otherwise, if it is greater than `max2`, update `max2`.
3. Remove the last digit using `n /= 10`.

Finally, return `max1 * max2`.

## Key Logic
- `n % 10` extracts the last digit.
- `n /= 10` removes the last digit.
- Maintain the two largest digits while traversing the number.
- Updating `max2 = max1` before replacing `max1` preserves the previous largest digit.

## Solution

```cpp
class Solution {
public:
    int maxProduct(int n) {
        int digits, max1 = 0, max2 = 0;

        while(n > 0) {
            if(n % 10 > max1) {
                max2 = max1;
                max1 = n % 10;
            }
            else if(n % 10 > max2) {
                max2 = n % 10;
            }

            n /= 10;
        }

        return max1 * max2;
    }
};
```

## Complexity
- **Time Complexity:** O(d), where d is the number of digits.
- **Space Complexity:** O(1), as only two variables are maintained.

## What I Learned
- Extracting digits using modulo and division.
- Maintaining the two largest values in a single traversal.
- Applying a greedy approach without sorting or storing digits.
