## Problem

Given a positive integer `n`, assign alternating signs to its digits.

The **most significant digit** gets a positive sign, and every following digit gets the opposite sign.

For example:

```text
n = 521

(+5) + (-2) + (+1) = 4
```

Return the resulting alternating digit sum.

## My Approach

I processed the number digit by digit using:

- `% 10` to extract the last digit.
- `/ 10` to remove the last digit.

Since this processes the number from **right to left**, I started with:

```cpp
int sign = 1;
```

and flipped the sign after every digit:

```cpp
sign *= -1;
```

At the end, I used `-sign * sum` to correct the overall sign because the required positive sign belongs to the **leftmost digit**, while my traversal starts from the rightmost digit.

## Key Logic

The main idea is:

```cpp
sum += sign * (n % 10);
sign *= -1;
n /= 10;
```

For:

```text
n = 521
```

The traversal is:

```text
Right → Left

1 → +1
2 → -2
5 → +5

sum = 1 - 2 + 5
    = 4
```

The sign correction at the end makes sure the leftmost digit always receives the positive sign.

```cpp
return -sign * sum;
```

## Solution

```cpp
class Solution {
public:
    int alternateDigitSum(int n) {
        int sum = 0;
        int sign = 1;

        while(n != 0) {
            sum += sign * (n % 10);
            sign *= -1;
            n /= 10;
        }

        return -sign * sum;
    }
};
```

## Complexity

**Time:** `O(log n)` because we process each digit once.

**Space:** `O(1)` because only a few variables are used.

## What I Learned

- `% 10` extracts the last digit of a number.
- `/ 10` removes the last digit.
- A variable like `sign` can be used to alternate between `+1` and `-1`.
- When processing digits from right to left, sometimes the final sign needs to be adjusted to match the required left-to-right pattern.
- The number of digits of `n` is `O(log n)`, so processing every digit takes `O(log n)` time.