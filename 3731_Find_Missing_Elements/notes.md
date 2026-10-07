## Problem

You are given an array `nums` containing unique integers from a certain continuous range, but some integers may be missing.

The smallest and largest integers of the original range are guaranteed to still be present.

Return all missing integers in sorted order.

## My Approach

I first find the minimum and maximum values in the array using `min_element()` and `max_element()`.

Then I use an `unordered_map` as a frequency table to mark which numbers are present in the array.

Finally, I traverse from `min` to `max`.

If:

```cpp
freq[i] == 0
```

then `i` is missing, so I add it to the answer.

Because I traverse from the smallest value to the largest value, the resulting array is automatically sorted.

## Key Logic

First find the range:

```cpp
int min = *min_element(nums.begin(), nums.end());
int max = *max_element(nums.begin(), nums.end());
```

Then mark every number that exists:

```cpp
unordered_map<int, int> freq;

for(int x : nums){
    freq[x]++;
}
```

Finally, check every number in the complete range:

```cpp
for(int i = min; i <= max; i++){
    if(freq[i] == 0){
        ans.push_back(i);
    }
}
```

A frequency of `0` means that number never appeared in `nums`.

## Solution

```cpp
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());

        vector<int> ans;
        unordered_map<int, int> freq;

        for(int x : nums){
            freq[x]++;
        }

        for(int i = min; i <= max; i++){
            if(freq[i] == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
```

## Complexity

Let `R = max - min + 1`.

- **Time:** `O(n + R)` average
- **Space:** `O(n)` including the frequency map and output.

## What I Learned

- `min_element()` and `max_element()` can quickly find the boundaries of a range.
- A hash map can be used to mark which values are present.
- `freq[i] == 0` can identify a missing value.
- Traversing from `min` to `max` automatically produces a sorted answer.
- This is another useful **frequency hashing** pattern.