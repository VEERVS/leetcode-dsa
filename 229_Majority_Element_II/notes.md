## Problem

Given an integer array `nums` of size `n`, find all elements that appear more than `n / 3` times.

There can be at most **two** such elements.

Return all elements satisfying the condition.

## My Approach

I used an `unordered_map` to count the frequency of every element.

The solution has two steps:

1. Traverse the array and store the frequency of every value.
2. Traverse the frequency map and add every element whose frequency is greater than `n / 3`.

The resulting elements are stored in a `vector<int>`.

## Key Logic

First create a frequency map:

```cpp
unordered_map<int, int> freq;
```

Then count every element:

```cpp
for(int val : nums){
    freq[val]++;
}
```

After that, check every `(value, frequency)` pair:

```cpp
for(auto& pair : freq){
    if(pair.second > nums.size() / 3){
        ans.push_back(pair.first);
    }
}
```

Here:

```cpp
pair.first
```

is the element.

And:

```cpp
pair.second
```

is its frequency.

For example:

```text
nums = [1,2,3,1,2,1]

n = 6
n/3 = 2

frequency:
1 → 3
2 → 2
3 → 1

Only 1 satisfies:

3 > 2

Answer = [1]
```

## Solution

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> ans;

        for(int val : nums){
            freq[val]++;
        }

        for(auto& pair : freq){
            if(pair.second > nums.size() / 3){
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};
```

## Complexity

**Time:** `O(n)` average

The first loop counts frequencies in `O(n)` average time.

The second loop processes at most `n` distinct elements, so overall it remains `O(n)` average.

**Space:** `O(n)`

The `unordered_map` can store up to `n` different values.

## What I Learned

- `unordered_map` is useful for frequency-based problems.
- `pair.first` gives the key and `pair.second` gives its value.
- For Majority Element II, the condition is `frequency > n/3`.
- There can be at most **two** elements appearing more than `n/3` times.
- This hashing approach is simple, although there is also an optimized `O(1)`-space Boyer-Moore Voting solution.