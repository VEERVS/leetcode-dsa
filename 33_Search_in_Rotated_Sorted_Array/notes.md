## Problem
Given a sorted array of distinct integers that has been rotated at an unknown pivot, find the index of the target. Return -1 if the target does not exist.

## My Approach
Used Modified Binary Search.

At every iteration, identified which half of the rotated array is sorted. Then checked whether the target lies within the boundaries of that sorted half and eliminated the other half.

## Key Logic
- If `nums[mid] == target`, return `mid`.
- If `nums[left] <= nums[mid]`, the left half is sorted.
  - If `target` lies between `nums[left]` and `nums[mid]`, search left.
  - Otherwise, search right.
- Otherwise, the right half is sorted.
  - If `target` lies between `nums[mid]` and `nums[right]`, search right.
  - Otherwise, search left.
- Return -1 if the target is not found.

## Solution
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target <= nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if(nums[mid] <= target && target <= nums[right]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
```

## Complexity
- Time Complexity: O(log n)
- Space Complexity: O(1)

## What I Learned
- A rotated sorted array always has at least one sorted half.
- `nums[left] <= nums[mid]` identifies a sorted left half.
- The target's range determines which half to eliminate.
- Binary Search can work even when the entire array is not globally sorted.