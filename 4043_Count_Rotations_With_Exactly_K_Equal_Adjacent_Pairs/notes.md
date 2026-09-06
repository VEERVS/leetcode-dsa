## Problem

Given a string `s` and an integer `k`, count how many cyclic rotations of `s` have exactly `k` pairs of adjacent equal characters.

A cyclic rotation moves some prefix of the string to the end while keeping the order of characters.

For each rotation, we count how many adjacent positions contain the same character.

## My Approach

I used brute force by checking all possible rotations.

Instead of actually creating every rotated string, I used modulo indexing to simulate each rotation directly from the original string.

For a rotation starting at index `i`, the character at position `j` can be accessed using:

`(i + j) % n`

I then compared each character with the next character in that rotation and counted equal adjacent pairs.

If the score became exactly `k`, I increased the answer.

## Key Logic

The important idea was using modulo to simulate rotations.

For a rotation starting at `i`:

` s[(i + j) % n] `

gives the character at the current position.

The next character is:

` s[(i + j + 1) % n] `

The modulo makes the index wrap back to the beginning of the string.

I only check `n - 1` adjacent pairs because the problem does not consider the last character and the first character as an adjacent pair.

## Solution

```c
#include <string.h>

int countRotations(char* s, int k) {
    int n = strlen(s);
    int ans = 0;

    for(int i = 0; i < n; i++) {
        int score = 0;

        for(int j = 0; j < n - 1; j++) {
            if(s[(i + j) % n] == s[(i + j + 1) % n]) {
                score++;
            }
        }

        if(score == k) {
            ans++;
        }
    }

    return ans;
}
```

## Complexity

Time: `O(n²)`

Space: `O(1)`

## What I Learned

I learned how to simulate cyclic rotations using modulo without actually creating new strings.

The main pattern is `(start + index) % n`, which allows the index to wrap around when it reaches the end.

I also learned that sometimes brute force is a perfectly valid approach when the constraints allow it.