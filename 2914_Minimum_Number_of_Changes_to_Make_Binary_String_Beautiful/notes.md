# 2914. Minimum Number of Changes to Make Binary String Beautiful

## Problem
Given an even-length binary string `s`, find the minimum number of character changes required to make it beautiful.

A string is beautiful if it can be partitioned into substrings such that:
- Every substring has an even length.
- Every substring contains only `0`s or only `1`s.

## My Approach
Used greedy pair checking.

1. Initialize `count = 0`.
2. Traverse the string in non-overlapping pairs using `i += 2`.
3. Compare the two characters in each pair.
4. If they are different, increment `count`.
5. Return the total count.

## Key Logic
- `i += 2`: Processes non-overlapping pairs.
- `s[i] != s[i+1]`: Checks whether the current pair contains different characters.
- Every mismatched pair requires exactly one change.
- Every matching pair requires zero changes.

For example:

`1001` → `10 | 01`

Both pairs contain different characters, so the answer is `2`.

## Solution

```cpp
class Solution {
public:
    int minChanges(string s) {
        int count = 0;

        for(int i = 0; i < s.size(); i += 2) {
            if(s[i] != s[i+1]) {
                count++;
            }
        }

        return count;
    }
};
```

## Complexity
- **Time Complexity:** O(N) — Each character is visited exactly once.
- **Space Complexity:** O(1) — Only a counter is used.

## What I Learned
- How to traverse an array or string in pairs.
- How to use greedy decisions for minimum changes.
- Why comparing adjacent pairs is sufficient for this problem.
- How to solve a problem without using extra data structures.