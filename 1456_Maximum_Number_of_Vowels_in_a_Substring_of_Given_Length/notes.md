## Problem
Given a string `s` and an integer `k`, return the maximum number of vowels in any substring of length `k`.

The vowels are `a`, `e`, `i`, `o`, and `u`.

## My Approach
I counted the vowels in the first `k` characters and initialized `maxVow` with that count.

Then I slid the window through the string. For every slide, I added one if the incoming character was a vowel and subtracted one if the outgoing character was a vowel. I updated the maximum after each slide.

## Key Logic
- Count the vowels in the initial window.
- Set `maxVow = vowCount`.
- Start the sliding loop at `i = k`.
- Check the incoming character `s[i]` and increment the count if it is a vowel.
- Check the outgoing character `s[i-k]` and decrement the count if it is a vowel.
- Update the maximum using `max(maxVow, vowCount)`.

## Solution
```cpp
class Solution {
public:
    int maxVowels(string s, int k) {
        int vowCount = 0;

        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u') {
                vowCount++;
            }
        }

        int maxVow = vowCount;

        for (int i = k; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u') {
                vowCount++;
            }

            if (s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' ||
                s[i-k] == 'o' || s[i-k] == 'u') {
                vowCount--;
            }

            maxVow = max(maxVow, vowCount);
        }

        return maxVow;
    }
};
```

## Complexity
- Time: `O(n)`.
- Auxiliary space: `O(1)`.

## What I Learned
- A fixed-size sliding window can track counts, not just sums.
- Add the incoming character and remove the outgoing character.
- Initialize the maximum with the first window so that it is included.
- Update the maximum after every slide.
- Maintaining a running count avoids recounting every substring from scratch.