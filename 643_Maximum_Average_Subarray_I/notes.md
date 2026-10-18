## Problem
Given an integer array `nums` and an integer `k`, find a contiguous subarray of length `k` with the maximum average value.

Return the maximum average.

## My Approach
I calculated the sum of the first `k` elements to create the initial window. I converted its sum into an average and stored it as `maxAvg`.

Then I slid the window through the array. For every slide, I removed the outgoing element and added the incoming element. I calculated the new average and updated `maxAvg` if the new average was larger.

## Key Logic
- Calculate the first window sum using indices `0` through `k - 1`.
- Initialize `maxAvg` using the first window.
- Start the sliding loop at `i = 0` and continue while `i < n - k`.
- Remove `nums[i]`, the element leaving the window.
- Add `nums[i + k]`, the element entering the window.
- Divide the updated sum by `k` to calculate the current average.

The update is:

`winSum = winSum - nums[i] + nums[i + k]`

There are `n - k` slides after the initial window.

## Solution
```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int winSum = 0;

        for (int i = 0; i < k; i++) {
            winSum += nums[i];
        }

        double maxAvg = (double)winSum / k;

        for (int i = 0; i < nums.size() - k; i++) {
            winSum = winSum - nums[i] + nums[i + k];

            double winAvg = (double)winSum / k;
            maxAvg = max(maxAvg, winAvg);
        }

        return maxAvg;
    }
};
```

## Complexity
- Time: `O(n)` because each element is processed a constant number of times.
- Space: `O(1)` auxiliary space.

## What I Learned
- A rolling sum avoids recalculating every window from scratch.
- The outgoing element is at `nums[i]`.
- The incoming element is at `nums[i + k]`.
- Initializing `maxAvg` with the first window ensures the first window is considered.
- Casting the sum to `double` before division prevents integer division.