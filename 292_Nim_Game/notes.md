## Problem

There is a heap containing `n` stones.

Alice and Bob take turns removing 1 to 3 stones.

Alice goes first.

The player who removes the last stone wins.

Return `true` if Alice can win assuming both players play optimally.

## My Approach

I looked for a repeating pattern based on the number of stones.

If there are:

`1, 2, 3`

stones, Alice can remove all of them and win.

But with:

`4`

stones, Alice can remove 1, 2, or 3 stones, leaving Bob with `3`, `2`, or `1` stones.

Bob can then take the remaining stones and win.

This creates a losing position at every multiple of `4`.

Therefore:

- `n % 4 == 0` → Alice loses.
- Otherwise → Alice wins.

## Key Logic

The important pattern is that a player can always respond to the opponent's move so that together they remove exactly 4 stones.

For example, if Alice removes:

- 1 → Bob removes 3
- 2 → Bob removes 2
- 3 → Bob removes 1

Therefore, positions divisible by 4 are losing positions.

## Solution

```cpp
class Solution {
public:
    bool canWinNim(int n) {
        return n == 1 || n == 2 || n % 4 != 0;
    }
};
```

## Complexity

Time: `O(1)`

Space: `O(1)`

## What I Learned

I learned how to identify repeating patterns in game problems.

Instead of simulating every possible move, I can identify the losing positions and derive a mathematical condition.

The important pattern for Nim Game is:

`n % 4 == 0`

which represents a losing position for the first player.