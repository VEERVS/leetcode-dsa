## Problem

You are given an array `nums` consisting of positive integers.

Return the total frequencies of elements in `nums` such that those elements all have the maximum frequency.

The frequency of an element is the number of times it appears in the array.

## My Approach

I use an `unordered_map<int, int>` to count the frequency of each element.

First, I traverse the array and increment the frequency of every element.

Next, I traverse the frequency map to find the maximum frequency and store it in `max`.

Finally, I traverse the map again. Whenever an element's frequency equals `max`, I add that frequency to `count`.

I return `count`, which represents the total occurrences of all elements having the maximum frequency.

## Key Logic

Count the frequency of every element:

```cpp
for(int x : nums) {
    freq[x]++;
}
```

Find the maximum frequency:

```cpp
int max = 0;

for(auto& pair : freq) {
    if(pair.second > max) {
        max = pair.second;
    }
}
```

Add the frequencies that equal the maximum:

```cpp
if(pair.second == max) {
    count += max;
}
```

**Example:**

```text
Input:  [1,2,2,3,1,4]
Output: 4
```

The frequencies are:

```text
1 → 2
2 → 2
3 → 1
4 → 1
```

The maximum frequency is `2`. Both `1` and `2` have this frequency, so the answer is `2 + 2 = 4`.

## Solution

```cpp
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int x : nums) {
            freq[x]++;
        }

        int max = 0;

        for(auto& pair : freq) {
            if(pair.second > max) {
                max = pair.second;
            }
        }

        int count = 0;

        for(auto& pair : freq) {
            if(pair.second == max) {
                count += max;
            }
        }

        return count;
    }
};
```

## Complexity

- **Time:** `O(n)` average, where `n` is the number of elements.
- **Space:** `O(n)` for the frequency map in the worst case.

## What I Learned

- An `unordered_map` efficiently stores element frequencies.
- The maximum frequency can be found by traversing the frequency map.
- Multiple elements can share the same maximum frequency.
- The question asks for the **total occurrences**, not the number of distinct elements with maximum frequency.
- Two passes over the frequency map make the solution easy to understand.