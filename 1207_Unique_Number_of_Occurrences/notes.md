## Problem

Given an integer array `arr`, return `true` if the number of occurrences of each value in the array is unique.

Return `false` if two different values have the same frequency.

## My Approach

I used two hashing structures.

First, I used an `unordered_map` to calculate the frequency of every value.

Then I used an `unordered_set` to keep track of frequencies that had already appeared.

For every frequency:

- If the frequency is already in the set, two values have the same number of occurrences → return `false`.
- Otherwise, insert the frequency into the set.

If all frequencies are unique, return `true`.

## Key Logic

First calculate frequencies:

```cpp
unordered_map<int, int> freq;

for(int x : arr){
    freq[x]++;
}
```

Then iterate through the frequency map:

```cpp
for(auto x : freq){
    int occur = x.second;

    if(set.count(occur) == 1){
        return false;
    }

    set.insert(occur);
}
```

Here:

```cpp
x.first
```

is the number itself, while:

```cpp
x.second
```

is its frequency.

For:

```text
arr = [1,2,2,1,1,3]
```

we get:

```text
1 → 3
2 → 2
3 → 1
```

The frequencies are:

```text
3, 2, 1
```

All are different → `true`.

## Solution

```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        for(int x : arr){
            freq[x]++;
        }

        unordered_set<int> set;

        for(auto x : freq){
            int occur = x.second;

            if(set.count(occur) == 1){
                return false;
            }

            set.insert(occur);
        }

        return true;
    }
};
```

## Complexity

- **Time:** `O(n)` average
- **Space:** `O(n)` in the worst case

The frequency map can contain up to `n` different values, and the set can contain up to `n` different frequencies.

## What I Learned

- `unordered_map` can be used to calculate frequencies.
- `unordered_set` stores only unique values.
- `set.count(x)` checks whether a value already exists.
- In a frequency map:
  - `x.first` → key/value from the array
  - `x.second` → frequency of that value
- A powerful hashing pattern is:

```text
Array
  ↓
unordered_map
  ↓
Calculate frequencies
  ↓
unordered_set
  ↓
Check whether frequencies repeat
```

- `unordered_map` answers **"how many?"**
- `unordered_set` answers **"have I seen this before?"**