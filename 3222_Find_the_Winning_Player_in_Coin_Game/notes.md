## Problem

Alice and Bob play a game using coins worth `75` and `10`.

On every turn, the player must pick coins whose total value is exactly `115`.

A valid move therefore requires:

- `1` coin of value `75`
- `4` coins of value `10`

Alice starts first. If a player cannot make a move, they lose.

Return the name of the winning player.

## My Approach

I noticed that every move always consumes exactly:

- `1` coin from `x`
- `4` coins from `y`

Therefore, the maximum number of moves possible is:

`min(x, y / 4)`

Once the number of possible moves is known, the winner depends only on whether that number is odd or even.

Since Alice starts:

- Odd number of moves → Alice makes the last move.
- Even number of moves → Bob makes the last move.

## Key Logic

```cpp
int moves = min(x, y / 4);
```

Then:

```cpp
moves % 2 != 0
```

means Alice wins.

Otherwise Bob wins.

## Solution

```cpp
class Solution {
public:
    string winningPlayer(int x, int y) {
        int moves = min(x, y / 4);

        if(moves % 2 != 0) {
            return "Alice";
        } else {
            return "Bob";
        }
    }
};
```

## Complexity

Time: `O(1)`

Space: `O(1)`

## What I Learned

I learned to look at how much each move consumes instead of simulating the entire game.

The key observation was that every move requires exactly `1` of `x` and `4` of `y`, so the number of possible moves is simply `min(x, y / 4)`.

Then the game reduces to checking the parity of the number of moves.