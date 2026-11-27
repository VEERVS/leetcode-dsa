## Problem
Given a sorted array of integers and a target, return the index of the target if it exists. Otherwise, return -1.

## My Approach
Used standard Binary Search with two pointers: `left` and `right`.

Calculated the middle index and compared `nums[mid]` with the target. Eliminated half of the search space in each iteration.

## Key Logic
- If `nums[mid] == target`, return `mid`.
- If `nums[mid] < target`, search the right half using `left = mid + 1`.
- If `nums[mid] > target`, search the left half using `right = mid - 1`.
- If the loop terminates, the target doesn't exist.

## Solution
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

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
        return -1;
    }
};
```

## Complexity
- Time Complexity: O(log n)
- Space Complexity: O(1)

## What I Learned
- Binary Search works on sorted arrays.
- Each iteration eliminates half of the remaining search space.
- `left <= right` ensures even a single remaining element is checked.
- Calculating mid as `left + (right-left)/2` avoids potential integer overflow.