## Problem
Given a binary array `nums`, an operation consists of choosing exactly three consecutive elements and flipping each one (`0` becomes `1`, and `1` becomes `0`).

Return the minimum number of operations required to make every element equal to `1`. If it is impossible, return `-1`.

**LeetCode:** 3191. Minimum Operations to Make Binary Array Elements Equal to One I

## My Approach
I used a greedy left-to-right approach.

Whenever `nums[i] == 0`, I flipped the three consecutive elements starting at index `i`. This fixes the current position because later operations starting to its right cannot change it.

I continued until no more groups of three could be processed. Finally, I checked whether any zero remained. If a zero remained, the transformation was impossible.

## Key Logic
1. Initialize `count = 0` and calculate `n = nums.size()`.
2. Iterate while `i <= n - 3`, ensuring three elements are available.
3. If `nums[i] == 0`:
   - Flip `nums[i]`, `nums[i + 1]`, and `nums[i + 2]` using `1 - nums[i]`.
   - Increment `count`.
4. After the loop, check the array for remaining zeros.
5. If any zero remains, return `-1`; otherwise, return `count`.

## Solution
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                nums[i] = 1 - nums[i];
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];

                count++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                return -1;
            }
        }

        return count;
    }
};
```

## Complexity
- **Time Complexity:** `O(n)` — the algorithm performs two linear passes.
- **Space Complexity:** `O(1)` — the input array is modified directly, using constant extra space.

## What I Learned
- Greedy algorithms can solve problems where each decision fixes the earliest unresolved position.
- When the current element is zero, flipping the group starting there is necessary to fix it.
- `1 - bit` flips a binary value between `0` and `1`.
- The loop must stop when fewer than three elements remain.
- A final scan detects whether the transformation was impossible.