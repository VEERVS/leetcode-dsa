## Problem

A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string `sentence` containing only lowercase English letters, return `true` if `sentence` is a pangram, or `false` otherwise.

## My Approach

I use an `unordered_map<char, int>` to store the frequency of each character in the sentence.

I traverse the string using a range-based `for` loop and increment the frequency of every character.

Since an `unordered_map` stores each unique character only once, its size tells me how many distinct letters appear.

If the map contains exactly 26 unique characters, the sentence is a pangram.

## Key Logic

Increment the frequency of every character:

```cpp
freq[c]++;
```

Check whether all 26 letters are present:

```cpp
return freq.size() == 26;
```

For example, `"thequickbrownfoxjumpsoverthelazydog"` contains every letter from `a` to `z`, so the answer is `true`.

## Solution

```cpp
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> freq;

        for(char c : sentence) {
            freq[c]++;
        }

        return freq.size() == 26;
    }
};
```

## Complexity

- **Time:** `O(n)` average, where `n` is the length of the sentence.
- **Space:** `O(1)` auxiliary space because the map can contain at most 26 distinct lowercase letters.

## What I Learned

- An `unordered_map` stores unique keys.
- `freq.size()` counts distinct characters, not their total occurrences.
- A pangram must contain every letter from `a` to `z` at least once.