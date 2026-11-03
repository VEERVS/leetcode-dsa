## Problem
Given an integer array `nums`, you can increase any element by 1 in one move.

Return the minimum number of moves required to make all elements equal.

**LeetCode:** 3736. Minimum Moves to Equal Array Elements III

## My Approach
I used a greedy approach.

Since we can only increase elements, the optimal target must be the maximum element in the array.

I found the maximum element using `max_element()` and calculated how many increments each element needs to reach it.

## Key Logic
1. Find the maximum element using `max_element()`.
2. Initialize `ans = 0`.
3. Traverse the array.
4. Add the difference between the maximum element and the current element:

   `ans += (maxEle - x)`

5. Return the total moves.

## Solution
```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        int ans = 0;

        for(int x : nums) {
            ans += (maxEle - x);
        }

        return ans;
    }
};
```

## Complexity
- **Time Complexity:** O(n) — finding the maximum and traversing the array.
- **Space Complexity:** O(1) — constant extra space.

## What I Learned
- When only increment operations are allowed, the maximum element is the optimal target.
- `max_element()` returns an iterator, so we use `*` to access its value.
- A greedy choice can eliminate unnecessary operations.
- Always understand which operations are allowed before choosing the target value.