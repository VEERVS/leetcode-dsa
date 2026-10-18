## Problem
Given an integer array `arr`, an integer `k`, and an integer `threshold`, count the contiguous subarrays of size `k` whose average is greater than or equal to `threshold`.

## My Approach
I calculated the sum of the first `k` elements and checked whether its average met the threshold. If it did, I incremented `count`.

Then I used a fixed-size sliding window. For each slide, I removed the outgoing element and added the incoming element, calculated the new average, and incremented `count` if the average met the threshold.

## Key Logic
- Calculate the first window sum.
- Check the initial window separately.
- Slide the window by subtracting `arr[i]` and adding `arr[i + k]`.
- Check each updated window and increment `count` when it qualifies.

We can avoid floating-point division because:

`average >= threshold`

is equivalent to:

`windowSum >= threshold * k`

Since `k` is positive, comparing sums is simpler and avoids unnecessary floating-point calculations.

## Solution
```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int winSum = 0;

        for (int i = 0; i < k; i++) {
            winSum += arr[i];
        }

        if (winSum >= threshold * k) {
            count++;
        }

        for (int i = 0; i < arr.size() - k; i++) {
            winSum = winSum - arr[i] + arr[i + k];

            if (winSum >= threshold * k) {
                count++;
            }
        }

        return count;
    }
};
```

## Complexity
- Time: `O(n)` because each element is processed a constant number of times.
- Space: `O(1)` auxiliary space.

## What I Learned
- Sliding windows can count qualifying subarrays, not just find a maximum or minimum.
- The first window must be checked separately when the loop only processes subsequent slides.
- After updating the sum, the new window must be checked.
- Comparing `winSum >= threshold * k` avoids calculating the average.
- The number of windows of size `k` in an array of size `n` is `n - k + 1`.