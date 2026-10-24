## Problem

Given two strings `s1` and `s2`, return `true` if `s2` contains a permutation of `s1`. Otherwise, return `false`.

A permutation contains the same characters with the same frequencies, but the characters may appear in a different order.

## My Approach

Use a fixed-size sliding window and two frequency arrays of size 26.

- `s1Freq` stores the character frequencies of `s1`.
- `winFreq` stores the character frequencies of the current window in `s2`.
- The window size is equal to `s1.size()`.

First, count the characters in `s1` and the first window of `s2`. Compare the frequency arrays. Then slide the window by removing the outgoing character and adding the incoming character.

Return `true` if the arrays match at any point; otherwise, return `false`.

## Key Logic

- If `s1.size() > s2.size()`, return `false`.
- Convert lowercase characters to array indices using `character - 'a'`.
- Compare frequency arrays using `s1Freq == winFreq`.
- Remove the outgoing character using `winFreq[s2[i-k] - 'a']--`.
- Add the incoming character using `winFreq[s2[i] - 'a']++`.
- Return `true` immediately when both arrays match.

## Solution

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1Freq(26, 0);
        vector<int> winFreq(26, 0);
        int k = s1.size();

        for (int i = 0; i < k; i++) {
            s1Freq[s1[i] - 'a']++;
            winFreq[s2[i] - 'a']++;
        }

        if (s1Freq == winFreq) {
            return true;
        }

        for (int i = k; i < s2.size(); i++) {
            winFreq[s2[i-k] - 'a']--;
            winFreq[s2[i] - 'a']++;

            if (s1Freq == winFreq) {
                return true;
            }
        }

        return false;
    }
};
```

## Complexity

- Time: O(n), where n is the length of `s2`, because each window update takes constant time and comparing 26 frequencies is O(26).
- Space: O(1), because the frequency arrays have fixed size 26.

## What I Learned

- How permutations can be identified using character frequencies.
- How to maintain a fixed-size sliding window.
- How to remove outgoing and add incoming characters efficiently.
- How to compare frequency arrays to detect a permutation.
- Why checking whether `s1` is longer than `s2` prevents invalid indexing.