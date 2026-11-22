# 1662. Check If Two String Arrays are Equivalent

## Problem
Given two string arrays `word1` and `word2`, determine whether concatenating all elements of both arrays produces the same string.

Return `true` if they represent the same string; otherwise, return `false`.

## My Approach
Used the STL `accumulate()` function to concatenate all strings in each array.

1. Create an empty string `a`.
2. Use `accumulate()` on `word1` to concatenate all its elements.
3. Similarly, concatenate all elements of `word2` into string `b`.
4. Compare both strings using `a == b`.
5. Return the comparison result.

## Key Logic
- `accumulate()` combines all elements of a range into a single result.
- `string("")` provides an empty initial string.
- String concatenation joins the array elements in their original order.
- `a == b` checks whether both resulting strings are identical.

## Solution

```cpp
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = accumulate(word1.begin(), word1.end(), string(""));
        string b = accumulate(word2.begin(), word2.end(), string(""));

        return a == b;
    }
};
```

## Complexity
Let L be the total number of characters across both arrays.

- **Time Complexity:** O(L) — All characters are concatenated and then compared.
- **Space Complexity:** O(L) — Two resulting strings are created.

## What I Learned
- How to use `accumulate()` with strings.
- How to concatenate an entire vector of strings.
- Why the initial value `string("")` is important.
- How to compare two concatenated strings directly.