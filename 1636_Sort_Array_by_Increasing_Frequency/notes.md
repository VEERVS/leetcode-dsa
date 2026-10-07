## Problem

Given an array of integers `nums`, sort the array in increasing order based on the frequency of each value.

If multiple values have the same frequency, sort those values in decreasing order.

## My Approach

I first use an `unordered_map` to count the frequency of every number.

Then I use `sort()` with a custom comparator.

The comparator follows two rules:

1. Lower frequency comes first.
2. If two numbers have the same frequency, the larger number comes first.

## Key Logic

First calculate the frequencies:

```cpp
unordered_map<int, int> freq;

for(int x : nums){
    freq[x]++;
}
```

Then use a custom comparator:

```cpp
sort(nums.begin(), nums.end(), [&](int a, int b) {
    if(freq[a] != freq[b]){
        return freq[a] < freq[b];
    }

    return a > b;
});
```

The comparator answers:

> Should `a` come before `b`?

If their frequencies are different:

```cpp
freq[a] < freq[b]
```

means the number with the smaller frequency comes first.

If their frequencies are equal:

```cpp
a > b
```

means the larger number comes first.

For example:

```text
nums = [1,1,2,2,2,3]

1 → frequency 2
2 → frequency 3
3 → frequency 1
```

Therefore:

```text
3, 1, 1, 2, 2, 2
```

## Solution

```cpp
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int x : nums){
            freq[x]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if(freq[a] != freq[b]){
                return freq[a] < freq[b];
            }

            return a > b;
        });

        return nums;
    }
};
```

## Complexity

- **Time:** `O(n log n)` average
- **Space:** `O(n)`.

The frequency map requires `O(n)` space in the worst case, while `sort()` takes `O(n log n)` time.

## What I Learned

- `unordered_map` can provide the frequency used by a sorting comparator.
- A comparator answers whether `a` should come before `b`.
- `<` can be used for increasing order.
- `>` can be used for decreasing order.
- The lambda capture `[&]` allows the comparator to access the `freq` map outside the lambda.
- Custom comparators are extremely useful when sorting depends on something other than the actual value.