## Problem

Given a 2D array `accounts`, where `accounts[i][j]` represents the money customer `i` has in bank `j`, return the maximum wealth of any customer.

A customer's wealth is the sum of all their bank accounts.

## My Approach

I iterate through every customer and calculate their total wealth using `accumulate()`.

For each customer:

`sum = accumulate(customer.begin(), customer.end(), 0)`

I then keep track of the largest wealth using `max()`.

## Key Logic

- Each row represents one customer.
- Sum all values in the row to get that customer's wealth.
- Compare the wealth with the current maximum.
- Return the maximum wealth after checking all customers.

For example:

`[[1,2,3], [3,2,1]]`

- Customer 1 → `1 + 2 + 3 = 6`
- Customer 2 → `3 + 2 + 1 = 6`

Maximum wealth = `6`.

## Solution

```cpp
#include <algorithm>

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;

        for(auto customer : accounts) {
            int sum = accumulate(customer.begin(), customer.end(), 0);
            maxWealth = max(maxWealth, sum);
        }

        return maxWealth;
    }
};
```

## Complexity

Let `m` be the number of customers and `n` be the number of bank accounts per customer.

- Time: `O(m × n)`
- Space: `O(1)` extra space

## What I Learned

- A 2D vector can be traversed row by row using a range-based `for` loop.
- `accumulate()` is useful for quickly calculating the sum of a range.
- `max()` can maintain the largest value seen so far.
- STL can make simple array operations much cleaner.