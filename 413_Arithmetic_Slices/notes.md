## Problem

Given an integer array `nums`, return the number of arithmetic subarrays.

An arithmetic subarray must contain at least three elements, and the difference between consecutive elements must be equal.

## My Approach

Use a single traversal with two variables:
- `count`: Number of new arithmetic slices ending at the current index.
- `ans`: Total number of arithmetic slices found so far.

Compare the current difference with the previous difference. If they match, increase `count` and add it to `ans`. Otherwise, reset `count` to zero.

## Key Logic

- Compare `nums[i] - nums[i-1]` with `nums[i-1] - nums[i-2]`.
- When the differences match, `count++`.
- Add `count` to `ans`, because longer arithmetic slices also become possible.
- When the differences differ, reset `count = 0`.
- Never reset `ans`, because previously discovered slices remain valid.

Example: `[1, 2, 3, 4]`

- `[1, 2, 3]` contributes 1 slice.
- `[2, 3, 4]` contributes 1 slice.
- `[1, 2, 3, 4]` contributes 1 slice.

Total = 3.

## Solution

```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }

        int count = 0, ans = 0;

        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] ==
                nums[i - 1] - nums[i - 2]) {
                count++;
                ans += count;
            } else {
                count = 0;
            }
        }

        return ans;
    }
};