## Problem
Given an array `prices`, where `prices[i]` represents the stock price on day `i`, maximize the profit by buying once and selling on a later day.

Return the maximum profit. If no profit is possible, return `0`.

**LeetCode:** 121. Best Time to Buy and Sell Stock

## My Approach
I used a one-pass greedy approach with two variables:

- `left` stores the index of the best buying price seen so far.
- `right` scans through the array to consider each selling day.

Whenever the current price is lower than the price at `left`, I update `left = right` because the current day offers a better buying price.

For each day, I calculate the possible profit and update the maximum profit.

## Key Logic
1. Initialize `MAXprofit = 0` and `left = 0`.
2. Iterate through the array using `right`.
3. If `prices[right] < prices[left]`, update `left = right`.
4. Calculate the current profit as `prices[right] - prices[left]`.
5. Update `MAXprofit` with the maximum of the current and previous profits.
6. Return `MAXprofit`.

## Solution
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MAXprofit = 0, left = 0;

        for (int right = 0; right < prices.size(); right++) {
            if (prices[left] > prices[right]) {
                left = right;
            }

            MAXprofit = max(
                MAXprofit,
                prices[right] - prices[left]
            );
        }

        return MAXprofit;
    }
};
```

## Complexity
- **Time Complexity:** `O(n)` — the array is traversed once.
- **Space Complexity:** `O(1)` — only a constant number of variables are used.

## What I Learned
- Track the minimum buying price seen so far to maximize future profit.
- Buying must happen before selling.
- When a lower price appears, updating `left = right` selects a better buying day.
- Greedy one-pass techniques can solve some problems that initially look like sliding-window problems.
- Initializing the maximum profit to zero handles decreasing prices correctly.