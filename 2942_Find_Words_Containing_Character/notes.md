# 2942. Find Words Containing Character

## Problem
Given an array of strings `words` and a character `x`, return the indices of all words that contain the character `x`.

Each index should appear only once in the result.

## My Approach
Used nested loops to check every character in every word.

1. Create an empty vector `ans` to store the matching indices.
2. Traverse the words using the outer loop.
3. For each word, traverse its characters using the inner loop.
4. If a character matches `x`:
   - Add the current word index `i` to `ans`.
   - Use `break` to stop checking that word.
5. Return `ans`.

## Key Logic
- Outer loop: Iterates through every word.
- Inner loop: Checks every character of the current word.
- `if(c == x)`: Checks whether the character matches.
- `ans.push_back(i)`: Stores the index of the matching word.
- `break`: Prevents adding the same index multiple times.

## Solution

```cpp
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        for(int i = 0; i < words.size(); i++) {
            for(char c : words[i]) {
                if(c == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};
```

## Complexity
- **Time Complexity:** O(N × L), where N is the number of words and L is the maximum word length.
- **Space Complexity:** O(N) for the resulting vector.

## What I Learned
- How to use nested loops with strings.
- How to use a range-based for loop to traverse characters.
- Why `break` is useful when only one match per word is required.
- How to collect indices satisfying a condition.