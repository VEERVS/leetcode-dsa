## Problem

Given an integer array `nums`, for every `nums[i]`, count how many numbers in the array are smaller than it.

Return the resulting array.

For each index `i`, we need to count all valid indices `j` such that:

`j != i` and `nums[j] < nums[i]`

## My Approach

I used a brute-force nested loop.

For every element `nums[i]`, I create a counter starting at `0`.

Then I compare it with every other element `nums[j]`.

If:

`nums[j] < nums[i]`

I increment the counter.

After checking the entire array, I push the count into the answer vector.

This directly follows the definition of the problem.

## Key Logic

For every element, we need to know how many elements are smaller than it.

So I use:

- Outer loop → selects the current element.
- Inner loop → checks every other element.
- `count` → stores how many elements are smaller.

For example:

`nums = [8,1,2,2,3]`

For `8`, the smaller elements are:

`1, 2, 2, 3`

So the answer is `4`.

## Solution

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            int count = 0;

            for(int j = 0; j < nums.size(); j++) {
                if(nums[i] > nums[j]) {
                    count++;
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};
```

## Complexity

- Time: `O(n²)`
- Space: `O(n)` for the output vector

## What I Learned

- Nested loops are useful when every element needs to be compared with every other element.
- The outer loop selects the current element while the inner loop performs the comparisons.
- The condition `nums[i] > nums[j]` directly represents "nums[j] is smaller than nums[i]".
- This brute-force approach is simple and follows the problem statement directly.
- The problem can be optimized further using sorting or frequency counting.