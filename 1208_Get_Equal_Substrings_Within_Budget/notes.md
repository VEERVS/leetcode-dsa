## Problem

Given two strings `s` and `t` of equal length and an integer `maxCost`, find the maximum length of a substring of `s` that can be changed into the corresponding substring of `t` without exceeding `maxCost`.

The cost of changing a character is `abs(s[i] - t[i])`.

## My Approach

Use a variable-size sliding window with two pointers, `left` and `right`.

Maintain a running sum of the character conversion costs inside the current window.

- Expand the window by moving `right` forward and adding the new character's cost.
- If the total cost exceeds `maxCost`, shrink the window from the left until it becomes valid.
- Update the maximum valid window length after each iteration.

## Key Logic

- Calculate each character's conversion cost using `abs(s[right] - t[right])`.
- Add the cost to `sum`.
- While `sum > maxCost`, subtract the cost at `left` and increment `left`.
- Calculate the current window length using `right - left + 1`.
- Update the answer using `ans = max(ans, right - left + 1)`.

Example: `s = "abcd"`, `t = "bcdf"`, `maxCost = 3`.

The character costs are `[1, 1, 1, 2]`. The substring `"abc"` costs 3, so the maximum valid length is 3.

## Solution

```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int sum = 0, ans = 0, left = 0;

        for (int right = 0; right < s.size(); right++) {
            sum += abs(s[right] - t[right]);

            while (sum > maxCost) {
                sum -= abs(s[left] - t[left]);
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
```

## Complexity

- Time: O(n), because each pointer moves forward at most n times.
- Space: O(1), because only a constant number of variables are used.

## What I Learned

- How variable-size sliding windows work with a running cost.
- How to shrink a window until it satisfies a constraint.
- Why the left pointer only moves forward.
- How to track the maximum valid window length.
- How the sliding-window technique handles budget-constrained substring problems efficiently.