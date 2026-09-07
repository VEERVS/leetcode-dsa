## Problem

Alice and Bob play a game starting with an integer `n`.

On each turn, a player chooses an integer `x` such that:

`0 < x < n`

and:

`n % x == 0`

Then `n` is replaced with:

`n - x`

Alice goes first.

Return `true` if Alice wins when both players play optimally.

## My Approach

I noticed a mathematical pattern in the game.

The winning condition depends only on whether `n` is even or odd.

If `n` is even, Alice can always choose `x = 1`.

This changes `n` from even to odd.

From an odd number, every valid divisor other than the number itself is odd, so subtracting it makes the result even.

Therefore, Alice can always move to an odd number and maintain the winning strategy.

## Key Logic

The result follows a simple parity pattern:

- Even `n` → Alice wins.
- Odd `n` → Alice loses.

So the answer is simply:

`n % 2 == 0`

## Solution

```cpp
class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};
```

## Complexity

Time: `O(1)`

Space: `O(1)`

## What I Learned

I learned how a game problem can sometimes be reduced to a simple mathematical invariant instead of simulating every possible move.

The key observation here is **parity**: even starting values are winning positions, while odd starting values are losing positions.