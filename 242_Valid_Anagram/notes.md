## Problem

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

An anagram is formed by rearranging the characters of another string while using every character exactly the same number of times.

## My Approach

I use sorting to determine whether the two strings contain exactly the same characters.

First, I sort string `s` in ascending order.

Then, I sort string `t` in ascending order.

If both strings are anagrams, sorting them will produce identical strings because they contain the same characters with the same frequencies.

Finally, I compare the sorted strings using `==`.

If they are equal, I return `true`. Otherwise, I return `false`.

## Key Logic

Sort both strings:

```cpp
sort(s.begin(), s.end());
sort(t.begin(), t.end());
```

Compare the sorted strings:

```cpp
return s == t;
```

**Example 1:**

```text
Input:
s = "anagram"
t = "nagaram"

After sorting:

s = "aaagmnr"
t = "aaagmnr"

Output: true
```

Both strings contain the same characters with the same frequencies.

**Example 2:**

```text
Input:
s = "rat"
t = "car"

After sorting:

s = "art"
t = "acr"

Output: false
```

The sorted strings are different, so they are not anagrams.

## Solution

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};
```

## Complexity

Let `n` be the length of `s` and `m` be the length of `t`.

- **Time:** `O(n log n + m log m)` because both strings are sorted.
- **Space:** Typically `O(log n + log m)` auxiliary stack space for `std::sort`, excluding the string copies created by pass-by-value parameters.

## What I Learned

- Two strings are anagrams if they contain identical characters with identical frequencies.
- Sorting converts different character arrangements into a common order.
- `sort(s.begin(), s.end())` sorts a string in ascending character order.
- The `==` operator compares two strings character by character.
- Sorting provides a simple solution without manually counting character frequencies.
- A frequency array of size `26` can optimize this problem to `O(n + m)` time and `O(1)` auxiliary space because the strings contain only lowercase English letters.