# 4113. Game of Divisible Sums

## Problem
Alice and Bob play a game with an integer array `nums`. Alice goes first.

On each turn, the current player removes either:
- The leftmost element.
- The two leftmost elements, if at least two elements remain.

The sum of the removed elements determines who plays next:

- If the sum is divisible by 3, the other player plays next.
- Otherwise, the same player plays again.

Both players play optimally, trying to maximize their own score.

Return Alice's score minus Bob's score.

## My Approach
Used Dynamic Programming with space optimization, processing the array from right to left.

Instead of maintaining a complete DP array, I used two variables:

- `next1`: Best score difference for the suffix starting at the next index.
- `next2`: Best score difference for the suffix starting two indices ahead.

For every index:

1. Consider taking one element.
2. Calculate the resulting score difference depending on whether its value is divisible by 3.
3. If possible, consider taking two elements and calculate the resulting score difference.
4. Choose the maximum of both choices.
5. Update `next1` and `next2` for the next iteration.

## Key Logic

We calculate the maximum score difference between the current player and the opponent.

For a move with sum `take`:

- If `take % 3 == 0`, the opponent plays next.

  `result = take - futureDifference`

- Otherwise, the same player plays again.

  `result = take + futureDifference`

The recurrence for taking one element is:

`take1 % 3 == 0 ? take1 - next1 : take1 + next1`

For taking two elements:

`take2 % 3 == 0 ? take2 - next2 : take2 + next2`

We select the maximum possible result because the current player plays optimally.

## Solution

```cpp
class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        long long next1 = 0;
        long long next2 = 0;

        for(int i = nums.size() - 1; i >= 0; i--) {
            long long take1 = nums[i];

            long long best = (take1 % 3 == 0)
                ? (take1 - next1)
                : (take1 + next1);

            if(i + 1 < (int)nums.size()) {
                long long take2 = (long long)nums[i] + nums[i + 1];

                long long res = (take2 % 3 == 0)
                    ? (take2 - next2)
                    : (take2 + next2);

                best = max(best, res);
            }

            next2 = next1;
            next1 = best;
        }

        return next1;
    }
};
```

## Complexity
- **Time Complexity:** O(n) — Each array element is processed once.
- **Space Complexity:** O(1) — Only two DP state variables are maintained.

## What I Learned
- How to formulate a game-theory problem using dynamic programming.
- How to calculate score difference instead of tracking both players' scores separately.
- How the next player's turn depends on divisibility by 3.
- How to solve a DP problem from right to left.
- How to optimize DP space using two variables instead of a full array.