## Problem

A happy number is a number that eventually becomes `1` when repeatedly replaced by the sum of the squares of its digits.

If the process enters a cycle that does not contain `1`, the number is not happy.

Return `true` if `n` is happy, otherwise return `false`.

## My Approach

I calculate the sum of the squares of the digits using `% 10` and `/ 10`.

If the resulting number is `1` or `7`, I return `true`.

Otherwise, I continue the process recursively.

For unhappy numbers, the process eventually reaches a single-digit cycle. The only single-digit value that can continue into the unhappy cycle is `4`, while `1` and `7` lead to happiness.

## Key Logic

For each digit:

```text
digit = n % 10
sum += digit * digit
n /= 10
```

Example:

`19`

`1² + 9² = 82`

`8² + 2² = 68`

`6² + 8² = 100`

`1² + 0² + 0² = 1`

Therefore, `19` is happy.

## Solution

```cpp
class Solution {
public:
    bool isHappy(int n) {
        if(n == 1 || n == 7) {
            return true;
        }

        int sum = 0;

        while(n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }

        if(sum < 10 && sum != 1 && sum != 7) {
            return false;
        }
        else {
            return isHappy(sum);
        }
    }
};
```

## Complexity

- Time: `O(log n)` per digit-square transformation, with a bounded number of transformations.
- Space: `O(log n)` due to the recursive call stack.

## What I Learned

- `% 10` extracts digits while `/ 10` removes them.
- Repeated digit transformations can quickly reduce a large number to a small value.
- Some problems can be solved by recognizing mathematical patterns instead of explicitly storing every previous value.
- This problem also introduces the idea of **cycles**, which can later be solved more generally using a `set` or Floyd's cycle detection.