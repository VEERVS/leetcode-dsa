# 2710. Remove Trailing Zeros From a String

## Problem
Given a positive integer `num` represented as a string, remove all trailing zeros and return the resulting string.

## My Approach
Used a `while` loop to remove zeros from the end of the string.

1. Check whether the last character is `'0'`.
2. Also ensure the string is not empty.
3. If both conditions are true, remove the last character using `pop_back()`.
4. Repeat until the last character is no longer `'0'`.
5. Return the modified string.

## Key Logic
- `num.back()` accesses the last character of the string.
- `num.pop_back()` removes the last character.
- `while` repeatedly removes trailing zeros.
- `!num.empty()` ensures the string is not empty before accessing its last character.

Example:

`"51230100"` → `"5123010"` → `"512301"`

## Solution

```cpp
class Solution {
public:
    string removeTrailingZeros(string num) {
        while(num.back() == '0' && !num.empty()) {
            num.pop_back();
        }

        return num;
    }
};
```

## Complexity
- **Time Complexity:** O(N) — In the worst case, every character is removed.
- **Space Complexity:** O(1) auxiliary space — The string is modified in place.

## What I Learned
- How to access the last character using `back()`.
- How to remove the last character using `pop_back()`.
- How to use a while loop for repeated removal.
- How to manipulate strings without creating another string.