## Problem
Given a sorted array of integers, find the starting and ending positions of a given target.

If the target doesn't exist, return [-1, -1].

## My Approach
Used two separate Binary Searches.

The first Binary Search finds the first occurrence of the target, while the second finds the last occurrence.

Instead of returning immediately after finding the target, save its index and continue searching for a better boundary.

## Key Logic
First Occurrence:
- If `nums[mid] == target`, save `mid` in `ans[0]`.
- Continue searching left using `right = mid - 1`.

Last Occurrence:
- If `nums[mid] == target`, save `mid` in `ans[1]`.
- Continue searching right using `left = mid + 1`.

For both searches:
- If `nums[mid] < target`, move right.
- If `nums[mid] > target`, move left.
- Reset `left` and `right` before starting the second search.

If the target doesn't exist, both answer positions remain -1.

## Solution
```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int left = 0;
        int right = nums.size() - 1;

        // First occurrence
        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                ans[0] = mid;
                right = mid - 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        // Reset boundaries
        left = 0;
        right = nums.size() - 1;

        // Last occurrence
        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                ans[1] = mid;
                left = mid + 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return ans;
    }
};
```

## Complexity
- Time Complexity: O(log n) + O(log n) = O(log n)
- Space Complexity: O(1) auxiliary space.

## What I Learned
- Finding a target doesn't always mean Binary Search should terminate.
- To find the first occurrence, save the index and continue searching left.
- To find the last occurrence, save the index and continue searching right.
- If the target occurs only once, both positions are equal.
- If the target doesn't exist, the initialized answer remains [-1, -1].
- Binary Search can find boundaries, not just individual elements.