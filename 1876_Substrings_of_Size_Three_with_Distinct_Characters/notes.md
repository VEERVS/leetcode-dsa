## Problem
A string is called good if it contains no repeated characters.

Given a string `s`, return the number of good substrings of length exactly three.

**LeetCode:** 1876. Substrings of Size Three with Distinct Characters

## My Approach
I used a fixed-size sliding window of length three.

Since every required substring must contain exactly three characters, I traversed the string starting from index 2.

For each position, I checked whether the current character and the two preceding characters were all different.

If all three characters were distinct, I incremented the answer.

## Key Logic
1. If the string length is less than 3, return 0.
2. Initialize `count = 0`.
3. Start traversing from index 2.
4. Check whether:
   - `s[i] != s[i - 1]`
   - `s[i - 1] != s[i - 2]`
   - `s[i] != s[i - 2]`
5. If all conditions hold, increment `count`.
6. Return the total count.

## Solution
```cpp
class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.size() < 3) return 0;

        int count = 0;

        for (int i = 2; i < s.size(); i++) {
            if (s[i] != s[i - 1] &&
                s[i - 1] != s[i - 2] &&
                s[i] != s[i - 2]) {
                count++;
            }
        }

        return count;
    }
};
```

## Complexity
- **Time Complexity:** `O(n)` — each possible substring is checked once.
- **Space Complexity:** `O(1)` — only a counter is maintained.

## What I Learned
- Fixed-size sliding windows are useful when the required substring length is given.
- A window of size three can be checked using three pairwise comparisons.
- Every index from 2 onward represents the ending position of one possible substring.
- Direct comparisons can be more efficient than using a frequency map when the window is very small.