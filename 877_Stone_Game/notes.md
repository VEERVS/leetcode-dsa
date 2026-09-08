## Problem

Alice and Bob play a game with an even number of stone piles arranged in a row.

On each turn, a player can take the entire pile from either the beginning or the end.

Alice goes first.

The player with the greater total number of stones wins.

Return `true` if Alice wins assuming both players play optimally.

## My Approach

I noticed that the number of piles is always even.

Alice can use a strategy that guarantees her a win by controlling one of the two parity groups of positions.

She can effectively choose either all piles at even indices or all piles at odd indices.

Since the total number of stones is odd, these two groups cannot have equal sums.

Alice can choose the group with the larger sum and force herself to collect more stones.

Therefore, Alice always wins.

## Key Logic

The important observation is that the number of piles is even.

Alice can always force a winning strategy, regardless of the actual values of the piles.

Therefore, the answer is always:

`true`

## Solution

```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
```

## Complexity

Time: `O(1)`

Space: `O(1)`

## What I Learned

I learned that some game problems don't require simulation or dynamic programming.

Instead, the constraints can guarantee that one player always has a winning strategy.

Here, because the number of piles is even and Alice moves first, Alice can always win.