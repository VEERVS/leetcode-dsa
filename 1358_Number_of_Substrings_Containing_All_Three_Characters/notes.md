## Problem
Given a string `s` containing only the characters `'a'`, `'b'`, and `'c'`, return the number of substrings containing at least one occurrence of all three characters.

**LeetCode:** 1358. Number of Substrings Containing All Three Characters

## My Approach
I used a variable-size sliding window with an `unordered_map` to track character frequencies.

I expanded the window by moving `right` and increasing the frequency of `s[right]`. Whenever all three distinct characters were present, I counted the valid substrings and shrank the window from the left.

For every valid window ending at index `right`, the number of valid substrings is `s.size() - right`, because every extension to the right remains valid.

## Key Logic
1. Create an `unordered_map<char, int>` to store character frequencies.
2. Expand the window by incrementing `freq[s[right]]`.
3. While `freq.size() == 3`:
   - Add `s.size() - right` to the answer.
   - Decrease the frequency of `s[left]`.
   - Erase the character if its frequency becomes zero.
   - Move `left` forward.
4. Return the total count.

## Solution
```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> freq;
        int left = 0, count = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;

            while (freq.size() == 3) {
                count += s.size() - right;

                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }

                left++;
            }
        }

        return count;
    }
};
```

## Complexity
- **Time Complexity:** `O(n)` — each character enters and leaves the window at most once.
- **Space Complexity:** `O(1)` — the map stores at most three distinct characters.

## What I Learned
- Sliding windows can count substrings without generating every possible substring.
- Once a window contains all required characters, every extension to the right remains valid.
- `s.size() - right` counts all valid extensions of the current window.
- Removing zero-frequency characters keeps `freq.size()` accurate.
- The variable-size sliding window gives a linear-time solution.