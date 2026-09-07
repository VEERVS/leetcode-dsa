## Problem

Given an integer `n`, calculate its digit frequency score.

The score is defined as the sum of:

`d * freq(d)`

for every distinct digit `d` appearing in `n`.

Here, `freq(d)` is the number of times digit `d` occurs.

## My Approach

I traversed the digits of the number using `% 10` to extract the last digit and `/ 10` to remove it.

However, instead of maintaining a frequency array, I noticed that each digit contributes:

`digit * frequency`

which is equivalent to adding the digit once for every occurrence.

Therefore, I simply added every extracted digit to `sum`.

For example, for `122`:

`1 + 2 + 2 = 5`

This is the same as:

`1 * 1 + 2 * 2 = 5`

## Key Logic

The important observation is:

`d * freq(d)`

is simply `d` added `freq(d)` times.

Therefore, we don't actually need to explicitly count frequencies.

Using:

`n % 10`

gets the current digit.

Using:

`n /= 10`

removes that digit.

## Solution

```cpp
class Solution {
public:
    int digitFrequencyScore(int n) {
        int sum = 0;

        while(n != 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }
};
```

## Complexity

Time: `O(log n)`

Space: `O(1)`

## What I Learned

I learned that sometimes a frequency-based formula can be simplified by looking at what the formula actually represents.

Instead of explicitly storing frequencies, `digit * frequency` can be obtained simply by adding every occurrence of the digit.