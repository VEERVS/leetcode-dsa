## Problem
Given a string `answerKey` containing `'T'` and `'F'`, and an integer `k`, return the maximum number of consecutive identical answers possible after changing at most `k` characters.

**LeetCode:** 2024. Maximize the Confusion of an Exam

## My Approach
I used a variable-size sliding window with two frequency counters to track the number of `'T'` and `'F'` characters.

The idea is to make every character in the current window identical by replacing the less frequent character.

The number of replacements required is:

`windowLength - max(countT, countF)`

If this exceeds `k`, I shrink the window from the left and update the corresponding frequency counter.

After restoring the window's validity, I update the maximum window length.

## Key Logic
1. Initialize `countT`, `countF`, `left`, and `ans` to zero.
2. Expand the window by adding the current character's frequency.
3. Calculate the replacements required:

   `windowLength - max(countT, countF)`

4. While the replacements required exceed `k`:
   - Decrease the frequency of the outgoing character.
   - Increment `left`.
5. Update `ans = max(ans, right - left + 1)`.
6. Return `ans`.

## Solution
```cpp
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int countF = 0, countT = 0;
        int left = 0, ans = 0;

        for (int right = 0; right < answerKey.size(); right++) {
            if (answerKey[right] == 'T') {
                countT++;
            } else {
                countF++;
            }

            while ((right - left + 1) - max(countT, countF) > k) {
                if (answerKey[left] == 'T') {
                    countT--;
                } else {
                    countF--;
                }

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
```

## Complexity
- **Time Complexity:** `O(n)` — each character enters and leaves the window at most once.
- **Space Complexity:** `O(1)` — only two frequency counters and a few variables are used.

## What I Learned
- Sliding windows can maintain constraints based on character frequencies.
- The majority character determines the minimum number of replacements.
- `windowLength - maximumFrequency` calculates the minimum replacements needed to make a window uniform.
- Shrink the window whenever the replacement limit is exceeded.
- This pattern is useful for problems involving at most `k` replacements.