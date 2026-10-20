## Problem
Given an integer array `nums` and an integer `k`, calculate the average of the subarray centered at every index `i`, extending `k` elements to the left and `k` elements to the right.

The window size is `2 * k + 1`. If a complete window cannot fit around an index, its answer is `-1`.

## My Approach
I initialized the answer vector with `-1` for every index. Then I calculated the sum of the first window and stored its average at index `k`.

I used a fixed-size sliding window to calculate subsequent averages efficiently. For each new center, I removed the element leaving the window and added the new element entering it.

I used `long long` for the window sum to avoid integer overflow.

## Key Logic
- Window size: `2 * k + 1`.
- Calculate the first window sum using the first `2 * k + 1` elements.
- Store its average at `ans[k]`.
- For each subsequent center `i`:
  - Remove `nums[i - k - 1]`.
  - Add `nums[i + k]`.
  - Store the new average at `ans[i]`.
- Initialize the answer with `-1` so invalid edge positions remain unchanged.
- If `n < 2 * k + 1`, return the answer immediately.

## Solution
```cpp
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);

        if (n < 2LL * k + 1) {
            return ans;
        }

        long long winSum = 0;

        for (int i = 0; i < 2LL * k + 1; i++) {
            winSum += nums[i];
        }

        ans[k] = winSum / (2LL * k + 1);

        for (int i = k + 1; i < n - k; i++) {
            winSum = winSum - nums[i - k - 1] + nums[i + k];
            ans[i] = winSum / (2LL * k + 1);
        }

        return ans;
    }
};
```

## Complexity
- Time: `O(n)`.
- Space: `O(n)` for the required output vector; auxiliary space excluding the output is `O(1)`.

## What I Learned
- A centered window of radius `k` has size `2 * k + 1`.
- `vector<int> ans(n, -1)` creates an answer vector of length `n`, initialized with `-1`.
- The outgoing index for a new center `i` is `i - k - 1`.
- The incoming index is `i + k`.
- `long long` prevents overflow in the window sum.
- Always check whether the full window fits before accessing its elements.