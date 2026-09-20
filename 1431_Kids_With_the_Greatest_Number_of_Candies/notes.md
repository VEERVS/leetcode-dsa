## Problem

Given an array `candies`, where `candies[i]` represents the number of candies the `i`th child has, and an integer `extraCandies`.

For each child, determine whether giving them all the extra candies would make their total candies greater than or equal to the current maximum number of candies among all children.

Return a boolean array containing the result for every child.

## My Approach

First, I find the maximum number of candies any child currently has using `max_element()`.

Then, I traverse the array again.

For each child, I check:

`candies[i] + extraCandies >= max`

If the condition is true, I push `true` into the answer vector; otherwise, I push `false`.

## Key Logic

The only value we need to compare against is the current maximum number of candies.

For every child:

`candies[i] + extraCandies >= maximum`

If this is true, that child can have the greatest number of candies after receiving all the extra candies.

I used `max_element()` from the C++ STL to find the maximum efficiently.

## Solution

```cpp
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;

        int max = *max_element(candies.begin(), candies.end());

        for(int i = 0; i < candies.size(); i++) {
            ans.push_back(candies[i] + extraCandies >= max);
        }

        return ans;
    }
};
```

## Complexity

- Time: `O(n)`
- Space: `O(n)` for the output vector

## What I Learned

- `max_element()` can be used to find the maximum element in a vector.
- Dereferencing the iterator with `*max_element(...)` gives the actual maximum value.
- A simple comparison against the maximum is enough to solve the problem.
- `vector<bool>` can be used when the result only contains `true` and `false`.