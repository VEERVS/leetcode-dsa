## Problem

Given a string `s`, calculate its score.

The score is the sum of the absolute differences between the ASCII values of every pair of adjacent characters.

For example:

```text
"hello"

|h - e| + |e - l| + |l - l| + |l - o|
```

## My Approach

I traversed the string from left to right and compared every character with the next character.

For each position:

```c
abs(s[i] - s[i + 1])
```

gives the absolute ASCII difference between two adjacent characters.

I added every difference to `sum`.

The loop must stop before the last character because the last character has no next character.

## Key Logic

For:

```text
s = "hello"
```

the calculation is:

```text
|h - e| = 3
|e - l| = 7
|l - l| = 0
|l - o| = 3

3 + 7 + 0 + 3 = 13
```

The important boundary condition is:

```c
s[i + 1] != '\0'
```

This prevents comparing the last character with the null terminator.

## Solution

```c
#include <stdlib.h>

int scoreOfString(char* s) {
    int sum = 0, diff;

    for(int i = 0; s[i + 1] != '\0'; i++) {
        diff = abs(s[i] - s[i + 1]);
        sum += diff;
    }

    return sum;
}
```

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## What I Learned

- Characters can be directly used in arithmetic because they have ASCII values.
- `abs()` gives the absolute difference.
- When using `s[i + 1]`, I need to carefully handle the last character.
- I learned an important off-by-one boundary condition while debugging this problem.