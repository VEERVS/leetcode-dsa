# 1704. Determine if String Halves Are Alike

## Problem
Given a string `s` of even length, divide it into two equal halves:

- `a`: First half.
- `b`: Second half.

Two halves are alike if they contain the same number of vowels.

Vowels include both uppercase and lowercase characters: `a, e, i, o, u, A, E, I, O, U`.

Return `true` if both halves are alike; otherwise, return `false`.

## My Approach
Used two separate counters to count vowels in each half.

1. Initialize `count1 = 0` and `count2 = 0`.
2. Traverse the first half of the string, from index `0` to `s.size()/2 - 1`.
3. Check whether each character is a vowel (uppercase or lowercase).
4. Increment `count1` whenever a vowel is found.
5. Traverse the second half, from index `s.size()/2` to the end.
6. Count its vowels using `count2`.
7. Return `true` if both counters are equal.

## Key Logic
- `s.size()/2` gives the midpoint of the even-length string.
- First loop counts vowels in the first half.
- Second loop counts vowels in the second half.
- Both uppercase and lowercase vowels are checked explicitly.
- `count1 == count2` determines whether the halves are alike.

## Solution

```cpp
class Solution {
public:
    bool halvesAreAlike(string s) {
        int count1 = 0, count2 = 0;

        for(int i = 0; i < s.size()/2; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
               s[i] == 'o' || s[i] == 'u' || s[i] == 'A' ||
               s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
               s[i] == 'U') {
                count1++;
            }
        }

        for(int i = s.size()/2; i < s.size(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
               s[i] == 'o' || s[i] == 'u' || s[i] == 'A' ||
               s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
               s[i] == 'U') {
                count2++;
            }
        }

        return count1 == count2;
    }
};
```

## Complexity
- **Time Complexity:** O(n) — Both halves are traversed once, together covering the entire string.
- **Space Complexity:** O(1) — Only two counters are used.

## What I Learned
- How to divide an even-length string into two equal halves.
- How to count specific characters using conditions.
- How to handle uppercase and lowercase vowels.
- How to compare character frequencies across two portions of a string.