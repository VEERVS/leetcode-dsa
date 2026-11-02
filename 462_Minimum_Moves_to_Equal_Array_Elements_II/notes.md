## Problem
Given an integer array `nums`, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement any element by 1.

**LeetCode:** 462. Minimum Moves to Equal Array Elements II

## My Approach
I used sorting and the mathematical property of the median.

The median is the optimal target because choosing it minimizes the sum of absolute differences between all elements and the target.

After sorting the array:
- If the array length is odd, the median is `nums[n / 2]`.
- If the array length is even, any value between the two middle elements minimizes the total moves. I chose their average.

I then traversed the array and added the absolute difference between each element and the median to calculate the minimum number of moves.

## Key Logic
1. Sort the array.
2. Find the median:
   - Odd length: `nums[n / 2]`
   - Even length: `(nums[n / 2 - 1] + nums[n / 2]) / 2`
3. Initialize `moves = 0`.
4. Traverse the array and calculate:

   `moves += abs(x - median)`

5. Return the total moves.

## Solution
```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int median;

        if (n % 2 != 0) {
            median = nums[n / 2];
        } else {
            median = (nums[n / 2 - 1] + nums[n / 2]) / 2;
        }

        int moves = 0;

        for (int x : nums) {
            moves += abs(x - median);
        }

        return moves;
    }
};
```

## Complexity
- **Time Complexity:** `O(n log n)` — sorting takes O(n log n), followed by one linear traversal.
- **Space Complexity:** `O(1)` auxiliary space for the calculations, excluding the space used internally by sorting.

## What I Learned
- The median minimizes the sum of absolute differences.
- Sorting makes finding the median straightforward.
- For an even-sized array, any value between the two middle elements is optimal.
- `abs(x - median)` calculates the number of moves required to make an element equal to the target.
- Mathematical observations can simplify optimization problems without requiring brute force.