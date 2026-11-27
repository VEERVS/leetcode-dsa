## Problem
Given a sorted array of distinct integers and a target, return its index if found. Otherwise, return the index where it should be inserted to maintain sorted order.

## My Approach
Used standard Binary Search.

If the target is found, return its index. Otherwise, after the loop terminates, return `left`, which represents the correct insertion position.

## Key Logic
- If `nums[mid] == target`, return `mid`.
- If `nums[mid] < target`, move right.
- If `nums[mid] > target`, move left.
- When the loop terminates, `left` points to the insertion position.
- At termination, `left = right + 1`.

## Solution
```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return left;
    }
};
```

## Complexity
- Time Complexity: O(log n)
- Space Complexity: O(1)

## What I Learned
- Binary Search can find insertion positions, not just existing elements.
- When the target is absent, `left` points to the first position where it can be inserted.
- `left` is equivalent to `right + 1` after the loop terminates.
- This introduces the concept of Lower Bound.