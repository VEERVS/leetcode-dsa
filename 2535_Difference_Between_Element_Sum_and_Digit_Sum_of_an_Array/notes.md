## Problem

Given a positive integer array `nums`, calculate:

- **Element sum:** Sum of all elements in the array.
- **Digit sum:** Sum of all digits appearing in every element.

Return the absolute difference between the element sum and digit sum.

## My Approach

I used `accumulate()` to calculate the element sum:

```cpp
int sum = accumulate(nums.begin(), nums.end(), 0);
```

Then I traversed every number and calculated its digit sum using `% 10` and `/ 10`.

I stored the total digit sum in `dSum`.

Finally, I returned:

```cpp
sum - dSum
```

Since the array contains positive integers, the element sum is always greater than or equal to the digit sum, so the result is non-negative.

## Key Logic

For:

```text
nums = [1, 15, 6, 3]
```

Element sum:

```text
1 + 15 + 6 + 3 = 25
```

Digit sum:

```text
1 + 1 + 5 + 6 + 3 = 16
```

Difference:

```text
25 - 16 = 9
```

The digit sum is calculated using:

```cpp
while(num > 0) {
    dig += num % 10;
    num /= 10;
}
```

## Solution

```cpp
#include <numeric>

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int dSum = 0;

        for(int num : nums) {
            int dig = 0;

            while(num > 0) {
                dig += num % 10;
                num /= 10;
            }

            dSum += dig;
        }

        return sum - dSum;
    }
};
```

## Complexity

Let `n` be the number of elements and `d` be the maximum number of digits in an element.

**Time:** `O(n × d)`

**Space:** `O(1)`

## What I Learned

- `accumulate()` can calculate the sum of all elements in a vector.
- Range-based `for` loops make array traversal cleaner.
- A copy of each element can be modified safely when using `for(int num : nums)`.
- Element sum and digit sum are different concepts even though both involve addition.
- For positive integers, the element value is always at least as large as the sum of its digits.