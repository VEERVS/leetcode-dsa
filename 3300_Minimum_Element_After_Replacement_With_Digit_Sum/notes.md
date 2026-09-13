## Problem

Given an integer array `nums`, replace every element with the sum of its digits.

Return the minimum element after all replacements.

For example:

```text
[10, 12, 13, 14]

10 → 1
12 → 3
13 → 4
14 → 5

Result = [1, 3, 4, 5]

Minimum = 1
```

## My Approach

I traversed the array and calculated the digit sum of every element.

For each element:

1. Store it in `temp`.
2. Extract each digit using `% 10`.
3. Add the digit to `sum`.
4. Remove the digit using `/ 10`.
5. Replace the original element with its digit sum.

After replacing every element, I used `min_element()` to find the smallest value in the array.

## Key Logic

For each number:

```cpp
while(temp != 0) {
    sum += temp % 10;
    temp /= 10;
}
```

Then:

```cpp
nums[i] = sum;
```

This modifies the array directly instead of creating another array.

Finally:

```cpp
*min_element(nums.begin(), nums.end())
```

returns the minimum element.

## Solution

```cpp
class Solution {
public:
    int minElement(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            int sum = 0;

            while(temp != 0) {
                sum += temp % 10;
                temp /= 10;
            }

            nums[i] = sum;
        }

        return *min_element(nums.begin(), nums.end());
    }
};
```

## Complexity

Let `n` be the number of elements and `d` be the maximum number of digits in an element.

**Time:** `O(n × d)`

**Space:** `O(1)` extra space, since the array is modified in-place.

## What I Learned

- How to combine array traversal with digit manipulation.
- How to modify an array in-place.
- `min_element()` from `<algorithm>` returns an iterator, so `*min_element(...)` gives the actual value.
- Digit processing takes `O(log x)` for a number `x`.
- Multiple operations can be performed on each array element without creating another array.