## Problem

Given an integer array `nums` and an integer `digit`, return the total number of times `digit` appears in the decimal representation of all elements in `nums`.

For example:

```text
nums = [12, 54, 32, 22]
digit = 2
```

Occurrences of `2`:

```text
12 → 1
32 → 1
22 → 2

Total = 4
```

## My Approach

I used two loops.

The outer loop processes every number in the array.

For each number, I use a temporary variable and process its digits one by one.

For every extracted digit, I compare it with the given `digit`.

If they are equal, I increment `count`.

## Key Logic

The digit extraction is:

```cpp
int dig = temp % 10;
temp /= 10;
```

Then:

```cpp
if(dig == digit) {
    count++;
}
```

This checks every digit of every number exactly once.

## Solution

```cpp
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            int temp = nums[i];

            while(temp != 0) {
                int dig = temp % 10;

                if(dig == digit) {
                    count++;
                }

                temp /= 10;
            }
        }

        return count;
    }
};
```

## Complexity

Let `n` be the number of elements and `d` be the maximum number of digits in an element.

**Time:** `O(n × d)`

**Space:** `O(1)`

## What I Learned

- Nested loops do not automatically mean `O(n²)`; the inner loop here depends on the **number of digits**, not the array size.
- `% 10` and `/ 10` are useful for digit-by-digit processing.
- A running counter can track occurrences without storing the digits.
- The same digit-processing pattern can be reused for many number problems.