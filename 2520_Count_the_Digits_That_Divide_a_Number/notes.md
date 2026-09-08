## Problem

Given an integer `num`, return the number of digits in `num` that divide `num`.

A digit `d` divides `num` if:

`num % d == 0`

Every occurrence of a digit is counted separately.

## My Approach

I used a temporary copy of the number:

```cpp
int count = 0, temp = num;
```

I extracted each digit using:

```cpp
temp % 10
```

Then I checked whether the original number is divisible by that digit.

If it is, I incremented `count`.

After processing the digit, I removed it using:

```cpp
temp /= 10;
```

## Key Logic

The important part is that I must always test the **original number**:

```cpp
num % digit == 0
```

not the changing `temp`.

For example, with:

`num = 121`

Digits are:

`1, 2, 1`

Both occurrences of `1` divide `121`, while `2` does not.

Therefore, the answer is `2`.

## Solution

```cpp
class Solution {
public:
    int countDigits(int num) {
        int count = 0, temp = num;

        while(temp != 0) {
            int digit = temp % 10;

            if(num % digit == 0) {
                count++;
            }

            temp /= 10;
        }

        return count;
    }
};
```

## Complexity

Time: `O(log n)`

Space: `O(1)`

## What I Learned

I practiced extracting individual digits from an integer using `% 10` and `/ 10`.

I also learned the importance of keeping the original number unchanged while using a temporary variable to traverse its digits.