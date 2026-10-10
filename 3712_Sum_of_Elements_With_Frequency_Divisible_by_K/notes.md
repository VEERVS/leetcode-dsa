## Problem

Given an integer array `nums` and an integer `k`, return the sum of all elements whose frequencies are divisible by `k`.

Each qualifying element contributes its value once for every occurrence in the array.

If no elements qualify, return `0`.

## My Approach

I used an `unordered_map<int, int>` to count the frequency of every number.

Then I traversed the map. For each entry, I checked whether its frequency was divisible by `k`.

If it was, I added:

```cpp
value * frequency
```

to the sum because every occurrence of that value must be included.

## Key Logic

First, count the frequencies:

```cpp
unordered_map<int, int> freq;

for(int x : nums){
    freq[x]++;
}
```

Then check every map entry:

```cpp
for(auto& x : freq){
    if(x.second % k == 0){
        sum += x.first * x.second;
    }
}
```

Here:

- `x.first` is the number.
- `x.second` is its frequency.
- `x.second % k == 0` checks whether the frequency is divisible by `k`.

For example:

```text
nums = [1,2,2,3,3,3,3,4]
k = 2

1 → frequency 1 → ignored
2 → frequency 2 → contributes 2 × 2 = 4
3 → frequency 4 → contributes 3 × 4 = 12
4 → frequency 1 → ignored

Answer = 4 + 12 = 16
```

## Solution

```cpp
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int x : nums){
            freq[x]++;
        }

        int sum = 0;

        for(auto& x : freq){
            if(x.second % k == 0){
                sum += x.first * x.second;
            }
        }

        return sum;
    }
};
```

## Complexity

- **Time:** `O(n)` average
- **Space:** `O(n)` for the frequency map in the worst case.

We traverse the array once to count frequencies and traverse the map once to calculate the answer.

## What I Learned

- Hash maps can group identical values and count their occurrences.
- `x.first` accesses the key and `x.second` accesses the frequency.
- The modulo operator checks whether a frequency is divisible by `k`.
- When every occurrence must contribute, multiply the value by its frequency.
- This pattern combines frequency hashing, modulo, and conditional summation.