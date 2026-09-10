## Problem

Given an integer `x`, find the sum of its digits.

If `x` is divisible by the sum of its digits, then `x` is a **Harshad Number**. Return the sum of its digits.

Otherwise, return `-1`.

For example:

```text
x = 18

Digit sum = 1 + 8 = 9

18 % 9 = 0

Answer = 9
```

## My Approach

I used a temporary variable `temp` to process the digits of `x` without changing the original value.

I repeatedly:

1. Extract the last digit using `% 10`.
2. Add it to `sum`.
3. Remove the last digit using `/ 10`.

After calculating the digit sum, I check whether `x` is divisible by `sum`.

If:

```cpp
x % sum == 0
```

then `x` is a Harshad number, so I return `sum`.

Otherwise, I return `-1`.

## Key Logic

The main digit-processing logic is:

```cpp
while(temp != 0) {
    sum += temp % 10;
    temp /= 10;
}
```

For `x = 18`:

```text
temp = 18
18 % 10 = 8
sum = 8

temp = 1
1 % 10 = 1
sum = 9

temp = 0 → stop
```

Then:

```cpp
if(x % sum == 0)
    return sum;
else
    return -1;
```

I keep `x` unchanged because I need the original number for the divisibility check.

## Solution

```cpp
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0, temp = x;

        while(temp != 0) {
            sum += temp % 10;
            temp /= 10;
        }

        if(x % sum == 0) {
            return sum;
        } else {
            return -1;
        }
    }
};
```

## Complexity

**Time:** `O(log x)` because we process every digit of `x` once.

**Space:** `O(1)` because only a few variables are used.

## What I Learned

- `% 10` extracts the last digit of an integer.
- `/ 10` removes the last digit.
- Using a temporary variable allows me to process a number while preserving the original value.
- A Harshad number is divisible by the sum of its digits.
- Digit-processing problems commonly have `O(log n)` time complexity because the number of digits is proportional to `log n`.