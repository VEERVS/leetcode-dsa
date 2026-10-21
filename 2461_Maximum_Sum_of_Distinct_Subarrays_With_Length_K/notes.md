## Problem
Given an integer array `nums` and an integer `k`, find the maximum sum among all contiguous subarrays of length `k` in which every element is distinct.

Return `0` if no valid subarray exists.

## My Approach
I used a fixed-size sliding window with a rolling sum and an `unordered_map` to track the frequency of each element.

First, I calculated the sum and frequencies of the first `k` elements. If the map contained exactly `k` distinct keys, the first window was valid.

Then I slid the window one element at a time, updating the sum and the frequency map. Whenever the map contained exactly `k` distinct keys, I updated the maximum sum.

## Key Logic
- Calculate the initial window sum and element frequencies.
- If `freq.size() == k`, all elements in the window are distinct.
- For every slide:
  - Add the incoming element and subtract the outgoing element from the window sum.
  - Decrease the outgoing element's frequency.
  - Erase its key when its frequency becomes zero.
  - Increase the incoming element's frequency.
- If `freq.size() == k`, update `maxSum`.
- Return `maxSum`, which remains `0` if no valid window exists.

## Solution
```cpp
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        long long winSum = 0;

        for (int i = 0; i < k; i++) {
            winSum += nums[i];
            freq[nums[i]]++;
        }

        long long maxSum = 0;

        if (freq.size() == k) {
            maxSum = winSum;
        }

        for (int i = k; i < nums.size(); i++) {
            winSum = winSum + nums[i] - nums[i-k];

            freq[nums[i-k]]--;

            if (freq[nums[i-k]] == 0) {
                freq.erase(nums[i-k]);
            }

            freq[nums[i]]++;

            if (freq.size() == k) {
                maxSum = max(maxSum, winSum);
            }
        }

        return maxSum;
    }
};
```

## Complexity
- Time: `O(n)` average, assuming typical constant-time hash map operations.
- Auxiliary space: `O(k)` for the frequency map.

## What I Learned
- A rolling sum can be combined with a frequency map to enforce a distinctness condition.
- `unordered_map<int, int>` stores each number and its frequency.
- A window of length `k` is valid when it contains exactly `k` distinct keys.
- A key should be erased only when its frequency reaches zero.
- The initial window must also be checked for validity.
- `long long` safely handles large window sums.