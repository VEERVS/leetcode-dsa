## Problem

Given a string `s` containing lowercase English letters, split it into the maximum number of substrings such that every substring starts with a distinct character.

Return the maximum number of substrings possible.

## My Approach

I realized that the only thing that matters is whether a character has already appeared as the starting character.

Since there are only 26 lowercase English letters, I used a frequency/seen array of size `26`.

For each character:
- Convert it to an index using `s[i] - 'a'`.
- If it has not been seen before, mark it as seen and increase `count`.
- If it has already been seen, ignore it.

Thus, the answer is simply the number of distinct characters in the string.

## Key Logic

```c
s[i] - 'a'
```

converts a lowercase character into an index:

```text
'a' → 0
'b' → 1
'c' → 2
...
'z' → 25
```

The array stores whether we have already seen that character.

For:

```text
s = "abab"
```

we get:

```text
a → new → count = 1
b → new → count = 2
a → already seen
b → already seen
```

Answer:

```text
2
```

## Solution

```c
int maxDistinct(char* s) {
    int freq[26] = {0};
    int count = 0;

    for(int i = 0; s[i] != '\0'; i++) {
        if(freq[s[i] - 'a'] == 0) {
            freq[s[i] - 'a'] = 1;
            count++;
        }
    }

    return count;
}
```

## Complexity

- Time: `O(n)`
- Space: `O(1)` because the array always has only 26 elements.

## What I Learned

- Character frequency/seen arrays are extremely useful for string problems.
- `s[i] - 'a'` maps lowercase letters to indices `0–25`.
- When I only need to know whether something has appeared, a `0/1` array is enough; I don't need the actual frequency.
- This is a basic pattern that will appear frequently in string and hashing problems.