## Problem
Given a sorted array of unique elements that has been rotated, return its minimum element.

## My Approach
Used Modified Binary Search by comparing the middle element with the rightmost element.

Instead of searching for a target, narrowed the search space until only the minimum element remained.

## Key Logic
- If `nums[mid] > nums[right]`, the minimum must be strictly to the right of `mid`.
  - Update `left = mid + 1`.
- Otherwise, the minimum is at `mid` or somewhere to its left.
  - Update `right = mid`.
- Continue while `left < right`.
- When both pointers meet, return `nums[left]`.

## Solution
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right){
            int mid = left + (right-left)/2;

            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return nums[left];
    }
};
```

## Complexity
- Time Complexity: O(log n)
- Space Complexity: O(1)

## What I Learned
- Binary Search can find a minimum without directly searching for a target.
- Comparing `nums[mid]` with `nums[right]` identifies the direction of the minimum.
- `right = mid` preserves the possibility that mid itself is the answer.
- `left = mid + 1` safely eliminates mid when it is strictly greater than nums[right].
- `while(left < right)` prevents an infinite loop and stops when one candidate remains.