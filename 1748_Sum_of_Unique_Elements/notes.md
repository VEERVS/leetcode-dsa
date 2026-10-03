## Problem

Given an integer array `nums`, find the sum of all elements that appear exactly once in the array.

An element is unique if its frequency is exactly `1`.

## My Approach

I used a frequency array to count how many times each number appears.

First, I traverse the entire array and increment the frequency of every element.

Then I traverse the array again:

- If `freq[x] == 1`, the element appears exactly once, so I add it to `sum`.
- Otherwise, I ignore it.

Finally, I return the sum.

## Key Logic

The frequency array stores:

```text
freq[x] = number of times x appears
```

For example:

```text
nums = [1, 2, 3, 2]

freq[1] = 1
freq[2] = 2
freq[3] = 1
```

Therefore:

```text
1 → unique → add
2 → appears twice → skip
3 → unique → add

answer = 1 + 3 = 4
```

The important condition is:

```cpp
if(freq[x] == 1)
```

because we only want elements appearing **exactly once**.

## Solution

```cpp
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int freq[101] = {0};

        for(int x : nums) {
            freq[x]++;
        }

        int sum = 0;

        for(int x : nums) {
            if(freq[x] == 1) {
                sum += x;
            }
        }

        return sum;
    }
};
```

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

The frequency array has a fixed size of `101`, so its size does not grow with `n`.

## What I Learned

- Frequency arrays are useful when the range of possible values is small and known.
- `freq[x]++` counts occurrences of each value.
- We can determine whether an element is unique by checking `freq[x] == 1`.
- The problem can be solved in two simple passes: first count frequencies, then calculate the answer.