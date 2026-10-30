## Problem
Given an integer array `nums`, return the third distinct maximum number.

If the third distinct maximum does not exist, return the maximum number.

**LeetCode:** 414. Third Maximum Number

## My Approach
I used three variables to track the first, second, and third distinct maximum values.

I initialized all three variables with `LLONG_MIN` so that negative numbers could also be handled correctly.

I traversed the array once:
- Skipped duplicate values.
- Updated all three maximum variables whenever a larger number was found.
- Updated the second and third maximum when necessary.

At the end, I checked whether a third distinct maximum existed.

## Key Logic
1. Initialize `first`, `second`, and `third` to `LLONG_MIN`.
2. Traverse the array.
3. Skip an element if it is already equal to one of the three tracked values.
4. If the current number is greater than `first`, shift all three values.
5. Otherwise, check whether it belongs in second or third position.
6. If `third` remains `LLONG_MIN`, return `first`; otherwise, return `third`.

## Solution
```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LLONG_MIN;
        long second = LLONG_MIN;
        long third = LLONG_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == first ||
                nums[i] == second ||
                nums[i] == third) {
                continue;
            }

            if (nums[i] > first) {
                third = second;
                second = first;
                first = nums[i];
            }
            else if (nums[i] > second) {
                third = second;
                second = nums[i];
            }
            else if (nums[i] > third) {
                third = nums[i];
            }
        }

        return third == LLONG_MIN ? (int)first : (int)third;
    }
};
```

## Complexity
- **Time Complexity:** `O(n)` — one traversal of the array.
- **Space Complexity:** `O(1)` — only three variables are maintained.

## What I Learned
- Three variables can track the three largest distinct values without sorting.
- Duplicate values must be skipped.
- Updating maximum values requires shifting the previous values.
- `LLONG_MIN` is useful as a sentinel when handling negative integers.
- A single traversal can solve certain ranking problems efficiently.