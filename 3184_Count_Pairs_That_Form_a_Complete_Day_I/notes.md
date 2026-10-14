## Problem

Given an integer array `hours` representing durations in hours, return the number of pairs `(i, j)` such that `i < j` and `hours[i] + hours[j]` forms a complete day.

A complete day is a duration that is an exact multiple of 24 hours.

## My Approach

I use two nested loops to check every possible pair of elements in the array.

The outer loop selects the first element at index `i`, while the inner loop starts from `i + 1` to select the second element at index `j`.

For each pair, I calculate their sum and check whether it is divisible by 24 using the modulo operator.

If the remainder is zero, the pair forms a complete day, so I increment `count`.

After checking all pairs, I return `count`.

## Key Logic

Start the inner loop at `i + 1` to avoid checking the same pair twice and to ensure `i < j`.

Check whether the sum forms a complete day:

```cpp
if((hours[i] + hours[j]) % 24 == 0 && i < j) {
    count++;
}
```

The condition `i < j` is already guaranteed by the loop structure, so it is technically unnecessary.

**Example:**

```text
Input:  [12,12,30,24,24]

Valid pairs:
(0,1) → 12 + 12 = 24
(3,4) → 24 + 24 = 48

Output: 2
```

## Solution

```cpp
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int count = 0;

        for(int i = 0; i < hours.size(); i++) {
            for(int j = i + 1; j < hours.size(); j++) {
                if((hours[i] + hours[j]) % 24 == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};
```

## Complexity

- **Time:** `O(n²)` because every possible pair is checked.
- **Space:** `O(1)` auxiliary space because only a fixed number of variables are used.

## What I Learned

- Nested loops can be used to check every unique pair in an array.
- Starting the inner loop at `i + 1` prevents duplicate pair checks.
- The modulo operator `%` checks whether a sum is divisible by 24.
- This brute-force solution is easy to understand and can later be optimized using frequency counting of remainders.