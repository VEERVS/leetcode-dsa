## Problem

You are given an integer array `nums` consisting of `2 * n` integers.

You need to divide `nums` into `n` pairs such that:

- Each element belongs to exactly one pair.
- The two elements in every pair are equal.

Return `true` if the array can be divided into equal pairs. Otherwise, return `false`.

## My Approach

I use a frequency array `freq[501]` to count the occurrences of each number.

Since the array contains values in the range `1` to `500`, each value can directly be used as an index in the frequency array.

First, I traverse `nums` and increment the frequency of every element.

Then, I traverse the array again. If any element has an odd frequency, it cannot be completely divided into pairs, so I return `false`.

If every element has an even frequency, I return `true`.

## Key Logic

Count the occurrences:

```cpp
freq[nums[i]]++;
```

Check whether each frequency is even:

```cpp
if(freq[nums[i]] % 2 != 0) {
    return false;
}
```

An even frequency means the element can be paired with an identical element.

**Example 1:**

```text
Input:  [3,2,3,2,2,2]
Output: true
```

Frequencies:

```text
2 → 4
3 → 2
```

Both frequencies are even, so all elements can form equal pairs.

**Example 2:**

```text
Input:  [1,2,3,4]
Output: false
```

Every element appears once. Since each frequency is odd, equal pairs cannot be formed.

## Solution

```cpp
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int freq[501] = {0};

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(freq[nums[i]] % 2 != 0) {
                return false;
            }
        }

        return true;
    }
};
```

## Complexity

- **Time:** `O(n)`, where `n` represents the length of the input array for complexity analysis.
- **Space:** `O(1)` because the frequency array has a fixed size of `501`.

## What I Learned

- Frequency counting helps solve pairing problems without explicitly creating pairs.
- An element can be completely paired with identical elements if and only if its frequency is even.
- The modulo operator `% 2` checks whether a number is odd or even.
- A fixed-size frequency array can use `O(1)` auxiliary space when the value range is bounded.
- We can return `false` as soon as an element with an odd frequency is found.