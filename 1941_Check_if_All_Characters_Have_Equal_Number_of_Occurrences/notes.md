## Problem

Given a string `s`, return `true` if `s` is a good string, or `false` otherwise.

A string is good if all characters that appear in it have the same number of occurrences.

## My Approach

I use an `unordered_map<char, int>` to store the frequency of every character in the string.

First, I traverse the string and increment the frequency of each character.

Then, I store the frequency of the first character in a variable `val`. This becomes the reference frequency.

Next, I traverse the frequency map. If any character has a frequency different from `val`, I return `false`.

If every character has the same frequency, I return `true`.

## Key Logic

Count the frequency of every character:

```cpp
for(char x : s) {
    freq[x]++;
}
```

Store the frequency of the first character:

```cpp
int val = freq[s[0]];
```

Compare every character's frequency with the reference:

```cpp
for(auto& pair : freq) {
    if(pair.second != val) {
        return false;
    }
}
```

**Example 1:**

```text
Input:  "abacbc"

Frequencies:
a → 2
b → 2
c → 2

Output: true
```

**Example 2:**

```text
Input:  "aaabb"

Frequencies:
a → 3
b → 2

Output: false
```

## Solution

```cpp
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> freq;

        for(char x : s) {
            freq[x]++;
        }

        int val = freq[s[0]];

        for(auto& pair : freq) {
            if(pair.second != val) {
                return false;
            }
        }

        return true;
    }
};
```

## Complexity

- **Time:** `O(n)` average, where `n` is the length of the string.
- **Space:** `O(1)` auxiliary space because the number of possible characters is bounded by the alphabet.

## What I Learned

- An `unordered_map` is useful for counting character frequencies.
- The first character's frequency can serve as a reference value.
- Comparing every frequency against one reference is enough to check equality.
- Returning `false` immediately avoids unnecessary comparisons when a mismatch is found.