## Problem

Given an array of positive integers `nums` and an integer `k`, return the number of contiguous subarrays whose product is strictly less than `k`.

## My Approach

Use a variable-size sliding window with a running product.

Maintain:
- `left`: Starting index of the window.
- `right`: Ending index of the window.
- `prod`: Product of the elements inside the window.
- `ans`: Total number of valid subarrays.

Expand the window by multiplying the current element into `prod`.

If the product becomes greater than or equal to `k`, shrink the window from the left by dividing out elements until the product is strictly less than `k`.

For each valid window, add `right - left + 1` to the answer because every non-empty suffix ending at `right` is also valid.

## Key Logic

- If `k <= 1`, return `0`, because all numbers are positive integers.
- Expand the window using `prod *= nums[right]`.
- Shrink while `prod >= k`.
- Remove the outgoing element using `prod /= nums[left]`.
- Count all valid subarrays ending at `right` using `ans += right - left + 1`.

Example: `nums = [10, 5, 2, 6]`, `k = 100`.

The valid subarrays are `[10]`, `[5]`, `[2]`, `[6]`, `[10,5]`, `[5,2]`, `[2,6]`, and `[5,2,6]`.

The answer is `8`.

## Solution

```cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int ans = 0, left = 0, prod = 1;

        for (int right = 0; right < nums.size(); right++) {
            prod *= nums[right];

            while (prod >= k) {
                prod /= nums[left];
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};
```

## Complexity

- Time: O(n), because each pointer moves forward at most n times.
- Space: O(1), because only a constant number of variables are used.

## What I Learned

- How to maintain a running product in a variable-size sliding window.
- Why the condition must be `prod >= k` when the product must be strictly less than `k`.
- Why `k <= 1` requires an early return.
- Why `ans += right - left + 1` counts every valid subarray ending at the current right index.
- How positive array elements make this sliding-window technique possible.