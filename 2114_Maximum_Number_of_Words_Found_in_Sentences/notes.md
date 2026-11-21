# 2114. Maximum Number of Words Found in Sentences

## Problem
Given an array of strings `sentences`, where each string represents a sentence, return the maximum number of words present in any single sentence.

Words are separated by a single space.

## My Approach
Used nested traversal to count spaces in every sentence.

1. Initialize `ans = 0` to store the maximum space count.
2. Traverse every sentence using a range-based for loop.
3. For each sentence, initialize `count = 0`.
4. Traverse every character in the sentence.
5. Whenever a space (`' '`) is found, increment `count`.
6. Update `ans` with the maximum space count.
7. Return `ans + 1` because the number of words is always one more than the number of spaces.

## Key Logic
- Outer loop: Traverses every sentence.
- Inner loop: Traverses every character in the current sentence.
- `if(c == ' ')`: Counts the spaces.
- `ans = max(ans, count)`: Keeps track of the maximum number of spaces.
- `return ans + 1`: Converts the maximum space count into the maximum word count.

**Important:** A sentence containing N spaces has N + 1 words.

## Solution

```cpp
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;

        for(const string& s : sentences) {
            int count = 0;

            for(char c : s) {
                if(c == ' ') {
                    count++;
                }
            }

            ans = max(ans, count);
        }

        return ans + 1;
    }
};
```

## Complexity
- **Time Complexity:** O(N × L), where N is the number of sentences and L is the maximum sentence length.
- **Space Complexity:** O(1) auxiliary space.

## What I Learned
- How to traverse a vector of strings using range-based loops.
- How to count spaces to determine the number of words.
- The relationship between spaces and words: `words = spaces + 1`.
- How to maintain a maximum while processing multiple strings.