## Problem

Given an integer array `nums`, return `true` if any value appears at least twice in the array.

Return `false` if every element is distinct.

## My Approach

I use an `unordered_map<int, int>` to store the frequency of every element in the array.

First, I traverse `nums` using a range-based `for` loop and increment the frequency of each element.

After building the frequency map, I traverse it to check whether any element has a frequency greater than or equal to `2`.

If such an element exists, I immediately return `true` because the array contains a duplicate.

Otherwise, I return `false`.

## Key Logic

Count the frequency of every element:

```cpp
for(int x : nums) {
    freq[x]++;
}
```

Check whether any element appears at least twice:

```cpp
for(auto& pair : freq) {
    if(pair.second >= 2) {
        return true;
    }
}
```

**Example 1:**

```text
Input: [1,2,3,1]

Frequencies:
1 → 2
2 → 1
3 → 1

Output: true
```

The number `1` appears twice.

**Example 2:**

```text
Input: [1,2,3,4]

Frequencies:
1 → 1
2 → 1
3 → 1
4 → 1

Output: false
```

Every element appears exactly once.

## Solution

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int x : nums) {
            freq[x]++;
        }

        for(auto& pair : freq) {
            if(pair.second >= 2) {
                return true;
            }
        }

        return false;
    }
};
```

## Complexity

- **Time:** `O(n)` average, where `n` is the number of elements.
- **Space:** `O(n)` in the worst case because the frequency map may store all `n` distinct elements.

## What I Learned

- An `unordered_map` efficiently counts element frequencies.
- `freq[x]++` increments the occurrence count of element `x`.
- `pair.first` represents the element, while `pair.second` represents its frequency.
- A duplicate exists if any element has a frequency of at least `2`.
- Returning immediately after finding a duplicate avoids unnecessary checks.
- This problem can also be solved using an `unordered_set`, which is useful when we only need to detect duplicates rather than count frequencies.