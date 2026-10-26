## Problem

Given a binary array `nums`, delete exactly one element and return the length of the longest non-empty subarray containing only `1`s in the resulting array.

## My Approach

Use a variable-size sliding window that allows at most one zero.

Maintain:
- `left`: Starting index of the current window.
- `zeros`: Number of zeros inside the window.
- `ans`: Maximum valid subarray length after deleting one element.

Expand the window using `right`. Whenever the window contains more than one zero, shrink it from the left until at most one zero remains.

Since exactly one element must be deleted, calculate the answer using `right - left`, not `right - left + 1`.

## Key Logic

- Increase `zeros` whenever `nums[right] == 0`.
- While `zeros > 1`, remove elements from the left.
- Decrease `zeros` only when the outgoing element is zero.
- Update the answer using `ans = max(ans, right - left)`.
- Subtracting one from the window length accounts for the mandatory deletion.

## Solution

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, zeros = 0, left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                zeros++;
            }

            while (zeros > 1) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }

            ans = max(ans, right - left);
        }

        return ans;
    }
};
```

## Complexity

- Time: O(n), because each pointer moves forward at most n times.
- Space: O(1), because only a constant number of variables are used.

## What I Learned

- How to maintain a variable-size window with at most one zero.
- Why the zero counter must only decrease when a zero leaves the window.
- Why the answer uses `right - left` instead of `right - left + 1`.
- How to handle the requirement to delete exactly one element, even when the array contains only ones.