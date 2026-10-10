## Problem

Given a string `s` consisting of lowercase English letters, return the first letter to appear twice.

The answer is the character whose second occurrence appears earliest in the string.

## My Approach

I used an `unordered_map<char, int>` to count the frequency of each character while traversing the string from left to right.

For every character, I increment its frequency. As soon as its frequency becomes `2`, I return that character.

Since the string is traversed from left to right, the first character whose frequency reaches `2` is the required answer.

## Key Logic

```cpp
unordered_map<char, int> freq;

for(char c : s){
    freq[c]++;

    if(freq[c] == 2){
        return c;
    }
}
```

For example:

```text
s = "abccbaacz"

a → frequency 1
b → frequency 1
c → frequency 1
c → frequency 2 → return 'c'
```

We return immediately when the second occurrence is found.

## Solution

```cpp
class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> freq;

        for(char c : s){
            freq[c]++;

            if(freq[c] == 2){
                return c;
            }
        }

        return 0;
    }
};
```

## Complexity

- **Time:** `O(n)` average
- **Space:** `O(1)` for this problem because the string contains only lowercase English letters, giving at most 26 distinct keys.

## What I Learned

- An `unordered_map<char, int>` can track character frequencies.
- A frequency can be checked immediately after incrementing it.
- Returning immediately avoids processing unnecessary characters.
- Traversal order matters when the problem asks for the first repeated character.
- Hashing can solve this problem in one pass.