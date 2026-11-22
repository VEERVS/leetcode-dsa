# 2124. Check if All A's Appears Before All B's

## Problem
Given a string `s` containing only `'a'` and `'b'`, return `true` if every `'a'` appears before every `'b'`.

Otherwise, return `false`.

## My Approach
Used a single loop to check adjacent characters.

1. Traverse the string using a loop.
2. Check whether the current character is `'b'` and the next character is `'a'`.
3. If this pattern is found, return `false` immediately.
4. If the entire string is traversed without finding this pattern, return `true`.

## Key Logic
- The invalid pattern is `"ba"`.
- Once a `'b'` appears, no `'a'` should appear after it.
- Checking adjacent characters is sufficient because any violation must contain a transition from `'b'` to `'a'`.
- If no such transition exists, the string satisfies the condition.

Examples:
- `"aaabbb"` → true
- `"abab"` → false
- `"bbb"` → true

## Solution

```cpp
class Solution {
public:
    bool checkString(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'b' && s[i+1] == 'a') {
                return false;
            }
        }

        return true;
    }
};
```

## Complexity
- **Time Complexity:** O(N) — The string is traversed once.
- **Space Complexity:** O(1) — No extra data structure is used.

## What I Learned
- How to detect invalid adjacent character patterns.
- How to use early returns to avoid unnecessary traversal.
- Why checking the transition from `'b'` to `'a'` is sufficient.
- How a simple adjacent comparison can verify an ordering condition.