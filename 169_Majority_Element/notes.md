## Problem

Given an array `nums` of size `n`, return the **majority element**.

The majority element is the element that appears more than `n / 2` times.

The problem guarantees that a majority element always exists.

## My Approach

I used an `unordered_map` to store the frequency of every element.

For every value in the array:
1. Increase its frequency in the map.
2. Check if its frequency has become greater than `n / 2`.
3. If yes, immediately return that value.

Since the majority element is guaranteed to exist, the answer will always be found.

## Key Logic

```cpp
unordered_map<int, int> freq;
```

This stores:

```text
value → frequency
```

For every element:

```cpp
freq[val]++;
```

Then:

```cpp
if(freq[val] > nums.size() / 2)
    return val;
```

As soon as an element crosses the majority threshold, we return it.

For example:

```text
nums = [2,2,1,1,1,2,2]

n = 7
n/2 = 3

frequency of 2 eventually becomes 4

4 > 3 → 2 is the majority element
```

## Solution

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int val : nums){
            freq[val]++;

            if(freq[val] > nums.size() / 2){
                return val;
            }
        }

        return -1;
    }
};
```

## Complexity

**Time:** `O(n)` average

Each element is processed once and `unordered_map` operations take `O(1)` average time.

**Space:** `O(n)`

The frequency map can store up to `n` different elements.

## What I Learned

- `unordered_map` can be used for frequency counting.
- `freq[value]++` is a simple way to update frequencies.
- The majority condition is `frequency > n/2`.
- We can return early as soon as the frequency crosses the required threshold.
- This is a straightforward hashing-based solution.