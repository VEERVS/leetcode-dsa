## Problem

Given a positive integer `n`, express it as a sum of base-10 components using the fewest components possible.

A base-10 component is a non-zero digit multiplied by a power of 10.

For example, `537 = 500 + 30 + 7`, so the answer is `[500, 30, 7]`.

## My Approach

I process the number digit by digit using `% 10` and `/ 10`.

For every non-zero digit, I multiply it by the current power of 10 and store it in the answer.

Since extracting digits from right to left gives the components in ascending order, I reverse the vector at the end to get descending order.

## Key Logic

```cpp
int digit = n % 10;
```

Extracts the last digit.

```cpp
digit * base
```

Converts the digit into its base-10 component.

For example, with `537`:

- `7 * 1 = 7`
- `3 * 10 = 30`
- `5 * 100 = 500`

Zero digits are skipped because they do not contribute a component.

Finally:

```cpp
return vector<int>(ans.rbegin(), ans.rend());
```

returns the components in descending order.

## Solution

```cpp
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        long long base = 1;

        while(n > 0) {
            int digit = n % 10;

            if(digit != 0) {
                ans.push_back(digit * base);
            }

            base *= 10;
            n /= 10;
        }

        return vector<int>(ans.rbegin(), ans.rend());
    }
};
```

## Complexity

- Time Complexity: `O(d)`
- Space Complexity: `O(d)`

`d` is the number of digits in `n`.

## What I Learned

- `% 10` extracts the last digit.
- `/ 10` removes the last digit.
- Maintaining `base = 1, 10, 100...` lets us reconstruct each digit's place value.
- Zero-value components can simply be skipped.
- `rbegin()` and `rend()` can be used to reverse a vector while constructing another vector.