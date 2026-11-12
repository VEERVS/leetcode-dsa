# 3227. Vowels Game in a String

## Problem
Alice and Bob play a game on a string `s`.

- Alice starts first and must remove a non-empty substring containing an odd number of vowels.
- Bob must remove a non-empty substring containing an even number of vowels.
- The first player unable to make a move loses.

Return `true` if Alice wins, assuming both players play optimally.

## My Approach
Used a simple vowel-counting approach based on a mathematical observation.

1. Initialize a counter `count = 0`.
2. Traverse the entire string.
3. Check whether each character is one of the five vowels: `a`, `e`, `i`, `o`, or `u`.
4. Increment the counter whenever a vowel is found.
5. If the string contains zero vowels, return `false`.
6. Otherwise, return `true`.

## Key Logic
- If the string contains no vowels, Alice cannot make her first move and loses.
- If the string contains at least one vowel, Alice can always force a win.
- Therefore, the result depends only on whether at least one vowel exists.

## Solution

```cpp
class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' ||
                s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                count++;
            }
        }

        if (!count) return false;

        return true;
    }
};
```

## Complexity
- **Time Complexity:** O(n) — Traverse the string once.
- **Space Complexity:** O(1) — Only a counter is used.

## What I Learned
- How to identify vowels using character comparisons.
- How to simplify a game-theory problem through a mathematical observation.
- How to avoid unnecessary game simulation when a decisive property determines the outcome.