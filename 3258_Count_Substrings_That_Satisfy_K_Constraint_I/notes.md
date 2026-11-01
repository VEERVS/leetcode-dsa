## Problem
Given a binary string `s` and an integer `k`, a substring satisfies the k-constraint if either:
- The number of `0`s is at most `k`.
- The number of `1`s is at most `k`.

Return the total number of substrings satisfying the k-constraint.

**LeetCode:** 3258. Count Substrings That Satisfy K-Constraint I

## My Approach
I used a variable-size sliding window with two frequency counters: `oneCount` and `zeroCount`.

I expanded the window by counting the current character.

The window becomes invalid only when both the number of zeros and the number of ones exceed `k`.

Whenever the window became invalid, I shrank it from the left until at least one of the two counts became less than or equal to `k`.

For every valid window, I added `right - left + 1` to the answer because every substring ending at `right` and starting between `left` and `right` is valid.

## Key Logic
1. Initialize `left`, `ans`, `oneCount`, and `zeroCount`.
2. Expand the window and update the appropriate frequency counter.
3. While `oneCount > k && zeroCount > k`:
   - Decrease the frequency of the outgoing character.
   - Increment `left`.
4. Add `right - left + 1` to the answer.
5. Return the total count.

## Solution
```cpp
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int left = 0, ans = 0;
        int oneCount = 0, zeroCount = 0;

        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '1') {
                oneCount++;
            } else {
                zeroCount++;
            }

            while (oneCount > k && zeroCount > k) {
                if (s[left] == '1') {
                    oneCount--;
                } else {
                    zeroCount--;
                }

                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};
```

## Complexity
- **Time Complexity:** `O(n)` — each character enters and leaves the window at most once.
- **Space Complexity:** `O(1)` — only a few counters are maintained.

## What I Learned
- A window can be invalid when multiple conditions are violated simultaneously.
- The `&&` operator is important when validity requires either condition to hold.
- `right - left + 1` counts all valid substrings ending at the current right pointer.
- Sliding windows can count substrings based on binary character frequencies.