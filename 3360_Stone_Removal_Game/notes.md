
## Problem
Alice and Bob take turns removing stones from a pile. Alice removes exactly 10 stones first. On every subsequent turn, the player removes one fewer stone than the previous opponent.

The player who cannot make a move loses. Return true if Alice wins.

## My Approach
Used simulation to reproduce the game's rules.

- Initially, `stones = 10`.
- On every turn, check whether enough stones remain.
- If yes, subtract the required stones.
- Decrease the required stones by one.
- Increment the turn count.

After the game ends, check whether the number of completed turns is odd or even.

## Key Logic
- Alice plays on odd-numbered turns.
- Bob plays on even-numbered turns.
- If the total number of turns is odd, Alice wins.
- If the total number of turns is even, Bob wins.

`turns % 2 == 1` means Alice wins.

## Solution

```cpp
class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        int turns = 0;

        while(n >= stones) {
            n -= stones;
            stones--;
            turns++;
        }

        return turns % 2 == 1;
    }
};
```

## Complexity
- **Time Complexity:** O(1), at most 10 turns.
- **Space Complexity:** O(1).

## What I Learned
- Simulating alternating turns in a game.
- Tracking turn parity to determine the winner.
- Translating problem rules directly into code.
