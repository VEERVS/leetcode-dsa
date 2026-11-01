## Problem
Given a string `s`, return the maximum length of a substring such that each character appears at most twice.

**LeetCode:** 3090. Maximum Length Substring With Two Occurrences

## My Approach
I used a variable-size sliding window with a frequency array of size 26 to track lowercase English letters.

I expanded the window by increasing the frequency of the current character.

If the current character appeared more than twice, I shrank the window from the left until its frequency became valid again.

After restoring the window's validity, I updated the maximum substring length.

## Key Logic
1. Initialize a frequency array of size 26 with zeros.
2. Expand the window by incrementing `freq[s[right] - 'a']`.
3. While the frequency of the current character exceeds 2:
   - Decrease the frequency of `s[left]`.
   - Increment `left`.
4. Update the answer using `right - left + 1`.
5. Return the maximum length.

## Solution
```cpp
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int freq[26] = {};
        int left = 0, ans = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'a']++;

            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
```

## Complexity
- **Time Complexity:** `O(n)` — every character enters and leaves the window at most once.
- **Space Complexity:** `O(1)` — the frequency array always contains exactly 26 positions.

## What I Learned
- Frequency arrays are useful when the character set is fixed and small.
- `s[i] - 'a'` converts a lowercase character into an array index from 0 to 25.
- A variable-size window can maintain a maximum occurrence constraint.
- Shrinking the window restores the frequency constraint.
- The same pattern can be extended to problems allowing at most `k` occurrences of each character.