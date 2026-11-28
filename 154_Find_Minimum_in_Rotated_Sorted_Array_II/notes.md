## Problem
Given a rotated sorted array that may contain duplicate elements, return its minimum element.

## My Approach
Used Modified Binary Search with three possible comparisons between `nums[mid]` and `nums[right]`.

When both values are equal, the sorted direction cannot be determined confidently, so reduced the search space by decrementing `right`.

## Key Logic
- If `nums[mid] > nums[right]`, minimum lies strictly to the right.
  - Update `left = mid + 1`.
- If `nums[mid] < nums[right]`, minimum lies at mid or to its left.
  - Update `right = mid`.
- If `nums[mid] == nums[right]`, comparison is ambiguous.
  - Update `right--`.
- Continue while `left < right`.
- Return `nums[left]`.

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
            else if(nums[mid] < nums[right]){
                right = mid;
            }
            else{
                right--;
            }
        }
        return nums[left];
    }
};
```

## Complexity
- Average Time Complexity: O(log n)
- Worst-case Time Complexity: O(n), due to duplicates.
- Space Complexity: O(1)

## What I Learned
- Duplicate elements can make Binary Search direction ambiguous.
- When `nums[mid] == nums[right]`, decrementing right safely removes one duplicate candidate.
- Unlike LC 153, this problem can degrade to O(n) in the worst case.
- Binary Search can still be used with duplicates, but logarithmic performance is not always guaranteed.