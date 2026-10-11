## Problem

Given an integer array `nums` sorted in non-decreasing order, remove duplicates in-place so that each unique element appears only once.

Return the number of unique elements, `k`. The first `k` elements of the array must contain the unique values in their original sorted order.

## My Approach

I use a variable `k` as a write pointer to track the number of unique elements found so far.

I traverse the array using a range-based `for` loop. For each element `x`, I check two conditions:

- If `k == 0`, the first element is automatically unique.
- Otherwise, if `x != nums[k - 1]`, the current element differs from the last unique element stored.

Whenever either condition is true, I write `x` at `nums[k]` and increment `k`.

Because the array is sorted, duplicate elements appear next to each other. Therefore, comparing with the last unique element is sufficient.

## Key Logic

Check whether the current element is unique:

```cpp
if(k == 0 || x != nums[k - 1])
```

Write the unique element and move the write pointer:

```cpp
nums[k] = x;
k++;
```

For example:

```text
Input:  [1,1,2,2,3]
Output: 3

First 3 elements: [1,2,3]
```

The function returns `3`, representing the number of unique elements.

## Solution

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;

        for(int x : nums) {
            if(k == 0 || x != nums[k - 1]) {
                nums[k] = x;
                k++;
            }
        }

        return k;
    }
};
```

## Complexity

- **Time:** `O(n)`, because each element is visited once.
- **Space:** `O(1)` auxiliary space because no additional array is created.

## What I Learned

- Sorted arrays make duplicate detection easier because equal elements are adjacent.
- The write-pointer technique modifies an array in-place.
- A range-based `for` loop can read elements while an index controls where results are written.
- Only the first `k` elements matter after removing duplicates.