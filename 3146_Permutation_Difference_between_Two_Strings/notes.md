# 3146. Permutation Difference between Two Strings

## Problem
Given two strings `s` and `t`, where `t` is a permutation of `s` and every character occurs at most once, calculate the sum of the absolute differences between the positions of each character in both strings.

Return the permutation difference.

## My Approach
Used a vector of size 26 to store the indices of lowercase English characters.

1. Initialize `indices` with 26 elements.
2. Traverse string `s` and store the index of each character using `indices[s[i] - 'a'] = i`.
3. Traverse string `t`.
4. For every character in `t`, retrieve its original index from `indices`.
5. Calculate the absolute difference between its index in `s` and its current index in `t`.
6. Add the difference to the answer.

## Key Logic
- `indices[s[i] - 'a'] = i`: Stores the position of each character in string `s`.
- `indices[t[i] - 'a']`: Retrieves the position of the same character in `s`.
- `abs(indices[t[i] - 'a'] - i)`: Calculates the absolute difference between the two positions.
- Accumulate all differences in `ans`.

## Solution

```cpp
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int ans = 0;
        vector<int> indices(26);

        for (int i = 0; i < s.length(); ++i) {
            indices[s[i] - 'a'] = i;
        }

        for (int i = 0; i < t.length(); ++i) {
            ans += abs(indices[t[i] - 'a'] - i);
        }

        return ans;
    }
};
```

## Complexity
- **Time Complexity:** O(n) — Two traversals of the strings.
- **Space Complexity:** O(1) — The vector always contains exactly 26 elements.

## What I Learned
- How to use character-to-index mapping with a vector.
- How subtracting `'a'` converts lowercase characters into indices from 0 to 25.
- How to retrieve character positions in constant time.
- How to calculate permutation differences using absolute differences.