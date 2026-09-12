## Problem

Given a positive integer `n`, calculate:

- `digitSum` = sum of all digits of `n`
- `squareSum` = sum of the squares of all digits of `n`

The number is considered **good** if:

```text
squareSum - digitSum >= 50
```

Return `true` if `n` is good, otherwise return `false`.

## My Approach

I used a temporary variable `temp` to process each digit while keeping the original number unchanged.

For every digit:

1. Extract the last digit using `% 10`.
2. Add the digit to `digitSum`.
3. Add the square of the digit to `squareSum`.
4. Remove the last digit using `/ 10`.

After processing all digits, I directly check:

```cpp
squareSum - digitSum >= 50
```

## Key Logic

The digit extraction is:

```cpp
temp % 10
```

and removing the digit is:

```cpp
temp /= 10;
```

For example, if:

```text
n = 123
```

then:

```text
digitSum = 1 + 2 + 3 = 6

squareSum = 1² + 2² + 3²
          = 1 + 4 + 9
          = 14
```

Then:

```text
squareSum - digitSum
= 14 - 6
= 8
```

Since `8 < 50`, the number is not good.

## Solution

```cpp
class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum = 0, squareSum = 0, temp = n;

        while(temp != 0) {
            digitSum += temp % 10;
            squareSum += (temp % 10) * (temp % 10);
            temp /= 10;
        }

        return squareSum - digitSum >= 50;
    }
};
```

## Complexity

**Time:** `O(log n)` because every digit is processed once.

**Space:** `O(1)`

## What I Learned

- A temporary variable can be used to traverse the digits without modifying the original number.
- `% 10` extracts the last digit.
- `/ 10` removes the last digit.
- Multiple properties of the same digit can be calculated during a single traversal.
- Returning a boolean condition directly makes the code cleaner.