## Problem

Given a string `s`, find the length of the longest substring without repeating characters.

A substring must contain consecutive characters from the original string.

## My Approach

Use a variable-size sliding window with an `unordered_set<char>`.

Maintain two pointers:
- `left`: Start of the current window.
- `right`: End of the current window.

Expand the window using `right`. If the current character already exists in the set, remove characters from the left until the duplicate is eliminated.

Update the maximum window length after inserting the current character.

## Key Logic

- Use `seen.count(s[right])` to check whether a character already exists.
- While a duplicate exists, erase `s[left]` and increment `left`.
- Insert the current character into the set.
- Calculate the current window length using `right - left + 1`.
- Update the maximum length with `max()`.

Example: `"abcabcbb"`

The longest substring without repeating characters is `"abc"`, with length 3.

## Solution

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, ans = 0;
        unordered_set<char> seen;

        for (int right = 0; right < s.size(); right++) {
            while (seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }

            seen.insert(s[right]);
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};