## Problem

Initially, the account balance is `100`.

Given a purchase amount, round it to the nearest multiple of `10` and subtract the rounded amount from the balance.

When the last digit is `5` or greater, round upward.

Return the final balance.

## My Approach

I use integer arithmetic to perform the rounding.

The expression:

```cpp
((purchaseAmount + 5) / 10) * 10
```

rounds the purchase amount to the nearest multiple of `10`.

I then subtract the rounded amount from the initial balance of `100`.

## Key Logic

Adding `5` before integer division makes values with a last digit of `5` or greater move to the next multiple of `10`.

Examples:

```text
9  → (9 + 5) / 10 * 10  = 10
14 → (14 + 5) / 10 * 10 = 20
15 → (15 + 5) / 10 * 10 = 20
21 → (21 + 5) / 10 * 10 = 20
```

Then:

`balance = 100 - roundedAmount`

## Solution

```cpp
class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int roundOff = ((purchaseAmount + 5) / 10) * 10;
        return 100 - roundOff;
    }
};
```

## Complexity

- Time: `O(1)`
- Space: `O(1)`

## What I Learned

- Integer division can be used to perform rounding tricks.
- Adding half of the divisor before integer division can implement nearest-multiple rounding.
- The expression `(x + 5) / 10 * 10` is a useful pattern for rounding an integer to the nearest multiple of `10`.