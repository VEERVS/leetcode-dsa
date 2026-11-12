# 810. Chalkboard XOR Game

## Problem
Given an integer array `nums`, Alice and Bob take turns removing exactly one number from the array, with Alice starting first.

- If removing a number makes the XOR of all remaining elements equal to zero, the player who removed it loses.
- If a player starts their turn with the XOR of all elements already equal to zero, that player wins.
- The player unable to make a move loses.

Return `true` if Alice wins, assuming optimal play.

## My Approach
Used the XOR property and a mathematical observation.

1. Initialize `sumXor = 0`.
2. Traverse the array and calculate the XOR of all elements.
3. Apply the winning condition:
   - If the total XOR is zero, Alice wins immediately.
   - If the number of elements is even, Alice also wins.
   - Otherwise, Alice loses.

## Key Logic
The final winning condition is:

`sumXor == 0 || nums.size() % 2 == 0`

Two important observations:

- If the initial XOR is zero, Alice wins immediately because the game rules explicitly state that a player starting with XOR zero wins.
- If the initial XOR is non-zero and the array length is even, Alice can force a win with optimal play.
- If the initial XOR is non-zero and the array length is odd, Bob can force a win.

## Solution

```cpp
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int sumXor = 0;

        for (int i = 0; i < nums.size(); i++) {
            sumXor ^= nums[i];
        }

        return sumXor == 0 || nums.size() % 2 == 0;
    }
};
```

## Complexity
- **Time Complexity:** O(n) — One traversal to calculate the XOR.
- **Space Complexity:** O(1) — Only a single variable is used.

## What I Learned
- How XOR can be accumulated using the `^=` operator.
- The importance of the XOR identity: `a ^ a = 0`.
- How mathematical observations can replace game simulation.
- How array parity and the total XOR determine the winning condition.