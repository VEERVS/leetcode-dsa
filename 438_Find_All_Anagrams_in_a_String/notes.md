## Problem

Given two strings `s` and `p`, return an array containing all starting indices of the anagrams of `p` in `s`.

Anagrams contain the same characters with the same frequencies, regardless of order.

## My Approach

Use a fixed-size sliding window and two frequency arrays of size 26.

- `pFreq` stores the character frequencies of `p`.
- `winFreq` stores the character frequencies of the current window in `s`.
- The window size is equal to `p.size()`.

Build the frequency arrays for `p` and the first window of `s`. If they match, store index `0`.

Then slide the window one character at a time, updating the frequencies. Whenever both arrays match, add the window's starting index to the answer.

## Key Logic

- If `p.size() > s.size()`, return an empty answer.
- Convert lowercase characters to array indices using `character - 'a'`.
- Compare frequencies using `pFreq == winFreq`.
- Remove the outgoing character using `winFreq[s[i-k] - 'a']--`.
- Add the incoming character using `winFreq[s[i] - 'a']++`.
- The starting index of each new window is `i - k + 1`.
- Store every matching index because multiple anagrams may exist.

## Solution

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pFreq(26, 0);
        vector<int> winFreq(26, 0);
        vector<int> ans;
        int k = p.size();

        if (k > s.size()) return ans;

        for (int i = 0; i < k; i++) {
            pFreq[p[i] - 'a']++;
            winFreq[s[i] - 'a']++;
        }

        if (pFreq == winFreq) {
            ans.push_back(0);
        }

        for (int i = k; i < s.size(); i++) {
            winFreq[s[i-k] - 'a']--;
            winFreq[s[i] - 'a']++;

            if (pFreq == winFreq) {
                ans.push_back(i-k+1);
            }
        }

        return ans;
    }
};
```

## Complexity

- Time: O(n), where n is the length of `s`, because each window update takes constant time and comparing 26 frequencies is O(26).
- Auxiliary space: O(1), excluding the answer vector.
- Output space: O(n) in the worst case for storing matching indices.

## What I Learned

- How to find every anagram using a fixed-size sliding window.
- How frequency arrays detect anagrams without sorting.
- How to maintain window frequencies in constant time per movement.
- Why the initial window must be checked separately.
- Why `i - k + 1` gives the starting index of the current window.
- How this problem extends LeetCode 567 by collecting all matches instead of returning a boolean.